/* Type header */
#ifndef __PHOTON_GT_PERIOD_H_3f2b62c1e4b9b6025c0507cc44c3df79__
#define __PHOTON_GT_PERIOD_H_3f2b62c1e4b9b6025c0507cc44c3df79__ 

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