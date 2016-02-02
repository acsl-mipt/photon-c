/* Type header */
#ifndef __PHOTON_GT_PERIOD_H_bf556cc87b0e4ad26f8ea3d2a75b040d__
#define __PHOTON_GT_PERIOD_H_bf556cc87b0e4ad26f8ea3d2a75b040d__ 

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