/* Type header */
#ifndef __PHOTON_GT_DATE_TIME_H_88f6a3ff44f1f94e8820061f4755bfcc__
#define __PHOTON_GT_DATE_TIME_H_88f6a3ff44f1f94e8820061f4755bfcc__ 

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