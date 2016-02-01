/* Type implementation */
#include "photon/foundation/PhotonGtGuid.h"


PhotonResult PhotonGtGuid_Serialize(PhotonGtGuid* self, PhotonWriter* writer) {
  PhotonBer_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtGuid_Deserialize(PhotonGtGuid* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(self, reader));
  return PhotonResult_Ok;
}