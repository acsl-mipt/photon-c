#include "photon/PhotonGcMainSingleton.h"


PhotonGtArrBer PhotonGcMainSingleton_SegmentReceiverRequestSegmentsAck(PhotonGcMain* self) {}
PhotonGtOptionalScriptingError PhotonGcMainSingleton_ScriptingUploadScript(PhotonGcMain* self, PhotonGtScriptId* scriptId, PhotonGtArrU8* scriptData, PhotonGtArrU8* scriptCode) {}
PhotonGtOptionalScriptingError PhotonGcMainSingleton_ScriptingDeleteScript(PhotonGcMain* self, PhotonGtScriptId* scriptId) {}
PhotonGtOptionalScriptingError PhotonGcMainSingleton_ScriptingRunScriptNow(PhotonGcMain* self, PhotonGtScriptId* scriptId) {}
PhotonGtOptionalScriptingError PhotonGcMainSingleton_ScriptingScheduleScriptRun(PhotonGcMain* self, PhotonGtScriptRunTiming* scriptRunTiming) {}
PhotonGtOptionalScriptingError PhotonGcMainSingleton_ScriptingEnableScriptRunTiming(PhotonGcMain* self, PhotonGtGuid* scriptRunTimingId) {}
PhotonGtOptionalScriptingError PhotonGcMainSingleton_ScriptingDisableScriptRunTiming(PhotonGcMain* self, PhotonGtGuid* scriptRunTimingId) {}
PhotonGtOptionalSegmentProcessAckError PhotonGcMainSingleton_SegmentSenderProcessSegmentsAck(PhotonGcMain* self, PhotonGtArrBerMin1* segmentsReceived) {}
PhotonGtOptionalSegmentStartAckError PhotonGcMainSingleton_SegmentStartSegmentAckMode(PhotonGcMain* self) {}
PhotonGtOptionalSegmentStopAckError PhotonGcMainSingleton_SegmentStopSegmentAckMode(PhotonGcMain* self) {}
PhotonGtB8 PhotonGcMainSingleton_SegmentRequestAckModeStatus(PhotonGcMain* self) {}
PhotonGtOptionalSegmentProcessAckError PhotonGcMainSingleton_SegmentProcessAckModeStatus(PhotonGcMain* self, PhotonGtB8* isSegmentationAckModeActive) {}
PhotonGtOptionalSegmentStartAckError PhotonGcMainSingleton_SegmentStartAckOnEverySegmentMode(PhotonGcMain* self) {}
PhotonGtOptionalSegmentStopAckError PhotonGcMainSingleton_SegmentStopAckOnEverySegmentMode(PhotonGcMain* self) {}
PhotonGtOptionalFileUploadError PhotonGcMainSingleton_FilesUploadFile(PhotonGcMain* self, PhotonGtFullFileInfo* fileInfo) {}
PhotonGtOrFullFileInfoFileDownloadError PhotonGcMainSingleton_FilesDownloadFile(PhotonGcMain* self, PhotonGtString* path) {}
PhotonGtOptionalFileDeleteError PhotonGcMainSingleton_FilesDeleteNode(PhotonGcMain* self, PhotonGtString* path) {}
PhotonGtOrArrNodeInfoFileListError PhotonGcMainSingleton_FilesRequestFileList(PhotonGcMain* self, PhotonGtString* path) {}
PhotonGtOptionalFileCreateDirError PhotonGcMainSingleton_FilesCreateDir(PhotonGcMain* self, PhotonGtString* path) {}
PhotonGtShortId PhotonGcMainSingleton_IdentificationRequestShortId(PhotonGcMain* self) {}
PhotonGtFullId PhotonGcMainSingleton_IdentificationRequestFullId(PhotonGcMain* self) {}
PhotonGtGuid PhotonGcMainSingleton_IdentificationRequestComponentGuid(PhotonGcMain* self, PhotonBer* componentNumber) {}
PhotonGtOptionalTmCmdError PhotonGcMainSingleton_TmSendEventMessage(PhotonGcMain* self, PhotonGtEventInfo* eventInfo) {}
PhotonGtOptionalTmCmdError PhotonGcMainSingleton_TmSendStatusMessage(PhotonGcMain* self, PhotonGtCompMsg* componentMessage) {}
PhotonGtOptionalTmCmdError PhotonGcMainSingleton_TmSetMessageRequest(PhotonGcMain* self, PhotonGtCompMsg* componentMessage, PhotonBer* priority) {}
PhotonGtOptionalTmCmdError PhotonGcMainSingleton_TmClearMessageRequest(PhotonGcMain* self, PhotonGtCompMsg* componentMessage, PhotonBer* priority) {}
PhotonGtOptionalTmCmdError PhotonGcMainSingleton_TmDenyMessage(PhotonGcMain* self, PhotonGtCompMsg* componentMessage) {}
PhotonGtOptionalTmCmdError PhotonGcMainSingleton_TmAllowMessage(PhotonGcMain* self, PhotonGtCompMsg* componentMessage) {}
PhotonGtOptionalTmCmdError PhotonGcMainSingleton_TmDenyEvent(PhotonGcMain* self, PhotonGtEventInfo* eventInfo) {}
PhotonGtOptionalTmCmdError PhotonGcMainSingleton_TmAllowEvent(PhotonGcMain* self, PhotonGtEventInfo* eventInfo) {}
void PhotonGcMainSingleton_RouterSetRoute(PhotonGcMain* self, PhotonGtAddress* address, PhotonGtAddress* next_hop) {}
void PhotonGcMainSingleton_RouterDelRoute(PhotonGcMain* self, PhotonGtAddress* address) {}
void PhotonGcMainSingleton_RouterSetGroupRoute(PhotonGcMain* self, PhotonGtAddress* groupAddress, PhotonGtAddress* next_hop) {}
void PhotonGcMainSingleton_RouterDelGroupRoute(PhotonGcMain* self, PhotonGtAddress* groupAddress) {}
PhotonGtArrBer PhotonGcMainSingleton_SegmentReceiverSegmentsReceived(PhotonGcMain* self) {}
PhotonGtArrGuid PhotonGcMainSingleton_ScriptingScriptsIds(PhotonGcMain* self) {}
PhotonGtArrScriptInfo PhotonGcMainSingleton_ScriptingScripts(PhotonGcMain* self) {}
PhotonGtArrScriptRunTiming PhotonGcMainSingleton_ScriptingScriptsRunTimings(PhotonGcMain* self) {}
PhotonGtB8 PhotonGcMainSingleton_SegmentIsSegmentationAckModeActive(PhotonGcMain* self) {}
PhotonBer PhotonGcMainSingleton_SegmentMaxSegmentNumber(PhotonGcMain* self) {}
PhotonGtB8 PhotonGcMainSingleton_SegmentIsAckOnEverySegmentModeActive(PhotonGcMain* self) {}
PhotonGtFullId PhotonGcMainSingleton_IdentificationFullId(PhotonGcMain* self) {}
PhotonGtArrU8 PhotonGcMainSingleton_TmOnceRequests(PhotonGcMain* self) {}
PhotonGtArrArrU8 PhotonGcMainSingleton_TmDeniedMessagesByComponent(PhotonGcMain* self) {}
PhotonGtArrArrU8 PhotonGcMainSingleton_TmPriorityOrderedRequests(PhotonGcMain* self) {}
PhotonGtRingBuf PhotonGcMainSingleton_TmOutOfOrderMesages(PhotonGcMain* self) {}
PhotonGtArrEventInfo PhotonGcMainSingleton_TmLostEvents(PhotonGcMain* self) {}
PhotonGtArrRoute PhotonGcMainSingleton_RouterRoutes(PhotonGcMain* self) {}
PhotonGtArrRoute PhotonGcMainSingleton_RouterGroupRoutes(PhotonGcMain* self) {}