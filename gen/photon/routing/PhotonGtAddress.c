/* Type implementation */
#include "photon/routing/PhotonGtAddress.h"


PhotonResult PhotonGtAddress_Serialize(const PhotonGtAddress* self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtAddress_Deserialize(PhotonGtAddress* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(self, reader));
  return PhotonResult_Ok;
}