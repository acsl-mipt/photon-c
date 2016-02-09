/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_FOUNDATION_PHOTON_GT_GUID_H__
#define __PHOTON_FOUNDATION_PHOTON_GT_GUID_H__ 
#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef PhotonBer PhotonGtGuid;

PhotonResult PhotonGtGuid_Serialize(const PhotonGtGuid* self, PhotonWriter* writer);

PhotonResult PhotonGtGuid_Deserialize(PhotonGtGuid* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif