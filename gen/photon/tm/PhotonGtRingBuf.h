/* Type header */
#ifndef __PHOTON_GT_RING_BUF_H_1bb57d11cc0f15c6deb5d3e22451d53b__
#define __PHOTON_GT_RING_BUF_H_1bb57d11cc0f15c6deb5d3e22451d53b__ 

#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtArrU8.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtArrU8 data;
  PhotonBer startOffset;
  PhotonBer endOffset;
} PhotonGtRingBuf;

PhotonResult PhotonGtRingBuf_Serialize(PhotonGtRingBuf* self, PhotonWriter* writer);

PhotonResult PhotonGtRingBuf_Deserialize(PhotonGtRingBuf* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif