/* Type implementation */
#include "photon/fs/PhotonGtNodeInfo.h"


PhotonResult PhotonGtNodeInfo_Serialize(const PhotonGtNodeInfo* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < /* node_info{ */sizeof(PhotonGtB8) + sizeof(PhotonGtBer)/* }node_info */)
    return PhotonResult_NotEnoughSpace;
  PhotonGtArrU8_Serialize(self->name, writer);
  PhotonWriter_WriteUint8(writer, self->isDir);
  PhotonBer_Serialize(self->attrs, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtNodeInfo_Deserialize(PhotonGtNodeInfo* self, PhotonReader* reader) {
  PhotonGtArrU8_Deserialize((PhotonGtArrU8*) &self->name, reader);
  self->isDir = PhotonReader_ReadUint8(reader);
  PhotonBer_Deserialize(&self->attrs, reader);
  return PhotonResult_Ok;
}