/* Type implementation */
#include "photon/identification/PhotonGtFullId.h"


PhotonResult PhotonGtFullId_Serialize(const PhotonGtFullId* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < /* full_id{ */self->deviceComponentGuidPairs.size * /* component_number_guid_pair{ */(sizeof(PhotonGtBer) + sizeof(PhotonGtBer))/* }component_number_guid_pair *//* }full_id */)
    return PhotonResult_NotEnoughSpace;
  PhotonGtShortId_Serialize(self->shortId, writer);
  PhotonGtArrComponentNumberGuidPairFixed1_Serialize(self->deviceComponentGuidPairs, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFullId_Deserialize(PhotonGtFullId* self, PhotonReader* reader) {
  PhotonGtShortId_Deserialize(&self->shortId, reader);
  PhotonGtArrComponentNumberGuidPairFixed1_Deserialize(&self->deviceComponentGuidPairs, reader);
  return PhotonResult_Ok;
}