#include "photon/PhotonGcMainSingleton.h"

PhotonGcMain main;
PhotonGcMain* PhotonGcMainSingleton_Init() {
  main.routerSetRoute = PhotonGcMainSingleton_SetRoute;
  main.routerDelRoute = PhotonGcMainSingleton_DelRoute;
  main.routerSetGroupRoute = PhotonGcMainSingleton_SetGroupRoute;
  main.routerDelGroupRoute = PhotonGcMainSingleton_DelGroupRoute;
  main.identificationRequestShortId = PhotonGcMainSingleton_RequestShortId;
  main.identificationRequestFullId = PhotonGcMainSingleton_RequestFullId;
  main.identificationRequestComponentGuid = PhotonGcMainSingleton_RequestComponentGuid;
  main.filesUploadFile = PhotonGcMainSingleton_UploadFile;
  main.filesDownloadFile = PhotonGcMainSingleton_DownloadFile;
  main.filesDeleteNode = PhotonGcMainSingleton_DeleteNode;
  main.filesRequestFileList = PhotonGcMainSingleton_RequestFileList;
  main.filesCreateDir = PhotonGcMainSingleton_CreateDir;
  main.segmentSenderProcessSegmentsAck = PhotonGcMainSingleton_ProcessSegmentsAck;
  main.segmentStartSegmentAckMode = PhotonGcMainSingleton_StartSegmentAckMode;
  main.segmentStopSegmentAckMode = PhotonGcMainSingleton_StopSegmentAckMode;
  main.segmentRequestAckModeStatus = PhotonGcMainSingleton_RequestAckModeStatus;
  main.segmentProcessAckModeStatus = PhotonGcMainSingleton_ProcessAckModeStatus;
  main.segmentStartAckOnEverySegmentMode = PhotonGcMainSingleton_StartAckOnEverySegmentMode;
  main.segmentStopAckOnEverySegmentMode = PhotonGcMainSingleton_StopAckOnEverySegmentMode;
  main.tmSendEventMessage = PhotonGcMainSingleton_SendEventMessage;
  main.tmSendStatusMessage = PhotonGcMainSingleton_SendStatusMessage;
  main.tmSetMessageRequest = PhotonGcMainSingleton_SetMessageRequest;
  main.tmClearMessageRequest = PhotonGcMainSingleton_ClearMessageRequest;
  main.tmDenyMessage = PhotonGcMainSingleton_DenyMessage;
  main.tmAllowMessage = PhotonGcMainSingleton_AllowMessage;
  main.tmDenyEvent = PhotonGcMainSingleton_DenyEvent;
  main.tmAllowEvent = PhotonGcMainSingleton_AllowEvent;
  main.segmentReceiverRequestSegmentsAck = PhotonGcMainSingleton_RequestSegmentsAck;
  main.scriptingUploadScript = PhotonGcMainSingleton_UploadScript;
  main.scriptingDeleteScript = PhotonGcMainSingleton_DeleteScript;
  main.scriptingRunScriptNow = PhotonGcMainSingleton_RunScriptNow;
  main.scriptingScheduleScriptRun = PhotonGcMainSingleton_ScheduleScriptRun;
  main.scriptingEnableScriptRunTiming = PhotonGcMainSingleton_EnableScriptRunTiming;
  main.scriptingDisableScriptRunTiming = PhotonGcMainSingleton_DisableScriptRunTiming;
  return &main;
}