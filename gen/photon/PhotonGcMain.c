/* Component Main implementation */
#include "photon/PhotonGcMain.h"

PhotonResult PhotonGcMain_FilesUploadFile(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtFullFileInfo fileInfo;
  PHOTON_TRY(PhotonGtFullFileInfo_Deserialize(&fileInfo, reader));
  PhotonGtOptionalFileUploadError cmdResult = self->filesUploadFile(self, &fileInfo);
  return PhotonGtOptionalFileUploadError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_FilesDownloadFile(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtString path;
  PHOTON_TRY(PhotonGtString_Deserialize(&path, reader));
  PhotonGtOrFullFileInfoFileDownloadError cmdResult = self->filesDownloadFile(self, &path);
  return PhotonGtOrFullFileInfoFileDownloadError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_FilesDeleteNode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtString path;
  PHOTON_TRY(PhotonGtString_Deserialize(&path, reader));
  PhotonGtOptionalFileDeleteError cmdResult = self->filesDeleteNode(self, &path);
  return PhotonGtOptionalFileDeleteError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_FilesRequestFileList(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtString path;
  PHOTON_TRY(PhotonGtString_Deserialize(&path, reader));
  PhotonGtOrArrNodeInfoFileListError cmdResult = self->filesRequestFileList(self, &path);
  return PhotonGtOrArrNodeInfoFileListError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_FilesCreateDir(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtString path;
  PHOTON_TRY(PhotonGtString_Deserialize(&path, reader));
  PhotonGtOptionalFileCreateDirError cmdResult = self->filesCreateDir(self, &path);
  return PhotonGtOptionalFileCreateDirError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_IdentificationRequestShortId(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtShortId cmdResult = self->identificationRequestShortId(self);
  return PhotonGtShortId_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_IdentificationRequestFullId(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtFullId cmdResult = self->identificationRequestFullId(self);
  return PhotonGtFullId_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_IdentificationRequestComponentGuid(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonBer componentNumber;
  PHOTON_TRY(PhotonBer_Deserialize(&componentNumber, reader));
  PhotonGtGuid cmdResult = self->identificationRequestComponentGuid(self, &componentNumber);
  return PhotonGtGuid_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_RouterSetRoute(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtAddress address;
  PHOTON_TRY(PhotonGtAddress_Deserialize(&address, reader));
  PhotonGtAddress next_hop;
  PHOTON_TRY(PhotonGtAddress_Deserialize(&next_hop, reader));
  self->routerSetRoute(self, &address, &next_hop);
}

PhotonResult PhotonGcMain_RouterDelRoute(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtAddress address;
  PHOTON_TRY(PhotonGtAddress_Deserialize(&address, reader));
  self->routerDelRoute(self, &address);
}

PhotonResult PhotonGcMain_RouterSetGroupRoute(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtAddress groupAddress;
  PHOTON_TRY(PhotonGtAddress_Deserialize(&groupAddress, reader));
  PhotonGtAddress next_hop;
  PHOTON_TRY(PhotonGtAddress_Deserialize(&next_hop, reader));
  self->routerSetGroupRoute(self, &groupAddress, &next_hop);
}

PhotonResult PhotonGcMain_RouterDelGroupRoute(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtAddress groupAddress;
  PHOTON_TRY(PhotonGtAddress_Deserialize(&groupAddress, reader));
  self->routerDelGroupRoute(self, &groupAddress);
}

PhotonResult PhotonGcMain_ScriptingUploadScript(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtScriptId scriptId;
  PHOTON_TRY(PhotonGtScriptId_Deserialize(&scriptId, reader));
  PhotonGtArrU8 scriptData;
  PHOTON_TRY(PhotonGtArrU8_Deserialize(&scriptData, reader));
  PhotonGtArrU8 scriptCode;
  PHOTON_TRY(PhotonGtArrU8_Deserialize(&scriptCode, reader));
  PhotonGtOptionalScriptingError cmdResult = self->scriptingUploadScript(self, &scriptId, &scriptData, &scriptCode);
  return PhotonGtOptionalScriptingError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ScriptingDeleteScript(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtScriptId scriptId;
  PHOTON_TRY(PhotonGtScriptId_Deserialize(&scriptId, reader));
  PhotonGtOptionalScriptingError cmdResult = self->scriptingDeleteScript(self, &scriptId);
  return PhotonGtOptionalScriptingError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ScriptingRunScriptNow(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtScriptId scriptId;
  PHOTON_TRY(PhotonGtScriptId_Deserialize(&scriptId, reader));
  PhotonGtOptionalScriptingError cmdResult = self->scriptingRunScriptNow(self, &scriptId);
  return PhotonGtOptionalScriptingError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ScriptingScheduleScriptRun(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtScriptRunTiming scriptRunTiming;
  PHOTON_TRY(PhotonGtScriptRunTiming_Deserialize(&scriptRunTiming, reader));
  PhotonGtOptionalScriptingError cmdResult = self->scriptingScheduleScriptRun(self, &scriptRunTiming);
  return PhotonGtOptionalScriptingError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ScriptingEnableScriptRunTiming(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtGuid scriptRunTimingId;
  PHOTON_TRY(PhotonGtGuid_Deserialize(&scriptRunTimingId, reader));
  PhotonGtOptionalScriptingError cmdResult = self->scriptingEnableScriptRunTiming(self, &scriptRunTimingId);
  return PhotonGtOptionalScriptingError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ScriptingDisableScriptRunTiming(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtGuid scriptRunTimingId;
  PHOTON_TRY(PhotonGtGuid_Deserialize(&scriptRunTimingId, reader));
  PhotonGtOptionalScriptingError cmdResult = self->scriptingDisableScriptRunTiming(self, &scriptRunTimingId);
  return PhotonGtOptionalScriptingError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_SegmentStartSegmentAckMode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStartAckError cmdResult = self->segmentStartSegmentAckMode(self);
  return PhotonGtOptionalSegmentStartAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_SegmentStopSegmentAckMode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStopAckError cmdResult = self->segmentStopSegmentAckMode(self);
  return PhotonGtOptionalSegmentStopAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_SegmentRequestAckModeStatus(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtB8 cmdResult = self->segmentRequestAckModeStatus(self);
  return PhotonGtB8_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_SegmentProcessAckModeStatus(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtB8 isSegmentationAckModeActive;
  PHOTON_TRY(PhotonGtB8_Deserialize(&isSegmentationAckModeActive, reader));
  PhotonGtOptionalSegmentProcessAckError cmdResult = self->segmentProcessAckModeStatus(self, &isSegmentationAckModeActive);
  return PhotonGtOptionalSegmentProcessAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_SegmentStartAckOnEverySegmentMode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStartAckError cmdResult = self->segmentStartAckOnEverySegmentMode(self);
  return PhotonGtOptionalSegmentStartAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_SegmentStopAckOnEverySegmentMode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStopAckError cmdResult = self->segmentStopAckOnEverySegmentMode(self);
  return PhotonGtOptionalSegmentStopAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_SegmentReceiverRequestSegmentsAck(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtArrBer cmdResult = self->segmentReceiverRequestSegmentsAck(self);
  return PhotonGtArrBer_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_SegmentSenderProcessSegmentsAck(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtArrBerMin1 segmentsReceived;
  PHOTON_TRY(PhotonGtArrBerMin1_Deserialize(&segmentsReceived, reader));
  PhotonGtOptionalSegmentProcessAckError cmdResult = self->segmentSenderProcessSegmentsAck(self, &segmentsReceived);
  return PhotonGtOptionalSegmentProcessAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_TmSendEventMessage(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtEventInfo eventInfo;
  PHOTON_TRY(PhotonGtEventInfo_Deserialize(&eventInfo, reader));
  PhotonGtOptionalTmCmdError cmdResult = self->tmSendEventMessage(self, &eventInfo);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_TmSendStatusMessage(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  PhotonGtOptionalTmCmdError cmdResult = self->tmSendStatusMessage(self, &componentMessage);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_TmSetMessageRequest(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  PhotonBer priority;
  PHOTON_TRY(PhotonBer_Deserialize(&priority, reader));
  PhotonGtOptionalTmCmdError cmdResult = self->tmSetMessageRequest(self, &componentMessage, &priority);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_TmClearMessageRequest(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  PhotonBer priority;
  PHOTON_TRY(PhotonBer_Deserialize(&priority, reader));
  PhotonGtOptionalTmCmdError cmdResult = self->tmClearMessageRequest(self, &componentMessage, &priority);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_TmDenyMessage(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  PhotonGtOptionalTmCmdError cmdResult = self->tmDenyMessage(self, &componentMessage);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_TmAllowMessage(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  PhotonGtOptionalTmCmdError cmdResult = self->tmAllowMessage(self, &componentMessage);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_TmDenyEvent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtEventInfo eventInfo;
  PHOTON_TRY(PhotonGtEventInfo_Deserialize(&eventInfo, reader));
  PhotonGtOptionalTmCmdError cmdResult = self->tmDenyEvent(self, &eventInfo);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_TmAllowEvent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtEventInfo eventInfo;
  PHOTON_TRY(PhotonGtEventInfo_Deserialize(&eventInfo, reader));
  PhotonGtOptionalTmCmdError cmdResult = self->tmAllowEvent(self, &eventInfo);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_WriteIdentificationFullId(PhotonGcMain* self, PhotonWriter* writer) {
  PhotonGtFullId fullid = self->identificationFullId(self);
  PHOTON_TRY(PhotonGtFullId_Serialize(&fullid, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_WriteScriptingAvailableScriptsIds(PhotonGcMain* self, PhotonWriter* writer) {
  PhotonGtArrGuid scriptsids = self->scriptingScriptsIds(self);
  PHOTON_TRY(PhotonGtArrGuid_Serialize(&scriptsids, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_WriteScriptingScriptsRunTimings(PhotonGcMain* self, PhotonWriter* writer) {
  PhotonGtArrScriptRunTiming scriptsruntimings = self->scriptingScriptsRunTimings(self);
  PHOTON_TRY(PhotonGtArrScriptRunTiming_Serialize(&scriptsruntimings, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_WriteSegmentReceiverSegmentsReceived(PhotonGcMain* self, PhotonWriter* writer) {
  PhotonGtArrBer segmentsreceived = self->segmentReceiverSegmentsReceived(self);
  PHOTON_TRY(PhotonGtArrBer_Serialize(&segmentsreceived, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_ExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_FilesUploadFile(self, reader, writer);
    case 1:
      return PhotonGcMain_FilesDownloadFile(self, reader, writer);
    case 2:
      return PhotonGcMain_FilesDeleteNode(self, reader, writer);
    case 3:
      return PhotonGcMain_FilesRequestFileList(self, reader, writer);
    case 4:
      return PhotonGcMain_FilesCreateDir(self, reader, writer);
    case 5:
      return PhotonGcMain_IdentificationRequestShortId(self, reader, writer);
    case 6:
      return PhotonGcMain_IdentificationRequestFullId(self, reader, writer);
    case 7:
      return PhotonGcMain_IdentificationRequestComponentGuid(self, reader, writer);
    case 8:
      return PhotonGcMain_RouterSetRoute(self, reader, writer);
    case 9:
      return PhotonGcMain_RouterDelRoute(self, reader, writer);
    case 10:
      return PhotonGcMain_RouterSetGroupRoute(self, reader, writer);
    case 11:
      return PhotonGcMain_RouterDelGroupRoute(self, reader, writer);
    case 12:
      return PhotonGcMain_ScriptingUploadScript(self, reader, writer);
    case 13:
      return PhotonGcMain_ScriptingDeleteScript(self, reader, writer);
    case 14:
      return PhotonGcMain_ScriptingRunScriptNow(self, reader, writer);
    case 15:
      return PhotonGcMain_ScriptingScheduleScriptRun(self, reader, writer);
    case 16:
      return PhotonGcMain_ScriptingEnableScriptRunTiming(self, reader, writer);
    case 17:
      return PhotonGcMain_ScriptingDisableScriptRunTiming(self, reader, writer);
    case 18:
      return PhotonGcMain_SegmentStartSegmentAckMode(self, reader, writer);
    case 19:
      return PhotonGcMain_SegmentStopSegmentAckMode(self, reader, writer);
    case 20:
      return PhotonGcMain_SegmentRequestAckModeStatus(self, reader, writer);
    case 21:
      return PhotonGcMain_SegmentProcessAckModeStatus(self, reader, writer);
    case 22:
      return PhotonGcMain_SegmentStartAckOnEverySegmentMode(self, reader, writer);
    case 23:
      return PhotonGcMain_SegmentStopAckOnEverySegmentMode(self, reader, writer);
    case 24:
      return PhotonGcMain_SegmentReceiverRequestSegmentsAck(self, reader, writer);
    case 25:
      return PhotonGcMain_SegmentSenderProcessSegmentsAck(self, reader, writer);
    case 26:
      return PhotonGcMain_TmSendEventMessage(self, reader, writer);
    case 27:
      return PhotonGcMain_TmSendStatusMessage(self, reader, writer);
    case 28:
      return PhotonGcMain_TmSetMessageRequest(self, reader, writer);
    case 29:
      return PhotonGcMain_TmClearMessageRequest(self, reader, writer);
    case 30:
      return PhotonGcMain_TmDenyMessage(self, reader, writer);
    case 31:
      return PhotonGcMain_TmAllowMessage(self, reader, writer);
    case 32:
      return PhotonGcMain_TmDenyEvent(self, reader, writer);
    case 33:
      return PhotonGcMain_TmAllowEvent(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_ReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  size_t commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcMain_ExecuteCommand(self, reader, writer, commandId);
}

PhotonResult PhotonGcMain_WriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    case 0:
      return PhotonGcMain_WriteIdentificationFullId(self, writer);
    case 1:
      return PhotonGcMain_WriteScriptingAvailableScriptsIds(self, writer);
    case 2:
      return PhotonGcMain_WriteScriptingScriptsRunTimings(self, writer);
    case 3:
      return PhotonGcMain_WriteSegmentReceiverSegmentsReceived(self, writer);
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonGtB8 PhotonGcMain_IsStatusMessage(size_t messageId) {
  switch (messageId) {
    case 0:
      return true;
    case 1:
      return true;
    case 2:
      return true;
    case 3:
      return true;
    default:
      return false;
  }
}

