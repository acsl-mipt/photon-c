/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_SCRIPTING_PHOTON_GT_SCRIPTING_ERROR_H__
#define __PHOTON_SCRIPTING_PHOTON_GT_SCRIPTING_ERROR_H__ 
#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_SCRIPTING_ERROR_OK = 0
  , PHOTON_GT_SCRIPTING_ERROR_CONFLICTING_SCRIPT_IDS = 4
  , PHOTON_GT_SCRIPTING_ERROR_NO_SUCH_SCRIPT = 3
  , PHOTON_GT_SCRIPTING_ERROR_MAXIMUM_SCRIPTS_REACHED = 1
  , PHOTON_GT_SCRIPTING_ERROR_NOT_ENOUGH_SPACE_FOR_SCRIPT = 2
} PhotonGtScriptingError;

PhotonResult PhotonGtScriptingError_Serialize(PhotonGtScriptingError self, PhotonWriter* writer);

PhotonResult PhotonGtScriptingError_Deserialize(PhotonGtScriptingError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif