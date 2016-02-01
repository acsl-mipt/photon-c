/* Type implementation */
#include "photon/tm/PhotonGtRingBuf.h"


PhotonResult PhotonGtRingBuf_Serialize(PhotonGtRingBuf* self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonGtArrU8_Serialize(&self->data, writer));
  PhotonBer_Serialize(&self->startOffset, writer);
  PhotonBer_Serialize(&self->endOffset, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtRingBuf_Deserialize(PhotonGtRingBuf* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonGtArrU8_Deserialize(&self->data, reader));
  PHOTON_TRY(PhotonBer_Deserialize(&self->startOffset, reader));
  PHOTON_TRY(PhotonBer_Deserialize(&self->endOffset, reader));
  return PhotonResult_Ok;
}