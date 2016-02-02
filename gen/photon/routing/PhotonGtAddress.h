/* Type header */
#ifndef __PHOTON_GT_ADDRESS_H_f3a5109ea79606ae4c8c0f5d00395173__
#define __PHOTON_GT_ADDRESS_H_f3a5109ea79606ae4c8c0f5d00395173__ 

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