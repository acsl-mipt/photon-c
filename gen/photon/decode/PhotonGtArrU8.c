/* Type implementation */
#include "photon/decode/PhotonGtArrU8.h"


PhotonResult PhotonGtArrU8_Serialize(PhotonGtArrU8 self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < self.size * /* u8{ */sizeof(PhotonGtU8)/* }u8 */)
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonBer_Serialize(self.size, writer));
  for(PhotonBer i = 0, size = self.size; i < size; ++i) {
    PhotonWriter_WriteUint8(writer, self.data[i]);
  }
  return PhotonResult_Ok;
}

PhotonResult PhotonGtArrU8_Deserialize(PhotonGtArrU8* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->size, reader));
  if (PhotonReader_ReadableSize(reader) < self->size * /* u8{ */sizeof(PhotonGtU8)/* }u8 */)
    return PhotonResult_NotEnoughData;
  for(PhotonBer i = 0, size = self->size; i < size; ++i) {
    self->data[i] = PhotonReader_ReadUint8(reader);
  }
  return PhotonResult_Ok;
}