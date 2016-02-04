/* Type header */
#ifndef __PHOTON_GT_SCRIPT_ID_H_ca3cbe753e79adbf275c6c6e3ab88c43__
#define __PHOTON_GT_SCRIPT_ID_H_ca3cbe753e79adbf275c6c6e3ab88c43__ 

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