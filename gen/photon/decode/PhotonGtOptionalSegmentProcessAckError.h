/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_SEGMENT_PROCESS_ACK_ERROR_H_005ce9dcb0aa33e839561b93e4a2354a__
#define __PHOTON_GT_OPTIONAL_SEGMENT_PROCESS_ACK_ERROR_H_005ce9dcb0aa33e839561b93e4a2354a__ 

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