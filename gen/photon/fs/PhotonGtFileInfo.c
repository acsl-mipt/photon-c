/* Type implementation */
#include "photon/fs/PhotonGtFileInfo.h"


PhotonResult PhotonGtFileInfo_Serialize(const PhotonGtFileInfo* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < sizeof(PhotonBer))
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonGtArrU8_Serialize(&self->filePath, writer));
  PHOTON_TRY(PhotonBer_Serialize(self->fileAttrs, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFileInfo_Deserialize(PhotonGtFileInfo* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonGtArrU8_Deserialize((PhotonGtArrU8*) &self->filePath, reader));
  PHOTON_TRY(PhotonBer_Deserialize(&self->fileAttrs, reader));
  return PhotonResult_Ok;
}