/* Component Main interface */
#ifndef __PHOTON_GC_MAIN_H_96e9c3b83b758f4db619ae678c399ada__
#define __PHOTON_GC_MAIN_H_96e9c3b83b758f4db619ae678c399ada__ 

#include "photon/photon_prologue.h"

#include "photon/identification/PhotonGcIdentification.h"
#include "photon/routing/PhotonGcRouter.h"
#include "photon/scripting/PhotonGcScripting.h"
#include "photon/segmentation/PhotonGcSegmentSender.h"
#include "photon/segmentation/PhotonGcSegmentReceiver.h"
#include "photon/tm/PhotonGcTm.h"
#include "photon/fs/PhotonGcFiles.h"

#ifdef __cplusplus
extern "C" {
#endif

struct PhotonGcMainUserFunctionTable_s;

typedef struct PhotonGcMain_s PhotonGcMain;

struct PhotonGcMain_s {
  PhotonGcMainData* data;
  void (*routerSetRoute)(PhotonGcMain*, PhotonGtAddress*, PhotonGtAddress*);
  void (*routerDelRoute)(PhotonGcMain*, PhotonGtAddress*);
  void (*routerSetGroupRoute)(PhotonGcMain*, PhotonGtAddress*, PhotonGtAddress*);
  void (*routerDelGroupRoute)(PhotonGcMain*, PhotonGtAddress*);
  PhotonGtShortId (*identificationRequestShortId)(PhotonGcMain*);
  PhotonGtFullId (*identificationRequestFullId)(PhotonGcMain*);
  PhotonGtGuid (*identificationRequestComponentGuid)(PhotonGcMain*, PhotonBer*);
  PhotonGtOptionalFileUploadError (*filesUploadFile)(PhotonGcMain*, PhotonGtFullFileInfo*);
  PhotonGtOrFullFileInfoFileDownloadError (*filesDownloadFile)(PhotonGcMain*, PhotonGtString*);
  PhotonGtOptionalFileDeleteError (*filesDeleteNode)(PhotonGcMain*, PhotonGtString*);
  PhotonGtOrArrNodeInfoFileListError (*filesRequestFileList)(PhotonGcMain*, PhotonGtString*);
  PhotonGtOptionalFileCreateDirError (*filesCreateDir)(PhotonGcMain*, PhotonGtString*);
  PhotonGtOptionalSegmentProcessAckError (*segmentSenderProcessSegmentsAck)(PhotonGcMain*, PhotonGtArrBerMin1*);
  PhotonGtOptionalSegmentStartAckError (*segmentStartSegmentAckMode)(PhotonGcMain*);
  PhotonGtOptionalSegmentStopAckError (*segmentStopSegmentAckMode)(PhotonGcMain*);
  PhotonGtB8 (*segmentRequestAckModeStatus)(PhotonGcMain*);
  PhotonGtOptionalSegmentProcessAckError (*segmentProcessAckModeStatus)(PhotonGcMain*, PhotonGtB8*);
  PhotonGtOptionalSegmentStartAckError (*segmentStartAckOnEverySegmentMode)(PhotonGcMain*);
  PhotonGtOptionalSegmentStopAckError (*segmentStopAckOnEverySegmentMode)(PhotonGcMain*);
  PhotonGtOptionalTmCmdError (*tmSendEventMessage)(PhotonGcMain*, PhotonGtEventInfo*);
  PhotonGtOptionalTmCmdError (*tmSendStatusMessage)(PhotonGcMain*, PhotonGtCompMsg*);
  PhotonGtOptionalTmCmdError (*tmSetMessageRequest)(PhotonGcMain*, PhotonGtCompMsg*, PhotonBer*);
  PhotonGtOptionalTmCmdError (*tmClearMessageRequest)(PhotonGcMain*, PhotonGtCompMsg*, PhotonBer*);
  PhotonGtOptionalTmCmdError (*tmDenyMessage)(PhotonGcMain*, PhotonGtCompMsg*);
  PhotonGtOptionalTmCmdError (*tmAllowMessage)(PhotonGcMain*, PhotonGtCompMsg*);
  PhotonGtOptionalTmCmdError (*tmDenyEvent)(PhotonGcMain*, PhotonGtEventInfo*);
  PhotonGtOptionalTmCmdError (*tmAllowEvent)(PhotonGcMain*, PhotonGtEventInfo*);
  PhotonGtArrBer (*segmentReceiverRequestSegmentsAck)(PhotonGcMain*);
  PhotonGtOptionalScriptingError (*scriptingUploadScript)(PhotonGcMain*, PhotonGtScriptId*, PhotonGtArrU8*, PhotonGtArrU8*);
  PhotonGtOptionalScriptingError (*scriptingDeleteScript)(PhotonGcMain*, PhotonGtScriptId*);
  PhotonGtOptionalScriptingError (*scriptingRunScriptNow)(PhotonGcMain*, PhotonGtScriptId*);
  PhotonGtOptionalScriptingError (*scriptingScheduleScriptRun)(PhotonGcMain*, PhotonGtScriptRunTiming*);
  PhotonGtOptionalScriptingError (*scriptingEnableScriptRunTiming)(PhotonGcMain*, PhotonGtGuid*);
  PhotonGtOptionalScriptingError (*scriptingDisableScriptRunTiming)(PhotonGcMain*, PhotonGtGuid*);
};
PhotonResult PhotonGcMain_FilesUploadFile(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_FilesDownloadFile(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_FilesDeleteNode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_FilesRequestFileList(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_FilesCreateDir(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_IdentificationRequestShortId(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_IdentificationRequestFullId(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_IdentificationRequestComponentGuid(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_RouterSetRoute(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_RouterDelRoute(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_RouterSetGroupRoute(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_RouterDelGroupRoute(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ScriptingUploadScript(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ScriptingDeleteScript(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ScriptingRunScriptNow(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ScriptingScheduleScriptRun(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ScriptingEnableScriptRunTiming(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_ScriptingDisableScriptRunTiming(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_SegmentStartSegmentAckMode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_SegmentStopSegmentAckMode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_SegmentRequestAckModeStatus(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_SegmentProcessAckModeStatus(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_SegmentStartAckOnEverySegmentMode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_SegmentStopAckOnEverySegmentMode(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_SegmentReceiverRequestSegmentsAck(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_SegmentSenderProcessSegmentsAck(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_TmSendEventMessage(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_TmSendStatusMessage(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_TmSetMessageRequest(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_TmClearMessageRequest(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_TmDenyMessage(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_TmAllowMessage(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_TmDenyEvent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcMain_TmAllowEvent(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);

PhotonResult PhotonGcMain_ExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);

PhotonResult PhotonGcMain_ReadExecuteCommand(PhotonGcMain* self, PhotonReader* reader, PhotonWriter* writer);


#ifdef __cplusplus
}
#endif
#include "photon/photon_epilogue.h"

#endif