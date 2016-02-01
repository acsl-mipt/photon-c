/* Type header */
#ifndef __PHOTON_GT_I8_H_55187446704ff4f22dafd91194a28b63__
#define __PHOTON_GT_I8_H_55187446704ff4f22dafd91194a28b63__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef signed char PhotonGtI8;

PhotonResult PhotonGtI8_Serialize(PhotonGtI8* self, PhotonWriter* writer);

PhotonResult PhotonGtI8_Deserialize(PhotonGtI8* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif