/* Type implementation */
#include "photon/foundation/PhotonGtI16.h"


PhotonResult PhotonGtI16_Serialize(PhotonGtI16* self, PhotonWriter* writer) {
  PhotonWriter_WriteInt16Le(writer, self);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtI16_Deserialize(PhotonGtI16* self, PhotonReader* reader) {
  PhotonReader_ReadInt16Le(reader);
  return PhotonResult_Ok;
}