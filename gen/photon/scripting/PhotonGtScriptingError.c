/* Type implementation */
#include "photon/scripting/PhotonGtScriptingError.h"


PhotonResult PhotonGtScriptingError_Serialize(PhotonGtScriptingError self, PhotonWriter* writer) {
  PhotonBer_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtScriptingError_Deserialize(PhotonGtScriptingError* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) self, reader);
  return PhotonResult_Ok;
}