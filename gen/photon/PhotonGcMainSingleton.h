#ifndef __PHOTON_GC_MAIN_SINGLETON_H_954a639ba05bb2f2adc01f733e8cae82__
#define __PHOTON_GC_MAIN_SINGLETON_H_954a639ba05bb2f2adc01f733e8cae82__ 

#include "photon/PhotonGcMain.h"

#ifdef __cplusplus
extern "C" {
#endif

PhotonGcMain* PhotonGcMainSingleton_Init();

PhotonResult PhotonGcMainSingleton_SetRoute(PhotonGcMain* self, PhotonGtAddress* address, PhotonGtAddress* next_hop);
PhotonResult PhotonGcMainSingleton_DelRoute(PhotonGcMain* self, PhotonGtAddress* address);
PhotonResult PhotonGcMainSingleton_SetGroupRoute(PhotonGcMain* self, PhotonGtAddress* groupAddress, PhotonGtAddress* next_hop);
PhotonResult PhotonGcMainSingleton_DelGroupRoute(PhotonGcMain* self, PhotonGtAddress* groupAddress);
PhotonResult PhotonGcMainSingleton_RequestShortId(PhotonGcMain* self, PhotonGtShortId* result);
PhotonResult PhotonGcMainSingleton_RequestFullId(PhotonGcMain* self, PhotonGtFullId* result);
PhotonResult PhotonGcMainSingleton_RequestComponentGuid(PhotonGcMain* self, PhotonGtGuid* result, PhotonBer* componentNumber);
PhotonResult PhotonGcMainSingleton_UploadFile(PhotonGcMain* self, PhotonGtOptionalFileUploadError* result, PhotonGtFullFileInfo* fileInfo);
PhotonResult PhotonGcMainSingleton_DownloadFile(PhotonGcMain* self, PhotonGtOrFullFileInfoFileDownloadError* result, PhotonGtString* path);
PhotonResult PhotonGcMainSingleton_DeleteNode(PhotonGcMain* self, PhotonGtOptionalFileDeleteError* result, PhotonGtString* path);
PhotonResult PhotonGcMainSingleton_RequestFileList(PhotonGcMain* self, PhotonGtOrArrNodeInfoFileListError* result, PhotonGtString* path);
PhotonResult PhotonGcMainSingleton_CreateDir(PhotonGcMain* self, PhotonGtOptionalFileCreateDirError* result, PhotonGtString* path);
PhotonResult PhotonGcMainSingleton_ProcessSegmentsAck(PhotonGcMain* self, PhotonGtOptionalSegmentProcessAckError* result, PhotonGtArrBerMin1* segmentsReceived);
PhotonResult PhotonGcMainSingleton_StartSegmentAckMode(PhotonGcMain* self, PhotonGtOptionalSegmentStartAckError* result);
PhotonResult PhotonGcMainSingleton_StopSegmentAckMode(PhotonGcMain* self, PhotonGtOptionalSegmentStopAckError* result);
PhotonResult PhotonGcMainSingleton_RequestAckModeStatus(PhotonGcMain* self, PhotonGtB8* result);
PhotonResult PhotonGcMainSingleton_ProcessAckModeStatus(PhotonGcMain* self, PhotonGtOptionalSegmentProcessAckError* result, PhotonGtB8* isSegmentationAckModeActive);
PhotonResult PhotonGcMainSingleton_StartAckOnEverySegmentMode(PhotonGcMain* self, PhotonGtOptionalSegmentStartAckError* result);
PhotonResult PhotonGcMainSingleton_StopAckOnEverySegmentMode(PhotonGcMain* self, PhotonGtOptionalSegmentStopAckError* result);
PhotonResult PhotonGcMainSingleton_SendEventMessage(PhotonGcMain* self, PhotonGtOptionalTmCmdError* result, PhotonGtEventInfo* eventInfo);
PhotonResult PhotonGcMainSingleton_SendStatusMessage(PhotonGcMain* self, PhotonGtOptionalTmCmdError* result, PhotonGtCompMsg* componentMessage);
PhotonResult PhotonGcMainSingleton_SetMessageRequest(PhotonGcMain* self, PhotonGtOptionalTmCmdError* result, PhotonGtCompMsg* componentMessage, PhotonBer* priority);
PhotonResult PhotonGcMainSingleton_ClearMessageRequest(PhotonGcMain* self, PhotonGtOptionalTmCmdError* result, PhotonGtCompMsg* componentMessage, PhotonBer* priority);
PhotonResult PhotonGcMainSingleton_DenyMessage(PhotonGcMain* self, PhotonGtOptionalTmCmdError* result, PhotonGtCompMsg* componentMessage);
PhotonResult PhotonGcMainSingleton_AllowMessage(PhotonGcMain* self, PhotonGtOptionalTmCmdError* result, PhotonGtCompMsg* componentMessage);
PhotonResult PhotonGcMainSingleton_DenyEvent(PhotonGcMain* self, PhotonGtOptionalTmCmdError* result, PhotonGtEventInfo* eventInfo);
PhotonResult PhotonGcMainSingleton_AllowEvent(PhotonGcMain* self, PhotonGtOptionalTmCmdError* result, PhotonGtEventInfo* eventInfo);
PhotonResult PhotonGcMainSingleton_RequestSegmentsAck(PhotonGcMain* self, PhotonGtArrBer* result);
PhotonResult PhotonGcMainSingleton_UploadScript(PhotonGcMain* self, PhotonGtOptionalScriptingError* result, PhotonGtScriptId* scriptId, PhotonGtArrU8* scriptData, PhotonGtArrU8* scriptCode);
PhotonResult PhotonGcMainSingleton_DeleteScript(PhotonGcMain* self, PhotonGtOptionalScriptingError* result, PhotonGtScriptId* scriptId);
PhotonResult PhotonGcMainSingleton_RunScriptNow(PhotonGcMain* self, PhotonGtOptionalScriptingError* result, PhotonGtScriptId* scriptId);
PhotonResult PhotonGcMainSingleton_ScheduleScriptRun(PhotonGcMain* self, PhotonGtOptionalScriptingError* result, PhotonGtScriptRunTiming* scriptRunTiming);
PhotonResult PhotonGcMainSingleton_EnableScriptRunTiming(PhotonGcMain* self, PhotonGtOptionalScriptingError* result, PhotonGtGuid* scriptRunTimingId);
PhotonResult PhotonGcMainSingleton_DisableScriptRunTiming(PhotonGcMain* self, PhotonGtOptionalScriptingError* result, PhotonGtGuid* scriptRunTimingId);

#ifdef __cplusplus
}
#endif
#endif