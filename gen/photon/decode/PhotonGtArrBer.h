/* Type header */
#ifndef __PHOTON_GT_ARR_BER_H_a4dd4fb2c192c7e42a432b6e6438ade5__
#define __PHOTON_GT_ARR_BER_H_a4dd4fb2c192c7e42a432b6e6438ade5__ 

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