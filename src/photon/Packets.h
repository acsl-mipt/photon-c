#ifndef __PHOTON_PACKETS_H__
#define __PHOTON_PACKETS_H__

#include "photon/Config.h"
#include "photon/Ber.h"
#include "photon/Enums.h"
#include "photon/Time.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_COMMAND_MESSAGE_HEADER 0x0c65
#define PHOTON_COMMAND_RESULT_HEADER 0x0c66
#define PHOTON_TM_STATUS_MESSAGE_HEADER 0x1c72
#define PHOTON_TM_EVENT_MESSAGE_HEADER 0x0c78
#define PHOTON_ADDRESS_PACKET_HEADER 0xac5e
#define PHOTON_EXCHANGE_PACKET_HEADER 0x6c5a
#define PHOTON_COUNTER_ADJUSTMENT_PACKET_HEADER 0x6c5b
#define PHOTON_RECEIPT_PACKET_HEADER 0x3c5c
#define PHOTON_TM_STREAM_SEPARATOR 0x043d

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
    PhotonTime timestamp;
} PhotonAddressPacket;

typedef struct {
    PhotonStreamType streamType;
    PhotonErrorControlType errorControlType;
    PhotonBer lastSequenceCounter;
} PhotonReceiptPacket;

typedef struct {
    PhotonBer componentNumber;
    PhotonBer commandNumber;
} PhotonCommandHeader;

#ifdef __cplusplus
}
#endif

#endif
