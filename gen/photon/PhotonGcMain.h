
/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_PHOTON_GC_MAIN_H__
#define __PHOTON_PHOTON_GC_MAIN_H__ 
#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "photon/foundation/PhotonGtArrGuid.h"
#include "photon/decode/PhotonGtOptionalFileUploadError.h"
#include "photon/fs/PhotonGtFileDeleteError.h"
#include "photon/scripting/PhotonGtScriptInfo.h"
#include "photon/decode/PhotonGtArrBer.h"
#include "photon/decode/PhotonGtOptionalSegmentStopAckError.h"
#include "photon/fs/PhotonGtFileDownloadError.h"
#include "photon/fs/PhotonGtFileInfo.h"
#include "photon/scripting/PhotonGtDateTime.h"
#include "photon/tm/PhotonGtArrEventInfo.h"
#include "photon/decode/PhotonGtOrBerFileListError.h"
#include "photon/foundation/PhotonGtArrArrU8.h"
#include "photon/fs/PhotonGtNodeInfo.h"
#include "photon/decode/PhotonGtOrArrU8FileDownloadError.h"
#include "photon/decode/PhotonGtOptionalTmCmdError.h"
#include "photon/segmentation/PhotonGtSegmentStopAckError.h"
#include "photon/tm/PhotonGtEventInfo.h"
#include "photon/decode/PhotonGtOptionalScriptingError.h"
#include "photon/identification/PhotonGtShortId.h"
#include "photon/decode/PhotonGtOptionalFileDeleteError.h"
#include "photon/scripting/PhotonGtPeriod.h"
#include "photon/scripting/PhotonGtScriptingError.h"
#include "photon/fs/PhotonGtFilesMode.h"
#include "photon/scripting/PhotonGtScriptId.h"
#include "photon/identification/PhotonGtComponentNumberGuidPair.h"
#include "photon/foundation/PhotonGtU8.h"
#include "photon/foundation/PhotonGtString.h"
#include "photon/routing/PhotonGtRoute.h"
#include "photon/routing/PhotonGtArrRoute.h"
#include "photon/decode/PhotonGtOptionalSegmentProcessAckError.h"
#include "photon/tm/PhotonGtCompMsg.h"
#include "photon/fs/PhotonGtFileUploadError.h"
#include "photon/tm/PhotonGtRingBuf.h"
#include "photon/foundation/PhotonGtB8.h"
#include "photon/decode/PhotonGtOrArrNodeInfoFileListError.h"
#include "photon/decode/PhotonGtOptionalFileDownloadError.h"
#include "photon/segmentation/PhotonGtSegmentProcessAckError.h"
#include "photon/decode/PhotonGtOptionalFileListError.h"
#include "photon/identification/PhotonGtFullId.h"
#include "photon/foundation/PhotonGtGuid.h"
#include "photon/fs/PhotonGtFileCreateDirError.h"
#include "photon/fs/PhotonGtArrNodeInfo.h"
#include "photon/fs/PhotonGtFileListError.h"
#include "photon/decode/PhotonGtOptionalFileCreateDirError.h"
#include "photon/identification/PhotonGtArrComponentNumberGuidPairMin1.h"
#include "photon/decode/PhotonGtArrBerMin1.h"
#include "photon/tm/PhotonGtTmCmdError.h"
#include "photon/scripting/PhotonGtArrScriptRunTiming.h"
#include "photon/decode/PhotonGtOrFileInfoFileDownloadError.h"
#include "photon/foundation/PhotonGtArrU8.h"
#include "photon/segmentation/PhotonGtSegmentStartAckError.h"
#include "photon/routing/PhotonGtAddress.h"
#include "photon/decode/PhotonGtOptionalSegmentStartAckError.h"
#include "photon/scripting/PhotonGtArrScriptInfo.h"
#include "photon/scripting/PhotonGtScriptRunTiming.h"

/* USER command implementation functions, MUST BE defined */

PhotonGtOptionalFileUploadError PhotonGcMain_FilesStartFileUpload(PhotonGcMain* self, PhotonGtFileInfo* fileInfo);
PhotonGtOptionalFileUploadError PhotonGcMain_FilesUploadFilePart(PhotonGcMain* self, PhotonGtArrU8* fileContentsPart);
PhotonGtOptionalFileUploadError PhotonGcMain_FilesStopFileUpload(PhotonGcMain* self);
const PhotonGtOrFileInfoFileDownloadError* PhotonGcMain_FilesStartFileDownload(PhotonGcMain* self, PhotonGtString* path);
const PhotonGtOrArrU8FileDownloadError* PhotonGcMain_FilesDownloadFilePart(PhotonGcMain* self, PhotonBer byteSize);
PhotonGtOptionalFileDownloadError PhotonGcMain_FilesStopFileDownload(PhotonGcMain* self);
PhotonGtOrBerFileListError PhotonGcMain_FilesStartRequestFileList(PhotonGcMain* self);
const PhotonGtOrArrNodeInfoFileListError* PhotonGcMain_FilesRequestFileListPart(PhotonGcMain* self, PhotonBer nodeSize);
PhotonGtOptionalFileListError PhotonGcMain_FilesStopRequestFileList(PhotonGcMain* self);
PhotonGtOptionalFileDeleteError PhotonGcMain_FilesDeleteNode(PhotonGcMain* self, PhotonGtString* path);
PhotonGtOptionalFileCreateDirError PhotonGcMain_FilesCreateDir(PhotonGcMain* self, PhotonGtString* path);
PhotonGtOptionalTmCmdError PhotonGcMain_TmSendEventMessage(PhotonGcMain* self, PhotonGtEventInfo* eventInfo);
PhotonGtOptionalTmCmdError PhotonGcMain_TmSendStatusMessage(PhotonGcMain* self, PhotonGtCompMsg componentMessage);
PhotonGtOptionalTmCmdError PhotonGcMain_TmSetMessageRequest(PhotonGcMain* self, PhotonGtCompMsg componentMessage, PhotonBer priority);
PhotonGtOptionalTmCmdError PhotonGcMain_TmClearMessageRequest(PhotonGcMain* self, PhotonGtCompMsg componentMessage, PhotonBer priority);
PhotonGtOptionalTmCmdError PhotonGcMain_TmDenyMessage(PhotonGcMain* self, PhotonGtCompMsg componentMessage);
PhotonGtOptionalTmCmdError PhotonGcMain_TmAllowMessage(PhotonGcMain* self, PhotonGtCompMsg componentMessage);
PhotonGtOptionalTmCmdError PhotonGcMain_TmDenyEvent(PhotonGcMain* self, PhotonGtEventInfo* eventInfo);
PhotonGtOptionalTmCmdError PhotonGcMain_TmAllowEvent(PhotonGcMain* self, PhotonGtEventInfo* eventInfo);
PhotonGtOptionalSegmentProcessAckError PhotonGcMain_SegmentSenderProcessSegmentsAck(PhotonGcMain* self, PhotonGtArrBerMin1* segmentsReceived);
PhotonGtOptionalScriptingError PhotonGcMain_ScriptingUploadScript(PhotonGcMain* self, PhotonGtScriptId scriptId, PhotonGtArrU8* scriptData, PhotonGtArrU8* scriptCode);
PhotonGtOptionalScriptingError PhotonGcMain_ScriptingDeleteScript(PhotonGcMain* self, PhotonGtScriptId scriptId);
PhotonGtOptionalScriptingError PhotonGcMain_ScriptingRunScriptNow(PhotonGcMain* self, PhotonGtScriptId scriptId);
PhotonGtOptionalScriptingError PhotonGcMain_ScriptingScheduleScriptRun(PhotonGcMain* self, PhotonGtScriptRunTiming* scriptRunTiming);
PhotonGtOptionalScriptingError PhotonGcMain_ScriptingEnableScriptRunTiming(PhotonGcMain* self, PhotonGtGuid scriptRunTimingId);
PhotonGtOptionalScriptingError PhotonGcMain_ScriptingDisableScriptRunTiming(PhotonGcMain* self, PhotonGtGuid scriptRunTimingId);
const PhotonGtArrBer* PhotonGcMain_SegmentReceiverRequestSegmentsAck(PhotonGcMain* self);
void PhotonGcMain_RouterSetRoute(PhotonGcMain* self, PhotonGtAddress address, PhotonGtAddress next_hop);
void PhotonGcMain_RouterDelRoute(PhotonGcMain* self, PhotonGtAddress address);
void PhotonGcMain_RouterSetGroupRoute(PhotonGcMain* self, PhotonGtAddress groupAddress, PhotonGtAddress next_hop);
void PhotonGcMain_RouterDelGroupRoute(PhotonGcMain* self, PhotonGtAddress groupAddress);
PhotonGtShortId PhotonGcMain_IdentificationRequestShortId(PhotonGcMain* self);
const PhotonGtFullId* PhotonGcMain_IdentificationRequestFullId(PhotonGcMain* self);
PhotonGtGuid PhotonGcMain_IdentificationRequestComponentGuid(PhotonGcMain* self, PhotonBer componentNumber);
PhotonGtOptionalSegmentStartAckError PhotonGcMain_SegmentStartSegmentAckMode(PhotonGcMain* self);
PhotonGtOptionalSegmentStopAckError PhotonGcMain_SegmentStopSegmentAckMode(PhotonGcMain* self);
PhotonGtB8 PhotonGcMain_SegmentRequestAckModeStatus(PhotonGcMain* self);
PhotonGtOptionalSegmentProcessAckError PhotonGcMain_SegmentProcessAckModeStatus(PhotonGcMain* self, PhotonGtB8 isSegmentationAckModeActive);
PhotonGtOptionalSegmentStartAckError PhotonGcMain_SegmentStartAckOnEverySegmentMode(PhotonGcMain* self);
PhotonGtOptionalSegmentStopAckError PhotonGcMain_SegmentStopAckOnEverySegmentMode(PhotonGcMain* self);

/* USER parameter implementation functions, MUST BE defined */

PhotonGtFilesMode PhotonGcMain_FilesActiveMode(PhotonGcMain* self);
const PhotonGtArrU8* PhotonGcMain_TmOnceRequests(PhotonGcMain* self);
const PhotonGtArrArrU8* PhotonGcMain_TmDeniedMessagesByComponent(PhotonGcMain* self);
const PhotonGtArrArrU8* PhotonGcMain_TmPriorityOrderedRequests(PhotonGcMain* self);
const PhotonGtRingBuf* PhotonGcMain_TmOutOfOrderMesages(PhotonGcMain* self);
const PhotonGtArrEventInfo* PhotonGcMain_TmLostEvents(PhotonGcMain* self);
const PhotonGtArrGuid* PhotonGcMain_ScriptingScriptsIds(PhotonGcMain* self);
const PhotonGtArrScriptInfo* PhotonGcMain_ScriptingScripts(PhotonGcMain* self);
const PhotonGtArrScriptRunTiming* PhotonGcMain_ScriptingScriptsRunTimings(PhotonGcMain* self);
const PhotonGtArrBer* PhotonGcMain_SegmentReceiverSegmentsReceived(PhotonGcMain* self);
const PhotonGtArrRoute* PhotonGcMain_RouterRoutes(PhotonGcMain* self);
const PhotonGtArrRoute* PhotonGcMain_RouterGroupRoutes(PhotonGcMain* self);
const PhotonGtFullId* PhotonGcMain_IdentificationFullId(PhotonGcMain* self);
PhotonGtB8 PhotonGcMain_SegmentIsSegmentationAckModeActive(PhotonGcMain* self);
PhotonBer PhotonGcMain_SegmentMaxSegmentNumber(PhotonGcMain* self);
PhotonGtB8 PhotonGcMain_SegmentIsAckOnEverySegmentModeActive(PhotonGcMain* self);

/* Component defines */

#define PHOTON_COMPONENTS 9
#define PHOTON_COMPONENT_IDS {0, 5, 1, 6, 2, 7, 3, 8, 4}
#define PHOTON_GC_MAIN_GUID "ru.mipt.acsl.photon.Main"
#define PHOTON_COMPONENT_0_GUID PHOTON_GC_MAIN_GUID
#define PHOTON_GC_MAIN_ID 0
#define PHOTON_GC_SEGMENT_RECEIVER_GUID "ru.mipt.acsl.segmentation.SegmentReceiver"
#define PHOTON_COMPONENT_5_GUID PHOTON_GC_SEGMENT_RECEIVER_GUID
#define PHOTON_GC_SEGMENT_RECEIVER_ID 5
#define PHOTON_GC_FILES_GUID "ru.mipt.acsl.fs.Files"
#define PHOTON_COMPONENT_1_GUID PHOTON_GC_FILES_GUID
#define PHOTON_GC_FILES_ID 1
#define PHOTON_GC_ROUTER_GUID "ru.mipt.acsl.routing.Router"
#define PHOTON_COMPONENT_6_GUID PHOTON_GC_ROUTER_GUID
#define PHOTON_GC_ROUTER_ID 6
#define PHOTON_GC_TM_GUID "ru.mipt.acsl.tm.Tm"
#define PHOTON_COMPONENT_2_GUID PHOTON_GC_TM_GUID
#define PHOTON_GC_TM_ID 2
#define PHOTON_GC_IDENTIFICATION_GUID "ru.mipt.acsl.identification.Identification"
#define PHOTON_COMPONENT_7_GUID PHOTON_GC_IDENTIFICATION_GUID
#define PHOTON_GC_IDENTIFICATION_ID 7
#define PHOTON_GC_SEGMENT_SENDER_GUID "ru.mipt.acsl.segmentation.SegmentSender"
#define PHOTON_COMPONENT_3_GUID PHOTON_GC_SEGMENT_SENDER_GUID
#define PHOTON_GC_SEGMENT_SENDER_ID 3
#define PHOTON_GC_SEGMENT_GUID "ru.mipt.acsl.segmentation.Segment"
#define PHOTON_COMPONENT_8_GUID PHOTON_GC_SEGMENT_GUID
#define PHOTON_GC_SEGMENT_ID 8
#define PHOTON_GC_SCRIPTING_GUID "ru.mipt.acsl.scripting.Scripting"
#define PHOTON_COMPONENT_4_GUID PHOTON_GC_SCRIPTING_GUID
#define PHOTON_GC_SCRIPTING_ID 4

/* Message ID for component defines */

#define PHOTON_GC_MAIN_MESSAGE_IDS_LEN 5
#define PHOTON_GC_MAIN_MESSAGE_IDS {0, 1, 2, 3, 4}
#define PHOTON_GC_MAIN_MESSAGE_PRIORITIES {0, 10, 0, 0, 0}
#define PHOTON_GC_MAIN_FILES_MESSAGE_IDS_LEN 1
#define PHOTON_GC_MAIN_FILES_MESSAGE_IDS {0}
#define PHOTON_GC_MAIN_FILES_MESSAGE_PRIORITIES {0}
#define PHOTON_GC_MAIN_TM_MESSAGE_IDS_LEN 0
#define PHOTON_GC_MAIN_TM_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_TM_MESSAGE_PRIORITIES {}
#define PHOTON_GC_MAIN_SEGMENT_SENDER_MESSAGE_IDS_LEN 0
#define PHOTON_GC_MAIN_SEGMENT_SENDER_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_SEGMENT_SENDER_MESSAGE_PRIORITIES {}
#define PHOTON_GC_MAIN_SCRIPTING_MESSAGE_IDS_LEN 2
#define PHOTON_GC_MAIN_SCRIPTING_MESSAGE_IDS {0, 1}
#define PHOTON_GC_MAIN_SCRIPTING_MESSAGE_PRIORITIES {0, 0}
#define PHOTON_GC_MAIN_SEGMENT_RECEIVER_MESSAGE_IDS_LEN 1
#define PHOTON_GC_MAIN_SEGMENT_RECEIVER_MESSAGE_IDS {0}
#define PHOTON_GC_MAIN_SEGMENT_RECEIVER_MESSAGE_PRIORITIES {0}
#define PHOTON_GC_MAIN_ROUTER_MESSAGE_IDS_LEN 0
#define PHOTON_GC_MAIN_ROUTER_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_ROUTER_MESSAGE_PRIORITIES {}
#define PHOTON_GC_MAIN_IDENTIFICATION_MESSAGE_IDS_LEN 1
#define PHOTON_GC_MAIN_IDENTIFICATION_MESSAGE_IDS {0}
#define PHOTON_GC_MAIN_IDENTIFICATION_MESSAGE_PRIORITIES {10}
#define PHOTON_GC_MAIN_SEGMENT_MESSAGE_IDS_LEN 0
#define PHOTON_GC_MAIN_SEGMENT_MESSAGE_IDS {}
#define PHOTON_GC_MAIN_SEGMENT_MESSAGE_PRIORITIES {}

/* Command ID for component defines */

#define PHOTON_GC_MAIN_COMMAND_IDS_LEN 40
#define PHOTON_GC_MAIN_COMMAND_IDS {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39}
#define PHOTON_GC_MAIN_FILES_COMMAND_IDS_LEN 11
#define PHOTON_GC_MAIN_FILES_COMMAND_IDS {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
#define PHOTON_GC_MAIN_TM_COMMAND_IDS_LEN 8
#define PHOTON_GC_MAIN_TM_COMMAND_IDS {0, 1, 2, 3, 4, 5, 6, 7}
#define PHOTON_GC_MAIN_SEGMENT_SENDER_COMMAND_IDS_LEN 7
#define PHOTON_GC_MAIN_SEGMENT_SENDER_COMMAND_IDS {0, 1, 2, 3, 4, 5, 6}
#define PHOTON_GC_MAIN_SCRIPTING_COMMAND_IDS_LEN 6
#define PHOTON_GC_MAIN_SCRIPTING_COMMAND_IDS {0, 1, 2, 3, 4, 5}
#define PHOTON_GC_MAIN_SEGMENT_RECEIVER_COMMAND_IDS_LEN 7
#define PHOTON_GC_MAIN_SEGMENT_RECEIVER_COMMAND_IDS {0, 1, 2, 3, 4, 5, 6}
#define PHOTON_GC_MAIN_ROUTER_COMMAND_IDS_LEN 4
#define PHOTON_GC_MAIN_ROUTER_COMMAND_IDS {0, 1, 2, 3}
#define PHOTON_GC_MAIN_IDENTIFICATION_COMMAND_IDS_LEN 3
#define PHOTON_GC_MAIN_IDENTIFICATION_COMMAND_IDS {0, 1, 2}
#define PHOTON_GC_MAIN_SEGMENT_COMMAND_IDS_LEN 6
#define PHOTON_GC_MAIN_SEGMENT_COMMAND_IDS {0, 1, 2, 3, 4, 5}

/* Implemented functions */

PhotonResult PhotonGcMain_ExecuteFilesStartFileUpload(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesUploadFilePart(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesStopFileUpload(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesStartFileDownload(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesDownloadFilePart(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesStopFileDownload(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesStartRequestFileList(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesRequestFileListPart(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesStopRequestFileList(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteFilesDeleteNode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
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
PhotonResult PhotonGcMain_WriteFilesActiveMode(PhotonGcMain* self, PhotonWriter* writer);
PhotonResult PhotonGcMain_WriteIdentificationFullId(PhotonGcMain* self, PhotonWriter* writer);
PhotonResult PhotonGcMain_WriteScriptingAvailableScriptsIds(PhotonGcMain* self, PhotonWriter* writer);
PhotonResult PhotonGcMain_WriteScriptingScriptsRunTimings(PhotonGcMain* self, PhotonWriter* writer);
PhotonResult PhotonGcMain_WriteSegmentReceiverSegmentsReceived(PhotonGcMain* self, PhotonWriter* writer);
PhotonResult PhotonGcMain_ExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcMain_ReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_WriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcMain_IsStatusMessage(size_t messageId);
PhotonResult PhotonGcMain_FilesExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId);
PhotonResult PhotonGcMain_SegmentExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId);
PhotonResult PhotonGcMain_SegmentReceiverExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId);
PhotonResult PhotonGcMain_SegmentSenderExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId);
PhotonResult PhotonGcMain_IdentificationExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId);
PhotonResult PhotonGcMain_RouterExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId);
PhotonResult PhotonGcMain_TmExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId);
PhotonResult PhotonGcMain_ScriptingExecuteCommandForComponent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t componentId, size_t commandId);
PhotonResult PhotonGcMain_FilesExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcMain_FilesReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_FilesWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcFiles_IsStatusMessage(size_t messageId);
PhotonResult PhotonGcMain_TmExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcMain_TmReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_TmWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcTm_IsStatusMessage(size_t messageId);
PhotonResult PhotonGcMain_SegmentSenderExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcMain_SegmentSenderReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_SegmentSenderWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcSegmentSender_IsStatusMessage(size_t messageId);
PhotonResult PhotonGcMain_ScriptingExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcMain_ScriptingReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ScriptingWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcScripting_IsStatusMessage(size_t messageId);
PhotonResult PhotonGcMain_SegmentReceiverExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcMain_SegmentReceiverReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_SegmentReceiverWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcSegmentReceiver_IsStatusMessage(size_t messageId);
PhotonResult PhotonGcMain_RouterExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcMain_RouterReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_RouterWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcRouter_IsStatusMessage(size_t messageId);
PhotonResult PhotonGcMain_IdentificationExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcMain_IdentificationReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_IdentificationWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcIdentification_IsStatusMessage(size_t messageId);
PhotonResult PhotonGcMain_SegmentExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcMain_SegmentReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_SegmentWriteMessage(PhotonGcMain* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcSegment_IsStatusMessage(size_t messageId);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"

#endif