/* Type implementation */
#include "photon/segmentation/PhotonGtSegmentProcessAckError.h"


PhotonResult PhotonGtSegmentProcessAckError_Serialize(PhotonGtSegmentProcessAckError* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < sizeof(PhotonBer))
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonBer_Serialize(self, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtSegmentProcessAckError_Deserialize(PhotonGtSegmentProcessAckError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(self, reader));
  return PhotonResult_Ok;
}