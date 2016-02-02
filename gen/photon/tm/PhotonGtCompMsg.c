/* Type implementation */
#include "photon/tm/PhotonGtCompMsg.h"


PhotonResult PhotonGtCompMsg_Serialize(PhotonGtCompMsg* self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self->componentNum, writer));
  PHOTON_TRY(PhotonBer_Serialize(self->messageNum, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtCompMsg_Deserialize(PhotonGtCompMsg* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->componentNum, reader));
  PHOTON_TRY(PhotonBer_Deserialize(&self->messageNum, reader));
  return PhotonResult_Ok;
}