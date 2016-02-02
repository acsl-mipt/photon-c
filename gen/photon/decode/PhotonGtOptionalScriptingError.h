/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_SCRIPTING_ERROR_H_192063a5ee88492a94a46ffa95c1dcd1__
#define __PHOTON_GT_OPTIONAL_SCRIPTING_ERROR_H_192063a5ee88492a94a46ffa95c1dcd1__ 

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