/* Type header */
#ifndef __PHOTON_GT_GUID_H_e09bae733df4b8768cd5bf5fdc280080__
#define __PHOTON_GT_GUID_H_e09bae733df4b8768cd5bf5fdc280080__ 

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