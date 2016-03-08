#ifndef __PHOTON_PACKETS_H__
#define __PHOTON_PACKETS_H__

#include "photon/Config.h"
#include "photon/Ber.h"
#include "photon/Enums.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    PhotonStreamType streamType;
    PhotonErrorControlType errorControlType;
    PhotonBer windowSize;
    PhotonBer sequenceCounter;
} PhotonExchangePacket;

#ifdef __cplusplus
}
#endif

#endif
