/* Type header */
#ifndef __PHOTON_GT_PERIOD_H_dfe8e5aa9e4e3f7752bc0453550fcb10__
#define __PHOTON_GT_PERIOD_H_dfe8e5aa9e4e3f7752bc0453550fcb10__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef PhotonBer PhotonGtPeriod;

PhotonResult PhotonGtPeriod_Serialize(PhotonGtPeriod* self, PhotonWriter* writer);

PhotonResult PhotonGtPeriod_Deserialize(PhotonGtPeriod* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif