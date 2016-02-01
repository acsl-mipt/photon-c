/* Type header */
#ifndef __PHOTON_GT_PERIOD_H_692c9071c5ff4d61b8462d2edd1dbdab__
#define __PHOTON_GT_PERIOD_H_692c9071c5ff4d61b8462d2edd1dbdab__ 

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