#ifndef __PHOTON_RESULT_H__
#define __PHOTON_RESULT_H__

#include "photon/Config.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_TRY(expr)                                                                                               \
    do {                                                                                                               \
        PhotonResult rv = expr;                                                                                        \
        if (rv != PhotonResult_Ok) {                                                                                   \
            return rv;                                                                                                 \
        }                                                                                                              \
    } while (0);

typedef enum {
    PhotonResult_Ok,
    PhotonResult_PacketNotFound,
    PhotonResult_InvalidBerLength,
    PhotonResult_UnexpectedEndOfBerStream,
    PhotonResult_NotEnoughSpace,
    PhotonResult_InvalidSize,
    PhotonResult_InvalidDataHeader,
    PhotonResult_InvalidPacketHeader,
    PhotonResult_InvalidDataSize,
    PhotonResult_InvalidAddressType,
    PhotonResult_InvalidReservedFieldValue,
    PhotonResult_InvalidStreamType,
    PhotonResult_InvalidErrorControlType,
    PhotonResult_InvalidWindowSize,
    PhotonResult_InvalidSequenceCounter,

    PhotonResult_InvalidCommandId,

    PhotonResult_InvalidMessageId
} PhotonResult;

#ifdef __cplusplus
}
#endif

#endif
