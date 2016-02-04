/* Type header */
#ifndef __PHOTON_GT_SCRIPTING_ERROR_H_4d1051a0ab050cc6fe544ebc5b69731f__
#define __PHOTON_GT_SCRIPTING_ERROR_H_4d1051a0ab050cc6fe544ebc5b69731f__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_SCRIPTING_ERROR_INVALID_ARGUMENT = 1
  , PHOTON_GT_SCRIPTING_ERROR_INVALID_STATE = 2
} PhotonGtScriptingError;

PhotonResult PhotonGtScriptingError_Serialize(PhotonGtScriptingError* self, PhotonWriter* writer);

PhotonResult PhotonGtScriptingError_Deserialize(PhotonGtScriptingError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif