#include "photon/PhotonGcMain.h"

PhotonResult PhotonGcMain_ExecuteFilesStartFileUpload(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtFileInfo fileInfo;
  PHOTON_TRY(PhotonGtFileInfo_Deserialize(&fileInfo, reader));
  PhotonGtOptionalFileUploadError cmdResult = PhotonGcMain_FilesStartFileUpload(self, &fileInfo);
  return PhotonGtOptionalFileUploadError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteFilesUploadFile(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtFileInfo fileInfo;
  PHOTON_TRY(PhotonGtFileInfo_Deserialize(&fileInfo, reader));
  PhotonGtOptionalFileUploadError cmdResult = PhotonGcMain_FilesUploadFile(self, &fileInfo);
  return PhotonGtOptionalFileUploadError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteFilesDownloadFile(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtString path;
  PHOTON_TRY(PhotonGtString_Deserialize(&path, reader));
  PhotonGtOrFileInfoFileDownloadError cmdResult = PhotonGcMain_FilesDownloadFile(self, &path);
  return PhotonGtOrFileInfoFileDownloadError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteFilesDeleteNode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtString path;
  PHOTON_TRY(PhotonGtString_Deserialize(&path, reader));
  PhotonGtOptionalFileDeleteError cmdResult = PhotonGcMain_FilesDeleteNode(self, &path);
  return PhotonGtOptionalFileDeleteError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteFilesRequestFileList(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtString path;
  PHOTON_TRY(PhotonGtString_Deserialize(&path, reader));
  PhotonGtOrArrNodeInfoFileListError cmdResult = PhotonGcMain_FilesRequestFileList(self, &path);
  return PhotonGtOrArrNodeInfoFileListError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteFilesCreateDir(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtString path;
  PHOTON_TRY(PhotonGtString_Deserialize(&path, reader));
  PhotonGtOptionalFileCreateDirError cmdResult = PhotonGcMain_FilesCreateDir(self, &path);
  return PhotonGtOptionalFileCreateDirError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteIdentificationRequestShortId(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtShortId cmdResult = PhotonGcMain_IdentificationRequestShortId(self);
  return PhotonGtShortId_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteIdentificationRequestFullId(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtFullId cmdResult = PhotonGcMain_IdentificationRequestFullId(self);
  return PhotonGtFullId_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteIdentificationRequestComponentGuid(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonBer componentNumber;
  PHOTON_TRY(PhotonBer_Deserialize(&componentNumber, reader));
  PhotonGtGuid cmdResult = PhotonGcMain_IdentificationRequestComponentGuid(self, componentNumber);
  return PhotonGtGuid_Serialize(cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteRouterSetRoute(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtAddress address;
  PHOTON_TRY(PhotonGtAddress_Deserialize(&address, reader));
  PhotonGtAddress next_hop;
  PHOTON_TRY(PhotonGtAddress_Deserialize(&next_hop, reader));
  PhotonGcMain_RouterSetRoute(self, address, next_hop);
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_ExecuteRouterDelRoute(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtAddress address;
  PHOTON_TRY(PhotonGtAddress_Deserialize(&address, reader));
  PhotonGcMain_RouterDelRoute(self, address);
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_ExecuteRouterSetGroupRoute(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtAddress groupAddress;
  PHOTON_TRY(PhotonGtAddress_Deserialize(&groupAddress, reader));
  PhotonGtAddress next_hop;
  PHOTON_TRY(PhotonGtAddress_Deserialize(&next_hop, reader));
  PhotonGcMain_RouterSetGroupRoute(self, groupAddress, next_hop);
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_ExecuteRouterDelGroupRoute(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtAddress groupAddress;
  PHOTON_TRY(PhotonGtAddress_Deserialize(&groupAddress, reader));
  PhotonGcMain_RouterDelGroupRoute(self, groupAddress);
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_ExecuteScriptingUploadScript(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtScriptId scriptId;
  PHOTON_TRY(PhotonGtScriptId_Deserialize(&scriptId, reader));
  PhotonGtArrU8 scriptData;
  PHOTON_TRY(PhotonGtArrU8_Deserialize(&scriptData, reader));
  PhotonGtArrU8 scriptCode;
  PHOTON_TRY(PhotonGtArrU8_Deserialize(&scriptCode, reader));
  PhotonGtOptionalScriptingError cmdResult = PhotonGcMain_ScriptingUploadScript(self, scriptId, &scriptData, &scriptCode);
  return PhotonGtOptionalScriptingError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteScriptingDeleteScript(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtScriptId scriptId;
  PHOTON_TRY(PhotonGtScriptId_Deserialize(&scriptId, reader));
  PhotonGtOptionalScriptingError cmdResult = PhotonGcMain_ScriptingDeleteScript(self, scriptId);
  return PhotonGtOptionalScriptingError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteScriptingRunScriptNow(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtScriptId scriptId;
  PHOTON_TRY(PhotonGtScriptId_Deserialize(&scriptId, reader));
  PhotonGtOptionalScriptingError cmdResult = PhotonGcMain_ScriptingRunScriptNow(self, scriptId);
  return PhotonGtOptionalScriptingError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteScriptingScheduleScriptRun(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtScriptRunTiming scriptRunTiming;
  PHOTON_TRY(PhotonGtScriptRunTiming_Deserialize(&scriptRunTiming, reader));
  PhotonGtOptionalScriptingError cmdResult = PhotonGcMain_ScriptingScheduleScriptRun(self, &scriptRunTiming);
  return PhotonGtOptionalScriptingError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteScriptingEnableScriptRunTiming(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtGuid scriptRunTimingId;
  PHOTON_TRY(PhotonGtGuid_Deserialize(&scriptRunTimingId, reader));
  PhotonGtOptionalScriptingError cmdResult = PhotonGcMain_ScriptingEnableScriptRunTiming(self, scriptRunTimingId);
  return PhotonGtOptionalScriptingError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteScriptingDisableScriptRunTiming(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtGuid scriptRunTimingId;
  PHOTON_TRY(PhotonGtGuid_Deserialize(&scriptRunTimingId, reader));
  PhotonGtOptionalScriptingError cmdResult = PhotonGcMain_ScriptingDisableScriptRunTiming(self, scriptRunTimingId);
  return PhotonGtOptionalScriptingError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteSegmentStartSegmentAckMode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStartAckError cmdResult = PhotonGcMain_SegmentStartSegmentAckMode(self);
  return PhotonGtOptionalSegmentStartAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteSegmentStopSegmentAckMode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStopAckError cmdResult = PhotonGcMain_SegmentStopSegmentAckMode(self);
  return PhotonGtOptionalSegmentStopAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteSegmentRequestAckModeStatus(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtB8 cmdResult = PhotonGcMain_SegmentRequestAckModeStatus(self);
  return PhotonGtB8_Serialize(cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteSegmentProcessAckModeStatus(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtB8 isSegmentationAckModeActive;
  PHOTON_TRY(PhotonGtB8_Deserialize(&isSegmentationAckModeActive, reader));
  PhotonGtOptionalSegmentProcessAckError cmdResult = PhotonGcMain_SegmentProcessAckModeStatus(self, isSegmentationAckModeActive);
  return PhotonGtOptionalSegmentProcessAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteSegmentStartAckOnEverySegmentMode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStartAckError cmdResult = PhotonGcMain_SegmentStartAckOnEverySegmentMode(self);
  return PhotonGtOptionalSegmentStartAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteSegmentStopAckOnEverySegmentMode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStopAckError cmdResult = PhotonGcMain_SegmentStopAckOnEverySegmentMode(self);
  return PhotonGtOptionalSegmentStopAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteSegmentReceiverRequestSegmentsAck(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtArrBer cmdResult = PhotonGcMain_SegmentReceiverRequestSegmentsAck(self);
  return PhotonGtArrBer_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteSegmentSenderProcessSegmentsAck(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtArrBerMin1 segmentsReceived;
  PHOTON_TRY(PhotonGtArrBerMin1_Deserialize(&segmentsReceived, reader));
  PhotonGtOptionalSegmentProcessAckError cmdResult = PhotonGcMain_SegmentSenderProcessSegmentsAck(self, &segmentsReceived);
  return PhotonGtOptionalSegmentProcessAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteTmSendEventMessage(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtEventInfo eventInfo;
  PHOTON_TRY(PhotonGtEventInfo_Deserialize(&eventInfo, reader));
  PhotonGtOptionalTmCmdError cmdResult = PhotonGcMain_TmSendEventMessage(self, &eventInfo);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteTmSendStatusMessage(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  PhotonGtOptionalTmCmdError cmdResult = PhotonGcMain_TmSendStatusMessage(self, &componentMessage);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteTmSetMessageRequest(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  PhotonBer priority;
  PHOTON_TRY(PhotonBer_Deserialize(&priority, reader));
  PhotonGtOptionalTmCmdError cmdResult = PhotonGcMain_TmSetMessageRequest(self, &componentMessage, priority);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteTmClearMessageRequest(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  PhotonBer priority;
  PHOTON_TRY(PhotonBer_Deserialize(&priority, reader));
  PhotonGtOptionalTmCmdError cmdResult = PhotonGcMain_TmClearMessageRequest(self, &componentMessage, priority);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteTmDenyMessage(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  PhotonGtOptionalTmCmdError cmdResult = PhotonGcMain_TmDenyMessage(self, &componentMessage);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteTmAllowMessage(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  PhotonGtOptionalTmCmdError cmdResult = PhotonGcMain_TmAllowMessage(self, &componentMessage);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteTmDenyEvent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtEventInfo eventInfo;
  PHOTON_TRY(PhotonGtEventInfo_Deserialize(&eventInfo, reader));
  PhotonGtOptionalTmCmdError cmdResult = PhotonGcMain_TmDenyEvent(self, &eventInfo);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_ExecuteTmAllowEvent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtEventInfo eventInfo;
  PHOTON_TRY(PhotonGtEventInfo_Deserialize(&eventInfo, reader));
  PhotonGtOptionalTmCmdError cmdResult = PhotonGcMain_TmAllowEvent(self, &eventInfo);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcMain_WriteIdentificationFullId(PhotonGcMain* self, PhotonWriter* writer) {
  const PhotonGtFullId* fullid = PhotonGcMain_IdentificationFullId(self);
  PHOTON_TRY(PhotonGtFullId_Serialize(fullid, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_WriteScriptingAvailableScriptsIds(PhotonGcMain* self, PhotonWriter* writer) {
  const PhotonGtArrGuid* scriptsids = PhotonGcMain_ScriptingScriptsIds(self);
  PHOTON_TRY(PhotonGtArrGuid_Serialize(scriptsids, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_WriteScriptingScriptsRunTimings(PhotonGcMain* self, PhotonWriter* writer) {
  const PhotonGtArrScriptRunTiming* scriptsruntimings = PhotonGcMain_ScriptingScriptsRunTimings(self);
  PHOTON_TRY(PhotonGtArrScriptRunTiming_Serialize(scriptsruntimings, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_WriteSegmentReceiverSegmentsReceived(PhotonGcMain* self, PhotonWriter* writer) {
  const PhotonGtArrBer* segmentsreceived = PhotonGcMain_SegmentReceiverSegmentsReceived(self);
  PHOTON_TRY(PhotonGtArrBer_Serialize(segmentsreceived, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_ExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ExecuteFilesStartFileUpload(self, reader, writer);
    case 1:
      return PhotonGcMain_ExecuteFilesUploadFile(self, reader, writer);
    case 2:
      return PhotonGcMain_ExecuteFilesDownloadFile(self, reader, writer);
    case 3:
      return PhotonGcMain_ExecuteFilesDeleteNode(self, reader, writer);
    case 4:
      return PhotonGcMain_ExecuteFilesRequestFileList(self, reader, writer);
    case 5:
      return PhotonGcMain_ExecuteFilesCreateDir(self, reader, writer);
    case 6:
      return PhotonGcMain_ExecuteIdentificationRequestShortId(self, reader, writer);
    case 7:
      return PhotonGcMain_ExecuteIdentificationRequestFullId(self, reader, writer);
    case 8:
      return PhotonGcMain_ExecuteIdentificationRequestComponentGuid(self, reader, writer);
    case 9:
      return PhotonGcMain_ExecuteRouterSetRoute(self, reader, writer);
    case 10:
      return PhotonGcMain_ExecuteRouterDelRoute(self, reader, writer);
    case 11:
      return PhotonGcMain_ExecuteRouterSetGroupRoute(self, reader, writer);
    case 12:
      return PhotonGcMain_ExecuteRouterDelGroupRoute(self, reader, writer);
    case 13:
      return PhotonGcMain_ExecuteScriptingUploadScript(self, reader, writer);
    case 14:
      return PhotonGcMain_ExecuteScriptingDeleteScript(self, reader, writer);
    case 15:
      return PhotonGcMain_ExecuteScriptingRunScriptNow(self, reader, writer);
    case 16:
      return PhotonGcMain_ExecuteScriptingScheduleScriptRun(self, reader, writer);
    case 17:
      return PhotonGcMain_ExecuteScriptingEnableScriptRunTiming(self, reader, writer);
    case 18:
      return PhotonGcMain_ExecuteScriptingDisableScriptRunTiming(self, reader, writer);
    case 19:
      return PhotonGcMain_ExecuteSegmentStartSegmentAckMode(self, reader, writer);
    case 20:
      return PhotonGcMain_ExecuteSegmentStopSegmentAckMode(self, reader, writer);
    case 21:
      return PhotonGcMain_ExecuteSegmentRequestAckModeStatus(self, reader, writer);
    case 22:
      return PhotonGcMain_ExecuteSegmentProcessAckModeStatus(self, reader, writer);
    case 23:
      return PhotonGcMain_ExecuteSegmentStartAckOnEverySegmentMode(self, reader, writer);
    case 24:
      return PhotonGcMain_ExecuteSegmentStopAckOnEverySegmentMode(self, reader, writer);
    case 25:
      return PhotonGcMain_ExecuteSegmentReceiverRequestSegmentsAck(self, reader, writer);
    case 26:
      return PhotonGcMain_ExecuteSegmentSenderProcessSegmentsAck(self, reader, writer);
    case 27:
      return PhotonGcMain_ExecuteTmSendEventMessage(self, reader, writer);
    case 28:
      return PhotonGcMain_ExecuteTmSendStatusMessage(self, reader, writer);
    case 29:
      return PhotonGcMain_ExecuteTmSetMessageRequest(self, reader, writer);
    case 30:
      return PhotonGcMain_ExecuteTmClearMessageRequest(self, reader, writer);
    case 31:
      return PhotonGcMain_ExecuteTmDenyMessage(self, reader, writer);
    case 32:
      return PhotonGcMain_ExecuteTmAllowMessage(self, reader, writer);
    case 33:
      return PhotonGcMain_ExecuteTmDenyEvent(self, reader, writer);
    case 34:
      return PhotonGcMain_ExecuteTmAllowEvent(self, reader, writer);
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

PhotonResult PhotonGcMain_SegmentReceiverExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId) {
  switch (componentId) {
    case 0:
      return PhotonGcMain_SegmentReceiverReadExecuteCommand(self, reader, writer);
    case 1:
      return PhotonGcMain_SegmentReadExecuteCommand(self, reader, writer);
    default:
      return PhotonResult_InvalidComponentId;
  }
}

PhotonResult PhotonGcMain_RouterExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId) {
  switch (componentId) {
    case 0:
      return PhotonGcMain_RouterReadExecuteCommand(self, reader, writer);
    default:
      return PhotonResult_InvalidComponentId;
  }
}

PhotonResult PhotonGcMain_FilesExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId) {
  switch (componentId) {
    case 0:
      return PhotonGcMain_FilesReadExecuteCommand(self, reader, writer);
    default:
      return PhotonResult_InvalidComponentId;
  }
}

PhotonResult PhotonGcMain_SegmentSenderExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId) {
  switch (componentId) {
    case 0:
      return PhotonGcMain_SegmentSenderReadExecuteCommand(self, reader, writer);
    case 1:
      return PhotonGcMain_SegmentReadExecuteCommand(self, reader, writer);
    default:
      return PhotonResult_InvalidComponentId;
  }
}

PhotonResult PhotonGcMain_IdentificationExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId) {
  switch (componentId) {
    case 0:
      return PhotonGcMain_IdentificationReadExecuteCommand(self, reader, writer);
    default:
      return PhotonResult_InvalidComponentId;
  }
}

PhotonResult PhotonGcMain_ScriptingExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId) {
  switch (componentId) {
    case 0:
      return PhotonGcMain_ScriptingReadExecuteCommand(self, reader, writer);
    default:
      return PhotonResult_InvalidComponentId;
  }
}

PhotonResult PhotonGcMain_TmExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId) {
  switch (componentId) {
    case 0:
      return PhotonGcMain_TmReadExecuteCommand(self, reader, writer);
    default:
      return PhotonResult_InvalidComponentId;
  }
}

PhotonResult PhotonGcMain_SegmentExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId) {
  switch (componentId) {
    case 0:
      return PhotonGcMain_SegmentReadExecuteCommand(self, reader, writer);
    default:
      return PhotonResult_InvalidComponentId;
  }
}

PhotonResult PhotonGcMain_SegmentSenderExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ExecuteSegmentSenderProcessSegmentsAck(self, reader, writer);
    case 1:
      return PhotonGcMain_ExecuteSegmentStartSegmentAckMode(self, reader, writer);
    case 2:
      return PhotonGcMain_ExecuteSegmentStopSegmentAckMode(self, reader, writer);
    case 3:
      return PhotonGcMain_ExecuteSegmentRequestAckModeStatus(self, reader, writer);
    case 4:
      return PhotonGcMain_ExecuteSegmentProcessAckModeStatus(self, reader, writer);
    case 5:
      return PhotonGcMain_ExecuteSegmentStartAckOnEverySegmentMode(self, reader, writer);
    case 6:
      return PhotonGcMain_ExecuteSegmentStopAckOnEverySegmentMode(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_SegmentSenderReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  size_t commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcMain_SegmentSenderExecuteCommand(self, reader, writer, commandId);
}

PhotonResult PhotonGcMain_SegmentSenderWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonGtB8 PhotonGcSegmentSender_IsStatusMessage(size_t messageId) {
  switch (messageId) {
    default:
      return false;
  }
}

PhotonResult PhotonGcMain_ScriptingExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ExecuteScriptingUploadScript(self, reader, writer);
    case 1:
      return PhotonGcMain_ExecuteScriptingDeleteScript(self, reader, writer);
    case 2:
      return PhotonGcMain_ExecuteScriptingRunScriptNow(self, reader, writer);
    case 3:
      return PhotonGcMain_ExecuteScriptingScheduleScriptRun(self, reader, writer);
    case 4:
      return PhotonGcMain_ExecuteScriptingEnableScriptRunTiming(self, reader, writer);
    case 5:
      return PhotonGcMain_ExecuteScriptingDisableScriptRunTiming(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_ScriptingReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  size_t commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcMain_ScriptingExecuteCommand(self, reader, writer, commandId);
}

PhotonResult PhotonGcMain_ScriptingWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    case 0:
      return PhotonGcMain_WriteScriptingAvailableScriptsIds(self, writer);
    case 1:
      return PhotonGcMain_WriteScriptingScriptsRunTimings(self, writer);
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

PhotonResult PhotonGcMain_TmExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ExecuteTmSendEventMessage(self, reader, writer);
    case 1:
      return PhotonGcMain_ExecuteTmSendStatusMessage(self, reader, writer);
    case 2:
      return PhotonGcMain_ExecuteTmSetMessageRequest(self, reader, writer);
    case 3:
      return PhotonGcMain_ExecuteTmClearMessageRequest(self, reader, writer);
    case 4:
      return PhotonGcMain_ExecuteTmDenyMessage(self, reader, writer);
    case 5:
      return PhotonGcMain_ExecuteTmAllowMessage(self, reader, writer);
    case 6:
      return PhotonGcMain_ExecuteTmDenyEvent(self, reader, writer);
    case 7:
      return PhotonGcMain_ExecuteTmAllowEvent(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_TmReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  size_t commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcMain_TmExecuteCommand(self, reader, writer, commandId);
}

PhotonResult PhotonGcMain_TmWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonGtB8 PhotonGcTm_IsStatusMessage(size_t messageId) {
  switch (messageId) {
    default:
      return false;
  }
}

PhotonResult PhotonGcMain_SegmentExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ExecuteSegmentStartSegmentAckMode(self, reader, writer);
    case 1:
      return PhotonGcMain_ExecuteSegmentStopSegmentAckMode(self, reader, writer);
    case 2:
      return PhotonGcMain_ExecuteSegmentRequestAckModeStatus(self, reader, writer);
    case 3:
      return PhotonGcMain_ExecuteSegmentProcessAckModeStatus(self, reader, writer);
    case 4:
      return PhotonGcMain_ExecuteSegmentStartAckOnEverySegmentMode(self, reader, writer);
    case 5:
      return PhotonGcMain_ExecuteSegmentStopAckOnEverySegmentMode(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_SegmentReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  size_t commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcMain_SegmentExecuteCommand(self, reader, writer, commandId);
}

PhotonResult PhotonGcMain_SegmentWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonGtB8 PhotonGcSegment_IsStatusMessage(size_t messageId) {
  switch (messageId) {
    default:
      return false;
  }
}

PhotonResult PhotonGcMain_IdentificationExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ExecuteIdentificationRequestShortId(self, reader, writer);
    case 1:
      return PhotonGcMain_ExecuteIdentificationRequestFullId(self, reader, writer);
    case 2:
      return PhotonGcMain_ExecuteIdentificationRequestComponentGuid(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_IdentificationReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  size_t commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcMain_IdentificationExecuteCommand(self, reader, writer, commandId);
}

PhotonResult PhotonGcMain_IdentificationWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    case 0:
      return PhotonGcMain_WriteIdentificationFullId(self, writer);
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonGtB8 PhotonGcIdentification_IsStatusMessage(size_t messageId) {
  switch (messageId) {
    case 0:
      return true;
    default:
      return false;
  }
}

PhotonResult PhotonGcMain_FilesExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ExecuteFilesStartFileUpload(self, reader, writer);
    case 1:
      return PhotonGcMain_ExecuteFilesUploadFile(self, reader, writer);
    case 2:
      return PhotonGcMain_ExecuteFilesDownloadFile(self, reader, writer);
    case 3:
      return PhotonGcMain_ExecuteFilesDeleteNode(self, reader, writer);
    case 4:
      return PhotonGcMain_ExecuteFilesRequestFileList(self, reader, writer);
    case 5:
      return PhotonGcMain_ExecuteFilesCreateDir(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_FilesReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  size_t commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcMain_FilesExecuteCommand(self, reader, writer, commandId);
}

PhotonResult PhotonGcMain_FilesWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonGtB8 PhotonGcFiles_IsStatusMessage(size_t messageId) {
  switch (messageId) {
    default:
      return false;
  }
}

PhotonResult PhotonGcMain_RouterExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ExecuteRouterSetRoute(self, reader, writer);
    case 1:
      return PhotonGcMain_ExecuteRouterDelRoute(self, reader, writer);
    case 2:
      return PhotonGcMain_ExecuteRouterSetGroupRoute(self, reader, writer);
    case 3:
      return PhotonGcMain_ExecuteRouterDelGroupRoute(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_RouterReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  size_t commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcMain_RouterExecuteCommand(self, reader, writer, commandId);
}

PhotonResult PhotonGcMain_RouterWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonGtB8 PhotonGcRouter_IsStatusMessage(size_t messageId) {
  switch (messageId) {
    default:
      return false;
  }
}

PhotonResult PhotonGcMain_SegmentReceiverExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ExecuteSegmentReceiverRequestSegmentsAck(self, reader, writer);
    case 1:
      return PhotonGcMain_ExecuteSegmentStartSegmentAckMode(self, reader, writer);
    case 2:
      return PhotonGcMain_ExecuteSegmentStopSegmentAckMode(self, reader, writer);
    case 3:
      return PhotonGcMain_ExecuteSegmentRequestAckModeStatus(self, reader, writer);
    case 4:
      return PhotonGcMain_ExecuteSegmentProcessAckModeStatus(self, reader, writer);
    case 5:
      return PhotonGcMain_ExecuteSegmentStartAckOnEverySegmentMode(self, reader, writer);
    case 6:
      return PhotonGcMain_ExecuteSegmentStopAckOnEverySegmentMode(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_SegmentReceiverReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer) {
  size_t commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcMain_SegmentReceiverExecuteCommand(self, reader, writer, commandId);
}

PhotonResult PhotonGcMain_SegmentReceiverWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    case 0:
      return PhotonGcMain_WriteSegmentReceiverSegmentsReceived(self, writer);
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonGtB8 PhotonGcSegmentReceiver_IsStatusMessage(size_t messageId) {
  switch (messageId) {
    case 0:
      return true;
    default:
      return false;
  }
}

