#include "photon/Config.h"
#include "photon/Ber.h"

unsigned int PhotonBer_ByteSize(PhotonBer self)
{
    if (self < 256) {
        return 1;
    } else if (self < 65536) {
        return 2;
    } else if (self < 16777216) {
        return 3;
    } else if (self < 4294967296) {
        return 4;
    } else if (self < 1099511627776) {
        return 5;
    } else if (self < 281474976710656) {
        return 6;
    } else if (self < 72057594037927936) {
        return 7;
    }
    return 8;
}

PhotonResult PhotonBer_Serialize(PhotonBer self, PhotonWriter* dest)
{
    if (self < 128) {
        if (PhotonWriter_IsAtEnd(dest)) {
            return PhotonResult_NotEnoughSpace;
        }
        PhotonWriter_WriteUint8(dest, (uint8_t)self);
        return PhotonResult_Ok;
    }

    unsigned size = PhotonBer_ByteSize(self);

    if (PhotonWriter_WritableSize(dest) < (size + 1)) {
        return PhotonResult_NotEnoughSpace;
    }

    PhotonWriter_WriteUint8(dest, 0x80 | size);
    PhotonWriter_Write(dest, &self, size); // big endian?
    return PhotonResult_Ok;
}

PhotonResult PhotonBer_Deserialize(PhotonBer* self, PhotonReader* src)
{
    if (PhotonReader_IsAtEnd(src)) {
        return PhotonResult_UnexpectedEndOfBerStream;
    }

    uint8_t firstOctet = PhotonReader_PeekUint8(src);
    if (!(firstOctet & 0x80)) {
        PhotonReader_Skip(src, 1);
        *self = (PhotonBer)firstOctet;
        return PhotonResult_Ok;
    }

    unsigned size = firstOctet & 0x7f;
    if ((size > 8) || (size == 0)) {
        return PhotonResult_InvalidBerLength;
    }
    if (PhotonReader_ReadableSize(src) < (size + 1)) {
        return PhotonResult_UnexpectedEndOfBerStream;
    }

    PhotonReader_Skip(src, 1);
    *self = 0;
    PhotonReader_Read(src, self, size);
    return PhotonResult_Ok;
}
