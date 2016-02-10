/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_FOUNDATION_PHOTON_GT_ARR_ARR_U8_H__
#define __PHOTON_FOUNDATION_PHOTON_GT_ARR_ARR_U8_H__ 
#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtArrU8.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_GT_ARR_ARR_U8_MIN_LEN 0
#define PHOTON_GT_ARR_ARR_U8_MAX_LEN 256

typedef struct {
  size_t size;
  PhotonGtArrU8* data;
} PhotonGtArrArrU8;

PhotonResult PhotonGtArrArrU8_Serialize(const PhotonGtArrArrU8* self, PhotonWriter* writer);

PhotonResult PhotonGtArrArrU8_Deserialize(PhotonGtArrArrU8* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif