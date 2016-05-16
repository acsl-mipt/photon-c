#include "photon/PhotonGcMain.h"

PhotonResult PhotonGcMain_ExecuteFilesStartFileUpload(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtFileInfo fileInfo;
  PHOTON_TRY(PhotonGtFileInfo_Deserialize(&fileInfo, reader));
  return PhotonBer_Serialize(PhotonGcMain_FilesStartFileUpload(&fileInfo), writer);
}

PhotonResult PhotonGcMain_ExecuteFilesUploadFilePart(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtArrU8 fileContentsPart;
  PHOTON_TRY(PhotonGtArrU8_Deserialize(&fileContentsPart, reader));
  return PhotonBer_Serialize(PhotonGcMain_FilesUploadFilePart(fileContentsPart), writer);
}

PhotonResult PhotonGcMain_ExecuteFilesStopFileUpload(PhotonReader* reader, PhotonWriter* writer) {
  (void)reader;
  return PhotonBer_Serialize(PhotonGcMain_FilesStopFileUpload(), writer);
}

PhotonResult PhotonGcMain_ExecuteFilesStartFileDownload(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtString path;
  PHOTON_TRY(PhotonGtArrU8_Deserialize((PhotonGtArrU8*) &path, reader));
  return PhotonGtOrFileInfoFileDownloadError_Serialize(PhotonGcMain_FilesStartFileDownload(path), writer);
}

PhotonResult PhotonGcMain_ExecuteFilesDownloadFilePart(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtBer byteSize;
  PHOTON_TRY(PhotonBer_Deserialize(&byteSize, reader));
  return PhotonGtOrArrU8FileDownloadError_Serialize(PhotonGcMain_FilesDownloadFilePart(byteSize), writer);
}

PhotonResult PhotonGcMain_ExecuteFilesStopFileDownload(PhotonReader* reader, PhotonWriter* writer) {
  (void)reader;
  return PhotonBer_Serialize(PhotonGcMain_FilesStopFileDownload(), writer);
}

PhotonResult PhotonGcMain_ExecuteFilesStartRequestFileList(PhotonReader* reader, PhotonWriter* writer) {
  (void)reader;
  return PhotonGtOrBerFileListError_Serialize(PhotonGcMain_FilesStartRequestFileList(), writer);
}

PhotonResult PhotonGcMain_ExecuteFilesRequestFileListPart(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtBer nodeSize;
  PHOTON_TRY(PhotonBer_Deserialize(&nodeSize, reader));
  return PhotonGtOrArrNodeInfoFileListError_Serialize(PhotonGcMain_FilesRequestFileListPart(nodeSize), writer);
}

PhotonResult PhotonGcMain_ExecuteFilesStopRequestFileList(PhotonReader* reader, PhotonWriter* writer) {
  (void)reader;
  return PhotonBer_Serialize(PhotonGcMain_FilesStopRequestFileList(), writer);
}

PhotonResult PhotonGcMain_ExecuteFilesDeleteNode(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtString path;
  PHOTON_TRY(PhotonGtArrU8_Deserialize((PhotonGtArrU8*) &path, reader));
  return PhotonBer_Serialize(PhotonGcMain_FilesDeleteNode(path), writer);
}

PhotonResult PhotonGcMain_ExecuteFilesCreateDir(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtString path;
  PHOTON_TRY(PhotonGtArrU8_Deserialize((PhotonGtArrU8*) &path, reader));
  return PhotonBer_Serialize(PhotonGcMain_FilesCreateDir(path), writer);
}

PhotonResult PhotonGcMain_ExecuteIdentificationRequestShortId(PhotonReader* reader, PhotonWriter* writer) {
  (void)reader;
  return PhotonGtShortId_Serialize(PhotonGcMain_IdentificationRequestShortId(), writer);
}

PhotonResult PhotonGcMain_ExecuteIdentificationRequestFullId(PhotonReader* reader, PhotonWriter* writer) {
  (void)reader;
  return PhotonGtFullId_Serialize(PhotonGcMain_IdentificationRequestFullId(), writer);
}

PhotonResult PhotonGcMain_ExecuteIdentificationRequestComponentGuid(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtBer componentNumber;
  PHOTON_TRY(PhotonBer_Deserialize(&componentNumber, reader));
  return PhotonBer_Serialize(PhotonGcMain_IdentificationRequestComponentGuid(componentNumber), writer);
}

PhotonResult PhotonGcMain_ExecuteRouterSetRoute(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtAddress address;
  PHOTON_TRY(PhotonBer_Deserialize((PhotonGtBer*) &address, reader));
  PhotonGtAddress next_hop;
  PHOTON_TRY(PhotonBer_Deserialize((PhotonGtBer*) &next_hop, reader));
  return PhotonBer_Serialize(PhotonGcMain_RouterSetRoute(address, next_hop), writer);
}

PhotonResult PhotonGcMain_ExecuteRouterDelRoute(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtAddress address;
  PHOTON_TRY(PhotonBer_Deserialize((PhotonGtBer*) &address, reader));
  return PhotonBer_Serialize(PhotonGcMain_RouterDelRoute(address), writer);
}

PhotonResult PhotonGcMain_ExecuteRouterSetGroupRoute(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtAddress groupAddress;
  PHOTON_TRY(PhotonBer_Deserialize((PhotonGtBer*) &groupAddress, reader));
  PhotonGtAddress next_hop;
  PHOTON_TRY(PhotonBer_Deserialize((PhotonGtBer*) &next_hop, reader));
  return PhotonBer_Serialize(PhotonGcMain_RouterSetGroupRoute(groupAddress, next_hop), writer);
}

PhotonResult PhotonGcMain_ExecuteRouterDelGroupRoute(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtAddress groupAddress;
  PHOTON_TRY(PhotonBer_Deserialize((PhotonGtBer*) &groupAddress, reader));
  return PhotonBer_Serialize(PhotonGcMain_RouterDelGroupRoute(groupAddress), writer);
}

PhotonResult PhotonGcMain_ExecuteScriptingUploadScript(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtScriptInfo script;
  PHOTON_TRY(PhotonGtScriptInfo_Deserialize(&script, reader));
  return PhotonBer_Serialize(PhotonGcMain_ScriptingUploadScript(&script), writer);
}

PhotonResult PhotonGcMain_ExecuteScriptingDeleteScript(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtScriptId scriptId;
  PHOTON_TRY(PhotonBer_Deserialize((PhotonGtBer*) (PhotonGtGuid*) &scriptId, reader));
  return PhotonBer_Serialize(PhotonGcMain_ScriptingDeleteScript(scriptId), writer);
}

PhotonResult PhotonGcMain_ExecuteScriptingRunScriptNow(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtScriptId scriptId;
  PHOTON_TRY(PhotonBer_Deserialize((PhotonGtBer*) (PhotonGtGuid*) &scriptId, reader));
  return PhotonBer_Serialize(PhotonGcMain_ScriptingRunScriptNow(scriptId), writer);
}

PhotonResult PhotonGcMain_ExecuteScriptingScheduleScriptRun(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtScriptRunTiming scriptRunTiming;
  PHOTON_TRY(PhotonGtScriptRunTiming_Deserialize(&scriptRunTiming, reader));
  return PhotonBer_Serialize(PhotonGcMain_ScriptingScheduleScriptRun(&scriptRunTiming), writer);
}

PhotonResult PhotonGcMain_ExecuteScriptingEnableScriptRunTiming(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtGuid scriptRunTimingId;
  PHOTON_TRY(PhotonBer_Deserialize((PhotonGtBer*) &scriptRunTimingId, reader));
  return PhotonBer_Serialize(PhotonGcMain_ScriptingEnableScriptRunTiming(scriptRunTimingId), writer);
}

PhotonResult PhotonGcMain_ExecuteScriptingDisableScriptRunTiming(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtGuid scriptRunTimingId;
  PHOTON_TRY(PhotonBer_Deserialize((PhotonGtBer*) &scriptRunTimingId, reader));
  return PhotonBer_Serialize(PhotonGcMain_ScriptingDisableScriptRunTiming(scriptRunTimingId), writer);
}

PhotonResult PhotonGcMain_ExecuteSegmentStartSegmentAckMode(PhotonReader* reader, PhotonWriter* writer) {
  (void)reader;
  return PhotonBer_Serialize(PhotonGcMain_SegmentStartSegmentAckMode(), writer);
}

PhotonResult PhotonGcMain_ExecuteSegmentStopSegmentAckMode(PhotonReader* reader, PhotonWriter* writer) {
  (void)reader;
  return PhotonBer_Serialize(PhotonGcMain_SegmentStopSegmentAckMode(), writer);
}

PhotonResult PhotonGcMain_ExecuteSegmentRequestAckModeStatus(PhotonReader* reader, PhotonWriter* writer) {
  (void)reader;
  PhotonWriter_WriteUint8(writer, PhotonGcMain_SegmentRequestAckModeStatus());
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_ExecuteSegmentProcessAckModeStatus(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtB8 isSegmentationAckModeActive;
  PHOTON_TRY(isSegmentationAckModeActive = PhotonReader_ReadUint8(reader));
  return PhotonBer_Serialize(PhotonGcMain_SegmentProcessAckModeStatus(isSegmentationAckModeActive), writer);
}

PhotonResult PhotonGcMain_ExecuteSegmentStartAckOnEverySegmentMode(PhotonReader* reader, PhotonWriter* writer) {
  (void)reader;
  return PhotonBer_Serialize(PhotonGcMain_SegmentStartAckOnEverySegmentMode(), writer);
}

PhotonResult PhotonGcMain_ExecuteSegmentStopAckOnEverySegmentMode(PhotonReader* reader, PhotonWriter* writer) {
  (void)reader;
  return PhotonBer_Serialize(PhotonGcMain_SegmentStopAckOnEverySegmentMode(), writer);
}

PhotonResult PhotonGcMain_ExecuteSegmentReceiverRequestSegmentsAck(PhotonReader* reader, PhotonWriter* writer) {
  (void)reader;
  return PhotonGtArrBer_Serialize(PhotonGcMain_SegmentReceiverRequestSegmentsAck(), writer);
}

PhotonResult PhotonGcMain_ExecuteSegmentSenderProcessSegmentsAck(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtArrBerFixed1 segmentsReceived;
  PHOTON_TRY(PhotonGtArrBerFixed1_Deserialize(&segmentsReceived, reader));
  return PhotonBer_Serialize(PhotonGcMain_SegmentSenderProcessSegmentsAck(segmentsReceived), writer);
}

PhotonResult PhotonGcMain_ExecuteTmSendStatusMessage(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  return PhotonBer_Serialize(PhotonGcMain_TmSendStatusMessage(componentMessage), writer);
}

PhotonResult PhotonGcMain_ExecuteTmSetMessageRequest(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  PhotonGtBer priority;
  PHOTON_TRY(PhotonBer_Deserialize(&priority, reader));
  return PhotonBer_Serialize(PhotonGcMain_TmSetMessageRequest(componentMessage, priority), writer);
}

PhotonResult PhotonGcMain_ExecuteTmClearMessageRequest(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  return PhotonBer_Serialize(PhotonGcMain_TmClearMessageRequest(componentMessage), writer);
}

PhotonResult PhotonGcMain_ExecuteTmDenyMessage(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  return PhotonBer_Serialize(PhotonGcMain_TmDenyMessage(componentMessage), writer);
}

PhotonResult PhotonGcMain_ExecuteTmAllowMessage(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  return PhotonBer_Serialize(PhotonGcMain_TmAllowMessage(componentMessage), writer);
}

PhotonResult PhotonGcMain_ExecuteTmDenyEvent(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtEventInfo eventInfo;
  PHOTON_TRY(PhotonGtEventInfo_Deserialize(&eventInfo, reader));
  return PhotonBer_Serialize(PhotonGcMain_TmDenyEvent(&eventInfo), writer);
}

PhotonResult PhotonGcMain_ExecuteTmAllowEvent(PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtEventInfo eventInfo;
  PHOTON_TRY(PhotonGtEventInfo_Deserialize(&eventInfo, reader));
  return PhotonBer_Serialize(PhotonGcMain_TmAllowEvent(&eventInfo), writer);
}

PhotonResult PhotonGcMain_WriteFilesActiveMode(PhotonWriter* writer) {
  /* activeMode */;
  PHOTON_TRY(PhotonBer_Serialize(PhotonGcMain_FilesActiveMode(), writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_WriteIdentificationFullId(PhotonWriter* writer) {
  /* fullId */;
  PHOTON_TRY(PhotonGtFullId_Serialize(PhotonGcMain_IdentificationFullId(), writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_WriteIdentificationDeviceComponentNumbers(PhotonWriter* writer) {
  /* fullId.deviceComponentGuidPairs[*].number */;
  PhotonGtArrComponentNumberGuidPairFixed1 array = PhotonGcMain_IdentificationFullId()->deviceComponentGuidPairs;
  size_t size = array.size;
  PHOTON_TRY(PhotonBer_Serialize(size, writer));
  for(size_t i = 0; i < size; ++i) {
    PHOTON_TRY(PhotonBer_Serialize(array.data[i].number, writer));
  }
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_WriteRouterNextHops(PhotonWriter* writer) {
  /* routes[*].next_hop */;
  PhotonGtArrRoute array = PhotonGcMain_RouterRoutes();
  size_t size = array.size;
  PHOTON_TRY(PhotonBer_Serialize(size, writer));
  for(size_t i = 0; i < size; ++i) {
    PHOTON_TRY(PhotonBer_Serialize(array.data[i].next_hop, writer));
  }
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_WriteScriptingAvailableScripts(PhotonWriter* writer) {
  /* scripts */;
  PHOTON_TRY(PhotonGtArrScript_Serialize(PhotonGcMain_ScriptingScripts(), writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_WriteSegmentReceiverSegmentsReceived(PhotonWriter* writer) {
  /* segmentsReceived */;
  PHOTON_TRY(PhotonGtArrBer_Serialize(PhotonGcMain_SegmentReceiverSegmentsReceived(), writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_WriteFilesModeChanged(PhotonWriter* writer, PhotonGtFilesEvent event, PhotonGtFilesMode oldMode) {
  if (0 == PhotonGcMain_IsEventAllowed(0, (PhotonBer) event))
    return PhotonResult_EventIsDenied;
  PhotonBer_Serialize(event, writer);
  PhotonBer_Serialize(oldMode, writer);
  PHOTON_TRY(PhotonBer_Serialize(PhotonGcMain_FilesActiveMode(), writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGcMain_ExecuteCommand(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ExecuteFilesStartFileUpload(reader, writer);
    case 1:
      return PhotonGcMain_ExecuteFilesUploadFilePart(reader, writer);
    case 2:
      return PhotonGcMain_ExecuteFilesStopFileUpload(reader, writer);
    case 3:
      return PhotonGcMain_ExecuteFilesStartFileDownload(reader, writer);
    case 4:
      return PhotonGcMain_ExecuteFilesDownloadFilePart(reader, writer);
    case 5:
      return PhotonGcMain_ExecuteFilesStopFileDownload(reader, writer);
    case 6:
      return PhotonGcMain_ExecuteFilesStartRequestFileList(reader, writer);
    case 7:
      return PhotonGcMain_ExecuteFilesRequestFileListPart(reader, writer);
    case 8:
      return PhotonGcMain_ExecuteFilesStopRequestFileList(reader, writer);
    case 9:
      return PhotonGcMain_ExecuteFilesDeleteNode(reader, writer);
    case 10:
      return PhotonGcMain_ExecuteFilesCreateDir(reader, writer);
    case 11:
      return PhotonGcMain_ExecuteIdentificationRequestShortId(reader, writer);
    case 12:
      return PhotonGcMain_ExecuteIdentificationRequestFullId(reader, writer);
    case 13:
      return PhotonGcMain_ExecuteIdentificationRequestComponentGuid(reader, writer);
    case 14:
      return PhotonGcMain_ExecuteRouterSetRoute(reader, writer);
    case 15:
      return PhotonGcMain_ExecuteRouterDelRoute(reader, writer);
    case 16:
      return PhotonGcMain_ExecuteRouterSetGroupRoute(reader, writer);
    case 17:
      return PhotonGcMain_ExecuteRouterDelGroupRoute(reader, writer);
    case 18:
      return PhotonGcMain_ExecuteScriptingUploadScript(reader, writer);
    case 19:
      return PhotonGcMain_ExecuteScriptingDeleteScript(reader, writer);
    case 20:
      return PhotonGcMain_ExecuteScriptingRunScriptNow(reader, writer);
    case 21:
      return PhotonGcMain_ExecuteScriptingScheduleScriptRun(reader, writer);
    case 22:
      return PhotonGcMain_ExecuteScriptingEnableScriptRunTiming(reader, writer);
    case 23:
      return PhotonGcMain_ExecuteScriptingDisableScriptRunTiming(reader, writer);
    case 24:
      return PhotonGcMain_ExecuteSegmentStartSegmentAckMode(reader, writer);
    case 25:
      return PhotonGcMain_ExecuteSegmentStopSegmentAckMode(reader, writer);
    case 26:
      return PhotonGcMain_ExecuteSegmentRequestAckModeStatus(reader, writer);
    case 27:
      return PhotonGcMain_ExecuteSegmentProcessAckModeStatus(reader, writer);
    case 28:
      return PhotonGcMain_ExecuteSegmentStartAckOnEverySegmentMode(reader, writer);
    case 29:
      return PhotonGcMain_ExecuteSegmentStopAckOnEverySegmentMode(reader, writer);
    case 30:
      return PhotonGcMain_ExecuteSegmentReceiverRequestSegmentsAck(reader, writer);
    case 31:
      return PhotonGcMain_ExecuteSegmentSenderProcessSegmentsAck(reader, writer);
    case 32:
      return PhotonGcMain_ExecuteTmSendStatusMessage(reader, writer);
    case 33:
      return PhotonGcMain_ExecuteTmSetMessageRequest(reader, writer);
    case 34:
      return PhotonGcMain_ExecuteTmClearMessageRequest(reader, writer);
    case 35:
      return PhotonGcMain_ExecuteTmDenyMessage(reader, writer);
    case 36:
      return PhotonGcMain_ExecuteTmAllowMessage(reader, writer);
    case 37:
      return PhotonGcMain_ExecuteTmDenyEvent(reader, writer);
    case 38:
      return PhotonGcMain_ExecuteTmAllowEvent(reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_ReadExecuteCommand(PhotonReader* reader, PhotonWriter* writer) {
  PhotonBer commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcMain_ExecuteCommand(reader, writer, commandId);
}

PhotonResult PhotonGcMain_WriteStatusMessage(PhotonWriter* writer, PhotonBer messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    case 0:
      return PhotonGcMain_WriteFilesActiveMode(writer);
    case 1:
      return PhotonGcMain_WriteIdentificationFullId(writer);
    case 2:
      return PhotonGcMain_WriteIdentificationDeviceComponentNumbers(writer);
    case 3:
      return PhotonGcMain_WriteRouterNextHops(writer);
    case 4:
      return PhotonGcMain_WriteScriptingAvailableScripts(writer);
    case 5:
      return PhotonGcMain_WriteSegmentReceiverSegmentsReceived(writer);
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonResult PhotonGcMain_ExecuteCommandForComponent(PhotonReader* reader, PhotonWriter* writer, PhotonBer componentId, PhotonBer commandId) {
  switch (componentId) {
    case 0:
      return PhotonGcMain_ExecuteCommandForComponentIdentification(reader, writer, commandId);
    case 1:
      return PhotonGcMain_ExecuteCommand(reader, writer, commandId);
    case 2:
      return PhotonGcMain_ExecuteCommandForComponentScripting(reader, writer, commandId);
    case 3:
      return PhotonGcMain_ExecuteCommandForComponentSegment(reader, writer, commandId);
    case 4:
      return PhotonGcMain_ExecuteCommandForComponentTm(reader, writer, commandId);
    case 5:
      return PhotonGcMain_ExecuteCommandForComponentFiles(reader, writer, commandId);
    case 6:
      return PhotonGcMain_ExecuteCommandForComponentSegmentReceiver(reader, writer, commandId);
    case 7:
      return PhotonGcMain_ExecuteCommandForComponentRouter(reader, writer, commandId);
    case 8:
      return PhotonGcMain_ExecuteCommandForComponentSegmentSender(reader, writer, commandId);
    default:
      return PhotonResult_InvalidComponentId;
  }
}

PhotonResult PhotonGcMain_ExecuteCommandForComponentSegment(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_SegmentReadExecuteCommand(reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_ExecuteCommandForComponentFiles(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_FilesReadExecuteCommand(reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_ExecuteCommandForComponentSegmentSender(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_SegmentSenderReadExecuteCommand(reader, writer);
    case 1:
      return PhotonGcMain_SegmentReadExecuteCommand(reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_ExecuteCommandForComponentSegmentReceiver(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_SegmentReceiverReadExecuteCommand(reader, writer);
    case 1:
      return PhotonGcMain_SegmentReadExecuteCommand(reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_ExecuteCommandForComponentScripting(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ScriptingReadExecuteCommand(reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_ExecuteCommandForComponentTm(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_TmReadExecuteCommand(reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_ExecuteCommandForComponentIdentification(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_IdentificationReadExecuteCommand(reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_ExecuteCommandForComponentRouter(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_RouterReadExecuteCommand(reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_ScriptingExecuteCommand(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ExecuteScriptingUploadScript(reader, writer);
    case 1:
      return PhotonGcMain_ExecuteScriptingDeleteScript(reader, writer);
    case 2:
      return PhotonGcMain_ExecuteScriptingRunScriptNow(reader, writer);
    case 3:
      return PhotonGcMain_ExecuteScriptingScheduleScriptRun(reader, writer);
    case 4:
      return PhotonGcMain_ExecuteScriptingEnableScriptRunTiming(reader, writer);
    case 5:
      return PhotonGcMain_ExecuteScriptingDisableScriptRunTiming(reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_ScriptingReadExecuteCommand(PhotonReader* reader, PhotonWriter* writer) {
  PhotonBer commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcMain_ScriptingExecuteCommand(reader, writer, commandId);
}

PhotonResult PhotonGcMain_ScriptingWriteMessage(PhotonWriter* writer, PhotonBer messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    case 0:
      return PhotonGcMain_WriteScriptingAvailableScripts(writer);
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonResult PhotonGcMain_SegmentExecuteCommand(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ExecuteSegmentStartSegmentAckMode(reader, writer);
    case 1:
      return PhotonGcMain_ExecuteSegmentStopSegmentAckMode(reader, writer);
    case 2:
      return PhotonGcMain_ExecuteSegmentRequestAckModeStatus(reader, writer);
    case 3:
      return PhotonGcMain_ExecuteSegmentProcessAckModeStatus(reader, writer);
    case 4:
      return PhotonGcMain_ExecuteSegmentStartAckOnEverySegmentMode(reader, writer);
    case 5:
      return PhotonGcMain_ExecuteSegmentStopAckOnEverySegmentMode(reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_SegmentReadExecuteCommand(PhotonReader* reader, PhotonWriter* writer) {
  PhotonBer commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcMain_SegmentExecuteCommand(reader, writer, commandId);
}

PhotonResult PhotonGcMain_SegmentWriteMessage(PhotonWriter* writer, PhotonBer messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonResult PhotonGcMain_IdentificationExecuteCommand(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ExecuteIdentificationRequestShortId(reader, writer);
    case 1:
      return PhotonGcMain_ExecuteIdentificationRequestFullId(reader, writer);
    case 2:
      return PhotonGcMain_ExecuteIdentificationRequestComponentGuid(reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_IdentificationReadExecuteCommand(PhotonReader* reader, PhotonWriter* writer) {
  PhotonBer commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcMain_IdentificationExecuteCommand(reader, writer, commandId);
}

PhotonResult PhotonGcMain_IdentificationWriteMessage(PhotonWriter* writer, PhotonBer messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    case 0:
      return PhotonGcMain_WriteIdentificationFullId(writer);
    case 1:
      return PhotonGcMain_WriteIdentificationDeviceComponentNumbers(writer);
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonResult PhotonGcMain_TmExecuteCommand(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ExecuteTmSendStatusMessage(reader, writer);
    case 1:
      return PhotonGcMain_ExecuteTmSetMessageRequest(reader, writer);
    case 2:
      return PhotonGcMain_ExecuteTmClearMessageRequest(reader, writer);
    case 3:
      return PhotonGcMain_ExecuteTmDenyMessage(reader, writer);
    case 4:
      return PhotonGcMain_ExecuteTmAllowMessage(reader, writer);
    case 5:
      return PhotonGcMain_ExecuteTmDenyEvent(reader, writer);
    case 6:
      return PhotonGcMain_ExecuteTmAllowEvent(reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_TmReadExecuteCommand(PhotonReader* reader, PhotonWriter* writer) {
  PhotonBer commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcMain_TmExecuteCommand(reader, writer, commandId);
}

PhotonResult PhotonGcMain_TmWriteMessage(PhotonWriter* writer, PhotonBer messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonResult PhotonGcMain_FilesExecuteCommand(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ExecuteFilesStartFileUpload(reader, writer);
    case 1:
      return PhotonGcMain_ExecuteFilesUploadFilePart(reader, writer);
    case 2:
      return PhotonGcMain_ExecuteFilesStopFileUpload(reader, writer);
    case 3:
      return PhotonGcMain_ExecuteFilesStartFileDownload(reader, writer);
    case 4:
      return PhotonGcMain_ExecuteFilesDownloadFilePart(reader, writer);
    case 5:
      return PhotonGcMain_ExecuteFilesStopFileDownload(reader, writer);
    case 6:
      return PhotonGcMain_ExecuteFilesStartRequestFileList(reader, writer);
    case 7:
      return PhotonGcMain_ExecuteFilesRequestFileListPart(reader, writer);
    case 8:
      return PhotonGcMain_ExecuteFilesStopRequestFileList(reader, writer);
    case 9:
      return PhotonGcMain_ExecuteFilesDeleteNode(reader, writer);
    case 10:
      return PhotonGcMain_ExecuteFilesCreateDir(reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_FilesReadExecuteCommand(PhotonReader* reader, PhotonWriter* writer) {
  PhotonBer commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcMain_FilesExecuteCommand(reader, writer, commandId);
}

PhotonResult PhotonGcMain_FilesWriteMessage(PhotonWriter* writer, PhotonBer messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    case 0:
      return PhotonGcMain_WriteFilesActiveMode(writer);
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonResult PhotonGcMain_SegmentReceiverExecuteCommand(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ExecuteSegmentReceiverRequestSegmentsAck(reader, writer);
    case 1:
      return PhotonGcMain_ExecuteSegmentStartSegmentAckMode(reader, writer);
    case 2:
      return PhotonGcMain_ExecuteSegmentStopSegmentAckMode(reader, writer);
    case 3:
      return PhotonGcMain_ExecuteSegmentRequestAckModeStatus(reader, writer);
    case 4:
      return PhotonGcMain_ExecuteSegmentProcessAckModeStatus(reader, writer);
    case 5:
      return PhotonGcMain_ExecuteSegmentStartAckOnEverySegmentMode(reader, writer);
    case 6:
      return PhotonGcMain_ExecuteSegmentStopAckOnEverySegmentMode(reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_SegmentReceiverReadExecuteCommand(PhotonReader* reader, PhotonWriter* writer) {
  PhotonBer commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcMain_SegmentReceiverExecuteCommand(reader, writer, commandId);
}

PhotonResult PhotonGcMain_SegmentReceiverWriteMessage(PhotonWriter* writer, PhotonBer messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    case 0:
      return PhotonGcMain_WriteSegmentReceiverSegmentsReceived(writer);
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonResult PhotonGcMain_RouterExecuteCommand(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ExecuteRouterSetRoute(reader, writer);
    case 1:
      return PhotonGcMain_ExecuteRouterDelRoute(reader, writer);
    case 2:
      return PhotonGcMain_ExecuteRouterSetGroupRoute(reader, writer);
    case 3:
      return PhotonGcMain_ExecuteRouterDelGroupRoute(reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_RouterReadExecuteCommand(PhotonReader* reader, PhotonWriter* writer) {
  PhotonBer commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcMain_RouterExecuteCommand(reader, writer, commandId);
}

PhotonResult PhotonGcMain_RouterWriteMessage(PhotonWriter* writer, PhotonBer messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    case 0:
      return PhotonGcMain_WriteRouterNextHops(writer);
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonResult PhotonGcMain_SegmentSenderExecuteCommand(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcMain_ExecuteSegmentSenderProcessSegmentsAck(reader, writer);
    case 1:
      return PhotonGcMain_ExecuteSegmentStartSegmentAckMode(reader, writer);
    case 2:
      return PhotonGcMain_ExecuteSegmentStopSegmentAckMode(reader, writer);
    case 3:
      return PhotonGcMain_ExecuteSegmentRequestAckModeStatus(reader, writer);
    case 4:
      return PhotonGcMain_ExecuteSegmentProcessAckModeStatus(reader, writer);
    case 5:
      return PhotonGcMain_ExecuteSegmentStartAckOnEverySegmentMode(reader, writer);
    case 6:
      return PhotonGcMain_ExecuteSegmentStopAckOnEverySegmentMode(reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcMain_SegmentSenderReadExecuteCommand(PhotonReader* reader, PhotonWriter* writer) {
  PhotonBer commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcMain_SegmentSenderExecuteCommand(reader, writer, commandId);
}

PhotonResult PhotonGcMain_SegmentSenderWriteMessage(PhotonWriter* writer, PhotonBer messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    default:
      return PhotonResult_InvalidMessageId;
  }
}

