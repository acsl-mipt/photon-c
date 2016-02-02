/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_SEGMENT_PROCESS_ACK_ERROR_H_51b9ecb6c4d1df834ca66e3e561846fb__
#define __PHOTON_GT_OPTIONAL_SEGMENT_PROCESS_ACK_ERROR_H_51b9ecb6c4d1df834ca66e3e561846fb__ 

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