/* Type implementation */
#include "photon/foundation/PhotonGtArrU8.h"


PhotonResult PhotonGtArrU8_Serialize(PhotonGtArrU8* self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self->size, writer));
  for(size_t i = 0, size = self->size; i < size; ++i) {
    PhotonWriter_WriteUint8(writer, self->data[i]);
  }
  return PhotonResult_Ok;
}

PhotonResult PhotonGtArrU8_Deserialize(PhotonGtArrU8* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->size, reader));
  for(size_t i = 0, size = self->size; i < size; ++i) {
    PhotonReader_ReadUint8(reader);
  }
  return PhotonResult_Ok;
}