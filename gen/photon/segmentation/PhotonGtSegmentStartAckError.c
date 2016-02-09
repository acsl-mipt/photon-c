/* Type implementation */
#include "photon/segmentation/PhotonGtSegmentStartAckError.h"


PhotonResult PhotonGtSegmentStartAckError_Serialize(PhotonGtSegmentStartAckError self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtSegmentStartAckError_Deserialize(PhotonGtSegmentStartAckError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) self, reader));
  return PhotonResult_Ok;
}