#include "photon/Config.h"
#include "photon/Decoder.h"
#include "photon/Ber.h"
#include "photon/Utils.h"

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

static PhotonResult decodeDataHeader(PhotonReader* src, PhotonDataHeader* dest, uint16_t expectedCode)
{
    if (PhotonReader_ReadableSize(src) < 3) {
        return PhotonResult_InvalidDataSize;
    }

    dest->code = PhotonReader_ReadUint16Be(src);
    if (dest->code != expectedCode) {
        return PhotonResult_InvalidDataHeader;
    }

    PHOTON_TRY(PhotonBer_Deserialize(&dest->length, src));

    return PhotonResult_Ok;
}

static PhotonResult sliceData(PhotonReader* src, size_t length, PhotonReader* dest)
{
    if (length > PhotonReader_ReadableSize(src)) {
        return PhotonResult_InvalidDataSize;
    }

    PhotonReader_Slice(src, length, dest);

    return PhotonResult_Ok;
}

PhotonResult PhotonDecoder_DecodeCommandMessage(PhotonReader* src, PhotonCommandMessage* dest)
{
    PHOTON_TRY(decodeDataHeader(src, &dest->header, PHOTON_COMMAND_MESSAGE_HEADER));

    PHOTON_TRY(sliceData(src, dest->header.length, &dest->commands));

    return PhotonResult_Ok;
}

PhotonResult PhotonDecoder_DecodeCommandResult(PhotonReader* src, PhotonCommandResult* dest)
{
    PHOTON_TRY(decodeDataHeader(src, &dest->header, PHOTON_COMMAND_RESULT_HEADER));

    PHOTON_TRY(sliceData(src, dest->header.length, &dest->resultData));

    return PhotonResult_Ok;
}

PhotonResult PhotonDecoder_DecodeTmStatusMessage(PhotonReader* src, PhotonTmStatusMessage* dest)
{
    PHOTON_TRY(decodeDataHeader(src, &dest->header, PHOTON_TM_STATUS_MESSAGE_HEADER));
    const uint8_t* msgEnd = PhotonReader_CurrentPtr(src) + dest->header.length;

    PHOTON_TRY(PhotonBer_Deserialize(&dest->segmentNumber, src));
    PHOTON_TRY(PhotonBer_Deserialize(&dest->maxSegmentNumber, src));
    PHOTON_TRY(PhotonBer_Deserialize(&dest->componentNumber, src));
    PHOTON_TRY(PhotonBer_Deserialize(&dest->messageNumber, src));

    PHOTON_TRY(sliceData(src, msgEnd - PhotonReader_CurrentPtr(src), &dest->parameters));

    return PhotonResult_Ok;
}

PhotonResult PhotonDecoder_DecodeTmEventMessage(PhotonReader* src, PhotonTmEventMessage* dest)
{
    PHOTON_TRY(decodeDataHeader(src, &dest->header, PHOTON_TM_EVENT_MESSAGE_HEADER));
    const uint8_t* msgEnd = PhotonReader_CurrentPtr(src) + dest->header.length;

    PHOTON_TRY(PhotonBer_Deserialize(&dest->componentNumber, src));
    PHOTON_TRY(PhotonBer_Deserialize(&dest->messageNumber, src));
    PHOTON_TRY(PhotonBer_Deserialize(&dest->eventNumber, src));
    PHOTON_TRY(PhotonBer_Deserialize(&dest->timestamp, src));

    PHOTON_TRY(sliceData(src, msgEnd - PhotonReader_CurrentPtr(src), &dest->parameters));

    return PhotonResult_Ok;
}

PhotonResult PhotonDecoder_DecodeAddressPacket(PhotonReader* src, PhotonAddressPacketDec* dest)
{
    PHOTON_TRY(decodeDataHeader(src, &dest->header, PHOTON_ADDRESS_PACKET_HEADER));
    const uint8_t* dataEnd = src->current + dest->header.length;

    PhotonBer addressType;
    PHOTON_TRY(PhotonBer_Deserialize(&addressType, src));

    switch (addressType) {
    case 2: {
        dest->packet.address.type = PhotonAddressType_SimpleAddress;
        const PhotonSimpleAddress* addr = &dest->packet.address.address.simple;
        PHOTON_TRY(PhotonBer_Deserialize(&addr->srcAddress, src));
        PHOTON_TRY(PhotonBer_Deserialize(&addr->destAddress, src));
        break;
    }
    case 3: {
        dest->packet.address.type = PhotonAddressType_Broadcast;
        const PhotonMulticastAddress* addr = &dest->packet.address.address.multicast;
        PHOTON_TRY(PhotonBer_Deserialize(&addr->srcAddress, src));
        PHOTON_TRY(PhotonBer_Deserialize(&addr->srcComponentNumber, src));
        PHOTON_TRY(PhotonBer_Deserialize(&addr->destComponentNumber, src));
        break;
    }
    case 4: {
        dest->packet.address.type = PhotonAddressType_NetworkAddress;
        const PhotonNetworkAddress* addr = &dest->packet.address.address.network;
        PHOTON_TRY(PhotonBer_Deserialize(&addr->srcAddress, src));
        PHOTON_TRY(PhotonBer_Deserialize(&addr->srcComponentNumber, src));
        PHOTON_TRY(PhotonBer_Deserialize(&addr->destComponentNumber, src));
        PHOTON_TRY(PhotonBer_Deserialize(&addr->destAddress, src));
        break;
    }
    case 6: {
        dest->packet.address.type = PhotonAddressType_GroupAddress;
        const PhotonGroupAddress* addr = &dest->packet.address.address.group;
        PHOTON_TRY(PhotonBer_Deserialize(&addr->srcAddress, src));
        PHOTON_TRY(PhotonBer_Deserialize(&addr->srcComponentNumber, src));
        PHOTON_TRY(PhotonBer_Deserialize(&addr->destComponentNumber, src));
        PHOTON_TRY(PhotonBer_Deserialize(&addr->destAddress, src));
        PHOTON_TRY(PhotonBer_Deserialize(&addr->srcGroup, src));
        PHOTON_TRY(PhotonBer_Deserialize(&addr->destGroup, src));
        break;
    }
    default:
        return PhotonResult_InvalidAddressType;
    }

    PHOTON_TRY(PhotonBer_Deserialize(&dest->packet.timestampType, src));
    PHOTON_TRY(PhotonBer_Deserialize(&dest->packet.timestamp, src));

    PHOTON_TRY(sliceData(src, dataEnd - src->current, &dest->data));

    return PhotonResult_Ok;
}

static PhotonResult decodeExchangePacketHeader(PhotonReader* src, PhotonPacketHeader* dest,
                                               PhotonStreamType* streamType, PhotonErrorControlType* controlType,
                                               const uint8_t** end, uint16_t expectedCode)
{
    const uint8_t* packetStart = PhotonReader_CurrentPtr(src);

     if (PhotonReader_ReadableSize(src) < 5) {
        return PhotonResult_InvalidDataSize;
    }

    dest->code = PhotonReader_ReadUint16Be(src);
    if (dest->code != expectedCode) {
        return PhotonResult_InvalidDataHeader;
    }

    PHOTON_TRY(PhotonBer_Deserialize(&dest->length, src));
    const uint8_t* packetEnd = PhotonReader_CurrentPtr(src) + dest->length;
    PHOTON_TRY(PhotonBer_Deserialize(&dest->reserved, src));

    if (dest->reserved != 1) {
        return PhotonResult_InvalidReservedFieldValue;
    }

    PhotonBer streamTypeBer;
    PHOTON_TRY(PhotonBer_Deserialize(&streamTypeBer, src));

    switch (streamTypeBer) {
    case 0:
        *streamType = PhotonStreamType_Commands;
        break;
    case 1:
        *streamType = PhotonStreamType_Telemetry;
        break;
    default:
        return PhotonResult_InvalidStreamType;
    };

    PhotonBer controlTypeBer;
    PHOTON_TRY(PhotonBer_Deserialize(&controlTypeBer, src));

    if (PhotonReader_ReadableSize(src) < dest->length) {
        return PhotonResult_InvalidDataSize;
    }

    unsigned checkedSize = packetEnd - packetStart;

    switch (controlTypeBer) {
    case 1:
        *controlType = PhotonErrorControlType_Crc16;
        packetEnd -= 2;
        uint16_t checksumCrc16;
        memcpy(&checksumCrc16, packetEnd, 2);
        uint16_t cs = Photon_Crc16(packetStart, (packetEnd - packetStart) / 2);
        if (cs != checksumCrc16) {
            return PhotonResult_InvalidChecksum;
        }
        break;
    default:
        return PhotonResult_InvalidErrorControlType;
    };

    *end = packetEnd;

    return PhotonResult_Ok;
}

PhotonResult PhotonDecoder_DecodeExchangePacket(PhotonReader* src, PhotonExchangePacketDec* dest)
{
    const uint8_t* packetEnd;
    const uint8_t* packetStart = src->current;
    PHOTON_TRY(decodeExchangePacketHeader(src, &dest->header, &dest->packet.streamType, &dest->packet.errorControlType,
                                          &packetEnd, PHOTON_EXCHANGE_PACKET_HEADER));

    PHOTON_TRY(PhotonBer_Deserialize(&dest->packet.windowSize, src));

    if (dest->packet.windowSize > (UINT16_MAX / 2)) {
        return PhotonResult_InvalidWindowSize;
    }

    PHOTON_TRY(PhotonBer_Deserialize(&dest->packet.sequenceCounter, src));

    if (dest->packet.sequenceCounter > UINT16_MAX) {
        return PhotonResult_InvalidSequenceCounter;
    }

    unsigned csSize;
    switch (dest->packet.errorControlType) {
    case PhotonErrorControlType_Crc16:
        csSize = 2;
        break;
    };

    PhotonReader_Slice(src, packetEnd - PhotonReader_CurrentPtr(src), &dest->data);

    PhotonReader_Skip(src, csSize);

    return PhotonResult_Ok;
}

// PhotonResult PhotonDecoder_DecodeCounterAdjustmentPacket(PhotonReader* src, PhotonCounterAdjustmentPacket* dest)
// {
//     const uint8_t* packetEnd;
//     PHOTON_TRY(decodeExchangePacketHeader(src, &dest->header, &packetEnd, PHOTON_COUNTER_ADJUSTMENT_PACKET_HEADER));
//
//     PHOTON_TRY(PhotonBer_Deserialize(&dest->sequenceCounter, src));
//
//     // TODO: skip CS
//
//     return PhotonResult_Ok;
// }
//
// PhotonResult PhotonDecoder_DecodeReceiptPacket(PhotonReader* src, PhotonReceiptPacket* dest)
// {
//     const uint8_t* packetEnd;
//     PHOTON_TRY(decodeExchangePacketHeader(src, &dest->header, &packetEnd, PHOTON_RECEIPT_PACKET_HEADER));
//
//     if (dest->header.streamType != PhotonStreamType_Commands) {
//         return PhotonResult_InvalidStreamType;
//     }
//
//     PHOTON_TRY(PhotonBer_Deserialize(&dest->lastSequenceCounter, src));
//
//     // TODO: skip CS
//
//     return PhotonResult_Ok;
// }
