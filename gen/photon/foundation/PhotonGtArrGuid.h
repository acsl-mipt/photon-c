/* Type header */
#ifndef __PHOTON_GT_ARR_GUID_H_5a9b220cc69a8a2034156a3c2f3734d9__
#define __PHOTON_GT_ARR_GUID_H_5a9b220cc69a8a2034156a3c2f3734d9__ 

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