/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_IDENTIFICATION_PHOTON_GT_ARR_COMPONENT_NUMBER_GUID_PAIR_FIXED1_H__
#define __PHOTON_IDENTIFICATION_PHOTON_GT_ARR_COMPONENT_NUMBER_GUID_PAIR_FIXED1_H__ 
#include "photon/prologue.h"

#include "photon/identification/PhotonGtComponentNumberGuidPair.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_GT_ARR_COMPONENT_NUMBER_GUID_PAIR_FIXED1_MIN_SIZE 1
#define PHOTON_GT_ARR_COMPONENT_NUMBER_GUID_PAIR_FIXED1_MAX_SIZE 1

typedef struct {
  size_t size;
  PhotonGtComponentNumberGuidPair data[1];
} PhotonGtArrComponentNumberGuidPairFixed1;

PhotonResult PhotonGtArrComponentNumberGuidPairFixed1_Serialize(PhotonGtArrComponentNumberGuidPairFixed1 self, PhotonWriter* writer);

PhotonResult PhotonGtArrComponentNumberGuidPairFixed1_Deserialize(PhotonGtArrComponentNumberGuidPairFixed1* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif