/* Type header */
#ifndef __PHOTON_GT_DATE_TIME_H_52be0582f7d14c4f2c9bbb55bcd4533f__
#define __PHOTON_GT_DATE_TIME_H_52be0582f7d14c4f2c9bbb55bcd4533f__ 

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