/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_SEGMENT_START_ACK_ERROR_H_b83a17833afe2645d2824a0e6a4ad479__
#define __PHOTON_GT_OPTIONAL_SEGMENT_START_ACK_ERROR_H_b83a17833afe2645d2824a0e6a4ad479__ 

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