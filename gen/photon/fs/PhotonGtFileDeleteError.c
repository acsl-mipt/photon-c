/* Type implementation */
#include "photon/fs/PhotonGtFileDeleteError.h"


PhotonResult PhotonGtFileDeleteError_Serialize(PhotonGtFileDeleteError self, PhotonWriter* writer) {
  PhotonBer_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFileDeleteError_Deserialize(PhotonGtFileDeleteError* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) self, reader);
  return PhotonResult_Ok;
}