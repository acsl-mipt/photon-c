/* Type implementation */
#include "photon/foundation/PhotonGtB8.h"


PhotonResult PhotonGtB8_Serialize(PhotonGtB8* self, PhotonWriter* writer) {
  PhotonWriter_WriteUint8(writer, self);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtB8_Deserialize(PhotonGtB8* self, PhotonReader* reader) {
  PhotonReader_ReadUint8(reader);
  return PhotonResult_Ok;
}