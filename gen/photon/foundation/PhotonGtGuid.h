/* Type header */
#ifndef __PHOTON_GT_GUID_H_46a44116fb0b6dd9692929155586b2d5__
#define __PHOTON_GT_GUID_H_46a44116fb0b6dd9692929155586b2d5__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef PhotonBer PhotonGtGuid;

PhotonResult PhotonGtGuid_Serialize(PhotonGtGuid* self, PhotonWriter* writer);

PhotonResult PhotonGtGuid_Deserialize(PhotonGtGuid* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif