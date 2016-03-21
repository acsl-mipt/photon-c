/* Type implementation */
#include "photon/fs/PhotonGtFileListError.h"


PhotonResult PhotonGtFileListError_Serialize(PhotonGtFileListError self, PhotonWriter* writer) {
  PhotonBer_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFileListError_Deserialize(PhotonGtFileListError* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) self, reader);
  return PhotonResult_Ok;
}