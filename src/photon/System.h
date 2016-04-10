#ifndef __PHOTON_SYSTEM_H__
#define __PHOTON_SYSTEM_H__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int64_t epochTime;
    int32_t nanoseconds;
} PhotonAbsoluteTime;

void PhotonSys_GetTime(PhotonAbsoluteTime* dest);

size_t PhotonSys_SendTelemetry(const void* src, size_t size);

size_t PhotonSys_RecieveCommands(void* src, size_t maxSize);

#ifdef __cplusplus
}
#endif

#endif
