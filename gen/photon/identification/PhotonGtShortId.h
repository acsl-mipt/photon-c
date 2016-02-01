/* Type header */
#ifndef __PHOTON_GT_SHORT_ID_H_1ecedcd87253449287e0d1b6c1d63f26__
#define __PHOTON_GT_SHORT_ID_H_1ecedcd87253449287e0d1b6c1d63f26__ 

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