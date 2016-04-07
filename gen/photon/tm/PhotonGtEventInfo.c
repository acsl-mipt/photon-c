/* Type implementation */
#include "photon/tm/PhotonGtEventInfo.h"


PhotonResult PhotonGtEventInfo_Serialize(const PhotonGtEventInfo* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < /* event_info{ *//* comp_msg{ */sizeof(PhotonGtBer) + sizeof(PhotonGtBer)/* }comp_msg */ + sizeof(PhotonGtBer)/* }event_info */)
    return PhotonResult_NotEnoughSpace;
  PhotonGtCompMsg_Serialize(self->componentMessage, writer);
  PhotonBer_Serialize(self->eventNum, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtEventInfo_Deserialize(PhotonGtEventInfo* self, PhotonReader* reader) {
  PhotonGtCompMsg_Deserialize(&self->componentMessage, reader);
  PhotonBer_Deserialize(&self->eventNum, reader);
  return PhotonResult_Ok;
}