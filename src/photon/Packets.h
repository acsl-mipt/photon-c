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
    PhotonBer srcAddress;
    PhotonBer destAddress;
} PhotonSimpleAddress;

typedef struct {
    PhotonBer srcAddress;
    PhotonBer srcComponentNumber;
    PhotonBer destComponentNumber;
    PhotonBer destAddress;
    PhotonBer srcGroup;
    PhotonBer destGroup;
} PhotonGroupAddress;

typedef struct {
    PhotonBer srcAddress;
    PhotonBer srcComponentNumber;
    PhotonBer destComponentNumber;
    PhotonBer destAddress;
} PhotonNetworkAddress;

typedef struct {
    PhotonBer srcAddress;
    PhotonBer srcComponentNumber;
    PhotonBer destComponentNumber;
} PhotonMulticastAddress;

typedef struct {
    union {
        PhotonSimpleAddress simple;
        PhotonGroupAddress group;
        PhotonNetworkAddress network;
        PhotonMulticastAddress multicast;
    } address;
    PhotonAddressType type;
} PhotonAddress;

typedef struct {
    PhotonStreamType streamType;
    PhotonErrorControlType errorControlType;
    PhotonBer windowSize;
    PhotonBer sequenceCounter;
} PhotonExchangePacket;

typedef struct {
    PhotonAddress address;
    PhotonBer timestampType;
    PhotonBer timestamp;
} PhotonAddressPacket;

#ifdef __cplusplus
}
#endif

#endif
