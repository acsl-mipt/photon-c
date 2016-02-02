/* Type implementation */
#include "photon/fs/PhotonGtFullFileInfo.h"


PhotonResult PhotonGtFullFileInfo_Serialize(PhotonGtFullFileInfo* self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonGtArrU8_Serialize(&self->filePath, writer));
  PHOTON_TRY(PhotonBer_Serialize(self->fileAttrs, writer));
  PHOTON_TRY(PhotonGtArrU8_Serialize(&self->fileContents, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFullFileInfo_Deserialize(PhotonGtFullFileInfo* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonGtArrU8_Deserialize(&self->filePath, reader));
  PHOTON_TRY(PhotonBer_Deserialize(&self->fileAttrs, reader));
  PHOTON_TRY(PhotonGtArrU8_Deserialize(&self->fileContents, reader));
  return PhotonResult_Ok;
}