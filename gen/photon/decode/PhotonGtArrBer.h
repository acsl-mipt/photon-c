/* Type header */
#ifndef __PHOTON_GT_ARR_BER_H_48677cc9652827fc55b97488b7e7e488__
#define __PHOTON_GT_ARR_BER_H_48677cc9652827fc55b97488b7e7e488__ 

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