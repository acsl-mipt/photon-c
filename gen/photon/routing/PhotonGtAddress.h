/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_ROUTING_PHOTON_GT_ADDRESS_H__
#define __PHOTON_ROUTING_PHOTON_GT_ADDRESS_H__ 
#include "photon/prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef PhotonGtBer PhotonGtAddress;

PhotonResult PhotonGtAddress_Serialize(PhotonGtAddress self, PhotonWriter* writer);

PhotonResult PhotonGtAddress_Deserialize(PhotonGtAddress* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif