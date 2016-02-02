/* Type implementation */
#include "photon/routing/PhotonGtRoute.h"


PhotonResult PhotonGtRoute_Serialize(PhotonGtRoute* self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self->destination_address, writer));
  PHOTON_TRY(PhotonBer_Serialize(self->next_hop, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtRoute_Deserialize(PhotonGtRoute* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->destination_address, reader));
  PHOTON_TRY(PhotonBer_Deserialize(&self->next_hop, reader));
  return PhotonResult_Ok;
}