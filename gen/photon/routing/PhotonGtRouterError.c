/* Type implementation */
#include "photon/routing/PhotonGtRouterError.h"


PhotonResult PhotonGtRouterError_Serialize(PhotonGtRouterError self, PhotonWriter* writer) {
  PhotonBer_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtRouterError_Deserialize(PhotonGtRouterError* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) self, reader);
  return PhotonResult_Ok;
}