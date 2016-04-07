/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_SCRIPTING_PHOTON_GT_SCRIPT_H__
#define __PHOTON_SCRIPTING_PHOTON_GT_SCRIPT_H__ 
#include "photon/prologue.h"

#include "photon/scripting/PhotonGtScriptInfo.h"
#include "photon/scripting/PhotonGtScriptRunTiming.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtScriptInfo info;
  PhotonGtScriptRunTiming runTiming;
} PhotonGtScript;

PhotonResult PhotonGtScript_Serialize(const PhotonGtScript* self, PhotonWriter* writer);

PhotonResult PhotonGtScript_Deserialize(PhotonGtScript* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif