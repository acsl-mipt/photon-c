/* Type header */
#ifndef __PHOTON_GT_SCRIPT_ID_H_aaff8ad134e93497d70c2f54912bd0e9__
#define __PHOTON_GT_SCRIPT_ID_H_aaff8ad134e93497d70c2f54912bd0e9__ 

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