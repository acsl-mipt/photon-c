/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_IDENTIFICATION_PHOTON_GT_FULL_ID_H__
#define __PHOTON_IDENTIFICATION_PHOTON_GT_FULL_ID_H__ 
#include "photon/prologue.h"

#include "photon/identification/PhotonGtShortId.h"
#include "photon/identification/PhotonGtArrComponentNumberGuidPairFixed1.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtShortId shortId;
  PhotonGtArrComponentNumberGuidPairFixed1 deviceComponentGuidPairs;
} PhotonGtFullId;

PhotonResult PhotonGtFullId_Serialize(const PhotonGtFullId* self, PhotonWriter* writer);

PhotonResult PhotonGtFullId_Deserialize(PhotonGtFullId* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif