/* Type header */
#ifndef __PHOTON_GT_ARR_SCRIPT_RUN_TIMING_H_d329e9b14cd176f385df65565960d84a__
#define __PHOTON_GT_ARR_SCRIPT_RUN_TIMING_H_d329e9b14cd176f385df65565960d84a__ 

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