/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_SEGMENT_PROCESS_ACK_ERROR_H_d31b9fd0dd461d7e39cea579a1c3050a__
#define __PHOTON_GT_OPTIONAL_SEGMENT_PROCESS_ACK_ERROR_H_d31b9fd0dd461d7e39cea579a1c3050a__ 
#include "photon/photon_prologue.h"

#include "photon/segmentation/PhotonGtSegmentProcessAckError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtB8 flag;
  PhotonGtSegmentProcessAckError value;
} PhotonGtOptionalSegmentProcessAckError;

PhotonResult PhotonGtOptionalSegmentProcessAckError_Serialize(PhotonGtOptionalSegmentProcessAckError* self, PhotonWriter* writer);

PhotonResult PhotonGtOptionalSegmentProcessAckError_Deserialize(PhotonGtOptionalSegmentProcessAckError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif