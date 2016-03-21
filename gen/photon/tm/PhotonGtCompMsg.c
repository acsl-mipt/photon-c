/* Type implementation */
#include "photon/tm/PhotonGtCompMsg.h"


PhotonResult PhotonGtCompMsg_Serialize(PhotonGtCompMsg self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < sizeof(PhotonGtBer) + sizeof(PhotonGtBer))
    return PhotonResult_NotEnoughSpace;
  PhotonBer_Serialize(self.componentNum, writer);
  PhotonBer_Serialize(self.messageNum, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtCompMsg_Deserialize(PhotonGtCompMsg* self, PhotonReader* reader) {
  PhotonBer_Deserialize(&self->componentNum, reader);
  PhotonBer_Deserialize(&self->messageNum, reader);
  return PhotonResult_Ok;
}