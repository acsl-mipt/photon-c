/* Type implementation */
#include "photon/routing/PhotonGtRouterError.h"


PhotonResult PhotonGtRouterError_Serialize(PhotonGtRouterError self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtRouterError_Deserialize(PhotonGtRouterError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) self, reader));
  return PhotonResult_Ok;
}