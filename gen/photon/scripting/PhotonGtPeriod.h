/* Type header */
#ifndef __PHOTON_GT_PERIOD_H_525d383725b3a1d3e3db0f4cc94dc1f6__
#define __PHOTON_GT_PERIOD_H_525d383725b3a1d3e3db0f4cc94dc1f6__ 

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