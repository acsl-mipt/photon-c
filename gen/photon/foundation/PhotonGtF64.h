/* Type header */
#ifndef __PHOTON_GT_F64_H_2a306fadc90e4e28889a2e57fdb20261__
#define __PHOTON_GT_F64_H_2a306fadc90e4e28889a2e57fdb20261__ 

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