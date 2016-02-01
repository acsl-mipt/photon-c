#include "photon/PhotonGcMainSingleton.h"

void PhotonGcMainSingleton_SetRoute(PhotonGcMain* self, PhotonGtAddress* address, PhotonGtAddress* next_hop){}
void PhotonGcMainSingleton_DelRoute(PhotonGcMain* self, PhotonGtAddress* address){}
void PhotonGcMainSingleton_SetGroupRoute(PhotonGcMain* self, PhotonGtAddress* groupAddress, PhotonGtAddress* next_hop){}
void PhotonGcMainSingleton_DelGroupRoute(PhotonGcMain* self, PhotonGtAddress* groupAddress) {}
PhotonGtShortId PhotonGcMainSingleton_RequestShortId(PhotonGcMain* self) {}
PhotonGtFullId PhotonGcMainSingleton_RequestFullId(PhotonGcMain* self) {}
PhotonGtGuid PhotonGcMainSingleton_RequestComponentGuid(PhotonGcMain* self, PhotonBer* componentNumber) {}
PhotonGtOptionalFileUploadError PhotonGcMainSingleton_UploadFile(PhotonGcMain* self, PhotonGtFullFileInfo* fileInfo) {}
PhotonGtOrFullFileInfoFileDownloadError PhotonGcMainSingleton_DownloadFile(PhotonGcMain* self, PhotonGtString* path) {}
PhotonGtOptionalFileDeleteError PhotonGcMainSingleton_DeleteNode(PhotonGcMain* self, PhotonGtString* path) {}
PhotonGtOrArrNodeInfoFileListError PhotonGcMainSingleton_RequestFileList(PhotonGcMain* self, PhotonGtString* path) {}
PhotonGtOptionalFileCreateDirError PhotonGcMainSingleton_CreateDir(PhotonGcMain* self, PhotonGtString* path) {}
PhotonGtOptionalSegmentProcessAckError PhotonGcMainSingleton_ProcessSegmentsAck(PhotonGcMain* self, PhotonGtArrBerMin1* segmentsReceived) {}
PhotonGtOptionalSegmentStartAckError PhotonGcMainSingleton_StartSegmentAckMode(PhotonGcMain* self) {}
PhotonGtOptionalSegmentStopAckError PhotonGcMainSingleton_StopSegmentAckMode(PhotonGcMain* self) {}
PhotonGtB8 PhotonGcMainSingleton_RequestAckModeStatus(PhotonGcMain* self) {}
PhotonGtOptionalSegmentProcessAckError PhotonGcMainSingleton_ProcessAckModeStatus(PhotonGcMain* self, PhotonGtB8* isSegmentationAckModeActive) {}
PhotonGtOptionalSegmentStartAckError PhotonGcMainSingleton_StartAckOnEverySegmentMode(PhotonGcMain* self) {}
PhotonGtOptionalSegmentStopAckError PhotonGcMainSingleton_StopAckOnEverySegmentMode(PhotonGcMain* self) {}
PhotonGtOptionalTmCmdError PhotonGcMainSingleton_SendEventMessage(PhotonGcMain* self, PhotonGtEventInfo* eventInfo) {}
PhotonGtOptionalTmCmdError PhotonGcMainSingleton_SendStatusMessage(PhotonGcMain* self, PhotonGtCompMsg* componentMessage) {}
PhotonGtOptionalTmCmdError PhotonGcMainSingleton_SetMessageRequest(PhotonGcMain* self, PhotonGtCompMsg* componentMessage, PhotonBer* priority) {}
PhotonGtOptionalTmCmdError PhotonGcMainSingleton_ClearMessageRequest(PhotonGcMain* self, PhotonGtCompMsg* componentMessage, PhotonBer* priority) {}
PhotonGtOptionalTmCmdError PhotonGcMainSingleton_DenyMessage(PhotonGcMain* self, PhotonGtCompMsg* componentMessage) {}
PhotonGtOptionalTmCmdError PhotonGcMainSingleton_AllowMessage(PhotonGcMain* self, PhotonGtCompMsg* componentMessage) {}
PhotonGtOptionalTmCmdError PhotonGcMainSingleton_DenyEvent(PhotonGcMain* self, PhotonGtEventInfo* eventInfo) {}
PhotonGtOptionalTmCmdError PhotonGcMainSingleton_AllowEvent(PhotonGcMain* self, PhotonGtEventInfo* eventInfo) {}
PhotonGtArrBer PhotonGcMainSingleton_RequestSegmentsAck(PhotonGcMain* self) {}
PhotonGtOptionalScriptingError PhotonGcMainSingleton_UploadScript(PhotonGcMain* self, PhotonGtScriptId* scriptId, PhotonGtArrU8* scriptData, PhotonGtArrU8* scriptCode) {}
PhotonGtOptionalScriptingError PhotonGcMainSingleton_DeleteScript(PhotonGcMain* self, PhotonGtScriptId* scriptId) {}
PhotonGtOptionalScriptingError PhotonGcMainSingleton_RunScriptNow(PhotonGcMain* self, PhotonGtScriptId* scriptId) {}
PhotonGtOptionalScriptingError PhotonGcMainSingleton_ScheduleScriptRun(PhotonGcMain* self, PhotonGtScriptRunTiming* scriptRunTiming) {}
PhotonGtOptionalScriptingError PhotonGcMainSingleton_EnableScriptRunTiming(PhotonGcMain* self, PhotonGtGuid* scriptRunTimingId) {}
PhotonGtOptionalScriptingError PhotonGcMainSingleton_DisableScriptRunTiming(PhotonGcMain* self, PhotonGtGuid* scriptRunTimingId) {}