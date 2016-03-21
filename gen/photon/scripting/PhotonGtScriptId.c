/* Type implementation */
#include "photon/scripting/PhotonGtScriptId.h"


PhotonResult PhotonGtScriptId_Serialize(PhotonGtScriptId self, PhotonWriter* writer) {
  PhotonBer_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtScriptId_Deserialize(PhotonGtScriptId* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) (PhotonGtGuid*) self, reader);
  return PhotonResult_Ok;
}