/* Type implementation */
#include "photon/identification/PhotonGtShortId.h"


PhotonResult PhotonGtShortId_Serialize(PhotonGtShortId* self, PhotonWriter* writer) {
  PhotonBer_Serialize(&self->deviceGuid, writer);
  PhotonBer_Serialize(&self->rootComponentGuid, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtShortId_Deserialize(PhotonGtShortId* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->deviceGuid, reader));
  PHOTON_TRY(PhotonBer_Deserialize(&self->rootComponentGuid, reader));
  return PhotonResult_Ok;
}