/* Type header */
#ifndef __PHOTON_GT_ADDRESS_H_018ac2a6d842647c893d7689624dae85__
#define __PHOTON_GT_ADDRESS_H_018ac2a6d842647c893d7689624dae85__ 
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