/* Type header */
#ifndef __PHOTON_GT_F32_H_93113292749346325997b92ae3b95d99__
#define __PHOTON_GT_F32_H_93113292749346325997b92ae3b95d99__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef float PhotonGtF32;

PhotonResult PhotonGtF32_Serialize(PhotonGtF32* self, PhotonWriter* writer);

PhotonResult PhotonGtF32_Deserialize(PhotonGtF32* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif