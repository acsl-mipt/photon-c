/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_SCRIPTING_PHOTON_GT_ARR_SCRIPT_INFO_H__
#define __PHOTON_SCRIPTING_PHOTON_GT_ARR_SCRIPT_INFO_H__ 
#include "photon/photon_prologue.h"

#include "photon/scripting/PhotonGtScriptInfo.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_GT_ARR_SCRIPT_INFO_MIN_SIZE 0
#define PHOTON_GT_ARR_SCRIPT_INFO_MAX_SIZE 0

typedef struct {
  size_t size;
  PhotonGtScriptInfo* data;
} PhotonGtArrScriptInfo;

PhotonResult PhotonGtArrScriptInfo_Serialize(PhotonGtArrScriptInfo self, PhotonWriter* writer);

PhotonResult PhotonGtArrScriptInfo_Deserialize(PhotonGtArrScriptInfo* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif