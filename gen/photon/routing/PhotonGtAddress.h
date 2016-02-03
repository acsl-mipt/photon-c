/* Type header */
#ifndef __PHOTON_GT_ADDRESS_H_c1f0be507474fbe5c41a42ced07eb418__
#define __PHOTON_GT_ADDRESS_H_c1f0be507474fbe5c41a42ced07eb418__ 

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