/* Type header */
#ifndef __PHOTON_GT_ADDRESS_H_2f7f5156b9dd6c7e440c37fa808ddf6d__
#define __PHOTON_GT_ADDRESS_H_2f7f5156b9dd6c7e440c37fa808ddf6d__ 

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