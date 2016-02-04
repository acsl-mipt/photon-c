/* Type header */
#ifndef __PHOTON_GT_ARR_BER_MIN1_H_77dd7a08b3fa71efb961d0d2f2371bb8__
#define __PHOTON_GT_ARR_BER_MIN1_H_77dd7a08b3fa71efb961d0d2f2371bb8__ 

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