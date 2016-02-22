/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_FOUNDATION_PHOTON_GT_ARR_GUID_H__
#define __PHOTON_FOUNDATION_PHOTON_GT_ARR_GUID_H__ 
#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtGuid.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_GT_ARR_GUID_MIN_SIZE 0
#define PHOTON_GT_ARR_GUID_MAX_SIZE 0

typedef struct {
  size_t size;
  PhotonGtGuid* data;
} PhotonGtArrGuid;

PhotonResult PhotonGtArrGuid_Serialize(PhotonGtArrGuid self, PhotonWriter* writer);

PhotonResult PhotonGtArrGuid_Deserialize(PhotonGtArrGuid* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif