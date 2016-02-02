/* Type header */
#ifndef __PHOTON_GT_SCRIPT_RUN_TIMING_H_3833b1502fa72d6e9290aa4e61a55baf__
#define __PHOTON_GT_SCRIPT_RUN_TIMING_H_3833b1502fa72d6e9290aa4e61a55baf__ 

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