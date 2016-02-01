/* Component Scripting interface */
#ifndef __PHOTON_GC_SCRIPTING_H_a46266096e73ed440fa52a48287e8f12__
#define __PHOTON_GC_SCRIPTING_H_a46266096e73ed440fa52a48287e8f12__ 

#include "photon/photon_prologue.h"

#include "photon/decode/PhotonGtOptionalScriptingError.h"
#include "photon/foundation/PhotonGtArrU8.h"
#include "photon/scripting/PhotonGtArrScriptInfo.h"
#include "photon/scripting/PhotonGtScriptId.h"
#include "photon/foundation/PhotonGtGuid.h"
#include "photon/foundation/PhotonGtArrGuid.h"
#include "photon/scripting/PhotonGtScriptRunTiming.h"
#include "photon/scripting/PhotonGtArrScriptRunTiming.h"

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
  PhotonGtOptionalScriptingError (*uploadScript)(PhotonGcScripting*, PhotonGtScriptId*, PhotonGtArrU8*, PhotonGtArrU8*);
  PhotonGtOptionalScriptingError (*deleteScript)(PhotonGcScripting*, PhotonGtScriptId*);
  PhotonGtOptionalScriptingError (*runScriptNow)(PhotonGcScripting*, PhotonGtScriptId*);
  PhotonGtOptionalScriptingError (*scheduleScriptRun)(PhotonGcScripting*, PhotonGtScriptRunTiming*);
  PhotonGtOptionalScriptingError (*enableScriptRunTiming)(PhotonGcScripting*, PhotonGtGuid*);
  PhotonGtOptionalScriptingError (*disableScriptRunTiming)(PhotonGcScripting*, PhotonGtGuid*);
};
PhotonResult PhotonGcScripting_UploadScript(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcScripting_DeleteScript(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcScripting_RunScriptNow(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcScripting_ScheduleScriptRun(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcScripting_EnableScriptRunTiming(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcScripting_DisableScriptRunTiming(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer);

PhotonResult PhotonGcScripting_ExecuteCommand(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);

PhotonResult PhotonGcScripting_ReadExecuteCommand(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer);


#ifdef __cplusplus
}
#endif
#include "photon/photon_epilogue.h"

#endif