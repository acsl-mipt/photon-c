/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_SCRIPTING_PHOTON_GT_PERIOD_H__
#define __PHOTON_SCRIPTING_PHOTON_GT_PERIOD_H__ 
#include "photon/prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef PhotonGtBer PhotonGtPeriod;

PhotonResult PhotonGtPeriod_Serialize(PhotonGtPeriod self, PhotonWriter* writer);

PhotonResult PhotonGtPeriod_Deserialize(PhotonGtPeriod* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif