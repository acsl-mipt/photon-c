/* Type implementation */
#include "photon/fs/PhotonGtFilesMode.h"


PhotonResult PhotonGtFilesMode_Serialize(PhotonGtFilesMode self, PhotonWriter* writer) {
  PhotonBer_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFilesMode_Deserialize(PhotonGtFilesMode* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) self, reader);
  return PhotonResult_Ok;
}