/* Type header */
#ifndef __PHOTON_GT_U8_H_5310675ee73de044266160a3da7bb262__
#define __PHOTON_GT_U8_H_5310675ee73de044266160a3da7bb262__ 

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