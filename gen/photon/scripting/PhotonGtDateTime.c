/* Type implementation */
#include "photon/scripting/PhotonGtDateTime.h"


PhotonResult PhotonGtDateTime_Serialize(PhotonGtDateTime self, PhotonWriter* writer) {
  PhotonBer_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtDateTime_Deserialize(PhotonGtDateTime* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) self, reader);
  return PhotonResult_Ok;
}