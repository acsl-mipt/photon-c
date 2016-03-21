/* Type implementation */
#include "photon/segmentation/PhotonGtSegmentStartAckError.h"


PhotonResult PhotonGtSegmentStartAckError_Serialize(PhotonGtSegmentStartAckError self, PhotonWriter* writer) {
  PhotonBer_Serialize(self, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtSegmentStartAckError_Deserialize(PhotonGtSegmentStartAckError* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) self, reader);
  return PhotonResult_Ok;
}