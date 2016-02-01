/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_SCRIPTING_ERROR_H_e6ab825c2d4ba32716b94e464883cc2d__
#define __PHOTON_GT_OPTIONAL_SCRIPTING_ERROR_H_e6ab825c2d4ba32716b94e464883cc2d__ 

#include "photon/photon_prologue.h"

#include "photon/scripting/PhotonGtScriptingError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtB8 flag;
  PhotonGtScriptingError value;
} PhotonGtOptionalScriptingError;

PhotonResult PhotonGtOptionalScriptingError_Serialize(PhotonGtOptionalScriptingError* self, PhotonWriter* writer);

PhotonResult PhotonGtOptionalScriptingError_Deserialize(PhotonGtOptionalScriptingError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif