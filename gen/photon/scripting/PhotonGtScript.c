/* Type implementation */
#include "photon/scripting/PhotonGtScript.h"


PhotonResult PhotonGtScript_Serialize(const PhotonGtScript* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < (*self).info.scriptCode.size * sizeof(unsigned char))
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonGtScriptInfo_Serialize(self->info, writer));
  PHOTON_TRY(PhotonGtScriptRunTiming_Serialize(&self->runTiming, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtScript_Deserialize(PhotonGtScript* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonGtScriptInfo_Deserialize(&self->info, reader));
  PHOTON_TRY(PhotonGtScriptRunTiming_Deserialize(&self->runTiming, reader));
  return PhotonResult_Ok;
}