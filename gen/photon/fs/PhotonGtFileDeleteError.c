/* Type implementation */
#include "photon/fs/PhotonGtFileDeleteError.h"


PhotonResult PhotonGtFileDeleteError_Serialize(PhotonGtFileDeleteError* self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFileDeleteError_Deserialize(PhotonGtFileDeleteError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(self, reader));
  return PhotonResult_Ok;
}