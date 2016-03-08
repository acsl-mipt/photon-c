#include "photon/Config.h"
#include "photon/Encoder.h"
#include "photon/Result.h"

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

static PHOTON_INLINE void writeBer16Fixed(uint16_t value, uint8_t* dest)
{
    *dest = 0x80 & 3;
    *(dest + 1) = (value & 0xf0) >> 8;
    *(dest + 2) = value & 0x0f;
}

PhotonResult PhotonEncoder_EncodeData(uint16_t header, void* data, PhotonGenerator gen, PhotonWriter* dest)
{
    if (PhotonWriter_WritableSize(dest) < 5) {
        return PhotonResult_NotEnoughSpace;
    }

    PhotonWriter_WriteUint16Be(dest, header);

    uint8_t* sizeDest = PhotonWriter_CurrentPtr(dest);
    PhotonWriter_Skip(dest, 3);

    PHOTON_TRY(gen(data, dest));

    size_t dataSize = PhotonWriter_CurrentPtr(dest) - sizeDest;
    writeBer16Fixed(dataSize, sizeDest);

    return PhotonResult_Ok;
}

PhotonResult PhotonEncoder_EncodeCommandResult(void* data, PhotonGenerator resultGen, PhotonWriter* dest)
{
    return PhotonEncoder_EncodeData(0x0c66, data, resultGen, dest);
}

PhotonResult PhotonEncoder_EncodeCommandMessage(void* data, PhotonGenerator msgGen, PhotonWriter* dest)
{
    return PhotonEncoder_EncodeData(0x0c65, data, msgGen, dest);
}

static PhotonResult tmStatusMessageGen(void* data, PhotonWriter* dest)
{
    PhotonTmStatusMessageGen* gen = (PhotonTmStatusMessageGen*)data;
    PHOTON_TRY(PhotonBer_Serialize(gen->segmentNumber, dest));
    PHOTON_TRY(PhotonBer_Serialize(gen->maxSegmentNumber, dest));
    PHOTON_TRY(PhotonBer_Serialize(gen->componentNumber, dest));
    PHOTON_TRY(PhotonBer_Serialize(gen->messageNumber, dest));
    return gen->gen(gen->data, dest);
}

PhotonResult PhotonEncoder_EncodeTmStatusMessage(PhotonTmStatusMessageGen* gen, PhotonWriter* dest)
{
    return PhotonEncoder_EncodeData(0x1c72, gen, tmStatusMessageGen, dest);
}

static PhotonResult tmEventMessageGen(void* data, PhotonWriter* dest)
{
    PhotonTmEventMessageGen* gen = (PhotonTmEventMessageGen*)data;
    PHOTON_TRY(PhotonBer_Serialize(gen->componentNumber, dest));
    PHOTON_TRY(PhotonBer_Serialize(gen->messageNumber, dest));
    PHOTON_TRY(PhotonBer_Serialize(gen->eventNumber, dest));
    PHOTON_TRY(PhotonBer_Serialize(gen->timestamp, dest));
    return gen->gen(gen->data, dest);
}

PhotonResult PhotonEncoder_EncodeTmEventMessage(PhotonTmEventMessageGen* gen, PhotonWriter* dest)
{
    return PhotonEncoder_EncodeData(0x0c78, gen, tmEventMessageGen, dest);
}

static PhotonResult addressPacketGen(void* data, PhotonWriter* dest)
{
    PhotonAddressPacketEnc* gen = (PhotonAddressPacketEnc*)data;
    PHOTON_TRY(PhotonBer_Serialize((PhotonBer)gen->address.type, dest));

    switch (gen->address.type) {
    case PhotonAddressType_Broadcast: {
        const PhotonMulticastAddress* addr = &gen->address.address.multicast;
        PHOTON_TRY(PhotonBer_Serialize(addr->srcAddress, dest));
        PHOTON_TRY(PhotonBer_Serialize(addr->srcComponentNumber, dest));
        PHOTON_TRY(PhotonBer_Serialize(addr->destComponentNumber, dest));
        break;
    }
    case PhotonAddressType_NetworkAddress: {
        const PhotonNetworkAddress* addr = &gen->address.address.network;
        PHOTON_TRY(PhotonBer_Serialize(addr->srcAddress, dest));
        PHOTON_TRY(PhotonBer_Serialize(addr->srcComponentNumber, dest));
        PHOTON_TRY(PhotonBer_Serialize(addr->destComponentNumber, dest));
        PHOTON_TRY(PhotonBer_Serialize(addr->destAddress, dest));
        break;
    }
    case PhotonAddressType_SimpleAddress: {
        const PhotonSimpleAddress* addr = &gen->address.address.simple;
        PHOTON_TRY(PhotonBer_Serialize(addr->srcAddress, dest));
        PHOTON_TRY(PhotonBer_Serialize(addr->destAddress, dest));
        break;
    }
    case PhotonAddressType_GroupAddress: {
        const PhotonGroupAddress* addr = &gen->address.address.group;
        PHOTON_TRY(PhotonBer_Serialize(addr->srcAddress, dest));
        PHOTON_TRY(PhotonBer_Serialize(addr->srcComponentNumber, dest));
        PHOTON_TRY(PhotonBer_Serialize(addr->destComponentNumber, dest));
        PHOTON_TRY(PhotonBer_Serialize(addr->destAddress, dest));
        PHOTON_TRY(PhotonBer_Serialize(addr->srcGroup, dest));
        PHOTON_TRY(PhotonBer_Serialize(addr->destGroup, dest));
        break;
    }
    default:
        return PhotonResult_InvalidAddressType;
    }

    PHOTON_TRY(PhotonBer_Serialize(2, dest)); // TODO: енум метки врем, destени
    PHOTON_TRY(PhotonBer_Serialize(gen->timestamp, dest));

    return gen->gen(gen->data, dest);
}

PhotonResult PhotonEncoder_EncodeAddressPacket(PhotonAddressPacketEnc* encoder, PhotonWriter* dest)
{
    return PhotonEncoder_EncodeData(0xac5e, encoder, addressPacketGen, dest);
}


static PhotonResult encodePacket(uint16_t header, PhotonErrorControlType csType, void* data, PhotonGenerator gen,
                                 PhotonWriter* dest)
{
    uint8_t* start = PhotonWriter_CurrentPtr(dest);
    if (PhotonWriter_WritableSize(dest) < 2) {
        return PhotonResult_NotEnoughSpace;
    }

    PhotonWriter_WriteUint16Be(dest, header);

    PhotonWriter payload;
    int csSize;
    switch (csType) {
    case PhotonErrorControlType_Crc16:
        csSize = 2;
        break;
    case PhotonErrorControlType_ReedSolomon:
        csSize = 4;
        break;
    default:
        return PhotonResult_InvalidErrorControlType;
    };

    if ((dest->end - dest->current) < csSize) {
        return PhotonResult_NotEnoughSpace;
    }
    PhotonWriter_SliceFromBack(dest, csSize, &payload);

    PHOTON_TRY(gen(data, &payload));
    dest->current = payload.current;

    // TODO: контрольные суммы
    switch (csType) {
    case PhotonErrorControlType_Crc16:
        (void)start;
        uint16_t crc16 = 0;
        PhotonWriter_WriteUint16Be(dest, crc16);
        break;
    case PhotonErrorControlType_ReedSolomon:
        (void)start;
        uint32_t rs = 0;
        PhotonWriter_WriteUint32Be(dest, rs);
        break;
    };

    return PhotonResult_Ok;
}

static PhotonResult receiptPacketGen(void* data, PhotonWriter* dest)
{
    PhotonReceiptPacketEnc* gen = (PhotonReceiptPacketEnc*)data;
    PHOTON_TRY(PhotonBer_Serialize(1, dest));
    PHOTON_TRY(PhotonBer_Serialize((PhotonBer)PhotonStreamType_Commands, dest));
    PHOTON_TRY(PhotonBer_Serialize((PhotonBer)gen->errorControlType, dest));
    PHOTON_TRY(PhotonBer_Serialize(gen->lastSequenceCounter, dest));

    return gen->gen(gen->data, dest);
}

PhotonResult PhotonEncoder_EncodeReceiptPacket(PhotonReceiptPacketEnc* encoder, PhotonWriter* dest)
{
    return encodePacket(0x345c, encoder->errorControlType, encoder, receiptPacketGen, dest);
}

static PhotonResult counterAdjustmentPacketGen(void* data, PhotonWriter* dest)
{
    PhotonCounterAdjustmentPacketEnc* gen = (PhotonCounterAdjustmentPacketEnc*)data;
    PHOTON_TRY(PhotonBer_Serialize(1, dest));
    PHOTON_TRY(PhotonBer_Serialize((PhotonBer)gen->streamType, dest));
    PHOTON_TRY(PhotonBer_Serialize((PhotonBer)gen->errorControlType, dest));
    PHOTON_TRY(PhotonBer_Serialize(gen->sequenceCounter, dest));

    return gen->gen(gen->data, dest);
}

PhotonResult PhotonEncoder_EncodeCounterAdjustmentPacket(PhotonCounterAdjustmentPacketEnc* encoder, PhotonWriter* dest)
{
    return encodePacket(0x645b, encoder->errorControlType, encoder, counterAdjustmentPacketGen, dest);
}

static PhotonResult exchangePacketGen(void* data, PhotonWriter* dest)
{
    PhotonExchangePacketEnc* gen = (PhotonExchangePacketEnc*)data;

    uint8_t* sizeDest = PhotonWriter_CurrentPtr(dest);
    PhotonWriter_Skip(dest, 3);

    PHOTON_TRY(PhotonBer_Serialize(1, dest));
    PHOTON_TRY(PhotonBer_Serialize((PhotonBer)gen->packet.streamType, dest));
    PHOTON_TRY(PhotonBer_Serialize((PhotonBer)gen->packet.errorControlType, dest));
    PHOTON_TRY(PhotonBer_Serialize(gen->packet.windowSize, dest));
    PHOTON_TRY(PhotonBer_Serialize(gen->packet.sequenceCounter, dest));

    PHOTON_TRY(gen->gen(gen->data, dest));

    size_t dataSize = PhotonWriter_CurrentPtr(dest) - sizeDest;
    writeBer16Fixed(dataSize, sizeDest);

    return PhotonResult_Ok;
}

PhotonResult PhotonEncoder_EncodeExchangePacket(PhotonExchangePacketEnc* encoder, PhotonWriter* dest)
{
    return encodePacket(0x6c5a, encoder->packet.errorControlType, encoder, exchangePacketGen, dest);
}
