/* Type implementation */
#include "photon/fs/PhotonGtFileCreateDirError.h"


PhotonResult PhotonGtFileCreateDirError_Serialize(PhotonGtFileCreateDirError* self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFileCreateDirError_Deserialize(PhotonGtFileCreateDirError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(self, reader));
  return PhotonResult_Ok;
}