/* Type implementation */
#include "photon/foundation/PhotonGtString.h"


PhotonResult PhotonGtString_Serialize(PhotonGtString self, PhotonWriter* writer) {
  PhotonGtArrU8_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtString_Deserialize(PhotonGtString* self, PhotonReader* reader) {
  PhotonGtArrU8_Deserialize((PhotonGtArrU8*) self, reader);
  return PhotonResult_Ok;
}