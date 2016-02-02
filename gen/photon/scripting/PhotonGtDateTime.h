/* Type header */
#ifndef __PHOTON_GT_DATE_TIME_H_73f32305bdd7894e78dbbd6c496f61c0__
#define __PHOTON_GT_DATE_TIME_H_73f32305bdd7894e78dbbd6c496f61c0__ 

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