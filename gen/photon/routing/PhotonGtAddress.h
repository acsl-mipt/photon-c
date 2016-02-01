/* Type header */
#ifndef __PHOTON_GT_ADDRESS_H_9f1276ff8b1ceb0ae890cf50e27b597a__
#define __PHOTON_GT_ADDRESS_H_9f1276ff8b1ceb0ae890cf50e27b597a__ 

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