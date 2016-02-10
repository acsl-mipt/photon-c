/* Type implementation */
#include "photon/tm/PhotonGtEventInfo.h"


PhotonResult PhotonGtEventInfo_Serialize(const PhotonGtEventInfo* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < sizeof(PhotonBer) + sizeof(PhotonBer) + sizeof(PhotonBer))
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonGtCompMsg_Serialize(self->componentMessage, writer));
  PHOTON_TRY(PhotonBer_Serialize(self->eventNum, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtEventInfo_Deserialize(PhotonGtEventInfo* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonGtCompMsg_Deserialize(&self->componentMessage, reader));
  PHOTON_TRY(PhotonBer_Deserialize(&self->eventNum, reader));
  return PhotonResult_Ok;
}