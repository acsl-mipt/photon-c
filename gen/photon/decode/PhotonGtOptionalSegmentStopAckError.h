/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_SEGMENT_STOP_ACK_ERROR_H_20be55b1c5f17e405505dc6618c490b6__
#define __PHOTON_GT_OPTIONAL_SEGMENT_STOP_ACK_ERROR_H_20be55b1c5f17e405505dc6618c490b6__ 

#include "photon/photon_prologue.h"

#include "photon/segmentation/PhotonGtSegmentStopAckError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtB8 flag;
  PhotonGtSegmentStopAckError value;
} PhotonGtOptionalSegmentStopAckError;

PhotonResult PhotonGtOptionalSegmentStopAckError_Serialize(PhotonGtOptionalSegmentStopAckError* self, PhotonWriter* writer);

PhotonResult PhotonGtOptionalSegmentStopAckError_Deserialize(PhotonGtOptionalSegmentStopAckError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif