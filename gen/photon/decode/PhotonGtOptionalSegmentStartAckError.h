/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_SEGMENT_START_ACK_ERROR_H_bd57b37c5923613efb6f7f6acb372cfc__
#define __PHOTON_GT_OPTIONAL_SEGMENT_START_ACK_ERROR_H_bd57b37c5923613efb6f7f6acb372cfc__ 

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