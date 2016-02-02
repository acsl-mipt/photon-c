/* Type header */
#ifndef __PHOTON_GT_ARR_COMPONENT_NUMBER_GUID_PAIR_MIN1_H_db9638937fb33aca5e930c374d70045f__
#define __PHOTON_GT_ARR_COMPONENT_NUMBER_GUID_PAIR_MIN1_H_db9638937fb33aca5e930c374d70045f__ 

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