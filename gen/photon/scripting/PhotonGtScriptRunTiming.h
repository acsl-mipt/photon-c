/* Type header */
#ifndef __PHOTON_GT_SCRIPT_RUN_TIMING_H_9bb023eea76b67a00f9a570895d0a5a6__
#define __PHOTON_GT_SCRIPT_RUN_TIMING_H_9bb023eea76b67a00f9a570895d0a5a6__ 

#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtGuid.h"
#include "photon/foundation/PhotonGtB8.h"
#include "photon/scripting/PhotonGtScriptId.h"
#include "photon/scripting/PhotonGtDateTime.h"
#include "photon/foundation/PhotonGtB8.h"
#include "photon/scripting/PhotonGtPeriod.h"
#include "photon/foundation/PhotonGtB8.h"
#include "photon/scripting/PhotonGtDateTime.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtGuid id;
  PhotonGtB8 isActive;
  PhotonGtScriptId scriptId;
  PhotonGtDateTime runOn;
  PhotonGtB8 isRepeated;
  PhotonGtPeriod repeatPeriod;
  PhotonGtB8 isRepeatingLimitedByDate;
  PhotonGtDateTime repeatUntil;
} PhotonGtScriptRunTiming;

PhotonResult PhotonGtScriptRunTiming_Serialize(PhotonGtScriptRunTiming* self, PhotonWriter* writer);

PhotonResult PhotonGtScriptRunTiming_Deserialize(PhotonGtScriptRunTiming* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif