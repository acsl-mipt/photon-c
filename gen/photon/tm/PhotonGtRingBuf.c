/* Type implementation */
#include "photon/tm/PhotonGtRingBuf.h"


PhotonResult PhotonGtRingBuf_Serialize(PhotonGtRingBuf* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < (*self).data.size * sizeof(unsigned char) + sizeof(PhotonBer) + sizeof(PhotonBer))
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonGtArrU8_Serialize(&self->data, writer));
  PHOTON_TRY(PhotonBer_Serialize(self->startOffset, writer));
  PHOTON_TRY(PhotonBer_Serialize(self->endOffset, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtRingBuf_Deserialize(PhotonGtRingBuf* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonGtArrU8_Deserialize(&self->data, reader));
  PHOTON_TRY(PhotonBer_Deserialize(&self->startOffset, reader));
  PHOTON_TRY(PhotonBer_Deserialize(&self->endOffset, reader));
  return PhotonResult_Ok;
}