/* Type header */
#ifndef __PHOTON_GT_F32_H_5da5de0707c357c02f769686d153ad80__
#define __PHOTON_GT_F32_H_5da5de0707c357c02f769686d153ad80__ 

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