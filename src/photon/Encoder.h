#ifndef __PHOTON_ENCODER_H__
#define __PHOTON_ENCODER_H__

#include "photon/Config.h"
#include "photon/Result.h"
#include "photon/Enums.h"
#include "photon/Writer.h"
#include "photon/Ber.h"
#include "photon/Packets.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uint64_t PhotonBer;

typedef PhotonResult (*PhotonGenerator)(void* data, PhotonWriter* dest);

typedef struct {
    PhotonBer segmentNumber;
    PhotonBer maxSegmentNumber;
    PhotonBer componentNumber;
    PhotonBer messageNumber;
    void* data;
    PhotonGenerator gen;
} PhotonTmStatusMessageGen;

typedef struct {
    PhotonBer componentNumber;
    PhotonBer messageNumber;
    PhotonBer eventNumber;
    PhotonBer timestamp;
    void* data;
    PhotonGenerator gen;
} PhotonTmEventMessageGen;

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
    PhotonAddress address;
    PhotonBer timestampType;
    PhotonBer timestamp;
    void* data;
    PhotonGenerator gen;
} PhotonAddressPacketEnc;

typedef struct {
    PhotonErrorControlType errorControlType;
    PhotonBer lastSequenceCounter;
    void* data;
    PhotonGenerator gen;
} PhotonReceiptPacketEnc;

typedef struct {
    PhotonStreamType streamType;
    PhotonErrorControlType errorControlType;
    PhotonBer sequenceCounter;
    void* data;
    PhotonGenerator gen;
} PhotonCounterAdjustmentPacketEnc;

typedef struct {
    PhotonExchangePacket packet;
    void* data;
    PhotonGenerator gen;
} PhotonExchangePacketEnc;

PhotonResult PhotonEncoder_EncodeData(uint16_t header, void* data, PhotonGenerator dataGen, PhotonWriter* dest);
PhotonResult PhotonEncoder_EncodeCommandResult(void* data, PhotonGenerator resultGen, PhotonWriter* dest);
PhotonResult PhotonEncoder_EncodeCommandMessage(void* data, PhotonGenerator msgGen, PhotonWriter* dest);
PhotonResult PhotonEncoder_EncodeTmStatusMessage(PhotonTmStatusMessageGen* gen, PhotonWriter* dest);
PhotonResult PhotonEncoder_EncodeTmEventMessage(PhotonTmEventMessageGen* gen, PhotonWriter* dest);
PhotonResult PhotonEncoder_EncodeAddressPacket(PhotonAddressPacketEnc* encoder, PhotonWriter* dest);
PhotonResult PhotonEncoder_EncodeReceiptPacket(PhotonReceiptPacketEnc* encoder, PhotonWriter* dest);
PhotonResult PhotonEncoder_EncodeCounterAdjustmentPacket(PhotonCounterAdjustmentPacketEnc* encoder, PhotonWriter* dest);
PhotonResult PhotonEncoder_EncodeExchangePacket(PhotonExchangePacketEnc* encoder, PhotonWriter* dest);

#ifdef __cplusplus
}
#endif

#endif
