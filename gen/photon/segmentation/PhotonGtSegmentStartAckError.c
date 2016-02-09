/* Type implementation */
#include "photon/segmentation/PhotonGtSegmentStartAckError.h"


PhotonResult PhotonGtSegmentStartAckError_Serialize(const PhotonGtSegmentStartAckError* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < sizeof(PhotonBer))
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonBer_Serialize(self, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtSegmentStartAckError_Deserialize(PhotonGtSegmentStartAckError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(self, reader));
  return PhotonResult_Ok;
}