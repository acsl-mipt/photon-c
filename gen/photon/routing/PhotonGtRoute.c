/* Type implementation */
#include "photon/routing/PhotonGtRoute.h"


PhotonResult PhotonGtRoute_Serialize(PhotonGtRoute self, PhotonWriter* writer) {
  PhotonBer_Serialize(self.destination_address, writer);
  PhotonBer_Serialize(self.next_hop, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtRoute_Deserialize(PhotonGtRoute* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) &self->destination_address, reader);
  PhotonBer_Deserialize((PhotonGtBer*) &self->next_hop, reader);
  return PhotonResult_Ok;
}