/* Type header */
#ifndef __PHOTON_GT_ADDRESS_H_2e13a39b3e9e0f299f0d7688a4d43a38__
#define __PHOTON_GT_ADDRESS_H_2e13a39b3e9e0f299f0d7688a4d43a38__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef PhotonBer PhotonGtAddress;

PhotonResult PhotonGtAddress_Serialize(PhotonGtAddress* self, PhotonWriter* writer);

PhotonResult PhotonGtAddress_Deserialize(PhotonGtAddress* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif