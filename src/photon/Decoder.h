#ifndef __PHOTON_DECODER_H__
#define __PHOTON_DECODER_H__

#include "photon/Config.h"
#include "photon/Result.h"
#include "photon/Reader.h"
#include "photon/Enums.h"
#include "photon/Ber.h"
#include "photon/Packets.h"
#include "photon/Time.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint16_t code;
    PhotonBer length;
} PhotonDataHeader;

typedef struct {
    PhotonDataHeader header;
    PhotonReader commands;
} PhotonCommandMessage;

typedef struct {
    PhotonDataHeader header;
    PhotonReader resultData;
} PhotonCommandResult;

typedef struct {
    PhotonCommandHeader commandHeader;
    PhotonReader payload;
} PhotonCommandDec;

typedef struct {
    PhotonDataHeader header;
    PhotonBer segmentNumber;
    PhotonBer maxSegmentNumber;
    PhotonBer componentNumber;
    PhotonBer messageNumber;
    PhotonReader parameters;
} PhotonTmStatusMessage;

typedef struct {
    PhotonDataHeader header;
    PhotonBer componentNumber;
    PhotonBer messageNumber;
    PhotonBer eventNumber;
    PhotonTime timestamp;
    PhotonReader parameters;
} PhotonTmEventMessage;

typedef struct {
    PhotonDataHeader header;
    PhotonAddressPacket packet;
    PhotonReader data;
} PhotonAddressPacketDec;

typedef struct {
    uint16_t code;
    PhotonBer length;
    PhotonBer reserved;
} PhotonPacketHeader;

typedef struct {
    PhotonPacketHeader header;
    PhotonExchangePacket packet;
    PhotonReader data;
} PhotonExchangePacketDec;

typedef struct {
    PhotonPacketHeader header;
    PhotonBer sequenceCounter;
} PhotonCounterAdjustmentPacket;

typedef struct {
    PhotonPacketHeader header;
    PhotonReceiptPacket packet;
} PhotonReceiptPacketDec;

PhotonResult PhotonDecoder_DecodeExchangePacket(PhotonReader* src, PhotonExchangePacketDec* dest);
PhotonResult PhotonDecoder_DecodeCounterAdjustmentPacket(PhotonReader* src, PhotonCounterAdjustmentPacket* dest);
PhotonResult PhotonDecoder_DecodeReceiptPacket(PhotonReader* src, PhotonReceiptPacketDec* dest);
PhotonResult PhotonDecoder_DecodeAddressPacket(PhotonReader* src, PhotonAddressPacketDec* dest);
PhotonResult PhotonDecoder_DecodeTmEventMessage(PhotonReader* src, PhotonTmEventMessage* dest);
PhotonResult PhotonDecoder_DecodeTmStatusMessage(PhotonReader* src, PhotonTmStatusMessage* dest);
PhotonResult PhotonDecoder_DecodeCommandMessage(PhotonReader* src, PhotonCommandMessage* dest);
PhotonResult PhotonDecoder_DecodeCommandResult(PhotonReader* src, PhotonCommandResult* dest);

#ifdef __cplusplus
}
#endif

#endif
