/* Type header */
#ifndef __PHOTON_GT_COMPONENT_NUMBER_GUID_PAIR_H_105044b6b5786d4a4cfed44c6071af12__
#define __PHOTON_GT_COMPONENT_NUMBER_GUID_PAIR_H_105044b6b5786d4a4cfed44c6071af12__ 

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