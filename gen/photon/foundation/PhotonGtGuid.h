/* Type header */
#ifndef __PHOTON_GT_GUID_H_457127f924f88db5bda6c49c7fb48fe6__
#define __PHOTON_GT_GUID_H_457127f924f88db5bda6c49c7fb48fe6__ 
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