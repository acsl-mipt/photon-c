/* Type header */
#ifndef __PHOTON_GT_SCRIPT_ID_H_cdf1a1e1e6aa80503cd6c9f3ed47a63a__
#define __PHOTON_GT_SCRIPT_ID_H_cdf1a1e1e6aa80503cd6c9f3ed47a63a__ 

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