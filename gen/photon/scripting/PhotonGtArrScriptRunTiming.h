/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_SCRIPTING_PHOTON_GT_ARR_SCRIPT_RUN_TIMING_H__
#define __PHOTON_SCRIPTING_PHOTON_GT_ARR_SCRIPT_RUN_TIMING_H__ 
#include "photon/photon_prologue.h"

#include "photon/scripting/PhotonGtScriptRunTiming.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_GT_ARR_SCRIPT_RUN_TIMING_MIN_LEN 0
#define PHOTON_GT_ARR_SCRIPT_RUN_TIMING_MAX_LEN 256

typedef struct {
  size_t size;
  PhotonGtScriptRunTiming* data;
} PhotonGtArrScriptRunTiming;

PhotonResult PhotonGtArrScriptRunTiming_Serialize(const PhotonGtArrScriptRunTiming* self, PhotonWriter* writer);

PhotonResult PhotonGtArrScriptRunTiming_Deserialize(PhotonGtArrScriptRunTiming* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif