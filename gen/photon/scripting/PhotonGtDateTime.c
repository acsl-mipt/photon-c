/* Type implementation */
#include "photon/scripting/PhotonGtDateTime.h"


PhotonResult PhotonGtDateTime_Serialize(const PhotonGtDateTime* self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtDateTime_Deserialize(PhotonGtDateTime* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(self, reader));
  return PhotonResult_Ok;
}