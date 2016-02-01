#ifndef __PHOTON_GUID_H__
#define __PHOTON_GUID_H__

#include "photon/Config.h"
#include "photon/Writer.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t data[16];
} PhotonGuid;

void PhotonGuid_Init(PhotonGuid* self);
void PhotonGuid_Serialize(const PhotonGuid* self, PhotonWriter* dest);

#ifdef __cplusplus
}
#endif

#endif
