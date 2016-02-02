/* Type header */
#ifndef __PHOTON_GT_U8_H_a7323835df4d0e2c0c3664dc601b55e1__
#define __PHOTON_GT_U8_H_a7323835df4d0e2c0c3664dc601b55e1__ 

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