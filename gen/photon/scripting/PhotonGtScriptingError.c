/* Type implementation */
#include "photon/scripting/PhotonGtScriptingError.h"


PhotonResult PhotonGtScriptingError_Serialize(PhotonGtScriptingError* self, PhotonWriter* writer) {
  PhotonBer_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtScriptingError_Deserialize(PhotonGtScriptingError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(self, reader));
  return PhotonResult_Ok;
}