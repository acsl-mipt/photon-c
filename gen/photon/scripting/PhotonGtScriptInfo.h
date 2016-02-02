/* Type header */
#ifndef __PHOTON_GT_SCRIPT_INFO_H_6193e3c6317fe5612281a9e68f6df88d__
#define __PHOTON_GT_SCRIPT_INFO_H_6193e3c6317fe5612281a9e68f6df88d__ 

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

PhotonResult PhotonGtScriptInfo_Serialize(PhotonGtScriptInfo* self, PhotonWriter* writer);

PhotonResult PhotonGtScriptInfo_Deserialize(PhotonGtScriptInfo* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif