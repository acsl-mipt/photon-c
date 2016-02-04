/* Type header */
#ifndef __PHOTON_GT_U16_H_a75839e28ef89bdbe0834a0c01b58d48__
#define __PHOTON_GT_U16_H_a75839e28ef89bdbe0834a0c01b58d48__ 

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