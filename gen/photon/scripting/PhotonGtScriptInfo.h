/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_SCRIPTING_PHOTON_GT_SCRIPT_INFO_H__
#define __PHOTON_SCRIPTING_PHOTON_GT_SCRIPT_INFO_H__ 
#include "photon/prologue.h"

#include "photon/scripting/PhotonGtScriptId.h"
#include "photon/decode/PhotonGtArrU8.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtScriptId scriptId;
  PhotonGtArrU8 scriptCode;
} PhotonGtScriptInfo;

PhotonResult PhotonGtScriptInfo_Serialize(const PhotonGtScriptInfo* self, PhotonWriter* writer);

PhotonResult PhotonGtScriptInfo_Deserialize(PhotonGtScriptInfo* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif