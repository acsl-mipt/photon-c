#include "photon/Config.h"
#include "photon/Exchange.h"
#include "photon/RingBuffer.h"

#include <stdbool.h>

void PhotonUavExchange_Init(PhotonUavExchange* self)
{
    self->cmdInCounter = 0;
    self->cmdOutCounter = 0;
    self->tmCounter = 0;
    PhotonRingBuf_Init(&self->ringBufIn, self->inBuffer, sizeof(self->inBuffer));
    PhotonRingBuf_Init(&self->ringBufOut, self->outBuffer, sizeof(self->outBuffer));
    self->errorControlType = PhotonErrorControlType_Crc16;
}

void PhotonUavExchange_AcceptIncomingData(PhotonUavExchange* self, const void* src, size_t size)
{
    PhotonRingBuf_Write(&self->ringBufIn, src, size);
}

#define HEADER_SIZE 2

static bool skipSeparator(PhotonRingBuf* ringBuf, uint16_t separator)
{
    const uint8_t firstByte = (separator & 0xf0) >> 8;;
    const uint8_t secondByte = separator & 0x0f;
    while (true) {
        if (PhotonRingBuf_ReadableSize(ringBuf) < HEADER_SIZE) {
            return false;
        }
        if (firstByte != PhotonRingBuf_PeekUint8(ringBuf, 0)) {
            PhotonRingBuf_Erase(ringBuf, 1);
            continue;
        }
        if (secondByte != PhotonRingBuf_PeekUint8(ringBuf, 1)) {
            PhotonRingBuf_Erase(ringBuf, 2);
            continue;
        }
        PhotonRingBuf_Erase(ringBuf, 2);
        return true;
    }
    return false;
}

static PhotonResult peekHeader(PhotonReader* src, uint16_t* dest)
{
    if ((src->end - src->current) < 3) {
        return PhotonResult_InvalidSize;
    }

    const uint8_t* start = src->current;
    *dest = PhotonReader_ReadUint16Be(src);
    src->current = start;

    return PhotonResult_Ok;
}

static PhotonResult parseUavIncomingPacket(PhotonUavExchange* self)
{

}

static bool findPacketInRingBuf(PhotonRingBuf* ringBuf, uint16_t separator, uint8_t* dest)
{
    if (!skipSeparator(ringBuf, separator)) {
        return false;
    }

    size_t incomingSize = PhotonRingBuf_ReadableSize(ringBuf);
    if (incomingSize < (HEADER_SIZE + 1)) {
        return false;
    }

    size_t packetSize;
    uint8_t berHeader = PhotonRingBuf_PeekUint8(ringBuf, HEADER_SIZE);
    if (berHeader & 0x80) {
        size_t berSize = berHeader & 0x7f;
        if (berSize > 8) {
            //TODO: send error
            PhotonRingBuf_Erase(ringBuf, 3);
            return false;
        }
        PhotonBer dataSize;
        PhotonRingBuf_Peek(ringBuf, &dataSize, berSize, 3); // big endian?
        packetSize = 3 + berSize + dataSize;
    } else {
        packetSize = 3 + berHeader;
    }

    if (packetSize > PHOTON_MAX_PACKET_SIZE) {
        //TODO: send error
        return false;
    }

    if (incomingSize < packetSize) {
        return false;
    }

    PhotonRingBuf_Read(ringBuf, dest, packetSize);
    return true;
}

PhotonResult PhotonUavExchange_HandleIncomingPacket(PhotonUavExchange* self, PhotonAddressPacketHandler handler, void* data)
{
    if (!findPacketInRingBuf(&self->ringBufIn, 0x4f07, self->temp)) {
        return false;
    }

    PhotonReader src;
    PhotonReader_Init(&src, self->temp, sizeof(self->temp));
    uint16_t header;
    PHOTON_TRY(peekHeader(&src, &header));

    switch (header) {
    case PHOTON_EXCHANGE_PACKET_HEADER: {
        PhotonExchangePacketDec exchangePacket;
        PHOTON_TRY(PhotonDecoder_DecodeExchangePacket(&src, &exchangePacket));

        if (exchangePacket.packet.streamType != PhotonStreamType_Commands) {
            return PhotonResult_InvalidStreamType;
        }

        if (exchangePacket.packet.sequenceCounter != self->cmdInCounter) {
            //TODO: сгенерировать пакет согласования счетчика
            return PhotonResult_InvalidSequenceCounter;
        }

        self->cmdInCounter++;

        PhotonAddressPacketDec addressPacket;
        PHOTON_TRY(PhotonDecoder_DecodeAddressPacket(&src, &addressPacket));
        PHOTON_TRY(handler(data, &addressPacket));
        break;
    }
//     case PHOTON_COUNTER_ADJUSTMENT_PACKET_HEADER: {
//         PhotonCounterAdjustmentPacket packet;
//         PHOTON_TRY(PhotonDecoder_DecodeCounterAdjustmentPacket(&src, &packet));
//         if (packet.packet.streamType != PhotonStreamType_Commands) {
//             return PhotonResult_InvalidStreamType;
//         }
//         self->cmdInCounter = packet.sequenceCounter;
//         break;
//    }
    default:
        return PhotonResult_InvalidPacketHeader;
    }
    return PhotonResult_Ok;
}

static PhotonResult sendPacket(PhotonUavExchange* self, void* data, PhotonGenerator gen)
{
    PhotonWriter dest;
    PhotonWriter_Init(&dest, self->temp, sizeof(self->temp));
    PhotonExchangePacketEnc enc;
    enc.data = data;
    enc.gen = gen;
    enc.packet.errorControlType = self->errorControlType;
    enc.packet.sequenceCounter = self->tmCounter;
    enc.packet.streamType = PhotonStreamType_Telemetry;
    enc.packet.windowSize = 0;
    PHOTON_TRY(PhotonEncoder_EncodeExchangePacket(&enc, &dest));
    PhotonRingBuf_Write(&self->ringBufOut, dest.start, dest.current - dest.start);
    return PhotonResult_Ok;
}

static PhotonResult encodeAddressPacket(void* data, PhotonWriter* dest)
{
    PhotonAddressPacketEnc* enc = (PhotonAddressPacketEnc*)data;
    PHOTON_TRY(PhotonEncoder_EncodeAddressPacket(enc, dest));
    return PhotonResult_Ok;
}

PhotonResult PhotonUavExchange_SendPacket(PhotonUavExchange* self, const PhotonAddress* address, void* data,
                                          PhotonGenerator gen)
{
    PhotonAddressPacketEnc enc;
    enc.address = *address;
    enc.data = data;
    enc.gen = gen;
    enc.timestamp = 0;
    enc.timestampType = 2; // FIXME
    return sendPacket(self, &enc, encodeAddressPacket);
}
