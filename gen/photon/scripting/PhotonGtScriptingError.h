/* Type header */
#ifndef __PHOTON_GT_SCRIPTING_ERROR_H_c91002e94e87c97e9bb061dde22e3b75__
#define __PHOTON_GT_SCRIPTING_ERROR_H_c91002e94e87c97e9bb061dde22e3b75__ 

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