/* Type header */
#ifndef __PHOTON_GT_ARR_SCRIPT_INFO_H_9f444b3097cdb8713defecaa57f2b4cf__
#define __PHOTON_GT_ARR_SCRIPT_INFO_H_9f444b3097cdb8713defecaa57f2b4cf__ 

#include "photon/photon_prologue.h"

#include "photon/scripting/PhotonGtScriptInfo.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  size_t size;
  PhotonGtScriptInfo data[256];
} PhotonGtArrScriptInfo;

PhotonResult PhotonGtArrScriptInfo_Serialize(PhotonGtArrScriptInfo* self, PhotonWriter* writer);

PhotonResult PhotonGtArrScriptInfo_Deserialize(PhotonGtArrScriptInfo* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif