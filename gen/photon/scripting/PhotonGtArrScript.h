/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_SCRIPTING_PHOTON_GT_ARR_SCRIPT_H__
#define __PHOTON_SCRIPTING_PHOTON_GT_ARR_SCRIPT_H__ 
#include "photon/prologue.h"

#include "photon/scripting/PhotonGtScript.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_GT_ARR_SCRIPT_MIN_SIZE 0
#define PHOTON_GT_ARR_SCRIPT_MAX_SIZE 0

typedef struct {
  size_t size;
  PhotonGtScript* data;
} PhotonGtArrScript;

PhotonResult PhotonGtArrScript_Serialize(PhotonGtArrScript self, PhotonWriter* writer);

PhotonResult PhotonGtArrScript_Deserialize(PhotonGtArrScript* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif