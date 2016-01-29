/* Type implementation */
#include "photon/foundation/PhotonGtU16.h"


PhotonResult PhotonGtU16_Serialize(PhotonGtU16* self, PhotonWriter* writer) {
  PhotonWriter_WriteUint16Le(writer, self);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtU16_Deserialize(PhotonGtU16* self, PhotonReader* reader) {
  *self = PhotonReader_ReadUint16Le(reader);
  return PhotonResult_Ok;
}