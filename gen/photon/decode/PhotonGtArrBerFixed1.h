/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_DECODE_PHOTON_GT_ARR_BER_FIXED1_H__
#define __PHOTON_DECODE_PHOTON_GT_ARR_BER_FIXED1_H__ 
#include "photon/prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_GT_ARR_BER_FIXED1_MIN_SIZE 1
#define PHOTON_GT_ARR_BER_FIXED1_MAX_SIZE 1

typedef struct {
  size_t size;
  PhotonGtBer data[1];
} PhotonGtArrBerFixed1;

PhotonResult PhotonGtArrBerFixed1_Serialize(PhotonGtArrBerFixed1 self, PhotonWriter* writer);

PhotonResult PhotonGtArrBerFixed1_Deserialize(PhotonGtArrBerFixed1* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif