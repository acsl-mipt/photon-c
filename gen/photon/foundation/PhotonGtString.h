/* Type header */
#ifndef __PHOTON_GT_STRING_H_d67debb6c5d2115941d273d01b82c1c7__
#define __PHOTON_GT_STRING_H_d67debb6c5d2115941d273d01b82c1c7__ 

#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtArrU8.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef PhotonGtArrU8 PhotonGtString;

PhotonResult PhotonGtString_Serialize(PhotonGtString* self, PhotonWriter* writer);

PhotonResult PhotonGtString_Deserialize(PhotonGtString* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif