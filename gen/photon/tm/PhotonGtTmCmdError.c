/* Type implementation */
#include "photon/tm/PhotonGtTmCmdError.h"


PhotonResult PhotonGtTmCmdError_Serialize(PhotonGtTmCmdError self, PhotonWriter* writer) {
  PhotonBer_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtTmCmdError_Deserialize(PhotonGtTmCmdError* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) self, reader);
  return PhotonResult_Ok;
}