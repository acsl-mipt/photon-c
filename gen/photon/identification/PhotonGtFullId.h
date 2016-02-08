/* Type header */
#ifndef __PHOTON_GT_FULL_ID_H_5574c76a24dae7cfda4dc1b662fe7496__
#define __PHOTON_GT_FULL_ID_H_5574c76a24dae7cfda4dc1b662fe7496__ 
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