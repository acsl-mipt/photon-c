/* Type implementation */
#include "photon/decode/PhotonGtArrBerMin1.h"


PhotonResult PhotonGtArrBerMin1_Serialize(PhotonGtArrBerMin1* self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self->size, writer));
  for(size_t i = 0, size = self->size; i < size; ++i) {
    PhotonBer_Serialize(&self->data[i], writer);
  }
  return PhotonResult_Ok;
}

PhotonResult PhotonGtArrBerMin1_Deserialize(PhotonGtArrBerMin1* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->size, reader));
  for(size_t i = 0, size = self->size; i < size; ++i) {
    PHOTON_TRY(PhotonBer_Deserialize(&self->data[i], reader));
  }
  return PhotonResult_Ok;
}