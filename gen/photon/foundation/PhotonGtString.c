/* Type implementation */
#include "photon/foundation/PhotonGtString.h"


PhotonResult PhotonGtString_Serialize(const PhotonGtString* self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonGtArrU8_Serialize(self, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtString_Deserialize(PhotonGtString* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonGtArrU8_Deserialize((PhotonGtArrU8*) self, reader));
  return PhotonResult_Ok;
}