/* Type header */
#ifndef __PHOTON_GT_U32_H_ac707422731cc5f72882414ac873670d__
#define __PHOTON_GT_U32_H_ac707422731cc5f72882414ac873670d__ 

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