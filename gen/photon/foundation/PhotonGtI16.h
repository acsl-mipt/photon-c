/* Type header */
#ifndef __PHOTON_GT_I16_H_547494b1cdedf9b3eecc53d9e084b91b__
#define __PHOTON_GT_I16_H_547494b1cdedf9b3eecc53d9e084b91b__ 

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