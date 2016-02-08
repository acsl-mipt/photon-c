/* Type header */
#ifndef __PHOTON_GT_SCRIPT_ID_H_cb27db8e2a52184e3c234d33299d3703__
#define __PHOTON_GT_SCRIPT_ID_H_cb27db8e2a52184e3c234d33299d3703__ 
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