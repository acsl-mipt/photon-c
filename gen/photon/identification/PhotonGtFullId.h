/* Type header */
#ifndef __PHOTON_IDENTIFICATION_PHOTON_GT_FULL_ID_H__
#define __PHOTON_IDENTIFICATION_PHOTON_GT_FULL_ID_H__ 
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