/* Type implementation */
#include "photon/identification/PhotonGtComponentNumberGuidPair.h"


PhotonResult PhotonGtComponentNumberGuidPair_Serialize(const PhotonGtComponentNumberGuidPair* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < sizeof(PhotonBer))
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonBer_Serialize(self->number, writer));
  PHOTON_TRY(PhotonBer_Serialize(self->guid, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtComponentNumberGuidPair_Deserialize(PhotonGtComponentNumberGuidPair* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->number, reader));
  PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) &self->guid, reader));
  return PhotonResult_Ok;
}