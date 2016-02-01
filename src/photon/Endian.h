#ifndef __PHOTON_ENDIAN_H__
#define __PHOTON_ENDIAN_H__

#include "photon/Config.h"

#include <stdint.h>

static PHOTON_INLINE uint16_t Photon_Be16Dec(const void* src)
{
    const uint8_t* p = (const uint8_t*)src;
    return ((p[0] << 8) | p[1]);
}

static PHOTON_INLINE uint32_t Photon_Be32Dec(const void* src)
{
    const uint8_t* p = (const uint8_t*)src;
    return (((uint32_t)p[0] << 24) | ((uint32_t)p[1] << 16) | ((uint32_t)p[2] << 8) | (uint32_t)p[3]);
}

static PHOTON_INLINE uint64_t Photon_Be64Dec(const void* src)
{
    const uint8_t* p = (const uint8_t*)src;
    return (((uint64_t)Photon_Be32Dec(p) << 32) | Photon_Be32Dec(p + 4));
}

static PHOTON_INLINE uint16_t Photon_Le16Dec(const void* src)
{
    const uint8_t* p = (const uint8_t*)src;
    return ((p[1] << 8) | p[0]);
}

static PHOTON_INLINE uint32_t Photon_Le32Dec(const void* src)
{
    const uint8_t* p = (const uint8_t*)src;
    return (((uint32_t)p[3] << 24) | ((uint32_t)p[2] << 16) | ((uint32_t)p[1] << 8) | (uint32_t)p[0]);
}

static PHOTON_INLINE uint64_t Photon_Le64Dec(const void* src)
{
    const uint8_t* p = (const uint8_t*)src;
    return (((uint64_t)Photon_Le32Dec(p + 4) << 32) | Photon_Le32Dec(p));
}

static PHOTON_INLINE void Photon_Be16Enc(void* dest, uint16_t value)
{
    uint8_t* p = (uint8_t*)dest;
    p[0] = (value >> 8) & 0xff;
    p[1] = value & 0xff;
}

static PHOTON_INLINE void Photon_Be32Enc(void* dest, uint32_t value)
{
    uint8_t* p = (uint8_t*)dest;
    p[0] = (value >> 24) & 0xff;
    p[1] = (value >> 16) & 0xff;
    p[2] = (value >> 8) & 0xff;
    p[3] = value & 0xff;
}

static PHOTON_INLINE void Photon_Be64Enc(void* dest, uint64_t value)
{
    uint8_t* p = (uint8_t*)dest;
    Photon_Be32Enc(p, value >> 32);
    Photon_Be32Enc(p + 4, value & 0xffffffff);
}

static PHOTON_INLINE void Photon_Le16Enc(void* dest, uint16_t value)
{
    uint8_t* p = (uint8_t*)dest;
    p[0] = value & 0xff;
    p[1] = (value >> 8) & 0xff;
}

static PHOTON_INLINE void Photon_Le32Enc(void* dest, uint32_t value)
{
    uint8_t* p = (uint8_t*)dest;
    p[0] = value & 0xff;
    p[1] = (value >> 8) & 0xff;
    p[2] = (value >> 16) & 0xff;
    p[3] = (value >> 24) & 0xff;
}

static PHOTON_INLINE void Photon_Le64Enc(void* dest, uint64_t value)
{
    uint8_t* p = (uint8_t*)dest;
    Photon_Le32Enc(p, value & 0xffffffff);
    Photon_Le32Enc(p + 4, value >> 32);
}

#endif
