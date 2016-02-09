
/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_PHOTON_GC_MAIN_H__
#define __PHOTON_PHOTON_GC_MAIN_H__ 
#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "photon/decode/PhotonGtOrArrNodeInfoFileListError.h"
#include "photon/foundation/PhotonGtGuid.h"
#include "photon/decode/PhotonGtArrBerMin1.h"
#include "photon/tm/PhotonGtTmCmdError.h"
#include "photon/foundation/PhotonGtB8.h"
#include "photon/decode/PhotonGtOrFileInfoFileDownloadError.h"
#include "photon/foundation/PhotonGtArrArrU8.h"
#include "photon/foundation/PhotonGtArrGuid.h"
#include "photon/scripting/PhotonGtScriptingError.h"
#include "photon/scripting/PhotonGtArrScriptRunTiming.h"
#include "photon/decode/PhotonGtOptionalFileCreateDirError.h"
#include "photon/fs/PhotonGtFileListError.h"
#include "photon/scripting/PhotonGtPeriod.h"
#include "photon/foundation/PhotonGtString.h"
#include "photon/decode/PhotonGtOptionalSegmentStopAckError.h"
#include "photon/scripting/PhotonGtScriptInfo.h"
#include "photon/tm/PhotonGtCompMsg.h"
#include "photon/foundation/PhotonGtArrU8.h"
#include "photon/identification/PhotonGtShortId.h"
#include "photon/tm/PhotonGtArrEventInfo.h"
#include "photon/decode/PhotonGtOptionalTmCmdError.h"
#include "photon/scripting/PhotonGtScriptId.h"
#include "photon/tm/PhotonGtRingBuf.h"
#include "photon/fs/PhotonGtFileDownloadError.h"
#include "photon/decode/PhotonGtOptionalSegmentProcessAckError.h"
#include "photon/scripting/PhotonGtScriptRunTiming.h"
#include "photon/fs/PhotonGtFileDeleteError.h"
#include "photon/scripting/PhotonGtArrScriptInfo.h"
#include "photon/fs/PhotonGtFileCreateDirError.h"
#include "photon/foundation/PhotonGtU8.h"
#include "photon/routing/PhotonGtArrRoute.h"
#include "photon/identification/PhotonGtFullId.h"
#include "photon/segmentation/PhotonGtSegmentProcessAckError.h"
#include "photon/decode/PhotonGtOptionalScriptingError.h"
#include "photon/decode/PhotonGtOptionalFileDeleteError.h"
#include "photon/tm/PhotonGtEventInfo.h"
#include "photon/identification/PhotonGtComponentNumberGuidPair.h"
#include "photon/routing/PhotonGtAddress.h"
#include "photon/routing/PhotonGtRoute.h"
#include "photon/identification/PhotonGtArrComponentNumberGuidPairMin1.h"
#include "photon/segmentation/PhotonGtSegmentStartAckError.h"
#include "photon/scripting/PhotonGtDateTime.h"
#include "photon/fs/PhotonGtFileInfo.h"
#include "photon/fs/PhotonGtFileUploadError.h"
#include "photon/fs/PhotonGtNodeInfo.h"
#include "photon/fs/PhotonGtArrNodeInfo.h"
#include "photon/decode/PhotonGtOptionalFileUploadError.h"
#include "photon/decode/PhotonGtOptionalSegmentStartAckError.h"
#include "photon/segmentation/PhotonGtSegmentStopAckError.h"
#include "photon/decode/PhotonGtArrBer.h"

/* USER command implementation functions, MUST BE defined */

PhotonGtOptionalFileUploadError PhotonGcMain_FilesStartFileUpload(PhotonGcMain* self, PhotonGtFileInfo* fileInfo);
PhotonGtOptionalFileUploadError PhotonGcMain_FilesUploadFile(PhotonGcMain* self, PhotonGtFileInfo* fileInfo);
PhotonGtOrFileInfoFileDownloadError PhotonGcMain_FilesDownloadFile(PhotonGcMain* self, PhotonGtString* path);
PhotonGtOptionalFileDeleteError PhotonGcMain_FilesDeleteNode(PhotonGcMain* self, PhotonGtString* path);
PhotonGtOrArrNodeInfoFileListError PhotonGcMain_FilesRequestFileList(PhotonGcMain* self, PhotonGtString* path);
PhotonGtOptionalFileCreateDirError PhotonGcMain_FilesCreateDir(PhotonGcMain* self, PhotonGtString* path);
void PhotonGcMain_RouterSetRoute(PhotonGcMain* self, PhotonGtAddress address, PhotonGtAddress next_hop);
void PhotonGcMain_RouterDelRoute(PhotonGcMain* self, PhotonGtAddress address);
void PhotonGcMain_RouterSetGroupRoute(PhotonGcMain* self, PhotonGtAddress groupAddress, PhotonGtAddress next_hop);
void PhotonGcMain_RouterDelGroupRoute(PhotonGcMain* self, PhotonGtAddress groupAddress);
PhotonGtShortId PhotonGcMain_IdentificationRequestShortId(PhotonGcMain* self);
PhotonGtFullId PhotonGcMain_IdentificationRequestFullId(PhotonGcMain* self);
PhotonGtGuid PhotonGcMain_IdentificationRequestComponentGuid(PhotonGcMain* self, PhotonBer componentNumber);
PhotonGtOptionalScriptingError PhotonGcMain_ScriptingUploadScript(PhotonGcMain* self, PhotonGtScriptId scriptId, PhotonGtArrU8* scriptData, PhotonGtArrU8* scriptCode);
PhotonGtOptionalScriptingError PhotonGcMain_ScriptingDeleteScript(PhotonGcMain* self, PhotonGtScriptId scriptId);
PhotonGtOptionalScriptingError PhotonGcMain_ScriptingRunScriptNow(PhotonGcMain* self, PhotonGtScriptId scriptId);
PhotonGtOptionalScriptingError PhotonGcMain_ScriptingScheduleScriptRun(PhotonGcMain* self, PhotonGtScriptRunTiming* scriptRunTiming);
PhotonGtOptionalScriptingError PhotonGcMain_ScriptingEnableScriptRunTiming(PhotonGcMain* self, PhotonGtGuid scriptRunTimingId);
PhotonGtOptionalScriptingError PhotonGcMain_ScriptingDisableScriptRunTiming(PhotonGcMain* self, PhotonGtGuid scriptRunTimingId);
PhotonGtOptionalSegmentStartAckError PhotonGcMain_SegmentStartSegmentAckMode(PhotonGcMain* self);
PhotonGtOptionalSegmentStopAckError PhotonGcMain_SegmentStopSegmentAckMode(PhotonGcMain* self);
PhotonGtB8 PhotonGcMain_SegmentRequestAckModeStatus(PhotonGcMain* self);
PhotonGtOptionalSegmentProcessAckError PhotonGcMain_SegmentProcessAckModeStatus(PhotonGcMain* self, PhotonGtB8 isSegmentationAckModeActive);
PhotonGtOptionalSegmentStartAckError PhotonGcMain_SegmentStartAckOnEverySegmentMode(PhotonGcMain* self);
PhotonGtOptionalSegmentStopAckError PhotonGcMain_SegmentStopAckOnEverySegmentMode(PhotonGcMain* self);
PhotonGtOptionalTmCmdError PhotonGcMain_TmSendEventMessage(PhotonGcMain* self, PhotonGtEventInfo* eventInfo);
PhotonGtOptionalTmCmdError PhotonGcMain_TmSendStatusMessage(PhotonGcMain* self, PhotonGtCompMsg* componentMessage);
PhotonGtOptionalTmCmdError PhotonGcMain_TmSetMessageRequest(PhotonGcMain* self, PhotonGtCompMsg* componentMessage, PhotonBer priority);
PhotonGtOptionalTmCmdError PhotonGcMain_TmClearMessageRequest(PhotonGcMain* self, PhotonGtCompMsg* componentMessage, PhotonBer priority);
PhotonGtOptionalTmCmdError PhotonGcMain_TmDenyMessage(PhotonGcMain* self, PhotonGtCompMsg* componentMessage);
PhotonGtOptionalTmCmdError PhotonGcMain_TmAllowMessage(PhotonGcMain* self, PhotonGtCompMsg* componentMessage);
PhotonGtOptionalTmCmdError PhotonGcMain_TmDenyEvent(PhotonGcMain* self, PhotonGtEventInfo* eventInfo);
PhotonGtOptionalTmCmdError PhotonGcMain_TmAllowEvent(PhotonGcMain* self, PhotonGtEventInfo* eventInfo);
PhotonGtArrBer PhotonGcMain_SegmentReceiverRequestSegmentsAck(PhotonGcMain* self);
PhotonGtOptionalSegmentProcessAckError PhotonGcMain_SegmentSenderProcessSegmentsAck(PhotonGcMain* self, PhotonGtArrBerMin1* segmentsReceived);

/* USER parameter implementation functions, MUST BE defined */

const PhotonGtArrRoute* PhotonGcMain_RouterRoutes(PhotonGcMain* self);
const PhotonGtArrRoute* PhotonGcMain_RouterGroupRoutes(PhotonGcMain* self);
const PhotonGtFullId* PhotonGcMain_IdentificationFullId(PhotonGcMain* self);
const PhotonGtArrGuid* PhotonGcMain_ScriptingScriptsIds(PhotonGcMain* self);
const PhotonGtArrScriptInfo* PhotonGcMain_ScriptingScripts(PhotonGcMain* self);
const PhotonGtArrScriptRunTiming* PhotonGcMain_ScriptingScriptsRunTimings(PhotonGcMain* self);
const PhotonGtB8* PhotonGcMain_SegmentIsSegmentationAckModeActive(PhotonGcMain* self);
const PhotonBer* PhotonGcMain_SegmentMaxSegmentNumber(PhotonGcMain* self);
const PhotonGtB8* PhotonGcMain_SegmentIsAckOnEverySegmentModeActive(PhotonGcMain* self);
const PhotonGtArrU8* PhotonGcMain_TmOnceRequests(PhotonGcMain* self);
const PhotonGtArrArrU8* PhotonGcMain_TmDeniedMessagesByComponent(PhotonGcMain* self);
const PhotonGtArrArrU8* PhotonGcMain_TmPriorityOrderedRequests(PhotonGcMain* self);
const PhotonGtRingBuf* PhotonGcMain_TmOutOfOrderMesages(PhotonGcMain* self);
const PhotonGtArrEventInfo* PhotonGcMain_TmLostEvents(PhotonGcMain* self);
const PhotonGtArrBer* PhotonGcMain_SegmentReceiverSegmentsReceived(PhotonGcMain* self);

/* Message ID for component defines */

#define PHOTON_GC_MAIN_MESSAGE_IDS_LEN 4
#define PHOTON_GC_MAIN_MESSAGE_IDS {0, 1, 2, 3}
#define PHOTON_GC_MAIN_MESSAGE_PRIORITIES {10, 0, 0, 0}
#define PHOTON_GC_MAIN_FILES_MESSAGE_IDS_LEN 0
#define PHOTON_GC_MAIN_FILES_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_FILES_MESSAGE_PRIORITIES {}
#define PHOTON_GC_MAIN_ROUTER_MESSAGE_IDS_LEN 0
#define PHOTON_GC_MAIN_ROUTER_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_ROUTER_MESSAGE_PRIORITIES {}
#define PHOTON_GC_MAIN_IDENTIFICATION_MESSAGE_IDS_LEN 1
#define PHOTON_GC_MAIN_IDENTIFICATION_MESSAGE_IDS {0}
#define PHOTON_GC_MAIN_IDENTIFICATION_MESSAGE_PRIORITIES {10}
#define PHOTON_GC_MAIN_SCRIPTING_MESSAGE_IDS_LEN 2
#define PHOTON_GC_MAIN_SCRIPTING_MESSAGE_IDS {0, 1}
#define PHOTON_GC_MAIN_SCRIPTING_MESSAGE_PRIORITIES {0, 0}
#define PHOTON_GC_MAIN_SEGMENT_MESSAGE_IDS_LEN 0
#define PHOTON_GC_MAIN_SEGMENT_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_SEGMENT_MESSAGE_PRIORITIES {}
#define PHOTON_GC_MAIN_TM_MESSAGE_IDS_LEN 0
#define PHOTON_GC_MAIN_TM_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_TM_MESSAGE_PRIORITIES {}
#define PHOTON_GC_MAIN_SEGMENT_RECEIVER_MESSAGE_IDS_LEN 1
#define PHOTON_GC_MAIN_SEGMENT_RECEIVER_MESSAGE_IDS {0}
#define PHOTON_GC_MAIN_SEGMENT_RECEIVER_MESSAGE_PRIORITIES {0}
#define PHOTON_GC_MAIN_SEGMENT_SENDER_MESSAGE_IDS_LEN 0
#define PHOTON_GC_MAIN_SEGMENT_SENDER_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_SEGMENT_SENDER_MESSAGE_PRIORITIES {}

/* Command ID for component defines */

#define PHOTON_GC_MAIN_COMMAND_IDS_LEN 35
#define PHOTON_GC_MAIN_COMMAND_IDS {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34}
#define PHOTON_GC_MAIN_FILES_COMMAND_IDS_LEN 6
#define PHOTON_GC_MAIN_FILES_COMMAND_IDS {0, 1, 2, 3, 4, 5}
#define PHOTON_GC_MAIN_ROUTER_COMMAND_IDS_LEN 4
#define PHOTON_GC_MAIN_ROUTER_COMMAND_IDS {0, 1, 2, 3}
#define PHOTON_GC_MAIN_IDENTIFICATION_COMMAND_IDS_LEN 3
#define PHOTON_GC_MAIN_IDENTIFICATION_COMMAND_IDS {0, 1, 2}
#define PHOTON_GC_MAIN_SCRIPTING_COMMAND_IDS_LEN 6
#define PHOTON_GC_MAIN_SCRIPTING_COMMAND_IDS {0, 1, 2, 3, 4, 5}
#define PHOTON_GC_MAIN_SEGMENT_COMMAND_IDS_LEN 6
#define PHOTON_GC_MAIN_SEGMENT_COMMAND_IDS {0, 1, 2, 3, 4, 5}
#define PHOTON_GC_MAIN_TM_COMMAND_IDS_LEN 8
#define PHOTON_GC_MAIN_TM_COMMAND_IDS {0, 1, 2, 3, 4, 5, 6, 7}
#define PHOTON_GC_MAIN_SEGMENT_RECEIVER_COMMAND_IDS_LEN 7
#define PHOTON_GC_MAIN_SEGMENT_RECEIVER_COMMAND_IDS {0, 1, 2, 3, 4, 5, 6}
#define PHOTON_GC_MAIN_SEGMENT_SENDER_COMMAND_IDS_LEN 7
#define PHOTON_GC_MAIN_SEGMENT_SENDER_COMMAND_IDS {0, 1, 2, 3, 4, 5, 6}

/* Implemented functions */

PhotonResult PhotonGcMain_ExecuteFilesStartFileUpload(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesUploadFile(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesDownloadFile(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesDeleteNode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesRequestFileList(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesCreateDir(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteIdentificationRequestShortId(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteIdentificationRequestFullId(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteIdentificationRequestComponentGuid(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteRouterSetRoute(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteRouterDelRoute(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteRouterSetGroupRoute(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteRouterDelGroupRoute(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteScriptingUploadScript(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteScriptingDeleteScript(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteScriptingRunScriptNow(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteScriptingScheduleScriptRun(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteScriptingEnableScriptRunTiming(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteScriptingDisableScriptRunTiming(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteSegmentStartSegmentAckMode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteSegmentStopSegmentAckMode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteSegmentRequestAckModeStatus(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteSegmentProcessAckModeStatus(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteSegmentStartAckOnEverySegmentMode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteSegmentStopAckOnEverySegmentMode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteSegmentReceiverRequestSegmentsAck(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteSegmentSenderProcessSegmentsAck(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteTmSendEventMessage(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteTmSendStatusMessage(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteTmSetMessageRequest(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteTmClearMessageRequest(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteTmDenyMessage(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteTmAllowMessage(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteTmDenyEvent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteTmAllowEvent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_WriteIdentificationFullId(PhotonGcMain* self, PhotonWriter* writer);
PhotonResult PhotonGcMain_WriteScriptingAvailableScriptsIds(PhotonGcMain* self, PhotonWriter* writer);
PhotonResult PhotonGcMain_WriteScriptingScriptsRunTimings(PhotonGcMain* self, PhotonWriter* writer);
PhotonResult PhotonGcMain_WriteSegmentReceiverSegmentsReceived(PhotonGcMain* self, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcMain_ReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_WriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcMain_IsStatusMessage(size_t messageId);
PhotonResult PhotonGcMain_TmExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId);
PhotonResult PhotonGcMain_SegmentSenderExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId);
PhotonResult PhotonGcMain_IdentificationExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId);
PhotonResult PhotonGcMain_RouterExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId);
PhotonResult PhotonGcMain_FilesExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId);
PhotonResult PhotonGcMain_SegmentExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId);
PhotonResult PhotonGcMain_ScriptingExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId);
PhotonResult PhotonGcMain_SegmentReceiverExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId);
PhotonResult PhotonGcMain_FilesExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcMain_FilesReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_FilesWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcFiles_IsStatusMessage(size_t messageId);
PhotonResult PhotonGcMain_RouterExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcMain_RouterReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_RouterWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcRouter_IsStatusMessage(size_t messageId);
PhotonResult PhotonGcMain_IdentificationExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcMain_IdentificationReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_IdentificationWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcIdentification_IsStatusMessage(size_t messageId);
PhotonResult PhotonGcMain_ScriptingExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcMain_ScriptingReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ScriptingWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcScripting_IsStatusMessage(size_t messageId);
PhotonResult PhotonGcMain_SegmentExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcMain_SegmentReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_SegmentWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcSegment_IsStatusMessage(size_t messageId);
PhotonResult PhotonGcMain_TmExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcMain_TmReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_TmWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcTm_IsStatusMessage(size_t messageId);
PhotonResult PhotonGcMain_SegmentReceiverExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcMain_SegmentReceiverReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_SegmentReceiverWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcSegmentReceiver_IsStatusMessage(size_t messageId);
PhotonResult PhotonGcMain_SegmentSenderExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcMain_SegmentSenderReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_SegmentSenderWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcSegmentSender_IsStatusMessage(size_t messageId);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"

#endif