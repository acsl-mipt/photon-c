#ifndef __PHOTON_EXCHANGE_H__
#define __PHOTON_EXCHANGE_H__

#include "photon/Config.h"
#include "photon/RingBuffer.h"
#include "photon/Decoder.h"
#include "photon/Encoder.h"
#include "photon/Enums.h"

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_MAX_PACKET_SIZE 1024
#define PHOTON_MAX_INCOMING_PACKETS 10
#define PHOTON_MAX_OUTGOING_PACKETS 10
#define PHOTON_MAX_TM_MESSAGE_SIZE 512
#define PHOTON_MAX_TM_MESSAGES 10

typedef PhotonResult (*PhotonAddressPacketHandler)(void*, PhotonAddressPacket*, PhotonReader*);
typedef PhotonResult (*PhotonExchangeHandler)(void*, PhotonRingBuf*);
typedef PhotonResult (*PhotonCommandResultHandler)(void*, PhotonCommandResult*);
typedef PhotonResult (*PhotonTmEventMessageHandler)(void*, PhotonTmEventMessageDec*);
typedef PhotonResult (*PhotonTmStatusMessageHandler)(void*, PhotonTmStatusMessageDec*);

typedef struct {
    uint16_t cmdInCounter;
    uint16_t cmdOutCounter;
    uint16_t tmCounter;
    PhotonErrorControlType errorControlType;
    PhotonRingBuf ringBufIn;
    PhotonRingBuf ringBufOut;
    uint32_t pad1;
    uint8_t inBuffer[PHOTON_MAX_PACKET_SIZE * PHOTON_MAX_INCOMING_PACKETS];
    uint32_t pad2;
    uint8_t outBuffer[PHOTON_MAX_PACKET_SIZE * PHOTON_MAX_OUTGOING_PACKETS];
    uint8_t temp[PHOTON_MAX_PACKET_SIZE];
    uint16_t encodedSeparator;
} PhotonUavExchange;

void PhotonUavExchange_Init(PhotonUavExchange* self);
void PhotonUavExchange_AcceptIncomingData(PhotonUavExchange* self, const void* src, size_t size);
PhotonResult PhotonUavExchange_HandleIncomingPacket(PhotonUavExchange* self, PhotonAddressPacketHandler handler, void* data);

PhotonResult PhotonUavExchange_SendPacket(PhotonUavExchange* self, const PhotonAddress* address,
                                          void* data, PhotonGenerator gen);

#ifdef __cplusplus
}
#endif

#endif
