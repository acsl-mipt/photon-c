/* Type implementation */
#include "photon/fs/PhotonGtFilesEvent.h"


PhotonResult PhotonGtFilesEvent_Serialize(PhotonGtFilesEvent self, PhotonWriter* writer) {
  PhotonBer_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFilesEvent_Deserialize(PhotonGtFilesEvent* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) self, reader);
  return PhotonResult_Ok;
}