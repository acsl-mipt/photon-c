/* Type header */
#ifndef __PHOTON_GT_SCRIPTING_ERROR_H_cadad1197c0e5f9064be9d19ad60043f__
#define __PHOTON_GT_SCRIPTING_ERROR_H_cadad1197c0e5f9064be9d19ad60043f__ 

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