/* Component Identification implementation */
#include "PhotonGcIdentification.h"

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

PhotonResult PhotonGcIdentification_ExecuteCommand(PhotonGcIdentification* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcIdentification_IdentificationRequestShortId(self, reader, writer);
    case 1:
      return PhotonGcIdentification_IdentificationRequestFullId(self, reader, writer);
    case 2:
      return PhotonGcIdentification_IdentificationRequestComponentGuid(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}