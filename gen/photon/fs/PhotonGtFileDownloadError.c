/* Type implementation */
#include "photon/fs/PhotonGtFileDownloadError.h"


PhotonResult PhotonGtFileDownloadError_Serialize(PhotonGtFileDownloadError self, PhotonWriter* writer) {
  PhotonBer_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFileDownloadError_Deserialize(PhotonGtFileDownloadError* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) self, reader);
  return PhotonResult_Ok;
}