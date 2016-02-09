/* Type implementation */
#include "photon/decode/PhotonGtOrFileInfoFileDownloadError.h"


PhotonResult PhotonGtOrFileInfoFileDownloadError_Serialize(const PhotonGtOrFileInfoFileDownloadError* self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self->tag, writer));
  switch (self->tag) {
    case 0:
      PHOTON_TRY(PhotonGtFileInfo_Serialize(&self->_1, writer));
      break;
    case 1:
      PHOTON_TRY(PhotonBer_Serialize(self->_2, writer));
      break;
    default:
      return PhotonResult_InvalidValue;
  }
  return PhotonResult_Ok;
}

PhotonResult PhotonGtOrFileInfoFileDownloadError_Deserialize(PhotonGtOrFileInfoFileDownloadError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->tag, reader));
  switch (self->tag) {
    case 0:
      PHOTON_TRY(PhotonGtFileInfo_Deserialize(&self->_1, reader));
      break;
    case 1:
      PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) &self->_2, reader));
      break;
    default:
      return PhotonResult_InvalidValue;
  }
  return PhotonResult_Ok;
}