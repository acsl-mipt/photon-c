/* Type implementation */
#include "photon/decode/PhotonGtOptionalSegmentStartAckError.h"


PhotonResult PhotonGtOptionalSegmentStartAckError_Serialize(const PhotonGtOptionalSegmentStartAckError* self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self->flag, writer));
  if (self->flag)
    PHOTON_TRY(PhotonBer_Serialize(self->value, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtOptionalSegmentStartAckError_Deserialize(PhotonGtOptionalSegmentStartAckError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) &self->flag, reader));
  if (self->flag)
    PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) &self->value, reader));
  return PhotonResult_Ok;
}