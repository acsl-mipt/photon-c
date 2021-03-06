/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_IDENTIFICATION_PHOTON_GT_COMPONENT_NUMBER_GUID_PAIR_H__
#define __PHOTON_IDENTIFICATION_PHOTON_GT_COMPONENT_NUMBER_GUID_PAIR_H__ 
#include "photon/prologue.h"

#include "photon/foundation/PhotonGtGuid.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtBer number;
  PhotonGtGuid guid;
} PhotonGtComponentNumberGuidPair;

PhotonResult PhotonGtComponentNumberGuidPair_Serialize(PhotonGtComponentNumberGuidPair self, PhotonWriter* writer);

PhotonResult PhotonGtComponentNumberGuidPair_Deserialize(PhotonGtComponentNumberGuidPair* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif