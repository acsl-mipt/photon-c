/* Type header */
#ifndef __PHOTON_GT_DATE_TIME_H_2e5da92b565723ec030b8df9f64e777f__
#define __PHOTON_GT_DATE_TIME_H_2e5da92b565723ec030b8df9f64e777f__ 

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