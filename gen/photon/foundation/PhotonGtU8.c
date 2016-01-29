/* Type implementation */
#include "photon/foundation/PhotonGtU8.h"


PhotonResult PhotonGtU8_Serialize(PhotonGtU8* self, PhotonWriter* writer) {
  PhotonWriter_WriteUint8(writer, self);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtU8_Deserialize(PhotonGtU8* self, PhotonReader* reader) {
  *self = PhotonReader_ReadUint8(reader);
  return PhotonResult_Ok;
}