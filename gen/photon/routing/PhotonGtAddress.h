/* Type header */
#ifndef __PHOTON_GT_ADDRESS_H_d2f6e6d405e1456caa4812165ce5f189__
#define __PHOTON_GT_ADDRESS_H_d2f6e6d405e1456caa4812165ce5f189__ 

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