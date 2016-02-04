/* Component Identification implementation */
#include "photon/identification/PhotonGcIdentification.h"

PhotonResult PhotonGcIdentification_RequestShortId(PhotonGcIdentification* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtShortId cmdResult = self->requestShortId(self);
  return PhotonGtShortId_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcIdentification_RequestFullId(PhotonGcIdentification* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtFullId cmdResult = self->requestFullId(self);
  return PhotonGtFullId_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcIdentification_RequestComponentGuid(PhotonGcIdentification* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonBer componentNumber;
  PHOTON_TRY(PhotonBer_Deserialize(&componentNumber, reader));
  PhotonGtGuid cmdResult = self->requestComponentGuid(self, &componentNumber);
  return PhotonGtGuid_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcIdentification_WriteFullId(PhotonGcIdentification* self, PhotonWriter* writer) {
  PhotonGtFullId fullid = self->fullId(self);
  PHOTON_TRY(PhotonGtFullId_Serialize(&fullid, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGcIdentification_ExecuteCommand(PhotonGcIdentification* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcIdentification_RequestShortId(self, reader, writer);
    case 1:
      return PhotonGcIdentification_RequestFullId(self, reader, writer);
    case 2:
      return PhotonGcIdentification_RequestComponentGuid(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcIdentification_ReadExecuteCommand(PhotonGcIdentification* self, PhotonReader* reader, PhotonWriter* writer) {
  size_t commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcIdentification_ExecuteCommand(self, reader, writer, commandId);
}

PhotonResult PhotonGcIdentification_WriteMessage(PhotonGcIdentification* self, PhotonWriter* writer, size_t messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    case 0:
      return PhotonGcIdentification_WriteFullId(self, writer);
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonGtB8 PhotonGcIdentification_IsStatusMessage(size_t messageId) {
  switch (messageId) {
    case 0:
      return true;
    default:
      return false;
  }
}

