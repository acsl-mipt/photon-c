#ifndef __PHOTON_UTILS_H__
#define __PHOTON_UTILS_H__

#include "photon/Config.h"
#include "photon/RingBuffer.h"
#include "photon/Reader.h"

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

bool Photon_SkipSeparator(PhotonRingBuf* ringBuf, uint16_t separator);
PhotonResult Photon_PeakHeader(PhotonReader* src, uint16_t* dest);
size_t Photon_FindPacketInRingBuf(PhotonRingBuf* ringBuf, uint16_t separator);
uint16_t Photon_Crc16(const uint16_t* src, size_t size);

#ifdef __cplusplus
}
#endif

#endif
