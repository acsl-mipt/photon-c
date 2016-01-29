/* Type implementation */
#include "photon/foundation/PhotonGtU32.h"


PhotonResult PhotonGtU32_Serialize(PhotonGtU32* self, PhotonWriter* writer) {
  PhotonWriter_WriteUint32Le(writer, self);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtU32_Deserialize(PhotonGtU32* self, PhotonReader* reader) {
  *self = PhotonReader_ReadUint32Le(reader);
  return PhotonResult_Ok;
}