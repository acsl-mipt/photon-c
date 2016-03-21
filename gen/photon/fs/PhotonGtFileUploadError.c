/* Type implementation */
#include "photon/fs/PhotonGtFileUploadError.h"


PhotonResult PhotonGtFileUploadError_Serialize(PhotonGtFileUploadError self, PhotonWriter* writer) {
  PhotonBer_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFileUploadError_Deserialize(PhotonGtFileUploadError* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) self, reader);
  return PhotonResult_Ok;
}