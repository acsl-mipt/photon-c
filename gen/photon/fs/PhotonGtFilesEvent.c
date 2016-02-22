/* Type implementation */
#include "photon/fs/PhotonGtFilesEvent.h"


PhotonResult PhotonGtFilesEvent_Serialize(PhotonGtFilesEvent self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFilesEvent_Deserialize(PhotonGtFilesEvent* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) self, reader));
  return PhotonResult_Ok;
}