/* Type implementation */
#include "photon/fs/PhotonGtFileInfo.h"


PhotonResult PhotonGtFileInfo_Serialize(const PhotonGtFileInfo* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < sizeof(PhotonBer) + sizeof(PhotonBer))
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonGtArrU8_Serialize(&self->path, writer));
  PHOTON_TRY(PhotonBer_Serialize(self->byteSize, writer));
  PHOTON_TRY(PhotonBer_Serialize(self->attrs, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFileInfo_Deserialize(PhotonGtFileInfo* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonGtArrU8_Deserialize((PhotonGtArrU8*) &self->path, reader));
  PHOTON_TRY(PhotonBer_Deserialize(&self->byteSize, reader));
  PHOTON_TRY(PhotonBer_Deserialize(&self->attrs, reader));
  return PhotonResult_Ok;
}