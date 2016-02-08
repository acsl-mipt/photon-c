/* Type implementation */
#include "photon/routing/PhotonGtArrRoute.h"


PhotonResult PhotonGtArrRoute_Serialize(PhotonGtArrRoute* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < (*self).size * sizeof(PhotonBer) + sizeof(PhotonBer))
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonBer_Serialize(self->size, writer));
  for(size_t i = 0, size = self->size; i < size; ++i) {
    PHOTON_TRY(PhotonGtRoute_Serialize(&self->data[i], writer));
  }
  return PhotonResult_Ok;
}

PhotonResult PhotonGtArrRoute_Deserialize(PhotonGtArrRoute* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->size, reader));
  if (PhotonReader_ReadableSize(reader) < (*self).size * sizeof(PhotonBer) + sizeof(PhotonBer))
    return PhotonResult_NotEnoughData;
  for(size_t i = 0, size = self->size; i < size; ++i) {
    PHOTON_TRY(PhotonGtRoute_Deserialize(&self->data[i], reader));
  }
  return PhotonResult_Ok;
}