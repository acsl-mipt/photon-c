/* Type header */
#ifndef __PHOTON_GT_ARR_SCRIPT_RUN_TIMING_H_042c14ba6d8d2fd2bd53d1e928d1a39d__
#define __PHOTON_GT_ARR_SCRIPT_RUN_TIMING_H_042c14ba6d8d2fd2bd53d1e928d1a39d__ 
#include "photon/photon_prologue.h"

#include "photon/scripting/PhotonGtScriptRunTiming.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  size_t size;
  PhotonGtScriptRunTiming data[256];
} PhotonGtArrScriptRunTiming;

PhotonResult PhotonGtArrScriptRunTiming_Serialize(PhotonGtArrScriptRunTiming* self, PhotonWriter* writer);

PhotonResult PhotonGtArrScriptRunTiming_Deserialize(PhotonGtArrScriptRunTiming* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif