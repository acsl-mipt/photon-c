/* Type implementation */
#include "photon/identification/PhotonGtComponentNumberGuidPair.h"


PhotonResult PhotonGtComponentNumberGuidPair_Serialize(PhotonGtComponentNumberGuidPair* self, PhotonWriter* writer) {
  PhotonBer_Serialize(&self->number, writer);
  PhotonBer_Serialize(&self->guid, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtComponentNumberGuidPair_Deserialize(PhotonGtComponentNumberGuidPair* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->number, reader));
  PHOTON_TRY(PhotonBer_Deserialize(&self->guid, reader));
  return PhotonResult_Ok;
}