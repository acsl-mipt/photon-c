/* Type implementation */
#include "photon/scripting/PhotonGtPeriod.h"


PhotonResult PhotonGtPeriod_Serialize(PhotonGtPeriod self, PhotonWriter* writer) {
  PhotonBer_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtPeriod_Deserialize(PhotonGtPeriod* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) self, reader);
  return PhotonResult_Ok;
}