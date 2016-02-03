/* Type header */
#ifndef __PHOTON_GT_F64_H_38db5ea777d7fd50416a754961c8d1a5__
#define __PHOTON_GT_F64_H_38db5ea777d7fd50416a754961c8d1a5__ 

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