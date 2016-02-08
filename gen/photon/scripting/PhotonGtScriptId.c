/* Type implementation */
#include "photon/scripting/PhotonGtScriptId.h"


PhotonResult PhotonGtScriptId_Serialize(PhotonGtScriptId* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < sizeof(PhotonBer))
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonBer_Serialize(self, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtScriptId_Deserialize(PhotonGtScriptId* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(self, reader));
  return PhotonResult_Ok;
}