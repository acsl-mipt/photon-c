/* Type header */
#ifndef __PHOTON_GT_COMPONENT_NUMBER_GUID_PAIR_H_c2b3a3ce558a6f1b5dc2249ed401e595__
#define __PHOTON_GT_COMPONENT_NUMBER_GUID_PAIR_H_c2b3a3ce558a6f1b5dc2249ed401e595__ 

#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtGuid.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonBer number;
  PhotonGtGuid guid;
} PhotonGtComponentNumberGuidPair;

PhotonResult PhotonGtComponentNumberGuidPair_Serialize(PhotonGtComponentNumberGuidPair* self, PhotonWriter* writer);

PhotonResult PhotonGtComponentNumberGuidPair_Deserialize(PhotonGtComponentNumberGuidPair* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif