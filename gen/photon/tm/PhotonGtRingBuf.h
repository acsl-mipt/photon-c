/* Type header */
#ifndef __PHOTON_GT_RING_BUF_H_cb4deffbdce14941a6cd69f608d0c9b9__
#define __PHOTON_GT_RING_BUF_H_cb4deffbdce14941a6cd69f608d0c9b9__ 

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