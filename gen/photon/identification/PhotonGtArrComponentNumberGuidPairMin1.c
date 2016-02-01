/* Type implementation */
#include "photon/identification/PhotonGtArrComponentNumberGuidPairMin1.h"


PhotonResult PhotonGtArrComponentNumberGuidPairMin1_Serialize(PhotonGtArrComponentNumberGuidPairMin1* self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self->size, writer));
  for(size_t i = 0, size = self->size; i < size; ++i) {
    PHOTON_TRY(PhotonGtComponentNumberGuidPair_Serialize(&self->data[i], writer));
  }
  return PhotonResult_Ok;
}

PhotonResult PhotonGtArrComponentNumberGuidPairMin1_Deserialize(PhotonGtArrComponentNumberGuidPairMin1* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->size, reader));
  for(size_t i = 0, size = self->size; i < size; ++i) {
    PHOTON_TRY(PhotonGtComponentNumberGuidPair_Deserialize(&self->data[i], reader));
  }
  return PhotonResult_Ok;
}