/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_FOUNDATION_PHOTON_GT_ARR_GUID_H__
#define __PHOTON_FOUNDATION_PHOTON_GT_ARR_GUID_H__ 
#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtGuid.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  size_t size;
  PhotonGtGuid data[256];
} PhotonGtArrGuid;

PhotonResult PhotonGtArrGuid_Serialize(const PhotonGtArrGuid* self, PhotonWriter* writer);

PhotonResult PhotonGtArrGuid_Deserialize(PhotonGtArrGuid* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif