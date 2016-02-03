/* Type header */
#ifndef __PHOTON_GT_DATE_TIME_H_f1d10e62b1f7604c6d7ca92b7015a5d9__
#define __PHOTON_GT_DATE_TIME_H_f1d10e62b1f7604c6d7ca92b7015a5d9__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef PhotonBer PhotonGtDateTime;

PhotonResult PhotonGtDateTime_Serialize(PhotonGtDateTime* self, PhotonWriter* writer);

PhotonResult PhotonGtDateTime_Deserialize(PhotonGtDateTime* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif