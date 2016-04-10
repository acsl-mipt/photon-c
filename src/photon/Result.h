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
    PhotonResult_NotEnoughData,
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
    PhotonResult_InvalidChecksum,
    PhotonResult_InvalidTimeType,
    PhotonResult_InvalidTimeValue,
    PhotonResult_EventIsDenied,

    PhotonResult_InvalidCommandId,
    PhotonResult_InvalidComponentId,
    PhotonResult_InvalidMessageId,
    PhotonResult_InvalidValue
} PhotonResult;

const char* PhotonResult_ToString(PhotonResult result);

#ifdef __cplusplus
}
#endif

#endif
