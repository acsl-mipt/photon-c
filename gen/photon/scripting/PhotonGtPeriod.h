/* Type header */
#ifndef __PHOTON_GT_PERIOD_H_336519afa9700735aad0d6d047dd05c0__
#define __PHOTON_GT_PERIOD_H_336519afa9700735aad0d6d047dd05c0__ 
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