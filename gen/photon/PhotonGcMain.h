
/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_PHOTON_GC_MAIN_H__
#define __PHOTON_PHOTON_GC_MAIN_H__ 
#include "photon/prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "photon/scripting/PhotonGtScriptingError.h"
#include "photon/foundation/PhotonGtGuid.h"
#include "photon/routing/PhotonGtAddress.h"
#include "photon/routing/PhotonGtArrRoute.h"
#include "photon/fs/PhotonGtArrNodeInfo.h"
#include "photon/fs/PhotonGtFilesEvent.h"
#include "photon/fs/PhotonGtFileDownloadError.h"
#include "photon/decode/PhotonGtArrBer.h"
#include "photon/segmentation/PhotonGtSegmentProcessAckError.h"
#include "photon/foundation/PhotonGtString.h"
#include "photon/fs/PhotonGtFileListError.h"
#include "photon/scripting/PhotonGtScript.h"
#include "photon/tm/PhotonGtCompMsg.h"
#include "photon/identification/PhotonGtFullId.h"
#include "photon/fs/PhotonGtFilesMode.h"
#include "photon/decode/PhotonGtArrU8.h"
#include "photon/fs/PhotonGtFileCreateDirError.h"
#include "photon/scripting/PhotonGtPeriod.h"
#include "photon/decode/PhotonGtArrBerFixed1.h"
#include "photon/segmentation/PhotonGtSegmentStartAckError.h"
#include "photon/decode/PhotonGtOrArrU8FileDownloadError.h"
#include "photon/segmentation/PhotonGtSegmentStopAckError.h"
#include "photon/scripting/PhotonGtScriptInfo.h"
#include "photon/identification/PhotonGtComponentNumberGuidPair.h"
#include "photon/tm/PhotonGtTmCmdError.h"
#include "photon/identification/PhotonGtArrComponentNumberGuidPairFixed1.h"
#include "photon/decode/PhotonGtOrBerFileListError.h"
#include "photon/identification/PhotonGtShortId.h"
#include "photon/scripting/PhotonGtDateTime.h"
#include "photon/decode/PhotonGtOrArrNodeInfoFileListError.h"
#include "photon/routing/PhotonGtRoute.h"
#include "photon/scripting/PhotonGtArrScript.h"
#include "photon/scripting/PhotonGtScriptRunTiming.h"
#include "photon/fs/PhotonGtFileUploadError.h"
#include "photon/fs/PhotonGtNodeInfo.h"
#include "photon/decode/PhotonGtOrFileInfoFileDownloadError.h"
#include "photon/fs/PhotonGtFileInfo.h"
#include "photon/tm/PhotonGtEventInfo.h"
#include "photon/routing/PhotonGtRouterError.h"
#include "photon/scripting/PhotonGtScriptId.h"
#include "photon/fs/PhotonGtFileDeleteError.h"

/* USER command implementation functions, MUST BE implemented */

PhotonGtScriptingError PhotonGcMain_ScriptingUploadScript(const PhotonGtScriptInfo* script);
PhotonGtScriptingError PhotonGcMain_ScriptingDeleteScript(PhotonGtScriptId scriptId);
PhotonGtScriptingError PhotonGcMain_ScriptingRunScriptNow(PhotonGtScriptId scriptId);
PhotonGtScriptingError PhotonGcMain_ScriptingScheduleScriptRun(const PhotonGtScriptRunTiming* scriptRunTiming);
PhotonGtScriptingError PhotonGcMain_ScriptingEnableScriptRunTiming(PhotonGtGuid scriptRunTimingId);
PhotonGtScriptingError PhotonGcMain_ScriptingDisableScriptRunTiming(PhotonGtGuid scriptRunTimingId);
PhotonGtSegmentStartAckError PhotonGcMain_SegmentStartSegmentAckMode();
PhotonGtSegmentStopAckError PhotonGcMain_SegmentStopSegmentAckMode();
PhotonGtB8 PhotonGcMain_SegmentRequestAckModeStatus();
PhotonGtSegmentProcessAckError PhotonGcMain_SegmentProcessAckModeStatus(PhotonGtB8 isSegmentationAckModeActive);
PhotonGtSegmentStartAckError PhotonGcMain_SegmentStartAckOnEverySegmentMode();
PhotonGtSegmentStopAckError PhotonGcMain_SegmentStopAckOnEverySegmentMode();
PhotonGtShortId PhotonGcMain_IdentificationRequestShortId();
const PhotonGtFullId* PhotonGcMain_IdentificationRequestFullId();
PhotonGtGuid PhotonGcMain_IdentificationRequestComponentGuid(PhotonGtBer componentNumber);
PhotonGtTmCmdError PhotonGcMain_TmSendStatusMessage(PhotonGtCompMsg componentMessage);
PhotonGtTmCmdError PhotonGcMain_TmSetMessageRequest(PhotonGtCompMsg componentMessage, PhotonGtBer priority);
PhotonGtTmCmdError PhotonGcMain_TmClearMessageRequest(PhotonGtCompMsg componentMessage);
PhotonGtTmCmdError PhotonGcMain_TmDenyMessage(PhotonGtCompMsg componentMessage);
PhotonGtTmCmdError PhotonGcMain_TmAllowMessage(PhotonGtCompMsg componentMessage);
PhotonGtTmCmdError PhotonGcMain_TmDenyEvent(const PhotonGtEventInfo* eventInfo);
PhotonGtTmCmdError PhotonGcMain_TmAllowEvent(const PhotonGtEventInfo* eventInfo);
PhotonGtFileUploadError PhotonGcMain_FilesStartFileUpload(const PhotonGtFileInfo* fileInfo);
PhotonGtFileUploadError PhotonGcMain_FilesUploadFilePart(PhotonGtArrU8 fileContentsPart);
PhotonGtFileUploadError PhotonGcMain_FilesStopFileUpload();
const PhotonGtOrFileInfoFileDownloadError* PhotonGcMain_FilesStartFileDownload(PhotonGtString path);
PhotonGtOrArrU8FileDownloadError PhotonGcMain_FilesDownloadFilePart(PhotonGtBer byteSize);
PhotonGtFileDownloadError PhotonGcMain_FilesStopFileDownload();
PhotonGtOrBerFileListError PhotonGcMain_FilesStartRequestFileList();
PhotonGtOrArrNodeInfoFileListError PhotonGcMain_FilesRequestFileListPart(PhotonGtBer nodeSize);
PhotonGtFileListError PhotonGcMain_FilesStopRequestFileList();
PhotonGtFileDeleteError PhotonGcMain_FilesDeleteNode(PhotonGtString path);
PhotonGtFileCreateDirError PhotonGcMain_FilesCreateDir(PhotonGtString path);
PhotonGtArrBer PhotonGcMain_SegmentReceiverRequestSegmentsAck();
PhotonGtRouterError PhotonGcMain_RouterSetRoute(PhotonGtAddress address, PhotonGtAddress next_hop);
PhotonGtRouterError PhotonGcMain_RouterDelRoute(PhotonGtAddress address);
PhotonGtRouterError PhotonGcMain_RouterSetGroupRoute(PhotonGtAddress groupAddress, PhotonGtAddress next_hop);
PhotonGtRouterError PhotonGcMain_RouterDelGroupRoute(PhotonGtAddress groupAddress);
PhotonGtSegmentProcessAckError PhotonGcMain_SegmentSenderProcessSegmentsAck(PhotonGtArrBerFixed1 segmentsReceived);

/* USER parameter implementation functions, MUST BE implemented */

PhotonGtArrScript PhotonGcMain_ScriptingScripts();
PhotonGtB8 PhotonGcMain_SegmentIsSegmentationAckModeActive();
PhotonGtBer PhotonGcMain_SegmentMaxSegmentNumber();
PhotonGtB8 PhotonGcMain_SegmentIsAckOnEverySegmentModeActive();
const PhotonGtFullId* PhotonGcMain_IdentificationFullId();
PhotonGtBer PhotonGcMain_TmAllowedMessages();
PhotonGtFilesMode PhotonGcMain_FilesActiveMode();
PhotonGtArrBer PhotonGcMain_SegmentReceiverSegmentsReceived();
PhotonGtArrRoute PhotonGcMain_RouterRoutes();
PhotonGtArrRoute PhotonGcMain_RouterGroupRoutes();

/* USER other functions, MUST BE implemented */
PhotonGtB8 PhotonGcMain_IsEventAllowed(PhotonBer messageId, PhotonBer eventId);
/* Component defines */

#define PHOTON_COMPONENTS_SIZE 9
#define PHOTON_COMPONENT_IDS {0, 1, 2, 3, 4, 5, 6, 7, 8}
#define PHOTON_GC_IDENTIFICATION_GUID "mcc.identification.Identification"
#define PHOTON_COMPONENT_0_GUID PHOTON_GC_IDENTIFICATION_GUID
#define PHOTON_GC_IDENTIFICATION_ID 0
#define PHOTON_GC_FILES_GUID "mcc.fs.Files"
#define PHOTON_COMPONENT_5_GUID PHOTON_GC_FILES_GUID
#define PHOTON_GC_FILES_ID 5
#define PHOTON_GC_MAIN_GUID "mcc.photon.Main"
#define PHOTON_COMPONENT_1_GUID PHOTON_GC_MAIN_GUID
#define PHOTON_GC_MAIN_ID 1
#define PHOTON_GC_SEGMENT_RECEIVER_GUID "mcc.segmentation.SegmentReceiver"
#define PHOTON_COMPONENT_6_GUID PHOTON_GC_SEGMENT_RECEIVER_GUID
#define PHOTON_GC_SEGMENT_RECEIVER_ID 6
#define PHOTON_GC_SCRIPTING_GUID "mcc.scripting.Scripting"
#define PHOTON_COMPONENT_2_GUID PHOTON_GC_SCRIPTING_GUID
#define PHOTON_GC_SCRIPTING_ID 2
#define PHOTON_GC_ROUTER_GUID "mcc.routing.Router"
#define PHOTON_COMPONENT_7_GUID PHOTON_GC_ROUTER_GUID
#define PHOTON_GC_ROUTER_ID 7
#define PHOTON_GC_SEGMENT_GUID "mcc.segmentation.Segment"
#define PHOTON_COMPONENT_3_GUID PHOTON_GC_SEGMENT_GUID
#define PHOTON_GC_SEGMENT_ID 3
#define PHOTON_GC_SEGMENT_SENDER_GUID "mcc.segmentation.SegmentSender"
#define PHOTON_COMPONENT_8_GUID PHOTON_GC_SEGMENT_SENDER_GUID
#define PHOTON_GC_SEGMENT_SENDER_ID 8
#define PHOTON_GC_TM_GUID "mcc.tm.Tm"
#define PHOTON_COMPONENT_4_GUID PHOTON_GC_TM_GUID
#define PHOTON_GC_TM_ID 4
#define PHOTON_COMPONENT_GUIDS {PHOTON_GC_IDENTIFICATION_GUID, PHOTON_GC_MAIN_GUID, PHOTON_GC_SCRIPTING_GUID, PHOTON_GC_SEGMENT_GUID, PHOTON_GC_TM_GUID, PHOTON_GC_FILES_GUID, PHOTON_GC_SEGMENT_RECEIVER_GUID, PHOTON_GC_ROUTER_GUID, PHOTON_GC_SEGMENT_SENDER_GUID}

/* Message ID for component defines */

#define PHOTON_GC_MAIN_EVENT_MESSAGE_IDS_SIZE 1
#define PHOTON_GC_MAIN_EVENT_MESSAGE_IDS {0}
#define PHOTON_GC_MAIN_STATUS_MESSAGE_IDS_SIZE 6
#define PHOTON_GC_MAIN_STATUS_MESSAGE_IDS {0, 1, 2, 3, 4, 5}
#define PHOTON_GC_MAIN_STATUS_MESSAGE_PRIORITIES {0, 0, 0, 0, 0, 0}
#define PHOTON_GC_MAIN_STATUS_MESSAGE_ID_PRIORITIES {\
  {0, 0}\
  {1, 0}\
  {2, 0}\
  {3, 0}\
  {4, 0}\
  {5, 0}\
}
#define PHOTON_GC_MAIN_SCRIPTING_EVENT_MESSAGE_IDS_SIZE 0
#define PHOTON_GC_MAIN_SCRIPTING_EVENT_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_SCRIPTING_STATUS_MESSAGE_IDS_SIZE 1
#define PHOTON_GC_MAIN_SCRIPTING_STATUS_MESSAGE_IDS {0}
#define PHOTON_GC_MAIN_SCRIPTING_STATUS_MESSAGE_PRIORITIES {0}
#define PHOTON_GC_MAIN_SCRIPTING_STATUS_MESSAGE_ID_PRIORITIES {\
  {0, 0}\
}
#define PHOTON_GC_MAIN_SEGMENT_EVENT_MESSAGE_IDS_SIZE 0
#define PHOTON_GC_MAIN_SEGMENT_EVENT_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_SEGMENT_STATUS_MESSAGE_IDS_SIZE 0
#define PHOTON_GC_MAIN_SEGMENT_STATUS_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_SEGMENT_STATUS_MESSAGE_PRIORITIES {}
#define PHOTON_GC_MAIN_SEGMENT_STATUS_MESSAGE_ID_PRIORITIES {\
\
}
#define PHOTON_GC_MAIN_IDENTIFICATION_EVENT_MESSAGE_IDS_SIZE 0
#define PHOTON_GC_MAIN_IDENTIFICATION_EVENT_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_IDENTIFICATION_STATUS_MESSAGE_IDS_SIZE 2
#define PHOTON_GC_MAIN_IDENTIFICATION_STATUS_MESSAGE_IDS {0, 1}
#define PHOTON_GC_MAIN_IDENTIFICATION_STATUS_MESSAGE_PRIORITIES {0, 0}
#define PHOTON_GC_MAIN_IDENTIFICATION_STATUS_MESSAGE_ID_PRIORITIES {\
  {0, 0}\
  {1, 0}\
}
#define PHOTON_GC_MAIN_TM_EVENT_MESSAGE_IDS_SIZE 0
#define PHOTON_GC_MAIN_TM_EVENT_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_TM_STATUS_MESSAGE_IDS_SIZE 0
#define PHOTON_GC_MAIN_TM_STATUS_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_TM_STATUS_MESSAGE_PRIORITIES {}
#define PHOTON_GC_MAIN_TM_STATUS_MESSAGE_ID_PRIORITIES {\
\
}
#define PHOTON_GC_MAIN_FILES_EVENT_MESSAGE_IDS_SIZE 1
#define PHOTON_GC_MAIN_FILES_EVENT_MESSAGE_IDS {0}
#define PHOTON_GC_MAIN_FILES_STATUS_MESSAGE_IDS_SIZE 1
#define PHOTON_GC_MAIN_FILES_STATUS_MESSAGE_IDS {0}
#define PHOTON_GC_MAIN_FILES_STATUS_MESSAGE_PRIORITIES {0}
#define PHOTON_GC_MAIN_FILES_STATUS_MESSAGE_ID_PRIORITIES {\
  {0, 0}\
}
#define PHOTON_GC_MAIN_SEGMENT_RECEIVER_EVENT_MESSAGE_IDS_SIZE 0
#define PHOTON_GC_MAIN_SEGMENT_RECEIVER_EVENT_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_SEGMENT_RECEIVER_STATUS_MESSAGE_IDS_SIZE 1
#define PHOTON_GC_MAIN_SEGMENT_RECEIVER_STATUS_MESSAGE_IDS {0}
#define PHOTON_GC_MAIN_SEGMENT_RECEIVER_STATUS_MESSAGE_PRIORITIES {0}
#define PHOTON_GC_MAIN_SEGMENT_RECEIVER_STATUS_MESSAGE_ID_PRIORITIES {\
  {0, 0}\
}
#define PHOTON_GC_MAIN_ROUTER_EVENT_MESSAGE_IDS_SIZE 0
#define PHOTON_GC_MAIN_ROUTER_EVENT_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_ROUTER_STATUS_MESSAGE_IDS_SIZE 1
#define PHOTON_GC_MAIN_ROUTER_STATUS_MESSAGE_IDS {0}
#define PHOTON_GC_MAIN_ROUTER_STATUS_MESSAGE_PRIORITIES {0}
#define PHOTON_GC_MAIN_ROUTER_STATUS_MESSAGE_ID_PRIORITIES {\
  {0, 0}\
}
#define PHOTON_GC_MAIN_SEGMENT_SENDER_EVENT_MESSAGE_IDS_SIZE 0
#define PHOTON_GC_MAIN_SEGMENT_SENDER_EVENT_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_SEGMENT_SENDER_STATUS_MESSAGE_IDS_SIZE 0
#define PHOTON_GC_MAIN_SEGMENT_SENDER_STATUS_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_SEGMENT_SENDER_STATUS_MESSAGE_PRIORITIES {}
#define PHOTON_GC_MAIN_SEGMENT_SENDER_STATUS_MESSAGE_ID_PRIORITIES {\
\
}

/* Command ID for component defines */

#define PHOTON_GC_MAIN_COMMAND_IDS_LEN 39
#define PHOTON_GC_MAIN_COMMAND_IDS {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38}
#define PHOTON_GC_MAIN_SCRIPTING_COMMAND_IDS_LEN 6
#define PHOTON_GC_MAIN_SCRIPTING_COMMAND_IDS {0, 1, 2, 3, 4, 5}
#define PHOTON_GC_MAIN_SEGMENT_COMMAND_IDS_LEN 6
#define PHOTON_GC_MAIN_SEGMENT_COMMAND_IDS {0, 1, 2, 3, 4, 5}
#define PHOTON_GC_MAIN_IDENTIFICATION_COMMAND_IDS_LEN 3
#define PHOTON_GC_MAIN_IDENTIFICATION_COMMAND_IDS {0, 1, 2}
#define PHOTON_GC_MAIN_TM_COMMAND_IDS_LEN 7
#define PHOTON_GC_MAIN_TM_COMMAND_IDS {0, 1, 2, 3, 4, 5, 6}
#define PHOTON_GC_MAIN_FILES_COMMAND_IDS_LEN 11
#define PHOTON_GC_MAIN_FILES_COMMAND_IDS {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
#define PHOTON_GC_MAIN_SEGMENT_RECEIVER_COMMAND_IDS_LEN 7
#define PHOTON_GC_MAIN_SEGMENT_RECEIVER_COMMAND_IDS {0, 1, 2, 3, 4, 5, 6}
#define PHOTON_GC_MAIN_ROUTER_COMMAND_IDS_LEN 4
#define PHOTON_GC_MAIN_ROUTER_COMMAND_IDS {0, 1, 2, 3}
#define PHOTON_GC_MAIN_SEGMENT_SENDER_COMMAND_IDS_LEN 7
#define PHOTON_GC_MAIN_SEGMENT_SENDER_COMMAND_IDS {0, 1, 2, 3, 4, 5, 6}

/* Implemented functions */

PhotonResult PhotonGcMain_ExecuteFilesStartFileUpload(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesUploadFilePart(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesStopFileUpload(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesStartFileDownload(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesDownloadFilePart(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesStopFileDownload(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesStartRequestFileList(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesRequestFileListPart(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesStopRequestFileList(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesDeleteNode(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesCreateDir(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteIdentificationRequestShortId(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteIdentificationRequestFullId(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteIdentificationRequestComponentGuid(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteRouterSetRoute(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteRouterDelRoute(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteRouterSetGroupRoute(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteRouterDelGroupRoute(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteScriptingUploadScript(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteScriptingDeleteScript(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteScriptingRunScriptNow(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteScriptingScheduleScriptRun(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteScriptingEnableScriptRunTiming(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteScriptingDisableScriptRunTiming(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteSegmentStartSegmentAckMode(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteSegmentStopSegmentAckMode(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteSegmentRequestAckModeStatus(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteSegmentProcessAckModeStatus(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteSegmentStartAckOnEverySegmentMode(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteSegmentStopAckOnEverySegmentMode(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteSegmentReceiverRequestSegmentsAck(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteSegmentSenderProcessSegmentsAck(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteTmSendStatusMessage(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteTmSetMessageRequest(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteTmClearMessageRequest(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteTmDenyMessage(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteTmAllowMessage(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteTmDenyEvent(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteTmAllowEvent(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_WriteFilesActiveMode(PhotonWriter* writer);
PhotonResult PhotonGcMain_WriteIdentificationFullId(PhotonWriter* writer);
PhotonResult PhotonGcMain_WriteIdentificationDeviceComponentNumbers(PhotonWriter* writer);
PhotonResult PhotonGcMain_WriteRouterNextHops(PhotonWriter* writer);
PhotonResult PhotonGcMain_WriteScriptingAvailableScripts(PhotonWriter* writer);
PhotonResult PhotonGcMain_WriteSegmentReceiverSegmentsReceived(PhotonWriter* writer);
PhotonResult PhotonGcMain_WriteFilesModeChanged(PhotonWriter* writer, PhotonGtFilesEvent event, PhotonGtFilesMode oldMode);
PhotonResult PhotonGcMain_ExecuteCommand(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId);
PhotonResult PhotonGcMain_ReadExecuteCommand(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_WriteStatusMessage(PhotonWriter* writer, PhotonBer messageId);
PhotonResult PhotonGcMain_ExecuteCommandForComponent(PhotonReader* reader, PhotonWriter* writer, PhotonBer componentId, PhotonBer commandId);
PhotonResult PhotonGcMain_ExecuteCommandForComponentSegment(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId);
PhotonResult PhotonGcMain_ExecuteCommandForComponentFiles(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId);
PhotonResult PhotonGcMain_ExecuteCommandForComponentSegmentSender(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId);
PhotonResult PhotonGcMain_ExecuteCommandForComponentSegmentReceiver(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId);
PhotonResult PhotonGcMain_ExecuteCommandForComponentScripting(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId);
PhotonResult PhotonGcMain_ExecuteCommandForComponentTm(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId);
PhotonResult PhotonGcMain_ExecuteCommandForComponentIdentification(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId);
PhotonResult PhotonGcMain_ExecuteCommandForComponentRouter(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId);
PhotonResult PhotonGcMain_ScriptingExecuteCommand(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId);
PhotonResult PhotonGcMain_ScriptingReadExecuteCommand(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ScriptingWriteMessage(PhotonWriter* writer, PhotonBer messageId);
PhotonResult PhotonGcMain_SegmentExecuteCommand(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId);
PhotonResult PhotonGcMain_SegmentReadExecuteCommand(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_SegmentWriteMessage(PhotonWriter* writer, PhotonBer messageId);
PhotonResult PhotonGcMain_IdentificationExecuteCommand(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId);
PhotonResult PhotonGcMain_IdentificationReadExecuteCommand(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_IdentificationWriteMessage(PhotonWriter* writer, PhotonBer messageId);
PhotonResult PhotonGcMain_TmExecuteCommand(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId);
PhotonResult PhotonGcMain_TmReadExecuteCommand(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_TmWriteMessage(PhotonWriter* writer, PhotonBer messageId);
PhotonResult PhotonGcMain_FilesExecuteCommand(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId);
PhotonResult PhotonGcMain_FilesReadExecuteCommand(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_FilesWriteMessage(PhotonWriter* writer, PhotonBer messageId);
PhotonResult PhotonGcMain_SegmentReceiverExecuteCommand(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId);
PhotonResult PhotonGcMain_SegmentReceiverReadExecuteCommand(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_SegmentReceiverWriteMessage(PhotonWriter* writer, PhotonBer messageId);
PhotonResult PhotonGcMain_RouterExecuteCommand(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId);
PhotonResult PhotonGcMain_RouterReadExecuteCommand(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_RouterWriteMessage(PhotonWriter* writer, PhotonBer messageId);
PhotonResult PhotonGcMain_SegmentSenderExecuteCommand(PhotonReader* reader, PhotonWriter* writer, PhotonBer commandId);
PhotonResult PhotonGcMain_SegmentSenderReadExecuteCommand(PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_SegmentSenderWriteMessage(PhotonWriter* writer, PhotonBer messageId);

#ifdef __cplusplus
}
#endif
#endif