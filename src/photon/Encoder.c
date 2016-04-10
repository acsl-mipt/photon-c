#include "photon/Config.h"
#include "photon/Encoder.h"
#include "photon/Result.h"
#include "photon/Endian.h"
#include "photon/Utils.h"

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

static PHOTON_INLINE void writeBer16Fixed(uint16_t value, uint8_t* dest)
{
    *dest = 0x80 | 2;
    Photon_Le16Enc(dest + 1, value);
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

    size_t dataSize = PhotonWriter_CurrentPtr(dest) - sizeDest - 3;
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

PhotonResult PhotonEncoder_EncodeCommand(PhotonCommandEnc* gen, PhotonWriter* dest)
{
    PHOTON_TRY(PhotonBer_Serialize(gen->header.componentNumber, dest));
    PHOTON_TRY(PhotonBer_Serialize(gen->header.commandNumber, dest));
    return gen->gen(gen->data, dest);
}

static PhotonResult tmStatusMessageGen(void* data, PhotonWriter* dest)
{
    PhotonTmStatusMessageGen* gen = (PhotonTmStatusMessageGen*)data;
    PHOTON_TRY(PhotonBer_Serialize(gen->msg.segmentNumber, dest));
    PHOTON_TRY(PhotonBer_Serialize(gen->msg.maxSegmentNumber, dest));
    PHOTON_TRY(PhotonBer_Serialize(gen->msg.componentNumber, dest));
    PHOTON_TRY(PhotonBer_Serialize(gen->msg.messageNumber, dest));
    return gen->gen(gen->data, dest);
}

PhotonResult PhotonEncoder_EncodeTmStatusMessage(PhotonTmStatusMessageGen* gen, PhotonWriter* dest)
{
    return PhotonEncoder_EncodeData(0x1c72, gen, tmStatusMessageGen, dest);
}

static PhotonResult tmEventMessageGen(void* data, PhotonWriter* dest)
{
    PhotonTmEventMessageGen* gen = (PhotonTmEventMessageGen*)data;
    PHOTON_TRY(PhotonBer_Serialize(gen->msg.componentNumber, dest));
    PHOTON_TRY(PhotonBer_Serialize(gen->msg.messageNumber, dest));
    PHOTON_TRY(PhotonBer_Serialize(gen->msg.eventNumber, dest));
    PHOTON_TRY(PhotonTime_Serialize(&gen->msg.timestamp, dest));
    return gen->gen(gen->data, dest);
}

PhotonResult PhotonEncoder_EncodeTmEventMessage(PhotonTmEventMessageGen* gen, PhotonWriter* dest)
{
    return PhotonEncoder_EncodeData(0x0c78, gen, tmEventMessageGen, dest);
}

static PhotonResult addressPacketGen(void* data, PhotonWriter* dest)
{
    PhotonAddressPacketEnc* enc = (PhotonAddressPacketEnc*)data;
    PHOTON_TRY(PhotonBer_Serialize((PhotonBer)enc->packet.address.type, dest));

    switch (enc->packet.address.type) {
    case PhotonAddressType_SimpleAddress: {
        const PhotonSimpleAddress* addr = &enc->packet.address.address.simple;
        PHOTON_TRY(PhotonBer_Serialize(addr->srcAddress, dest));
        PHOTON_TRY(PhotonBer_Serialize(addr->destAddress, dest));
        break;
    }
    case PhotonAddressType_Broadcast: {
        const PhotonMulticastAddress* addr = &enc->packet.address.address.multicast;
        PHOTON_TRY(PhotonBer_Serialize(addr->srcAddress, dest));
        PHOTON_TRY(PhotonBer_Serialize(addr->srcComponentNumber, dest));
        PHOTON_TRY(PhotonBer_Serialize(addr->destComponentNumber, dest));
        break;
    }
    case PhotonAddressType_NetworkAddress: {
        const PhotonNetworkAddress* addr = &enc->packet.address.address.network;
        PHOTON_TRY(PhotonBer_Serialize(addr->srcAddress, dest));
        PHOTON_TRY(PhotonBer_Serialize(addr->srcComponentNumber, dest));
        PHOTON_TRY(PhotonBer_Serialize(addr->destComponentNumber, dest));
        PHOTON_TRY(PhotonBer_Serialize(addr->destAddress, dest));
        break;
    }
    case PhotonAddressType_GroupAddress: {
        const PhotonGroupAddress* addr = &enc->packet.address.address.group;
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

    PHOTON_TRY(PhotonTime_Serialize(&enc->packet.timestamp, dest));

    return enc->gen(enc->data, dest);
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
    default:
        return PhotonResult_InvalidErrorControlType;
    };

    if ((dest->end - dest->current) < csSize) {
        return PhotonResult_NotEnoughSpace;
    }
    PhotonWriter_SliceFromBack(dest, csSize, &payload);
    if (PhotonWriter_WritableSize(&payload) % 2) {
        payload.end--;
    }

    PHOTON_TRY(gen(data, &payload));
    dest->current = payload.current;
    if (!((dest->current - start)) % 2) {
        dest->current++;
    }

    // TODO: контрольные суммы
    switch (csType) {
    case PhotonErrorControlType_Crc16:
        (void)start;
        uint16_t cs = Photon_Crc16(start, (dest->current - start) / 2);
        PhotonWriter_WriteUint16Le(dest, cs);
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
    PhotonCounterAdjustmentPacketEnc* enc = (PhotonCounterAdjustmentPacketEnc*)data;
    PHOTON_TRY(PhotonBer_Serialize(1, dest));
    PHOTON_TRY(PhotonBer_Serialize((PhotonBer)enc->streamType, dest));
    PHOTON_TRY(PhotonBer_Serialize((PhotonBer)enc->errorControlType, dest));
    PHOTON_TRY(PhotonBer_Serialize(enc->sequenceCounter, dest));

    return enc->gen(enc->data, dest);
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

    unsigned csSize = 2; //TODO: from enum
    size_t dataSize = PhotonWriter_CurrentPtr(dest) - sizeDest - 3 + csSize;
    writeBer16Fixed(dataSize, sizeDest);

    return PhotonResult_Ok;
}

PhotonResult PhotonEncoder_EncodeExchangePacket(PhotonExchangePacketEnc* encoder, PhotonWriter* dest)
{
    return encodePacket(0x6c5a, encoder->packet.errorControlType, encoder, exchangePacketGen, dest);
}
