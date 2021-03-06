#include "photon/Encoder.h"
#include "photon/Decoder.h"

#include <gtest/gtest.h>

#include <random>

PhotonResult generator(void* data, PhotonWriter* dest)
{
    PhotonWriter* params = (PhotonWriter*)data;
    PhotonWriter_Write(dest, params->start, params->current - params->start);
    return PhotonResult_Ok;
}

class ExchangePacketTest : public ::testing::Test {
protected:
    void SetUp()
    {
        PhotonWriter_Init(&_writer, data, sizeof(data));
        PhotonWriter_Init(&_paramsWriter, params, sizeof(params));
        PhotonReader_Init(&_reader, data, sizeof(data));
        memset(&_encoder, 0, sizeof(_encoder));
        memset(&_decoder, 0, sizeof(_decoder));
        memset(data, 0x77, sizeof(data));
        memset(data, 0x77, sizeof(params));
    }

    void expectEqPackets()
    {
        EXPECT_EQ(_encoder.packet.streamType, _decoder.packet.streamType);
        EXPECT_EQ(_encoder.packet.errorControlType, _decoder.packet.errorControlType);
        EXPECT_EQ(_encoder.packet.windowSize, _decoder.packet.windowSize);
        EXPECT_EQ(_encoder.packet.sequenceCounter, _decoder.packet.sequenceCounter);
        EXPECT_EQ(_paramsWriter.current - _paramsWriter.start, _decoder.data.end - _decoder.data.start);
    }


    void runTest()
    {
        _encoder.packet.errorControlType = PhotonErrorControlType_Crc16;
        _encoder.packet.sequenceCounter = 4985;
        _encoder.packet.streamType = PhotonStreamType_Telemetry;
        _encoder.packet.windowSize = 30954;
        _encoder.data = &_paramsWriter;
        _encoder.gen = generator;
        PhotonResult rv = PhotonEncoder_EncodeExchangePacket(&_encoder, &_writer);
        ASSERT_EQ(PhotonResult_Ok, rv) << PhotonResult_ToString(rv);
        rv = PhotonDecoder_DecodeExchangePacket(&_reader, &_decoder);
        ASSERT_EQ(PhotonResult_Ok, rv) << PhotonResult_ToString(rv);
        expectEqPackets();
    }

    PhotonExchangePacketEnc _encoder;
    PhotonExchangePacketDec _decoder;
    PhotonWriter _writer;
    PhotonWriter _paramsWriter;
    PhotonReader _reader;
    uint8_t data[10000];
    uint8_t params[10000];
};

TEST_F(ExchangePacketTest, uint8)
{
    PhotonWriter_WriteUint8(&_paramsWriter, 0xaa);
    runTest();
}

TEST_F(ExchangePacketTest, uint16)
{
    PhotonWriter_WriteUint16Be(&_paramsWriter, 0x88aa);
    runTest();
}

TEST_F(ExchangePacketTest, bigData)
{
    PhotonWriter_WriteUint16Be(&_paramsWriter, 0xabff);
    PhotonWriter_WriteUint16Be(&_paramsWriter, 0xcd00);
    PhotonWriter_WriteUint16Be(&_paramsWriter, 0x1199);
    PhotonWriter_WriteUint16Be(&_paramsWriter, 0x3388);
    PhotonWriter_WriteUint16Be(&_paramsWriter, 0x5566);
    PhotonWriter_WriteUint16Be(&_paramsWriter, 0x6611);
    PhotonWriter_WriteUint8(&_paramsWriter, 0xa5);
    runTest();
}
