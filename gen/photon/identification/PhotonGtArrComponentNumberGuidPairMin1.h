/* Type header */
#ifndef __PHOTON_GT_ARR_COMPONENT_NUMBER_GUID_PAIR_MIN1_H_7b8314b6156f509afb15d58032505ca7__
#define __PHOTON_GT_ARR_COMPONENT_NUMBER_GUID_PAIR_MIN1_H_7b8314b6156f509afb15d58032505ca7__ 

#include "photon/photon_prologue.h"

#include "photon/identification/PhotonGtComponentNumberGuidPair.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  size_t size;
  PhotonGtComponentNumberGuidPair data[256];
} PhotonGtArrComponentNumberGuidPairMin1;

PhotonResult PhotonGtArrComponentNumberGuidPairMin1_Serialize(PhotonGtArrComponentNumberGuidPairMin1* self, PhotonWriter* writer);

PhotonResult PhotonGtArrComponentNumberGuidPairMin1_Deserialize(PhotonGtArrComponentNumberGuidPairMin1* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif