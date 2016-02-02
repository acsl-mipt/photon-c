/* Type implementation */
#include "photon/foundation/PhotonGtF32.h"


PhotonResult PhotonGtF32_Serialize(PhotonGtF32* self, PhotonWriter* writer) {
  PhotonWriter_WriteFloat32Le(writer, self);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtF32_Deserialize(PhotonGtF32* self, PhotonReader* reader) {
  PhotonReader_ReadFloat32Le(reader);
  return PhotonResult_Ok;
}