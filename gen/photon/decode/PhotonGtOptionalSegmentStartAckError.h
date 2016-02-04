/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_SEGMENT_START_ACK_ERROR_H_25742aa2f637bf3ac025b3d5810e7aba__
#define __PHOTON_GT_OPTIONAL_SEGMENT_START_ACK_ERROR_H_25742aa2f637bf3ac025b3d5810e7aba__ 

#include "photon/photon_prologue.h"

#include "photon/segmentation/PhotonGtSegmentStartAckError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtB8 flag;
  PhotonGtSegmentStartAckError value;
} PhotonGtOptionalSegmentStartAckError;

PhotonResult PhotonGtOptionalSegmentStartAckError_Serialize(PhotonGtOptionalSegmentStartAckError* self, PhotonWriter* writer);

PhotonResult PhotonGtOptionalSegmentStartAckError_Deserialize(PhotonGtOptionalSegmentStartAckError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif