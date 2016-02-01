/* Type header */
#ifndef __PHOTON_GT_SCRIPT_ID_H_66e898dcad0d1b38802e0c2e61e29cf6__
#define __PHOTON_GT_SCRIPT_ID_H_66e898dcad0d1b38802e0c2e61e29cf6__ 

#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtGuid.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef PhotonGtGuid PhotonGtScriptId;

PhotonResult PhotonGtScriptId_Serialize(PhotonGtScriptId* self, PhotonWriter* writer);

PhotonResult PhotonGtScriptId_Deserialize(PhotonGtScriptId* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif