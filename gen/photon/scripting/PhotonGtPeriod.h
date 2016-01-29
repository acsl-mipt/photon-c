/* Type header */
#ifndef __PHOTON_GT_PERIOD_H_981f48b422f34b89a1cc3e6c5e21fc79__
#define __PHOTON_GT_PERIOD_H_981f48b422f34b89a1cc3e6c5e21fc79__ 

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