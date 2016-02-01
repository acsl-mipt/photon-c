/* Component Main interface */
#ifndef __PHOTON_GC_MAIN_H_360d71d7da04408b9960bc5ea58c1736__
#define __PHOTON_GC_MAIN_H_360d71d7da04408b9960bc5ea58c1736__ 

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
  void (*routerSetRoute)(PhotonGcRouter*, PhotonGtAddress*, PhotonGtAddress*);
  void (*routerDelRoute)(PhotonGcRouter*, PhotonGtAddress*);
  void (*routerSetGroupRoute)(PhotonGcRouter*, PhotonGtAddress*, PhotonGtAddress*);
  void (*routerDelGroupRoute)(PhotonGcRouter*, PhotonGtAddress*);
  PhotonGtShortId (*identificationRequestShortId)(PhotonGcIdentification*);
  PhotonGtFullId (*identificationRequestFullId)(PhotonGcIdentification*);
  PhotonGtGuid (*identificationRequestComponentGuid)(PhotonGcIdentification*, PhotonBer*);
  PhotonGtOptionalFileUploadError (*filesUploadFile)(PhotonGcFiles*, PhotonGtFullFileInfo*);
  PhotonGtOrFullFileInfoFileDownloadError (*filesDownloadFile)(PhotonGcFiles*, PhotonGtString*);
  PhotonGtOptionalFileDeleteError (*filesDeleteNode)(PhotonGcFiles*, PhotonGtString*);
  PhotonGtOrArrNodeInfoFileListError (*filesRequestFileList)(PhotonGcFiles*, PhotonGtString*);
  PhotonGtOptionalFileCreateDirError (*filesCreateDir)(PhotonGcFiles*, PhotonGtString*);
  PhotonGtOptionalSegmentProcessAckError (*segmentSenderProcessSegmentsAck)(PhotonGcSegmentSender*, PhotonGtArrBerMin1*);
  PhotonGtOptionalSegmentStartAckError (*segmentStartSegmentAckMode)(PhotonGcSegment*);
  PhotonGtOptionalSegmentStopAckError (*segmentStopSegmentAckMode)(PhotonGcSegment*);
  PhotonGtB8 (*segmentRequestAckModeStatus)(PhotonGcSegment*);
  PhotonGtOptionalSegmentProcessAckError (*segmentProcessAckModeStatus)(PhotonGcSegment*, PhotonGtB8*);
  PhotonGtOptionalSegmentStartAckError (*segmentStartAckOnEverySegmentMode)(PhotonGcSegment*);
  PhotonGtOptionalSegmentStopAckError (*segmentStopAckOnEverySegmentMode)(PhotonGcSegment*);
  PhotonGtOptionalTmCmdError (*tmSendEventMessage)(PhotonGcTm*, PhotonGtEventInfo*);
  PhotonGtOptionalTmCmdError (*tmSendStatusMessage)(PhotonGcTm*, PhotonGtCompMsg*);
  PhotonGtOptionalTmCmdError (*tmSetMessageRequest)(PhotonGcTm*, PhotonGtCompMsg*, PhotonBer*);
  PhotonGtOptionalTmCmdError (*tmClearMessageRequest)(PhotonGcTm*, PhotonGtCompMsg*, PhotonBer*);
  PhotonGtOptionalTmCmdError (*tmDenyMessage)(PhotonGcTm*, PhotonGtCompMsg*);
  PhotonGtOptionalTmCmdError (*tmAllowMessage)(PhotonGcTm*, PhotonGtCompMsg*);
  PhotonGtOptionalTmCmdError (*tmDenyEvent)(PhotonGcTm*, PhotonGtEventInfo*);
  PhotonGtOptionalTmCmdError (*tmAllowEvent)(PhotonGcTm*, PhotonGtEventInfo*);
  PhotonGtArrBer (*segmentReceiverRequestSegmentsAck)(PhotonGcSegmentReceiver*);
  PhotonGtOptionalScriptingError (*scriptingUploadScript)(PhotonGcScripting*, PhotonGtScriptId*, PhotonGtArrU8*, PhotonGtArrU8*);
  PhotonGtOptionalScriptingError (*scriptingDeleteScript)(PhotonGcScripting*, PhotonGtScriptId*);
  PhotonGtOptionalScriptingError (*scriptingRunScriptNow)(PhotonGcScripting*, PhotonGtScriptId*);
  PhotonGtOptionalScriptingError (*scriptingScheduleScriptRun)(PhotonGcScripting*, PhotonGtScriptRunTiming*);
  PhotonGtOptionalScriptingError (*scriptingEnableScriptRunTiming)(PhotonGcScripting*, PhotonGtGuid*);
  PhotonGtOptionalScriptingError (*scriptingDisableScriptRunTiming)(PhotonGcScripting*, PhotonGtGuid*);
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