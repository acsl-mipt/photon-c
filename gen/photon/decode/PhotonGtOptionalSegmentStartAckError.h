/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_DECODE_PHOTON_GT_OPTIONAL_SEGMENT_START_ACK_ERROR_H__
#define __PHOTON_DECODE_PHOTON_GT_OPTIONAL_SEGMENT_START_ACK_ERROR_H__ 
#include "photon/photon_prologue.h"

#include "photon/segmentation/PhotonGtSegmentStartAckError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtSegmentStartAckError value;
  PhotonGtB8 flag;
} PhotonGtOptionalSegmentStartAckError;

PhotonResult PhotonGtOptionalSegmentStartAckError_Serialize(PhotonGtOptionalSegmentStartAckError self, PhotonWriter* writer);

PhotonResult PhotonGtOptionalSegmentStartAckError_Deserialize(PhotonGtOptionalSegmentStartAckError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif