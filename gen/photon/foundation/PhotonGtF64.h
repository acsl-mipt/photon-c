/* Type header */
#ifndef __PHOTON_GT_F64_H_aa10bd79d74b39a55af9f4c242ad5443__
#define __PHOTON_GT_F64_H_aa10bd79d74b39a55af9f4c242ad5443__ 

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