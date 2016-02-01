/* Type header */
#ifndef __PHOTON_GT_GUID_H_7826da81543c36fcc723292215ef9cca__
#define __PHOTON_GT_GUID_H_7826da81543c36fcc723292215ef9cca__ 

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