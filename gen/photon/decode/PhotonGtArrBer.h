/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_DECODE_PHOTON_GT_ARR_BER_H__
#define __PHOTON_DECODE_PHOTON_GT_ARR_BER_H__ 
#include "photon/prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_GT_ARR_BER_MIN_SIZE 0
#define PHOTON_GT_ARR_BER_MAX_SIZE 0

typedef struct {
  size_t size;
  PhotonGtBer* data;
} PhotonGtArrBer;

PhotonResult PhotonGtArrBer_Serialize(PhotonGtArrBer self, PhotonWriter* writer);

PhotonResult PhotonGtArrBer_Deserialize(PhotonGtArrBer* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif