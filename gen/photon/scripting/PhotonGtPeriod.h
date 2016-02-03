/* Type header */
#ifndef __PHOTON_GT_PERIOD_H_1e42f123983c06ff51b36c3f870c233f__
#define __PHOTON_GT_PERIOD_H_1e42f123983c06ff51b36c3f870c233f__ 

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