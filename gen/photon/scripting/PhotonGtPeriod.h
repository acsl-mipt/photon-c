/* Type header */
#ifndef __PHOTON_GT_PERIOD_H_d49660419e02f1c4af1d6f6a6f771c83__
#define __PHOTON_GT_PERIOD_H_d49660419e02f1c4af1d6f6a6f771c83__ 

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