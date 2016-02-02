/* Type implementation */
#include "photon/foundation/PhotonGtI32.h"


PhotonResult PhotonGtI32_Serialize(PhotonGtI32* self, PhotonWriter* writer) {
  PhotonWriter_WriteInt32Le(writer, self);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtI32_Deserialize(PhotonGtI32* self, PhotonReader* reader) {
  PhotonReader_ReadInt32Le(reader);
  return PhotonResult_Ok;
}