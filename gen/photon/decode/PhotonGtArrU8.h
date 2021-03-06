/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_DECODE_PHOTON_GT_ARR_U8_H__
#define __PHOTON_DECODE_PHOTON_GT_ARR_U8_H__ 
#include "photon/prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_GT_ARR_U8_MIN_SIZE 0
#define PHOTON_GT_ARR_U8_MAX_SIZE 0

typedef struct {
  size_t size;
  PhotonGtU8* data;
} PhotonGtArrU8;

PhotonResult PhotonGtArrU8_Serialize(PhotonGtArrU8 self, PhotonWriter* writer);

PhotonResult PhotonGtArrU8_Deserialize(PhotonGtArrU8* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif