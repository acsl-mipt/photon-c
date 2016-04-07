/* Type implementation */
#include "photon/identification/PhotonGtArrComponentNumberGuidPairFixed1.h"


PhotonResult PhotonGtArrComponentNumberGuidPairFixed1_Serialize(PhotonGtArrComponentNumberGuidPairFixed1 self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < self.size * /* component_number_guid_pair{ */(sizeof(PhotonGtBer) + sizeof(PhotonGtBer))/* }component_number_guid_pair */)
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonBer_Serialize(self.size, writer));
  for(PhotonBer i = 0, size = self.size; i < size; ++i) {
    PhotonGtComponentNumberGuidPair_Serialize(self.data[i], writer);
  }
  return PhotonResult_Ok;
}

PhotonResult PhotonGtArrComponentNumberGuidPairFixed1_Deserialize(PhotonGtArrComponentNumberGuidPairFixed1* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->size, reader));
  if (PhotonReader_ReadableSize(reader) < self->size * /* component_number_guid_pair{ */(sizeof(PhotonGtBer) + sizeof(PhotonGtBer))/* }component_number_guid_pair */)
    return PhotonResult_NotEnoughData;
  for(PhotonBer i = 0, size = self->size; i < size; ++i) {
    PhotonGtComponentNumberGuidPair_Deserialize(&self->data[i], reader);
  }
  return PhotonResult_Ok;
}