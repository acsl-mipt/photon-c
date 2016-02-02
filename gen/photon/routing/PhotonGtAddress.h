/* Type header */
#ifndef __PHOTON_GT_ADDRESS_H_fa98d7ea0bce8ab1197f3d3351b48cf4__
#define __PHOTON_GT_ADDRESS_H_fa98d7ea0bce8ab1197f3d3351b48cf4__ 

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