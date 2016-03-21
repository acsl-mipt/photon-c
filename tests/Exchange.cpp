#include "photon/Exchange.h"
#include "photon/GcExchange.hpp"

#include "PhotonTest.h"

#include <gtest/gtest.h>

#include <random>
#include <deque>
#include <cassert>
#include <iostream>

static PhotonUavExchange _exchange;
static photon::Exchange _gcExchange;
static std::default_random_engine _randomEngine;
static std::uniform_int_distribution<uint> _dist(0, 65500);
static std::uniform_int_distribution<int> _sizeDist(10, 40);
static std::uniform_int_distribution<int> _countDist(1, 4);
static std::bernoulli_distribution _typeDist(0.75);
static std::deque<photon::TmStatus> _expectedStatuses;
static std::deque<photon::TmEvent> _expectedEvents;
static std::deque<photon::Command> _sentCommands;

template <typename T>
PhotonResult dataGen(void* data, PhotonWriter* dest, std::deque<T>* msgs)
{
    (void)data;
    const uint8_t* start = dest->current;
    for (int i = 0; i < _sizeDist(_randomEngine); i++) {
        PhotonWriter_WriteUint16Le(dest, _dist(_randomEngine));
    }
    T& last = msgs->back();
    const uint8_t* current = dest->current;
    last.payload.insert(last.payload.end(), start, current);
    return PhotonResult_Ok;
}

PhotonResult statusDataGen(void* data, PhotonWriter* dest)
{
    return dataGen(data, dest, &_expectedStatuses);
}

PhotonResult eventDataGen(void* data, PhotonWriter* dest)
{
    return dataGen(data, dest, &_expectedEvents);
}

PhotonResult statusGen(void* data, PhotonWriter* dest)
{
    (void)data;
    _expectedStatuses.emplace_back();
    photon::TmStatus& last = _expectedStatuses.back();
    last.componentNumber = _dist(_randomEngine);
    last.messageNumber = _dist(_randomEngine);
    PhotonWriter_WriteUint16Be(dest, 0x043d);
    PhotonTmStatusMessageGen statusGen;
    statusGen.componentNumber = last.componentNumber;
    statusGen.messageNumber = last.messageNumber;
    statusGen.data = 0;
    statusGen.gen = statusDataGen;
    statusGen.maxSegmentNumber = 0;
    statusGen.segmentNumber = 0;
    return PhotonEncoder_EncodeTmStatusMessage(&statusGen, dest);
}

PhotonResult eventGen(void* data, PhotonWriter* dest)
{
    (void)data;
    _expectedEvents.emplace_back();
    photon::TmEvent& last = _expectedEvents.back();
    last.componentNumber = _dist(_randomEngine);
    last.messageNumber = _dist(_randomEngine);
    last.eventNumber = _dist(_randomEngine);
    last.time = std::chrono::steady_clock::now();
    PhotonWriter_WriteUint16Be(dest, 0x043d);
    PhotonTmEventMessageGen eventGen;
    eventGen.componentNumber = last.componentNumber;
    eventGen.messageNumber = last.messageNumber;
    eventGen.eventNumber = last.eventNumber;
    eventGen.timestamp = last.time.time_since_epoch().count();
    eventGen.data = 0;
    eventGen.gen = eventDataGen;
    return PhotonEncoder_EncodeTmEventMessage(&eventGen, dest);
}

bool statusHandler(photon::TmStatus&& status)
{
    photon::TmStatus& expected = _expectedStatuses.front();
    photon::TmStatus got = std::move(status);
    EXPECT_EQ(expected.componentNumber, got.componentNumber);
    EXPECT_EQ(expected.messageNumber, got.messageNumber);
    EXPECT_EQ(expected.payload.size(), got.payload.size());
    _expectedStatuses.pop_front();
    return true;
}

bool eventHandler(photon::TmEvent&& event)
{
    photon::TmEvent& expected = _expectedEvents.front();
    EXPECT_EQ(expected.componentNumber, event.componentNumber);
    EXPECT_EQ(expected.messageNumber, event.messageNumber);
    EXPECT_EQ(expected.eventNumber, event.eventNumber);
   // EXPECT_EQ(expected.time, got.time);
    EXPECT_EQ(expected.payload.size(), event.payload.size());
    _expectedEvents.pop_front();
    return true;
}

std::vector<photon::Command> createCommands()
{
    std::vector<photon::Command> cmds;

    for (int i = 0; i < _countDist(_randomEngine); i++) {
        cmds.emplace_back();
        photon::Command& back = cmds.back();
        back.componentNumber = _dist(_randomEngine);
        back.commandNumber = _dist(_randomEngine);
        for (int i = 0; i < _sizeDist(_randomEngine); i++) {
            std::uint16_t data = _dist(_randomEngine);
            //back.payload.push_back(data & 0x00ff);
            //back.payload.push_back((data & 0xff00) >> 8);
            back.payload.push_back(0x99);
        }
        _sentCommands.push_back(back);
    }
    return cmds;
}

PhotonResult addressPacketHandler(void* data, PhotonAddressPacket* packet, PhotonReader* payload)
{
    PhotonCommandMessage dec;
    PhotonDecoder_DecodeCommandMessage(payload, &dec);
    while (!PhotonReader_IsAtEnd(payload)) {
        photon::Command front = _sentCommands.front();
        _sentCommands.pop_front();
        PhotonBer value;
        PHOTON_TRY(PhotonBer_Deserialize(&value, &dec.commands));
        EXPECT_EQ(front.componentNumber, value);
        PHOTON_TRY(PhotonBer_Deserialize(&value, &dec.commands));
        EXPECT_EQ(front.commandNumber, value);
        EXPECT_EQ_MEM(front.payload.data(), dec.commands.current, front.payload.size());
        PhotonReader_Skip(&dec.commands, front.payload.size());
    }
    return PhotonResult_Ok;
}

void uavSend()
{
    PhotonAddress addr;
    addr.type = PhotonAddressType_SimpleAddress;
    addr.address.simple.destAddress = 0;
    addr.address.simple.srcAddress = 1;
    PhotonGenerator gen;
    if (_typeDist(_randomEngine)) {
        gen = statusGen;
    } else {
        gen = eventGen;
    }
    PhotonResult rv = PhotonUavExchange_SendPacket(&_exchange, &addr, 0, gen);
    ASSERT_EQ(rv, PhotonResult_Ok);
}

void gcEncode()
{
    std::vector<photon::Command> cmds = createCommands();
    ASSERT_TRUE(_gcExchange.encodeCommandPacket(cmds));
}

void uavAccept()
{
    uint8_t cmdTmp[100];
    std::size_t size = 1;
    while (size != 0) {
        size = _gcExchange.readEncodedCommands(cmdTmp, sizeof(cmdTmp));
        PhotonUavExchange_AcceptIncomingData(&_exchange, cmdTmp, size);
    }
    PhotonResult rv = PhotonUavExchange_HandleIncomingPacket(&_exchange, addressPacketHandler, 0);
    ASSERT_EQ(PhotonResult_Ok, rv);
}

void gcAccept()
{
    uint8_t tmp[2048];
    std::size_t size = PhotonRingBuf_ReadableSize(&_exchange.ringBufOut);
    PhotonRingBuf_Read(&_exchange.ringBufOut, tmp, size);
    bool isFound = _gcExchange.acceptIncomingData(tmp, size);
    ASSERT_TRUE(isFound);
    bool isOk = _gcExchange.processIncomingPacket();
    ASSERT_TRUE(isOk);
}

TEST(ExchangeTest, main)
{
    PhotonUavExchange_Init(&_exchange);
    _gcExchange.setTmStatusHandler(statusHandler);
    _gcExchange.setTmEventHandler(eventHandler);
    _gcExchange.setErrorHandler([](std::string&& err) {
        std::cout << err << std::endl;
    });
    for (int i = 0; i < 1000; i++) {
        gcEncode();
        uavAccept();
        uavSend();
        gcAccept();
    }
}
