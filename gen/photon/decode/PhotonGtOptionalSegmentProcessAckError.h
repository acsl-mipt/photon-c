/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_SEGMENT_PROCESS_ACK_ERROR_H_f294ef0871dd6e50fa9f47b1b97a5435__
#define __PHOTON_GT_OPTIONAL_SEGMENT_PROCESS_ACK_ERROR_H_f294ef0871dd6e50fa9f47b1b97a5435__ 

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