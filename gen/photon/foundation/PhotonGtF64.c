/* Type implementation */
#include "photon/foundation/PhotonGtF64.h"


PhotonResult PhotonGtF64_Serialize(PhotonGtF64* self, PhotonWriter* writer) {
  PhotonWriter_WriteFloat64Le(writer, self);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtF64_Deserialize(PhotonGtF64* self, PhotonReader* reader) {
  *self = PhotonReader_ReadFloat64Le(reader);
  return PhotonResult_Ok;
}