/* Type implementation */
#include "photon/fs/PhotonGtFileCreateDirError.h"


PhotonResult PhotonGtFileCreateDirError_Serialize(PhotonGtFileCreateDirError self, PhotonWriter* writer) {
  PhotonBer_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFileCreateDirError_Deserialize(PhotonGtFileCreateDirError* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) self, reader);
  return PhotonResult_Ok;
}