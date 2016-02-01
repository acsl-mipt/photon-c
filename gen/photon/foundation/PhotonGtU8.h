/* Type header */
#ifndef __PHOTON_GT_U8_H_1b71ceadd9e086e5bb5ece4e30f8e48f__
#define __PHOTON_GT_U8_H_1b71ceadd9e086e5bb5ece4e30f8e48f__ 

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