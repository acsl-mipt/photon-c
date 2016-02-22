/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_IDENTIFICATION_PHOTON_GT_ARR_COMPONENT_NUMBER_GUID_PAIR_MIN1_H__
#define __PHOTON_IDENTIFICATION_PHOTON_GT_ARR_COMPONENT_NUMBER_GUID_PAIR_MIN1_H__ 
#include "photon/photon_prologue.h"

#include "photon/identification/PhotonGtComponentNumberGuidPair.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_GT_ARR_COMPONENT_NUMBER_GUID_PAIR_MIN1_MIN_SIZE 1
#define PHOTON_GT_ARR_COMPONENT_NUMBER_GUID_PAIR_MIN1_MAX_SIZE 0

typedef struct {
  size_t size;
  PhotonGtComponentNumberGuidPair* data;
} PhotonGtArrComponentNumberGuidPairMin1;

PhotonResult PhotonGtArrComponentNumberGuidPairMin1_Serialize(PhotonGtArrComponentNumberGuidPairMin1 self, PhotonWriter* writer);

PhotonResult PhotonGtArrComponentNumberGuidPairMin1_Deserialize(PhotonGtArrComponentNumberGuidPairMin1* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif