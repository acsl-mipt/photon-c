/* Component Scripting interface */
#ifndef __PHOTON_GC_SCRIPTING_H_6a2ef03c3d8f0042dc62695fc96aa458__
#define __PHOTON_GC_SCRIPTING_H_6a2ef03c3d8f0042dc62695fc96aa458__ 

#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtArrU8.h"
#include "photon/scripting/PhotonGtArrScriptInfo.h"
#include "photon/foundation/PhotonGtArrGuid.h"
#include "photon/scripting/PhotonGtArrScriptRunTiming.h"
#include "photon/decode/PhotonGtOptionalScriptingError.h"
#include "photon/foundation/PhotonGtGuid.h"
#include "photon/scripting/PhotonGtScriptRunTiming.h"
#include "photon/scripting/PhotonGtScriptId.h"

#ifdef __cplusplus
extern "C" {
#endif

struct PhotonGcScriptingUserFunctionTable_s;

typedef struct PhotonGcScripting_s PhotonGcScripting;

struct PhotonGcScripting_s {
  PhotonGcScriptingData* data;
  PhotonGtArrGuid (*scriptsIds)(PhotonGcScripting*);
  PhotonGtArrScriptInfo (*scripts)(PhotonGcScripting*);
  PhotonGtArrScriptRunTiming (*scriptsRunTimings)(PhotonGcScripting*);
  PhotonGtOptionalScriptingError (*uploadScript)(PhotonGcScripting*, PhotonGtScriptId, PhotonGtArrU8*, PhotonGtArrU8*);
  PhotonGtOptionalScriptingError (*deleteScript)(PhotonGcScripting*, PhotonGtScriptId);
  PhotonGtOptionalScriptingError (*runScriptNow)(PhotonGcScripting*, PhotonGtScriptId);
  PhotonGtOptionalScriptingError (*scheduleScriptRun)(PhotonGcScripting*, PhotonGtScriptRunTiming*);
  PhotonGtOptionalScriptingError (*enableScriptRunTiming)(PhotonGcScripting*, PhotonGtGuid);
  PhotonGtOptionalScriptingError (*disableScriptRunTiming)(PhotonGcScripting*, PhotonGtGuid);
};
PhotonResult PhotonGcScripting_UploadScript(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcScripting_DeleteScript(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcScripting_RunScriptNow(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcScripting_ScheduleScriptRun(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcScripting_EnableScriptRunTiming(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcScripting_DisableScriptRunTiming(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcScripting_WriteAvailableScriptsIds(PhotonGcScripting* self, PhotonWriter* writer);
PhotonResult PhotonGcScripting_WriteScriptsRunTimings(PhotonGcScripting* self, PhotonWriter* writer);

PhotonResult PhotonGcScripting_ReadExecuteCommand(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer);


#ifdef __cplusplus
}
#endif
#include "photon/photon_epilogue.h"

#endif