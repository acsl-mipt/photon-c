/* Type implementation */
#include "photon/segmentation/PhotonGtSegmentStopAckError.h"


PhotonResult PhotonGtSegmentStopAckError_Serialize(const PhotonGtSegmentStopAckError* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < sizeof(PhotonBer))
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonBer_Serialize(self, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtSegmentStopAckError_Deserialize(PhotonGtSegmentStopAckError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(self, reader));
  return PhotonResult_Ok;
}