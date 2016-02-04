/* Component Scripting implementation */
#include "photon/scripting/PhotonGcScripting.h"

PhotonResult PhotonGcScripting_UploadScript(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtScriptId scriptId;
  PHOTON_TRY(PhotonGtScriptId_Deserialize(&scriptId, reader));
  PhotonGtArrU8 scriptData;
  PHOTON_TRY(PhotonGtArrU8_Deserialize(&scriptData, reader));
  PhotonGtArrU8 scriptCode;
  PHOTON_TRY(PhotonGtArrU8_Deserialize(&scriptCode, reader));
  PhotonGtOptionalScriptingError cmdResult = self->uploadScript(self, &scriptId, &scriptData, &scriptCode);
  return PhotonGtOptionalScriptingError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcScripting_DeleteScript(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtScriptId scriptId;
  PHOTON_TRY(PhotonGtScriptId_Deserialize(&scriptId, reader));
  PhotonGtOptionalScriptingError cmdResult = self->deleteScript(self, &scriptId);
  return PhotonGtOptionalScriptingError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcScripting_RunScriptNow(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtScriptId scriptId;
  PHOTON_TRY(PhotonGtScriptId_Deserialize(&scriptId, reader));
  PhotonGtOptionalScriptingError cmdResult = self->runScriptNow(self, &scriptId);
  return PhotonGtOptionalScriptingError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcScripting_ScheduleScriptRun(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtScriptRunTiming scriptRunTiming;
  PHOTON_TRY(PhotonGtScriptRunTiming_Deserialize(&scriptRunTiming, reader));
  PhotonGtOptionalScriptingError cmdResult = self->scheduleScriptRun(self, &scriptRunTiming);
  return PhotonGtOptionalScriptingError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcScripting_EnableScriptRunTiming(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtGuid scriptRunTimingId;
  PHOTON_TRY(PhotonGtGuid_Deserialize(&scriptRunTimingId, reader));
  PhotonGtOptionalScriptingError cmdResult = self->enableScriptRunTiming(self, &scriptRunTimingId);
  return PhotonGtOptionalScriptingError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcScripting_DisableScriptRunTiming(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtGuid scriptRunTimingId;
  PHOTON_TRY(PhotonGtGuid_Deserialize(&scriptRunTimingId, reader));
  PhotonGtOptionalScriptingError cmdResult = self->disableScriptRunTiming(self, &scriptRunTimingId);
  return PhotonGtOptionalScriptingError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcScripting_WriteAvailableScriptsIds(PhotonGcScripting* self, PhotonWriter* writer) {
  PhotonGtArrGuid scriptsids = self->scriptsIds(self);
  PHOTON_TRY(PhotonGtArrGuid_Serialize(&scriptsids, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGcScripting_WriteScriptsRunTimings(PhotonGcScripting* self, PhotonWriter* writer) {
  PhotonGtArrScriptRunTiming scriptsruntimings = self->scriptsRunTimings(self);
  PHOTON_TRY(PhotonGtArrScriptRunTiming_Serialize(&scriptsruntimings, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGcScripting_ExecuteCommand(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcScripting_UploadScript(self, reader, writer);
    case 1:
      return PhotonGcScripting_DeleteScript(self, reader, writer);
    case 2:
      return PhotonGcScripting_RunScriptNow(self, reader, writer);
    case 3:
      return PhotonGcScripting_ScheduleScriptRun(self, reader, writer);
    case 4:
      return PhotonGcScripting_EnableScriptRunTiming(self, reader, writer);
    case 5:
      return PhotonGcScripting_DisableScriptRunTiming(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcScripting_ReadExecuteCommand(PhotonGcScripting* self, PhotonReader* reader, PhotonWriter* writer) {
  size_t commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcScripting_ExecuteCommand(self, reader, writer, commandId);
}

PhotonResult PhotonGcScripting_WriteMessage(PhotonGcScripting* self, PhotonWriter* writer, size_t messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    case 0:
      return PhotonGcScripting_WriteAvailableScriptsIds(self, writer);
    case 1:
      return PhotonGcScripting_WriteScriptsRunTimings(self, writer);
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonGtB8 PhotonGcScripting_IsStatusMessage(size_t messageId) {
  switch (messageId) {
    case 0:
      return true;
    case 1:
      return true;
    default:
      return false;
  }
}

