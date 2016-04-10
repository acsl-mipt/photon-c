#include "photon/GcExchange.hpp"
#include "photon/RingBuffer.h"
#include "photon/Result.h"
#include "photon/Encoder.h"
#include "photon/Decoder.h"
#include "photon/Utils.h"

#include <algorithm>
#include <cstdint>

namespace photon {

struct ExchangeData {
    ExchangeData();

    bool packetFound;
    std::size_t incomingPacketSize;

    PhotonRingBuf tmRingBuf;
    std::size_t tmCounter;
    std::uint8_t tmData[1024 * 10];
    std::uint8_t tmTemp[1024];

    PhotonRingBuf incomingRingBuf;
    std::uint8_t inData[1024 * 20];
    std::size_t cmdCounter;
    //bool readyToSend;

    PhotonRingBuf outgoingRingBuf;
    std::uint8_t outData[1024 * 20];

    std::uint8_t temp[1024];

    std::function<void(std::size_t)> receiptHandler;

    std::shared_ptr<ExchangeHandler> _handler;
};

ExchangeData::ExchangeData()
{
    packetFound = false;
    PhotonRingBuf_Init(&tmRingBuf, tmData, sizeof(tmData));
    PhotonRingBuf_Init(&incomingRingBuf, inData, sizeof(inData));
    PhotonRingBuf_Init(&outgoingRingBuf, outData, sizeof(outData));
    cmdCounter = 0;
    incomingPacketSize = 0;
    tmCounter = 0;
}

Exchange::Exchange()
    : _d(new ExchangeData)
{
}

Exchange::~Exchange()
{
}

static inline void appendFromReader(const PhotonReader& reader, std::vector<std::uint8_t>* vec)
{
    vec->insert(vec->end(), reader.current, reader.end);
}

bool Exchange::acceptIncomingData(const void* data, std::size_t size)
{
    PhotonRingBuf_Write(&_d->incomingRingBuf, data, size);
    _d->incomingPacketSize = Photon_FindPacketInRingBuf(&_d->incomingRingBuf, 0x047e);
    if (_d->incomingPacketSize) {
        _d->packetFound = true;
        PhotonRingBuf_Peek(&_d->incomingRingBuf, _d->temp, _d->incomingPacketSize, 0);
    }
    return _d->packetFound;
}

static PhotonResult processPacket2(ExchangeData* self, PhotonReader* src)
{
    uint16_t header;
    PHOTON_TRY(Photon_PeakHeader(src, &header));

    switch (header) {
    case PHOTON_EXCHANGE_PACKET_HEADER: {
        PhotonExchangePacketDec exchangePacket;
        PHOTON_TRY(PhotonDecoder_DecodeExchangePacket(src, &exchangePacket));
        PhotonRingBuf_Erase(&self->incomingRingBuf, self->incomingPacketSize);

        if (exchangePacket.packet.streamType != PhotonStreamType_Telemetry) {
            return PhotonResult_InvalidStreamType;
        }

        if (exchangePacket.packet.sequenceCounter != self->tmCounter) {
            //TODO: сообщить о пропавшей тм
        }

        self->tmCounter++;

        PhotonAddressPacketDec addressPacket;
        PHOTON_TRY(PhotonDecoder_DecodeAddressPacket(&exchangePacket.data, &addressPacket));
        PhotonRingBuf_Write(&self->tmRingBuf, addressPacket.data.current, PhotonReader_ReadableSize(&addressPacket.data));
        while (std::size_t tmSize = Photon_FindPacketInRingBuf(&self->tmRingBuf, PHOTON_TM_STREAM_SEPARATOR)) {
            PhotonRingBuf_Peek(&self->tmRingBuf, self->tmTemp, tmSize, 0);
            PhotonReader_Init(src, self->tmTemp, sizeof(self->tmTemp));
            uint16_t header;
            PHOTON_TRY(Photon_PeakHeader(src, &header));
            if (header == 0x0c78) {
                PhotonTmEventMessage msg;
                if (PhotonDecoder_DecodeTmEventMessage(src, &msg) != PhotonResult_Ok) {
                    continue;
                } else {
                    PhotonRingBuf_Erase(&self->tmRingBuf, tmSize);
                    TmEvent event;
                    event.componentNumber = msg.componentNumber;
                    event.messageNumber = msg.messageNumber;
                    event.eventNumber = msg.eventNumber;
                   // event.time = msg.timestamp;
                    appendFromReader(msg.parameters, &event.payload);
                    self->_handler->handleTmEvent(std::move(event));
                }
            } else if (header == 0x1c72) {
                PhotonTmStatusMessage msg;
                if (PhotonDecoder_DecodeTmStatusMessage(src, &msg) != PhotonResult_Ok) {
                    continue;
                } else {
                    PhotonRingBuf_Erase(&self->tmRingBuf, tmSize);
                    TmStatus status;
                    status.componentNumber = msg.componentNumber;
                    status.messageNumber = msg.messageNumber;
                    appendFromReader(msg.parameters, &status.payload);
                    self->_handler->handleTmStatus(std::move(status));
                }
            }
        }
        break;
    }
    case PHOTON_RECEIPT_PACKET_HEADER: {
        PhotonReceiptPacketDec packet;
        PHOTON_TRY(PhotonDecoder_DecodeReceiptPacket(src, &packet));
        if (packet.packet.streamType != PhotonStreamType_Commands) {
            return PhotonResult_InvalidStreamType;
        }
        //self->readyToSend = packet.packet.lastSequenceCounter == self->cmdCounter;
//        self->_handler->handleReceipt(packet.packet.lastSequenceCounter);
        break;
    }
    default:
        return PhotonResult_InvalidPacketHeader;
    }

    return PhotonResult_Ok;
}

std::size_t Exchange::copyIncomingPacket(void* dest, std::size_t size)
{
    if (_d->packetFound) {
        std::size_t minSize = std::min(_d->incomingPacketSize, size);
        PhotonRingBuf_Peek(&_d->incomingRingBuf, dest, minSize, 0);
        return minSize;
    }
    return 0;
}

void Exchange::skipIncomingPacket()
{
    if (_d->packetFound) {
        PhotonRingBuf_Erase(&_d->incomingRingBuf, _d->incomingPacketSize);
    }
    _d->packetFound = false;
}

bool Exchange::processIncomingPacket()
{
    return processPacket(_d->temp, sizeof(_d->temp));
}

bool Exchange::processPacket(const void* src, std::size_t size)
{
    if (!_d->packetFound) {
        return false;
    }
    PhotonReader reader;
    PhotonReader_Init(&reader, src, size);
    PhotonResult rv = processPacket2(_d.get(), &reader);
    _d->packetFound = false;
    if (rv != PhotonResult_Ok) {
        _d->_handler->handleError(PhotonResult_ToString(rv));
        return false;
    }
    return true;
}

static PhotonResult encodeCommand(void* data, PhotonWriter* dest)
{
    std::vector<std::uint8_t>* payload = (std::vector<std::uint8_t>*)data;
    if (PhotonWriter_WritableSize(dest) < payload->size()) {
        return PhotonResult_NotEnoughSpace;
    }
    PhotonWriter_Write(dest, payload->data(), payload->size());
    return PhotonResult_Ok;
}

static PhotonResult encodeCommands(void* data, PhotonWriter* dest)
{
    const std::vector<Command>* commands = (const std::vector<Command>*)data;
    PhotonCommandEnc encoder;
    encoder.gen = encodeCommand;
    for (const Command& cmd : *commands) {
        encoder.header.componentNumber = cmd.componentNumber;
        encoder.header.commandNumber = cmd.commandNumber;
        encoder.data = (void*)&cmd.payload;
        PHOTON_TRY(PhotonEncoder_EncodeCommand(&encoder, dest));
    }
    return PhotonResult_Ok;
}

static PhotonResult encodeAddressPacket(void* data, PhotonWriter* dest)
{
    return PhotonEncoder_EncodeCommandMessage(data, encodeCommands, dest);
}

static PhotonResult encodeExchangePacket(void* data, PhotonWriter* dest)
{
    PhotonAddressPacketEnc enc;
    enc.data = data;
    enc.gen = encodeAddressPacket;
    enc.packet.address.type = PhotonAddressType_SimpleAddress;
    enc.packet.address.address.simple.destAddress = 1;
    enc.packet.address.address.simple.srcAddress = 0;
    enc.packet.timestamp.type = PhotonTimePrecision_Seconds;
    enc.packet.timestamp.secs.seconds = 0;
    //TODO: set time
    return PhotonEncoder_EncodeAddressPacket(&enc, dest);
}

bool Exchange::encodeCommandPacket(const std::vector<Command>& commands)
{
    PhotonWriter dest;
    PhotonWriter_Init(&dest, _d->temp, sizeof(_d->temp));
    PhotonWriter_WriteUint16Be(&dest, 0x047e);

    PhotonExchangePacketEnc enc;
    enc.data = (void*)&commands;
    enc.gen = encodeExchangePacket;
    enc.packet.errorControlType = PhotonErrorControlType_Crc16;
    enc.packet.sequenceCounter = _d->cmdCounter;
    enc.packet.streamType = PhotonStreamType_Commands;
    enc.packet.windowSize = 0;
    PhotonResult rv = PhotonEncoder_EncodeExchangePacket(&enc, &dest);
    if (rv != PhotonResult_Ok) {
        return false;
    }
    _d->cmdCounter++;

    PhotonRingBuf_Write(&_d->outgoingRingBuf, dest.start, dest.current - dest.start);
    return true;
}

std::size_t Exchange::readEncodedCommands(void* dest, std::size_t maxSize)
{
    std::size_t size = std::min(maxSize, PhotonRingBuf_ReadableSize(&_d->outgoingRingBuf));
    PhotonRingBuf_Read(&_d->outgoingRingBuf, dest, size);
    return size;
}

std::size_t Exchange::incomingPacketSize() const
{
    if (_d->packetFound) {
        return _d->incomingPacketSize;
    }
    return 0;
}

void Exchange::setHandler(const std::shared_ptr<ExchangeHandler>& handler)
{
    _d->_handler = handler;
}

void ExchangeHandler::handleError(std::string&& errorMessage)
{
}

void ExchangeHandler::handleTmEvent(TmEvent&& event)
{
}

void ExchangeHandler::handleTmStatus(TmStatus&& status)
{
}
}
