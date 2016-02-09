/* Type implementation */
#include "photon/tm/PhotonGtTmCmdError.h"


PhotonResult PhotonGtTmCmdError_Serialize(PhotonGtTmCmdError self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtTmCmdError_Deserialize(PhotonGtTmCmdError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) self, reader));
  return PhotonResult_Ok;
}