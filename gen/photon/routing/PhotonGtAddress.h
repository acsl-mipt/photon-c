/* Type header */
#ifndef __PHOTON_GT_ADDRESS_H_e32d0cac9ca894fb385665d05477423c__
#define __PHOTON_GT_ADDRESS_H_e32d0cac9ca894fb385665d05477423c__ 

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