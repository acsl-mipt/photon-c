/* Type implementation */
#include "photon/scripting/PhotonGtScript.h"


PhotonResult PhotonGtScript_Serialize(const PhotonGtScript* self, PhotonWriter* writer) {
  if (PhotonWriter_WritableSize(writer) < /* script{ *//* script_info{ */self->info.scriptCode.size * /* u8{ */sizeof(PhotonGtU8)/* }u8 *//* }script_info */ + /* script_run_timing{ */sizeof(PhotonGtB8) + sizeof(PhotonGtB8) + sizeof(PhotonGtB8)/* }script_run_timing *//* }script */)
    return PhotonResult_NotEnoughSpace;
  PhotonGtScriptInfo_Serialize(&self->info, writer);
  PhotonGtScriptRunTiming_Serialize(&self->runTiming, writer);
  return PhotonResult_Ok;
}

PhotonResult PhotonGtScript_Deserialize(PhotonGtScript* self, PhotonReader* reader) {
  PhotonGtScriptInfo_Deserialize(&self->info, reader);
  PhotonGtScriptRunTiming_Deserialize(&self->runTiming, reader);
  return PhotonResult_Ok;
}