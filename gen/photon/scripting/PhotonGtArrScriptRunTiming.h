/* Type header */
#ifndef __PHOTON_GT_ARR_SCRIPT_RUN_TIMING_H_7d0426799898c667e4804cc9e3670cf4__
#define __PHOTON_GT_ARR_SCRIPT_RUN_TIMING_H_7d0426799898c667e4804cc9e3670cf4__ 

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