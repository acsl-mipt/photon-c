/* Type header */
#ifndef __PHOTON_GT_U32_H_d316a46f1e12f4d7edfe8197ab3936a7__
#define __PHOTON_GT_U32_H_d316a46f1e12f4d7edfe8197ab3936a7__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned int PhotonGtU32;

PhotonResult PhotonGtU32_Serialize(PhotonGtU32* self, PhotonWriter* writer);

PhotonResult PhotonGtU32_Deserialize(PhotonGtU32* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif