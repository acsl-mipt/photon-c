/* Type header */
#ifndef __PHOTON_GT_STRING_H_0df377aeae5e852815afc970dd18d2a5__
#define __PHOTON_GT_STRING_H_0df377aeae5e852815afc970dd18d2a5__ 

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