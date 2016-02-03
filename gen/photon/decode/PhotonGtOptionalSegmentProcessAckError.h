/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_SEGMENT_PROCESS_ACK_ERROR_H_f5521d5c4b3c2a5aa0d30410c4e3cb34__
#define __PHOTON_GT_OPTIONAL_SEGMENT_PROCESS_ACK_ERROR_H_f5521d5c4b3c2a5aa0d30410c4e3cb34__ 

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