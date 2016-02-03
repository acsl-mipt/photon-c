/* Type header */
#ifndef __PHOTON_GT_SCRIPT_INFO_H_952f17e8a419c9eeef154bb457dc4f47__
#define __PHOTON_GT_SCRIPT_INFO_H_952f17e8a419c9eeef154bb457dc4f47__ 

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