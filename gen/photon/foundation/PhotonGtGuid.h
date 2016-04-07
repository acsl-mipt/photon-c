/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_FOUNDATION_PHOTON_GT_GUID_H__
#define __PHOTON_FOUNDATION_PHOTON_GT_GUID_H__ 
#include "photon/prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef PhotonGtBer PhotonGtGuid;

PhotonResult PhotonGtGuid_Serialize(PhotonGtGuid self, PhotonWriter* writer);

PhotonResult PhotonGtGuid_Deserialize(PhotonGtGuid* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif