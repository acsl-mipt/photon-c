/* Type header */
#ifndef __PHOTON_GT_F64_H_9b31388926e2982e8aa6b0a0c2f6f94e__
#define __PHOTON_GT_F64_H_9b31388926e2982e8aa6b0a0c2f6f94e__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef double PhotonGtF64;

PhotonResult PhotonGtF64_Serialize(PhotonGtF64* self, PhotonWriter* writer);

PhotonResult PhotonGtF64_Deserialize(PhotonGtF64* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif