/* Type header */
#ifndef __PHOTON_GT_ARR_BER_MIN1_H_d835d4665da83eb5d1f625f5fecef181__
#define __PHOTON_GT_ARR_BER_MIN1_H_d835d4665da83eb5d1f625f5fecef181__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  size_t size;
  PhotonBer data[256];
} PhotonGtArrBerMin1;

PhotonResult PhotonGtArrBerMin1_Serialize(PhotonGtArrBerMin1* self, PhotonWriter* writer);

PhotonResult PhotonGtArrBerMin1_Deserialize(PhotonGtArrBerMin1* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif