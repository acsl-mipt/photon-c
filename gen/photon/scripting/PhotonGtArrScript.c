/* Type implementation */
#include "photon/scripting/PhotonGtArrScript.h"


PhotonResult PhotonGtArrScript_Serialize(PhotonGtArrScript self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < self.size * sizeof(PhotonBer) + sizeof(PhotonBer) + sizeof(unsigned char) + sizeof(PhotonBer) + sizeof(unsigned char) + sizeof(PhotonBer) + sizeof(PhotonBer) + sizeof(unsigned char) + sizeof(PhotonBer) + sizeof(unsigned char) + sizeof(PhotonBer))
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonBer_Serialize(self.size, writer));
  for(PhotonBer i = 0, size = self.size; i < size; ++i) {
    PHOTON_TRY(PhotonGtScript_Serialize(&self.data[i], writer));
  }
  return PhotonResult_Ok;
}

PhotonResult PhotonGtArrScript_Deserialize(PhotonGtArrScript* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->size, reader));
  if (PhotonReader_ReadableSize(reader) < (*self).size * sizeof(PhotonBer) + sizeof(PhotonBer) + sizeof(unsigned char) + sizeof(PhotonBer) + sizeof(unsigned char) + sizeof(PhotonBer) + sizeof(PhotonBer) + sizeof(unsigned char) + sizeof(PhotonBer) + sizeof(unsigned char) + sizeof(PhotonBer))
    return PhotonResult_NotEnoughData;
  for(PhotonBer i = 0, size = self->size; i < size; ++i) {
    PHOTON_TRY(PhotonGtScript_Deserialize(&self->data[i], reader));
  }
  return PhotonResult_Ok;
}