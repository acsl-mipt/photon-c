/* Type header */
#ifndef __PHOTON_GT_I32_H_37869299d59dd2bf278cc9a28fab35c1__
#define __PHOTON_GT_I32_H_37869299d59dd2bf278cc9a28fab35c1__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef signed int PhotonGtI32;

PhotonResult PhotonGtI32_Serialize(PhotonGtI32* self, PhotonWriter* writer);

PhotonResult PhotonGtI32_Deserialize(PhotonGtI32* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif