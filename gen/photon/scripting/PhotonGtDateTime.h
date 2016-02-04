/* Type header */
#ifndef __PHOTON_GT_DATE_TIME_H_e98594eadf062c6010a78b5876c4c4ba__
#define __PHOTON_GT_DATE_TIME_H_e98594eadf062c6010a78b5876c4c4ba__ 

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