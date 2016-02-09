/* Type implementation */
#include "photon/segmentation/PhotonGtSegmentStopAckError.h"


PhotonResult PhotonGtSegmentStopAckError_Serialize(PhotonGtSegmentStopAckError self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtSegmentStopAckError_Deserialize(PhotonGtSegmentStopAckError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) self, reader));
  return PhotonResult_Ok;
}