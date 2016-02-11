/* Type implementation */
#include "photon/decode/PhotonGtOptionalRouterError.h"


PhotonResult PhotonGtOptionalRouterError_Serialize(const PhotonGtOptionalRouterError* self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self->flag, writer));
  if (self->flag)
    PHOTON_TRY(PhotonBer_Serialize(self->value, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtOptionalRouterError_Deserialize(PhotonGtOptionalRouterError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) &self->flag, reader));
  if (self->flag)
    PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) &self->value, reader));
  return PhotonResult_Ok;
}