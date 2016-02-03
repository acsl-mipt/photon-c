/* Type header */
#ifndef __PHOTON_GT_U8_H_2e8d2598c0eb94c3d29ab43e74aaea44__
#define __PHOTON_GT_U8_H_2e8d2598c0eb94c3d29ab43e74aaea44__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char PhotonGtU8;

PhotonResult PhotonGtU8_Serialize(PhotonGtU8* self, PhotonWriter* writer);

PhotonResult PhotonGtU8_Deserialize(PhotonGtU8* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif