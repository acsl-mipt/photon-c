/* Type implementation */
#include "photon/fs/PhotonGtFileInfo.h"


PhotonResult PhotonGtFileInfo_Serialize(const PhotonGtFileInfo* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < /* file_info{ */sizeof(PhotonGtBer) + sizeof(PhotonGtBer)/* }file_info */)
    return PhotonResult_NotEnoughSpace;
  PhotonGtArrU8_Serialize(self->path, writer);
  PhotonBer_Serialize(self->byteSize, writer);
  PhotonBer_Serialize(self->attrs, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFileInfo_Deserialize(PhotonGtFileInfo* self, PhotonReader* reader) {
  PhotonGtArrU8_Deserialize((PhotonGtArrU8*) &self->path, reader);
  PhotonBer_Deserialize(&self->byteSize, reader);
  PhotonBer_Deserialize(&self->attrs, reader);
  return PhotonResult_Ok;
}