/* Type header */
#ifndef __PHOTON_GT_GUID_H_ab8d52824da45585d375221a56f12819__
#define __PHOTON_GT_GUID_H_ab8d52824da45585d375221a56f12819__ 

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