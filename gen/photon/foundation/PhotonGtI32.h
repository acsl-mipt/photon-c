/* Type header */
#ifndef __PHOTON_GT_I32_H_957bae2468cb56b4060c228b6463b2ef__
#define __PHOTON_GT_I32_H_957bae2468cb56b4060c228b6463b2ef__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef signed int PhotonGtI32;

PhotonResult PhotonGtI32_Serialize(PhotonGtI32* self, PhotonWriter* writer);

PhotonResult PhotonGtI32_Deserialize(PhotonGtI32* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif