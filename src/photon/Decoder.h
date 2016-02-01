#ifndef __PHOTON_DECODER_H__
#define __PHOTON_DECODER_H__

#include "photon/Config.h"
#include "photon/Result.h"
#include "photon/Reader.h"
#include "photon/Enums.h"
#include "photon/Ber.h"

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
    PhotonBer timestamp;
    PhotonReader parameters;
} PhotonTmEventMessage;

typedef struct {
    PhotonDataHeader header;
    PhotonAddressType addressType;
    PhotonBer srcAddress;
    PhotonBer srcComponentNumber;
    PhotonBer destComponentNumber;
    PhotonBer destAddress;
    PhotonBer srcGroup;
    PhotonBer destGroup;
    PhotonBer timestampType;
    PhotonBer timestamp;
    PhotonReader data;
} PhotonAddressPacket;

typedef struct {
    uint16_t code;
    PhotonBer length;
    PhotonBer reserved;
    PhotonStreamType streamType;
    PhotonErrorControlType errorControlType;
} PhotonPacketHeader;

typedef struct {
    PhotonPacketHeader header;
    PhotonBer windowSize;
    PhotonBer sequenceCounter;
    PhotonReader data;
} PhotonExchangePacket;

typedef struct {
    PhotonPacketHeader header;
    PhotonBer sequenceCounter;
} PhotonCounterAdjustmentPacket;

typedef struct {
    PhotonPacketHeader header;
    PhotonBer lastSequenceCounter;
} PhotonReceiptPacket;

PhotonResult PhotonDecoder_DecodeExchangePacket(PhotonReader* src, PhotonExchangePacket* dest);
PhotonResult PhotonDecoder_DecodeCounterAdjustmentPacket(PhotonReader* src, PhotonCounterAdjustmentPacket* dest);
PhotonResult PhotonDecoder_DecodeReceiptPacket(PhotonReader* src, PhotonReceiptPacket* dest);
PhotonResult PhotonDecoder_DecodeAddressPacket(PhotonReader* src, PhotonAddressPacket* dest);
PhotonResult PhotonDecoder_DecodeTmEventMessage(PhotonReader* src, PhotonTmEventMessage* dest);
PhotonResult PhotonDecoder_DecodeTmStatusMessage(PhotonReader* src, PhotonTmStatusMessage* dest);
PhotonResult PhotonDecoder_DecodeCommandMessage(PhotonReader* src, PhotonCommandMessage* dest);
PhotonResult PhotonDecoder_DecodeCommandResult(PhotonReader* src, PhotonCommandResult* dest);

#ifdef __cplusplus
}
#endif

#endif
