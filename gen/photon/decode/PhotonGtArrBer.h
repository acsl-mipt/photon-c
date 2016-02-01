/* Type header */
#ifndef __PHOTON_GT_ARR_BER_H_e93a9589df7145b217a290f13d95a14c__
#define __PHOTON_GT_ARR_BER_H_e93a9589df7145b217a290f13d95a14c__ 

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