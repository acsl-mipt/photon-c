/* Type header */
#ifndef __PHOTON_GT_DATE_TIME_H_de0bbd8ea9bd70c079e9fc1532bbe8e2__
#define __PHOTON_GT_DATE_TIME_H_de0bbd8ea9bd70c079e9fc1532bbe8e2__ 

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