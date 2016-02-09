/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_SEGMENTATION_PHOTON_GT_SEGMENT_START_ACK_ERROR_H__
#define __PHOTON_SEGMENTATION_PHOTON_GT_SEGMENT_START_ACK_ERROR_H__ 
#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_SEGMENT_START_ACK_ERROR_ALREADY_STARTED = 1
  , PHOTON_GT_SEGMENT_START_ACK_ERROR_INVALID_STATE = 2
} PhotonGtSegmentStartAckError;

PhotonResult PhotonGtSegmentStartAckError_Serialize(const PhotonGtSegmentStartAckError* self, PhotonWriter* writer);

PhotonResult PhotonGtSegmentStartAckError_Deserialize(PhotonGtSegmentStartAckError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif