/* Type implementation */
#include "photon/decode/PhotonGtOrArrU8FileDownloadError.h"


PhotonResult PhotonGtOrArrU8FileDownloadError_Serialize(PhotonGtOrArrU8FileDownloadError self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self.tag, writer));
  switch (self.tag) {
    case 0:
      PhotonGtArrU8_Serialize(self._1, writer);
      break;
    case 1:
      PhotonBer_Serialize(self._2, writer);
      break;
    default:
      return PhotonResult_InvalidValue;
  }
  return PhotonResult_Ok;
}

PhotonResult PhotonGtOrArrU8FileDownloadError_Deserialize(PhotonGtOrArrU8FileDownloadError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize(&self->tag, reader));
  switch (self->tag) {
    case 0:
      PhotonGtArrU8_Deserialize(&self->_1, reader);
      break;
    case 1:
      PhotonBer_Deserialize((PhotonGtBer*) &self->_2, reader);
      break;
    default:
      return PhotonResult_InvalidValue;
  }
  return PhotonResult_Ok;
}