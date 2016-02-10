/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_DECODE_PHOTON_GT_ARR_BER_H__
#define __PHOTON_DECODE_PHOTON_GT_ARR_BER_H__ 
#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_GT_ARR_BER_MIN_LEN 0
#define PHOTON_GT_ARR_BER_MAX_LEN 256

typedef struct {
  size_t size;
  PhotonBer* data;
} PhotonGtArrBer;

PhotonResult PhotonGtArrBer_Serialize(const PhotonGtArrBer* self, PhotonWriter* writer);

PhotonResult PhotonGtArrBer_Deserialize(PhotonGtArrBer* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif