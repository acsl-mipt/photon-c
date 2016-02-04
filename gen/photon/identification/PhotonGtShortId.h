/* Type header */
#ifndef __PHOTON_GT_SHORT_ID_H_49cd21fb7e3299f2f027698f19410dd5__
#define __PHOTON_GT_SHORT_ID_H_49cd21fb7e3299f2f027698f19410dd5__ 

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