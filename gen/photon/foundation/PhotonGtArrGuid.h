/* Type header */
#ifndef __PHOTON_GT_ARR_GUID_H_c0dc5bba8aa1865b5d96f067726ae945__
#define __PHOTON_GT_ARR_GUID_H_c0dc5bba8aa1865b5d96f067726ae945__ 

#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtGuid.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  size_t size;
  PhotonGtGuid data[256];
} PhotonGtArrGuid;

PhotonResult PhotonGtArrGuid_Serialize(PhotonGtArrGuid* self, PhotonWriter* writer);

PhotonResult PhotonGtArrGuid_Deserialize(PhotonGtArrGuid* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif