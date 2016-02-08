/* Type implementation */
#include "photon/fs/PhotonGtFileDownloadError.h"


PhotonResult PhotonGtFileDownloadError_Serialize(PhotonGtFileDownloadError* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < sizeof(PhotonBer))
    return PhotonResult_NotEnoughSpace;
  PHOTON_TRY(PhotonBer_Serialize(self, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtFileDownloadError_Deserialize(PhotonGtFileDownloadError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(self, reader));
  return PhotonResult_Ok;
}