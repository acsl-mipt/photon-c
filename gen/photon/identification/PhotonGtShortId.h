/* Type header */
#ifndef __PHOTON_GT_SHORT_ID_H_69b012ab0fc6de8144fc57c9c969ac44__
#define __PHOTON_GT_SHORT_ID_H_69b012ab0fc6de8144fc57c9c969ac44__ 

#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtGuid.h"
#include "photon/foundation/PhotonGtGuid.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtGuid deviceGuid;
  PhotonGtGuid rootComponentGuid;
} PhotonGtShortId;

PhotonResult PhotonGtShortId_Serialize(PhotonGtShortId* self, PhotonWriter* writer);

PhotonResult PhotonGtShortId_Deserialize(PhotonGtShortId* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif