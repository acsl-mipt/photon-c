/* Type implementation */
#include "photon/routing/PhotonGtAddress.h"


PhotonResult PhotonGtAddress_Serialize(PhotonGtAddress* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < sizeof(PhotonBer))
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonBer_Serialize(self, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtAddress_Deserialize(PhotonGtAddress* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(self, reader));
  return PhotonResult_Ok;
}