/* Type header */
#ifndef __PHOTON_GT_COMPONENT_NUMBER_GUID_PAIR_H_cc4093a6cfc44814a9817d3fe958c8cd__
#define __PHOTON_GT_COMPONENT_NUMBER_GUID_PAIR_H_cc4093a6cfc44814a9817d3fe958c8cd__ 

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