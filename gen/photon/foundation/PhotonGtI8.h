/* Type header */
#ifndef __PHOTON_GT_I8_H_7714d89ed35aa343beff7a49a812688b__
#define __PHOTON_GT_I8_H_7714d89ed35aa343beff7a49a812688b__ 

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