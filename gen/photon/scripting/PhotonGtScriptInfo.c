/* Type implementation */
#include "photon/scripting/PhotonGtScriptInfo.h"


PhotonResult PhotonGtScriptInfo_Serialize(PhotonGtScriptInfo* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < sizeof(PhotonBer) + (*self).scriptData.size * sizeof(unsigned char) + (*self).scriptCode.size * sizeof(unsigned char))
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonBer_Serialize(self->scriptId, writer));
  PHOTON_TRY(PhotonGtArrU8_Serialize(&self->scriptData, writer));
  PHOTON_TRY(PhotonGtArrU8_Serialize(&self->scriptCode, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtScriptInfo_Deserialize(PhotonGtScriptInfo* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->scriptId, reader));
  PHOTON_TRY(PhotonGtArrU8_Deserialize(&self->scriptData, reader));
  PHOTON_TRY(PhotonGtArrU8_Deserialize(&self->scriptCode, reader));
  return PhotonResult_Ok;
}