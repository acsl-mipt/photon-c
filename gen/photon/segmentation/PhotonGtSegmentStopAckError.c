/* Type implementation */
#include "photon/segmentation/PhotonGtSegmentStopAckError.h"


PhotonResult PhotonGtSegmentStopAckError_Serialize(PhotonGtSegmentStopAckError self, PhotonWriter* writer) {
  PhotonBer_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtSegmentStopAckError_Deserialize(PhotonGtSegmentStopAckError* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) self, reader);
  return PhotonResult_Ok;
}