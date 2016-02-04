/* Type header */
#ifndef __PHOTON_GT_FULL_ID_H_1bf446ba2746dcd1969b3d2af21da418__
#define __PHOTON_GT_FULL_ID_H_1bf446ba2746dcd1969b3d2af21da418__ 

#include "photon/photon_prologue.h"

#include "photon/identification/PhotonGtShortId.h"
#include "photon/identification/PhotonGtArrComponentNumberGuidPairMin1.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtShortId shortId;
  PhotonGtArrComponentNumberGuidPairMin1 deviceComponentGuidPairs;
} PhotonGtFullId;

PhotonResult PhotonGtFullId_Serialize(PhotonGtFullId* self, PhotonWriter* writer);

PhotonResult PhotonGtFullId_Deserialize(PhotonGtFullId* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif