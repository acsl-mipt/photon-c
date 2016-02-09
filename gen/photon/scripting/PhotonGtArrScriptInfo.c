/* Type implementation */
#include "photon/scripting/PhotonGtArrScriptInfo.h"


PhotonResult PhotonGtArrScriptInfo_Serialize(const PhotonGtArrScriptInfo* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < (*self).size * sizeof(PhotonBer) + sizeof(PhotonBer) + sizeof(unsigned char) + sizeof(PhotonBer) + sizeof(unsigned char))
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonBer_Serialize(self->size, writer));
  for(size_t i = 0, size = self->size; i < size; ++i) {
    PHOTON_TRY(PhotonGtScriptInfo_Serialize(&self->data[i], writer));
  }
  return PhotonResult_Ok;
}

PhotonResult PhotonGtArrScriptInfo_Deserialize(PhotonGtArrScriptInfo* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->size, reader));
  if (PhotonReader_ReadableSize(reader) < (*self).size * sizeof(PhotonBer) + sizeof(PhotonBer) + sizeof(unsigned char) + sizeof(PhotonBer) + sizeof(unsigned char))
    return PhotonResult_NotEnoughData;
  for(size_t i = 0, size = self->size; i < size; ++i) {
    PHOTON_TRY(PhotonGtScriptInfo_Deserialize(&self->data[i], reader));
  }
  return PhotonResult_Ok;
}