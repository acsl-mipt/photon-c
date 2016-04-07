/* Type implementation */
#include "photon/fs/PhotonGtArrNodeInfo.h"


PhotonResult PhotonGtArrNodeInfo_Serialize(PhotonGtArrNodeInfo self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < self.size * /* node_info{ */(sizeof(PhotonBer) + sizeof(PhotonGtB8) + sizeof(PhotonGtBer))/* }node_info */)
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonBer_Serialize(self.size, writer));
  for(PhotonBer i = 0, size = self.size; i < size; ++i) {
    PhotonGtNodeInfo_Serialize(&self.data[i], writer);
  }
  return PhotonResult_Ok;
}

PhotonResult PhotonGtArrNodeInfo_Deserialize(PhotonGtArrNodeInfo* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->size, reader));
  if (PhotonReader_ReadableSize(reader) < self->size * /* node_info{ */(sizeof(PhotonBer) + sizeof(PhotonGtB8) + sizeof(PhotonGtBer))/* }node_info */)
    return PhotonResult_NotEnoughData;
  for(PhotonBer i = 0, size = self->size; i < size; ++i) {
    PhotonGtNodeInfo_Deserialize(&self->data[i], reader);
  }
  return PhotonResult_Ok;
}