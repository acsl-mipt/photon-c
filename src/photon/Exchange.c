#include "photon/Config.h"
#include "photon/Exchange.h"
#include "photon/RingBuffer.h"
#include "photon/Endian.h"
#include "photon/Utils.h"
#include "photon/Clock.h"
#include "photon/System.h"

#include <stdbool.h>

void PhotonUavExchange_Init(PhotonUavExchange* self)
{
    self->cmdInCounter = 0;
    self->cmdOutCounter = 0;
    self->tmCounter = 0;
    PhotonRingBuf_Init(&self->ringBufIn, self->inBuffer, sizeof(self->inBuffer));
    PhotonRingBuf_Init(&self->ringBufOut, self->outBuffer, sizeof(self->outBuffer));
    self->errorControlType = PhotonErrorControlType_Crc16;
    Photon_Be16Enc(&self->encodedSeparator, 0x047e);
}

static void acceptIncomingData(PhotonUavExchange* self)
{
    size_t recievedSize = 1;
    while (recievedSize != 0) {
        uint8_t* dest = PhotonRingBuf_WritePtr(&self->ringBufIn);
        size_t size = PhotonRingBuf_LinearReadableSize(&self->ringBufIn);
        recievedSize = PhotonSys_RecieveCommands(dest, size);
        PhotonRingBuf_Advance(&self->ringBufIn, recievedSize);
    }
}

PhotonResult PhotonUavExchange_HandleIncomingPacket(PhotonUavExchange* self, PhotonAddressPacketHandler handler, void* data)
{
    acceptIncomingData(self);
    size_t packetSize = Photon_FindPacketInRingBuf(&self->ringBufIn, 0x047e);
    if (!packetSize) {
        return PhotonResult_PacketNotFound;
    }
    PhotonRingBuf_Peek(&self->ringBufIn, &self->temp, packetSize, 0);

    PhotonReader src;
    PhotonReader_Init(&src, self->temp, sizeof(self->temp));
    uint16_t header;
    PHOTON_TRY(Photon_PeakHeader(&src, &header));

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
        PHOTON_TRY(PhotonDecoder_DecodeAddressPacket(&exchangePacket.data, &addressPacket));
        PHOTON_TRY(handler(data, &addressPacket.packet, &addressPacket.data));
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
    PhotonRingBuf_Write(&self->ringBufOut, &self->encodedSeparator, 2);
    PhotonRingBuf_Write(&self->ringBufOut, dest.start, dest.current - dest.start);

    size_t acceptedSize = 1;
    while (acceptedSize != 0) {
        const uint8_t* src = PhotonRingBuf_ReadPtr(&self->ringBufOut);
        size_t size = PhotonRingBuf_LinearReadableSize(&self->ringBufOut);
        acceptedSize = PhotonSys_SendTelemetry(src, size);
        PhotonRingBuf_Erase(&self->ringBufOut, acceptedSize);
    }
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
    enc.packet.address = *address;
    enc.data = data;
    enc.gen = gen;
    PhotonClock_GetTime(&enc.packet.timestamp);
    return sendPacket(self, &enc, encodeAddressPacket);
}
