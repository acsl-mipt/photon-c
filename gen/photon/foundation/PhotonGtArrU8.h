/* Type header */
#ifndef __PHOTON_GT_ARR_U8_H_f81c60ba37d54e5af1ca9efd55a4684f__
#define __PHOTON_GT_ARR_U8_H_f81c60ba37d54e5af1ca9efd55a4684f__ 

#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtU8.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  size_t size;
  PhotonGtU8 data[256];
} PhotonGtArrU8;

PhotonResult PhotonGtArrU8_Serialize(PhotonGtArrU8* self, PhotonWriter* writer);

PhotonResult PhotonGtArrU8_Deserialize(PhotonGtArrU8* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif