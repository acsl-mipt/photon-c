/* Type header */
#ifndef __PHOTON_GT_B8_H_81226b45fa91a8601347a7d652ff9d64__
#define __PHOTON_GT_B8_H_81226b45fa91a8601347a7d652ff9d64__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char PhotonGtB8;

PhotonResult PhotonGtB8_Serialize(PhotonGtB8* self, PhotonWriter* writer);

PhotonResult PhotonGtB8_Deserialize(PhotonGtB8* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif