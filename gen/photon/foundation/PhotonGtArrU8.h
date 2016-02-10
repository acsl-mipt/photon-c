/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_FOUNDATION_PHOTON_GT_ARR_U8_H__
#define __PHOTON_FOUNDATION_PHOTON_GT_ARR_U8_H__ 
#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtU8.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_GT_ARR_U8_MIN_LEN 0
#define PHOTON_GT_ARR_U8_MAX_LEN 256

typedef struct {
  size_t size;
  PhotonGtU8* data;
} PhotonGtArrU8;

PhotonResult PhotonGtArrU8_Serialize(const PhotonGtArrU8* self, PhotonWriter* writer);

PhotonResult PhotonGtArrU8_Deserialize(PhotonGtArrU8* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif