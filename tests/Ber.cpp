#include "photon/Reader.h"
#include "photon/Ber.h"

#include "PhotonTest.h"

#include <gtest/gtest.h>

#include <cstring>

class BerTest : public ::testing::Test {
protected:
    template <std::size_t n, typename R>
    void init(const R (&array)[n])
    {
        PhotonReader_Init(&_reader, array, sizeof(R) * n);
    }

    void expectNextValue(PhotonBer expected)
    {
        PhotonBer value = 0;
        PhotonResult rv = PhotonBer_Deserialize(&value, &_reader);
        ASSERT_EQ(rv, PhotonResult_Ok);
        ASSERT_EQ(expected, value);
    }

    void expectEndOfStream()
    {
        ASSERT_TRUE(PhotonReader_IsAtEnd(&_reader));
    }


private:
    PhotonReader _reader;
};

TEST_F(BerTest, init)
{
}

TEST_F(BerTest, readShortForm)
{
    uint8_t data[] = {0, 80, 127};
    init(data);
    expectNextValue(0);
    expectNextValue(80);
    expectNextValue(127);
    expectEndOfStream();
}

TEST_F(BerTest, readLongForm)
{
    uint8_t data[] = {0x81, 0xff, 0x82, 0xbb, 0xaa, 0x83, 0xee, 0xdd, 0xcc,
                      0x88, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};
    init(data);
    expectNextValue(0xff);
    expectNextValue(0xaabb);
    expectNextValue(0xccddee);
    expectNextValue(0x8877665544332211);
    expectEndOfStream();
}

class BerWriteTest : public ::testing::Test {
protected:
    void SetUp()
    {
        PhotonWriter_Init(&_writer, _data, sizeof(_data));
    }

    void writeValue(PhotonBer value)
    {
        PhotonResult rv = PhotonBer_Serialize(value, &_writer);
        ASSERT_EQ(rv, PhotonResult_Ok);
    }

    template <std::size_t n, typename R>
    void expectStream(const R (&array)[n])
    {
        std::size_t size = sizeof(R) * n;
        EXPECT_EQ(size, _writer.current - _writer.start);
        EXPECT_EQ_MEM(array, _writer.start, size);
    }

/*
    void expectEndOfStream()
    {
        ASSERT_TRUE(PhotonReader_IsAtEnd(&_reader));
    }*/


private:
    uint8_t _data[1000];
    PhotonWriter _writer;
};

TEST_F(BerWriteTest, writeShortForm)
{
    writeValue(0);
    writeValue(80);
    writeValue(127);
    uint8_t expected[3] = {0, 80, 127};
    expectStream(expected);
}

TEST_F(BerWriteTest, writeLongForm)
{

    writeValue(0xff);
    writeValue(0xaabb);
    writeValue(0xccddee);
    writeValue(0x8877665544332211);
    uint8_t expected[] = {0x81, 0xff, 0x82, 0xbb, 0xaa, 0x83, 0xee, 0xdd, 0xcc,
                          0x88, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};
    expectStream(expected);
}
