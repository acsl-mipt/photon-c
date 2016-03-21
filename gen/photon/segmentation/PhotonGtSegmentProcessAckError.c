/* Type implementation */
#include "photon/segmentation/PhotonGtSegmentProcessAckError.h"


PhotonResult PhotonGtSegmentProcessAckError_Serialize(PhotonGtSegmentProcessAckError self, PhotonWriter* writer) {
  PhotonBer_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtSegmentProcessAckError_Deserialize(PhotonGtSegmentProcessAckError* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) self, reader);
  return PhotonResult_Ok;
}