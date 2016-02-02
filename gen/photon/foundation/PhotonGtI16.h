/* Type header */
#ifndef __PHOTON_GT_I16_H_576642b56ad503f358614c4230356874__
#define __PHOTON_GT_I16_H_576642b56ad503f358614c4230356874__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef signed short PhotonGtI16;

PhotonResult PhotonGtI16_Serialize(PhotonGtI16* self, PhotonWriter* writer);

PhotonResult PhotonGtI16_Deserialize(PhotonGtI16* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif