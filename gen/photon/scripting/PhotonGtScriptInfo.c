/* Type implementation */
#include "photon/scripting/PhotonGtScriptInfo.h"


PhotonResult PhotonGtScriptInfo_Serialize(const PhotonGtScriptInfo* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < /* script_info{ */self->scriptCode.size * /* u8{ */sizeof(PhotonGtU8)/* }u8 *//* }script_info */)
    return PhotonResult_NotEnoughSpace;
  PhotonBer_Serialize(self->scriptId, writer);
  PhotonGtArrU8_Serialize(self->scriptCode, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtScriptInfo_Deserialize(PhotonGtScriptInfo* self, PhotonReader* reader) {
  PhotonBer_Deserialize((PhotonGtBer*) (PhotonGtGuid*) &self->scriptId, reader);
  PhotonGtArrU8_Deserialize(&self->scriptCode, reader);
  return PhotonResult_Ok;
}