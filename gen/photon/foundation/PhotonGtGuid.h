/* Type header */
#ifndef __PHOTON_GT_GUID_H_797c350503d01e87cc0fa858a5903699__
#define __PHOTON_GT_GUID_H_797c350503d01e87cc0fa858a5903699__ 

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