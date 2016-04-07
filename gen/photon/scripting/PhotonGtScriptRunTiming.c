/* Type implementation */
#include "photon/scripting/PhotonGtScriptRunTiming.h"


PhotonResult PhotonGtScriptRunTiming_Serialize(const PhotonGtScriptRunTiming* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < /* script_run_timing{ */sizeof(PhotonGtB8) + sizeof(PhotonGtB8) + sizeof(PhotonGtB8)/* }script_run_timing */)
    return PhotonResult_NotEnoughSpace;
  PhotonBer_Serialize(self->id, writer);
  PhotonWriter_WriteUint8(writer, self->isActive);
  PhotonBer_Serialize(self->scriptId, writer);
  PhotonBer_Serialize(self->runOn, writer);
  PhotonWriter_WriteUint8(writer, self->isRepeated);
  PhotonBer_Serialize(self->repeatPeriod, writer);
  PhotonWriter_WriteUint8(writer, self->isRepeatingLimitedByDate);
  PhotonBer_Serialize(self->repeatUntil, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtScriptRunTiming_Deserialize(PhotonGtScriptRunTiming* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) &self->id, reader);
  self->isActive = PhotonReader_ReadUint8(reader);
  PhotonBer_Deserialize((PhotonGtBer*) (PhotonGtGuid*) &self->scriptId, reader);
  PhotonBer_Deserialize((PhotonGtBer*) &self->runOn, reader);
  self->isRepeated = PhotonReader_ReadUint8(reader);
  PhotonBer_Deserialize((PhotonGtBer*) &self->repeatPeriod, reader);
  self->isRepeatingLimitedByDate = PhotonReader_ReadUint8(reader);
  PhotonBer_Deserialize((PhotonGtBer*) &self->repeatUntil, reader);
  return PhotonResult_Ok;
}