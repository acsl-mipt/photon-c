/* Type header */
#ifndef __PHOTON_GT_U16_H_9815e259be3e1d7696a83a1d955381d2__
#define __PHOTON_GT_U16_H_9815e259be3e1d7696a83a1d955381d2__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned short PhotonGtU16;

PhotonResult PhotonGtU16_Serialize(PhotonGtU16* self, PhotonWriter* writer);

PhotonResult PhotonGtU16_Deserialize(PhotonGtU16* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif