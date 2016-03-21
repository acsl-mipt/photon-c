/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_DECODE_PHOTON_GT_ARR_BER_MIN1_H__
#define __PHOTON_DECODE_PHOTON_GT_ARR_BER_MIN1_H__ 
#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_GT_ARR_BER_MIN1_MIN_SIZE 1
#define PHOTON_GT_ARR_BER_MIN1_MAX_SIZE 0

typedef struct {
  size_t size;
  PhotonGtBer* data;
} PhotonGtArrBerMin1;

PhotonResult PhotonGtArrBerMin1_Serialize(PhotonGtArrBerMin1 self, PhotonWriter* writer);

PhotonResult PhotonGtArrBerMin1_Deserialize(PhotonGtArrBerMin1* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif