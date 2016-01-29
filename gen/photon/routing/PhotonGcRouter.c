/* Component Router implementation */
#include "PhotonGcRouter.h"

PhotonResult PhotonGcRouter_SetRoute(PhotonGcRouter* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtAddress address;
  PHOTON_TRY(PhotonGtAddress_Deserialize(&address, reader));
  PhotonGtAddress next_hop;
  PHOTON_TRY(PhotonGtAddress_Deserialize(&next_hop, reader));
  self->setRoute(self, &address, &next_hop);
}

PhotonResult PhotonGcRouter_DelRoute(PhotonGcRouter* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtAddress address;
  PHOTON_TRY(PhotonGtAddress_Deserialize(&address, reader));
  self->delRoute(self, &address);
}

PhotonResult PhotonGcRouter_SetGroupRoute(PhotonGcRouter* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtAddress groupAddress;
  PHOTON_TRY(PhotonGtAddress_Deserialize(&groupAddress, reader));
  PhotonGtAddress next_hop;
  PHOTON_TRY(PhotonGtAddress_Deserialize(&next_hop, reader));
  self->setGroupRoute(self, &groupAddress, &next_hop);
}

PhotonResult PhotonGcRouter_DelGroupRoute(PhotonGcRouter* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtAddress groupAddress;
  PHOTON_TRY(PhotonGtAddress_Deserialize(&groupAddress, reader));
  self->delGroupRoute(self, &groupAddress);
}

PhotonResult PhotonGcRouter_ExecuteCommand(PhotonGcRouter* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcRouter_RouterSetRoute(self, reader, writer);
    case 1:
      return PhotonGcRouter_RouterDelRoute(self, reader, writer);
    case 2:
      return PhotonGcRouter_RouterSetGroupRoute(self, reader, writer);
    case 3:
      return PhotonGcRouter_RouterDelGroupRoute(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}