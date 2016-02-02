/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_SEGMENT_START_ACK_ERROR_H_ed73fa495510f9b97a7f5411257f6d57__
#define __PHOTON_GT_OPTIONAL_SEGMENT_START_ACK_ERROR_H_ed73fa495510f9b97a7f5411257f6d57__ 

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