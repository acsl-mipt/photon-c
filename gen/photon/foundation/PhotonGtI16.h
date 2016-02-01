/* Type header */
#ifndef __PHOTON_GT_I16_H_73ac9016b56dffa1518bbbcb2dbe132f__
#define __PHOTON_GT_I16_H_73ac9016b56dffa1518bbbcb2dbe132f__ 

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