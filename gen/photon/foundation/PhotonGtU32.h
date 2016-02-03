/* Type header */
#ifndef __PHOTON_GT_U32_H_3961695480ecd1b10edf55ae794edf76__
#define __PHOTON_GT_U32_H_3961695480ecd1b10edf55ae794edf76__ 

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