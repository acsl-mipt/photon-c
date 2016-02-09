/* Type implementation */
#include "photon/fs/PhotonGtFileListError.h"


PhotonResult PhotonGtFileListError_Serialize(PhotonGtFileListError self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFileListError_Deserialize(PhotonGtFileListError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) self, reader));
  return PhotonResult_Ok;
}