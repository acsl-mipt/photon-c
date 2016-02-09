/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_SCRIPTING_PHOTON_GT_SCRIPT_INFO_H__
#define __PHOTON_SCRIPTING_PHOTON_GT_SCRIPT_INFO_H__ 
#include "photon/photon_prologue.h"

#include "photon/scripting/PhotonGtScriptId.h"
#include "photon/foundation/PhotonGtArrU8.h"
#include "photon/foundation/PhotonGtArrU8.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtScriptId scriptId;
  PhotonGtArrU8 scriptData;
  PhotonGtArrU8 scriptCode;
} PhotonGtScriptInfo;

PhotonResult PhotonGtScriptInfo_Serialize(const PhotonGtScriptInfo* self, PhotonWriter* writer);

PhotonResult PhotonGtScriptInfo_Deserialize(PhotonGtScriptInfo* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif