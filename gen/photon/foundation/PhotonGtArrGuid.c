/* Type implementation */
#include "photon/foundation/PhotonGtArrGuid.h"


PhotonResult PhotonGtArrGuid_Serialize(PhotonGtArrGuid self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < self.size * sizeof(PhotonBer))
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonBer_Serialize(self.size, writer));
  for(PhotonBer i = 0, size = self.size; i < size; ++i) {
    PHOTON_TRY(PhotonBer_Serialize(self.data[i], writer));
  }
  return PhotonResult_Ok;
}

PhotonResult PhotonGtArrGuid_Deserialize(PhotonGtArrGuid* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->size, reader));
  if (PhotonReader_ReadableSize(reader) < (*self).size * sizeof(PhotonBer))
    return PhotonResult_NotEnoughData;
  for(PhotonBer i = 0, size = self->size; i < size; ++i) {
    PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) &self->data[i], reader));
  }
  return PhotonResult_Ok;
}