/* Type header */
#ifndef __PHOTON_GT_COMPONENT_NUMBER_GUID_PAIR_H_2550d58b7f5cb1de49c90dee1ee91af6__
#define __PHOTON_GT_COMPONENT_NUMBER_GUID_PAIR_H_2550d58b7f5cb1de49c90dee1ee91af6__ 
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