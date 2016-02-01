/* Type header */
#ifndef __PHOTON_GT_RING_BUF_H_a8497aa556e12a8a91dc109f79ba4560__
#define __PHOTON_GT_RING_BUF_H_a8497aa556e12a8a91dc109f79ba4560__ 

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