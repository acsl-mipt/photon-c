/* Type implementation */
#include "photon/decode/PhotonGtOptionalSegmentStopAckError.h"


PhotonResult PhotonGtOptionalSegmentStopAckError_Serialize(PhotonGtOptionalSegmentStopAckError self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self.flag, writer));
  if (self.flag)
    PHOTON_TRY(PhotonBer_Serialize(self.value, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtOptionalSegmentStopAckError_Deserialize(PhotonGtOptionalSegmentStopAckError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) &self->flag, reader));
  if (self->flag)
    PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) &self->value, reader));
  return PhotonResult_Ok;
}