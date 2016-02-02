/* Type implementation */
#include "photon/foundation/PhotonGtI8.h"


PhotonResult PhotonGtI8_Serialize(PhotonGtI8* self, PhotonWriter* writer) {
  PhotonWriter_WriteUint8(writer, self);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtI8_Deserialize(PhotonGtI8* self, PhotonReader* reader) {
  PhotonReader_ReadUint8(reader);
  return PhotonResult_Ok;
}