/* Type implementation */
#include "photon/scripting/PhotonGtScriptRunTiming.h"


PhotonResult PhotonGtScriptRunTiming_Serialize(const PhotonGtScriptRunTiming* self, PhotonWriter* writer) {
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
  PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) &self->id, reader));
  *(unsigned char*) &self->isActive = PhotonReader_ReadUint8(reader);
  PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) (PhotonGtGuid*) &self->scriptId, reader));
  PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) &self->runOn, reader));
  *(unsigned char*) &self->isRepeated = PhotonReader_ReadUint8(reader);
  PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) &self->repeatPeriod, reader));
  *(unsigned char*) &self->isRepeatingLimitedByDate = PhotonReader_ReadUint8(reader);
  PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) &self->repeatUntil, reader));
  return PhotonResult_Ok;
}