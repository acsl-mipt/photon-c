/* Type implementation */
#include "photon/decode/PhotonGtArrBerFixed1.h"


PhotonResult PhotonGtArrBerFixed1_Serialize(PhotonGtArrBerFixed1 self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < self.size * /* ber{ */sizeof(PhotonGtBer)/* }ber */)
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonBer_Serialize(self.size, writer));
  for(PhotonBer i = 0, size = self.size; i < size; ++i) {
    PhotonBer_Serialize(self.data[i], writer);
  }
  return PhotonResult_Ok;
}

PhotonResult PhotonGtArrBerFixed1_Deserialize(PhotonGtArrBerFixed1* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->size, reader));
  if (PhotonReader_ReadableSize(reader) < self->size * /* ber{ */sizeof(PhotonGtBer)/* }ber */)
    return PhotonResult_NotEnoughData;
  for(PhotonBer i = 0, size = self->size; i < size; ++i) {
    PhotonBer_Deserialize(&self->data[i], reader);
  }
  return PhotonResult_Ok;
}