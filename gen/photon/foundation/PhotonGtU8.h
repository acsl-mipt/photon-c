/* Type header */
#ifndef __PHOTON_GT_U8_H_c3a8ea0885117d43ed0354374752ef4f__
#define __PHOTON_GT_U8_H_c3a8ea0885117d43ed0354374752ef4f__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char PhotonGtU8;

PhotonResult PhotonGtU8_Serialize(PhotonGtU8* self, PhotonWriter* writer);

PhotonResult PhotonGtU8_Deserialize(PhotonGtU8* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif