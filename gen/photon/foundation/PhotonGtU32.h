/* Type header */
#ifndef __PHOTON_GT_U32_H_3b5dcd4413d8f195e7d82fd5ef8dc13b__
#define __PHOTON_GT_U32_H_3b5dcd4413d8f195e7d82fd5ef8dc13b__ 

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