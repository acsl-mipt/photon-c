/* Type header */
#ifndef __PHOTON_GT_ARR_SCRIPT_RUN_TIMING_H_818aa79c1342760cf53a5f23b371293d__
#define __PHOTON_GT_ARR_SCRIPT_RUN_TIMING_H_818aa79c1342760cf53a5f23b371293d__ 

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