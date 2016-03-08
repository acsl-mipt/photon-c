#ifndef __PHOTON_ENUMS_H__
#define __PHOTON_ENUMS_H__

#include "photon/Config.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    PhotonAddressType_SimpleAddress = 2,
    PhotonAddressType_Broadcast = 3,
    PhotonAddressType_NetworkAddress = 4,
    PhotonAddressType_GroupAddress = 6,
} PhotonAddressType;

typedef enum {
    PhotonStreamType_Commands = 0,
    PhotonStreamType_Telemetry = 1,
} PhotonStreamType;

typedef enum {
    PhotonErrorControlType_Crc16 = 1,
    PhotonErrorControlType_ReedSolomon = 2,
} PhotonErrorControlType;

#ifdef __cplusplus
}
#endif

#endif
