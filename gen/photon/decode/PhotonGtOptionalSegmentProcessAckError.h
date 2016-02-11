/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_DECODE_PHOTON_GT_OPTIONAL_SEGMENT_PROCESS_ACK_ERROR_H__
#define __PHOTON_DECODE_PHOTON_GT_OPTIONAL_SEGMENT_PROCESS_ACK_ERROR_H__ 
#include "photon/photon_prologue.h"

#include "photon/segmentation/PhotonGtSegmentProcessAckError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtSegmentProcessAckError value;
  PhotonGtB8 flag;
} PhotonGtOptionalSegmentProcessAckError;

PhotonResult PhotonGtOptionalSegmentProcessAckError_Serialize(PhotonGtOptionalSegmentProcessAckError self, PhotonWriter* writer);

PhotonResult PhotonGtOptionalSegmentProcessAckError_Deserialize(PhotonGtOptionalSegmentProcessAckError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif