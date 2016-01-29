/* Type implementation */
#include "photon/fs/PhotonGtNodeInfo.h"


PhotonResult PhotonGtNodeInfo_Serialize(PhotonGtNodeInfo* self, PhotonWriter* writer) {
  PHOTON_TRY(PhotonGtArrU8_Serialize(&self->name, writer));
  PhotonWriter_WriteUint8(writer, &self->isDir);
  PhotonBer_Serialize(&self->attrs, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtNodeInfo_Deserialize(PhotonGtNodeInfo* self, PhotonReader* reader) {
  PHOTON_TRY(PhotonGtArrU8_Deserialize(&self->name, reader));
  self->isDir = PhotonReader_ReadUint8(reader);
  PHOTON_TRY(PhotonBer_Deserialize(&self->attrs, reader));
  return PhotonResult_Ok;
}