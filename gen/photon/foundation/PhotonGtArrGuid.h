/* Type header */
#ifndef __PHOTON_GT_ARR_GUID_H_ee7e073150ed612ecfff1f6eff3c8023__
#define __PHOTON_GT_ARR_GUID_H_ee7e073150ed612ecfff1f6eff3c8023__ 

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