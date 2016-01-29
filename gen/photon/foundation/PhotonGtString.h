/* Type header */
#ifndef __PHOTON_GT_STRING_H_36e6c7237dd4ab642995a3f2f88101d2__
#define __PHOTON_GT_STRING_H_36e6c7237dd4ab642995a3f2f88101d2__ 

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