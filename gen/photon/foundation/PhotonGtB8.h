/* Type header */
#ifndef __PHOTON_GT_B8_H_cb6ab354c8b6f7f0e73aa64a085a7345__
#define __PHOTON_GT_B8_H_cb6ab354c8b6f7f0e73aa64a085a7345__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char PhotonGtB8;

PhotonResult PhotonGtB8_Serialize(PhotonGtB8* self, PhotonWriter* writer);

PhotonResult PhotonGtB8_Deserialize(PhotonGtB8* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif