/* Type header */
#ifndef __PHOTON_GT_ARR_BER_H_1a5f9bdbbcb5b32925285358820dbf90__
#define __PHOTON_GT_ARR_BER_H_1a5f9bdbbcb5b32925285358820dbf90__ 
#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  size_t size;
  PhotonBer data[256];
} PhotonGtArrBer;

PhotonResult PhotonGtArrBer_Serialize(PhotonGtArrBer* self, PhotonWriter* writer);

PhotonResult PhotonGtArrBer_Deserialize(PhotonGtArrBer* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif