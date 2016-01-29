/* Type implementation */
#include "photon/identification/PhotonGtFullId.h"


PhotonResult PhotonGtFullId_Serialize(PhotonGtFullId* self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonGtShortId_Serialize(&self->shortId, writer));
  PHOTON_TRY(PhotonGtArrComponentNumberGuidPairMin1_Serialize(&self->deviceComponentGuidPairs, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFullId_Deserialize(PhotonGtFullId* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonGtShortId_Deserialize(&self->shortId, reader));
  PHOTON_TRY(PhotonGtArrComponentNumberGuidPairMin1_Deserialize(&self->deviceComponentGuidPairs, reader));
  return PhotonResult_Ok;
}