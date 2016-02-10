/* Type implementation */
#include "photon/fs/PhotonGtFilesMode.h"


PhotonResult PhotonGtFilesMode_Serialize(PhotonGtFilesMode self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFilesMode_Deserialize(PhotonGtFilesMode* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) self, reader));
  return PhotonResult_Ok;
}