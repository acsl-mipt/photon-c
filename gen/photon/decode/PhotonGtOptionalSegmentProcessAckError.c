/* Type implementation */
#include "photon/decode/PhotonGtOptionalSegmentProcessAckError.h"


PhotonResult PhotonGtOptionalSegmentProcessAckError_Serialize(PhotonGtOptionalSegmentProcessAckError self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self.flag, writer));
  if (self.flag)
    PHOTON_TRY(PhotonBer_Serialize(self.value, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtOptionalSegmentProcessAckError_Deserialize(PhotonGtOptionalSegmentProcessAckError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) &self->flag, reader));
  if (self->flag)
    PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) &self->value, reader));
  return PhotonResult_Ok;
}