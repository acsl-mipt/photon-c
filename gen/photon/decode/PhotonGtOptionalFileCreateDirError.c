/* Type implementation */
#include "photon/decode/PhotonGtOptionalFileCreateDirError.h"


PhotonResult PhotonGtOptionalFileCreateDirError_Serialize(const PhotonGtOptionalFileCreateDirError* self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonBer_Serialize(self->flag, writer));
  if (self->flag)
    PHOTON_TRY(PhotonBer_Serialize(self->value, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGtOptionalFileCreateDirError_Deserialize(PhotonGtOptionalFileCreateDirError* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) &self->flag, reader));
  if (self->flag)
    PHOTON_TRY(PhotonBer_Deserialize((PhotonBer*) &self->value, reader));
  return PhotonResult_Ok;
}