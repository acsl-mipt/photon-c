/* Component Tm implementation */
#include "PhotonGcTm.h"

PhotonResult PhotonGcTm_SendEventMessage(PhotonGcTm* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtEventInfo eventInfo;
  PHOTON_TRY(PhotonGtEventInfo_Deserialize(&eventInfo, reader));
  PhotonGtOptionalTmCmdError cmdResult = self->sendEventMessage(self, &eventInfo);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcTm_SendStatusMessage(PhotonGcTm* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  PhotonGtOptionalTmCmdError cmdResult = self->sendStatusMessage(self, &componentMessage);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcTm_SetMessageRequest(PhotonGcTm* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  PhotonBer priority;
  PHOTON_TRY(PhotonBer_Deserialize(&priority, reader));
  PhotonGtOptionalTmCmdError cmdResult = self->setMessageRequest(self, &componentMessage, &priority);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcTm_ClearMessageRequest(PhotonGcTm* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  PhotonBer priority;
  PHOTON_TRY(PhotonBer_Deserialize(&priority, reader));
  PhotonGtOptionalTmCmdError cmdResult = self->clearMessageRequest(self, &componentMessage, &priority);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcTm_DenyMessage(PhotonGcTm* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  PhotonGtOptionalTmCmdError cmdResult = self->denyMessage(self, &componentMessage);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcTm_AllowMessage(PhotonGcTm* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtCompMsg componentMessage;
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&componentMessage, reader));
  PhotonGtOptionalTmCmdError cmdResult = self->allowMessage(self, &componentMessage);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcTm_DenyEvent(PhotonGcTm* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtEventInfo eventInfo;
  PHOTON_TRY(PhotonGtEventInfo_Deserialize(&eventInfo, reader));
  PhotonGtOptionalTmCmdError cmdResult = self->denyEvent(self, &eventInfo);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcTm_AllowEvent(PhotonGcTm* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtEventInfo eventInfo;
  PHOTON_TRY(PhotonGtEventInfo_Deserialize(&eventInfo, reader));
  PhotonGtOptionalTmCmdError cmdResult = self->allowEvent(self, &eventInfo);
  return PhotonGtOptionalTmCmdError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcTm_ExecuteCommand(PhotonGcTm* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcTm_TmSendEventMessage(self, reader, writer);
    case 1:
      return PhotonGcTm_TmSendStatusMessage(self, reader, writer);
    case 2:
      return PhotonGcTm_TmSetMessageRequest(self, reader, writer);
    case 3:
      return PhotonGcTm_TmClearMessageRequest(self, reader, writer);
    case 4:
      return PhotonGcTm_TmDenyMessage(self, reader, writer);
    case 5:
      return PhotonGcTm_TmAllowMessage(self, reader, writer);
    case 6:
      return PhotonGcTm_TmDenyEvent(self, reader, writer);
    case 7:
      return PhotonGcTm_TmAllowEvent(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}