/* Type implementation */
#include "photon/identification/PhotonGtFullId.h"


PhotonResult PhotonGtFullId_Serialize(const PhotonGtFullId* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < (*self).deviceComponentGuidPairs.size * sizeof(PhotonGtBer) + sizeof(PhotonGtBer))
    return PhotonResult_NotEnoughSpace;
  PhotonGtShortId_Serialize(self->shortId, writer);
  PhotonGtArrComponentNumberGuidPairMin1_Serialize(self->deviceComponentGuidPairs, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFullId_Deserialize(PhotonGtFullId* self, PhotonReader* reader) {
  PhotonGtShortId_Deserialize(&self->shortId, reader);
  PhotonGtArrComponentNumberGuidPairMin1_Deserialize(&self->deviceComponentGuidPairs, reader);
  return PhotonResult_Ok;
}