/* Type header */
#ifndef __PHOTON_GT_I16_H_4ad7850bd6e97abb4c326e82bd6ca783__
#define __PHOTON_GT_I16_H_4ad7850bd6e97abb4c326e82bd6ca783__ 

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