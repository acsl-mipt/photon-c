#include "photon/Utils.h"
#include "photon/Endian.h"
#include "photon/Ber.h"
#include <stdio.h>

#define HEADER_SIZE 2
#define SEPARATOR_SIZE 2
#define PHOTON_MAX_PACKET_SIZE 1024 //FIXME: move to header

bool Photon_SkipSeparator(PhotonRingBuf* ringBuf, uint16_t separator)
{
    const uint8_t firstByte = (separator & 0xff00) >> 8;;
    const uint8_t secondByte = separator & 0x00ff;
    while (true) {
        if (PhotonRingBuf_ReadableSize(ringBuf) < HEADER_SIZE) {
            return false;
        }
        if (firstByte != PhotonRingBuf_PeekUint8(ringBuf, 0)) {
            PhotonRingBuf_Erase(ringBuf, 1);
            continue;
        }
        if (secondByte != PhotonRingBuf_PeekUint8(ringBuf, 1)) {
            PhotonRingBuf_Erase(ringBuf, 1);
            continue;
        }
        return true;
    }
    return false;
}

PhotonResult Photon_PeakHeader(PhotonReader* src, uint16_t* dest)
{
    if ((src->end - src->current) < 3) {
        return PhotonResult_InvalidSize;
    }

    const uint8_t* start = src->current;
    *dest = PhotonReader_PeakUint16Be(src);
    src->current = start;

    return PhotonResult_Ok;
}

size_t Photon_FindPacketInRingBuf(PhotonRingBuf* ringBuf, uint16_t separator)
{
    //TODO: send errors
    if (!Photon_SkipSeparator(ringBuf, separator)) {
        return 0;
    }

    size_t incomingSize = PhotonRingBuf_ReadableSize(ringBuf);
    if (incomingSize < (HEADER_SIZE + SEPARATOR_SIZE + 1)) {
        return 0;
    }

    size_t packetSize;
    uint8_t berHeader = PhotonRingBuf_PeekUint8(ringBuf, HEADER_SIZE + SEPARATOR_SIZE);
    unsigned berDataOffset = HEADER_SIZE + SEPARATOR_SIZE + 1;
    if (berHeader & 0x80) {
        size_t berSize = berHeader & 0x7f;
        if (berSize > 8) {
            return 0;
        }
        PhotonBer dataSize = 0;
        PhotonRingBuf_Peek(ringBuf, &dataSize, berSize, berDataOffset); // big endian?
        packetSize = berDataOffset + berSize + dataSize - SEPARATOR_SIZE;
    } else {
        packetSize = berDataOffset + berHeader - SEPARATOR_SIZE;
    }

    if (packetSize > PHOTON_MAX_PACKET_SIZE) {
        return 0;
    }

    if (incomingSize < packetSize) {
        return 0;
    }

    PhotonRingBuf_Erase(ringBuf, SEPARATOR_SIZE);
    return packetSize;
}

//TODO: crc16

uint16_t Photon_Crc16(const uint16_t* src, size_t size)
{
    uint16_t sum = 0;
    const uint16_t* end = src + size;
    while (src < end) {
        sum += *src;
        src++;
    }
    return sum;
}
