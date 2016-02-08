/* Type implementation */
#include "photon/scripting/PhotonGtScriptRunTiming.h"


PhotonResult PhotonGtScriptRunTiming_Serialize(PhotonGtScriptRunTiming* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < sizeof(PhotonBer) + sizeof(unsigned char) + sizeof(PhotonBer) + sizeof(PhotonBer) + sizeof(unsigned char) + sizeof(PhotonBer) + sizeof(unsigned char) + sizeof(PhotonBer))
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonBer_Serialize(self->id, writer));
  PhotonWriter_WriteUint8(writer, self->isActive);
  PHOTON_TRY(PhotonBer_Serialize(self->scriptId, writer));
  PHOTON_TRY(PhotonBer_Serialize(self->runOn, writer));
  PhotonWriter_WriteUint8(writer, self->isRepeated);
  PHOTON_TRY(PhotonBer_Serialize(self->repeatPeriod, writer));
  PhotonWriter_WriteUint8(writer, self->isRepeatingLimitedByDate);
  PHOTON_TRY(PhotonBer_Serialize(self->repeatUntil, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtScriptRunTiming_Deserialize(PhotonGtScriptRunTiming* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->id, reader));
  self->isActive = PhotonReader_ReadUint8(reader);
  PHOTON_TRY(PhotonBer_Deserialize(&self->scriptId, reader));
  PHOTON_TRY(PhotonBer_Deserialize(&self->runOn, reader));
  self->isRepeated = PhotonReader_ReadUint8(reader);
  PHOTON_TRY(PhotonBer_Deserialize(&self->repeatPeriod, reader));
  self->isRepeatingLimitedByDate = PhotonReader_ReadUint8(reader);
  PHOTON_TRY(PhotonBer_Deserialize(&self->repeatUntil, reader));
  return PhotonResult_Ok;
}