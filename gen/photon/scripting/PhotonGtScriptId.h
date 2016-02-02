/* Type header */
#ifndef __PHOTON_GT_SCRIPT_ID_H_e5a646b0e2a082356607c62a08c433d2__
#define __PHOTON_GT_SCRIPT_ID_H_e5a646b0e2a082356607c62a08c433d2__ 

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