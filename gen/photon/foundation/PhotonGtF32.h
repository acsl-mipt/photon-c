/* Type header */
#ifndef __PHOTON_GT_F32_H_5c7974a5c075af6f7024738826551f50__
#define __PHOTON_GT_F32_H_5c7974a5c075af6f7024738826551f50__ 

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