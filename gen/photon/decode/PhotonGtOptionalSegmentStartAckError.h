/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_SEGMENT_START_ACK_ERROR_H_a18fc78bed873a08c95b146cb9280fd2__
#define __PHOTON_GT_OPTIONAL_SEGMENT_START_ACK_ERROR_H_a18fc78bed873a08c95b146cb9280fd2__ 
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