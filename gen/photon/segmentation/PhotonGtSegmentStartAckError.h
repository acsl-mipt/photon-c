/* Type header */
#ifndef __PHOTON_GT_SEGMENT_START_ACK_ERROR_H_7d8b0b17e3c0619834197c3db99acbd7__
#define __PHOTON_GT_SEGMENT_START_ACK_ERROR_H_7d8b0b17e3c0619834197c3db99acbd7__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_SEGMENT_START_ACK_ERROR_ALREADY_STARTED = 1
  , PHOTON_GT_SEGMENT_START_ACK_ERROR_INVALID_STATE = 2
} PhotonGtSegmentStartAckError;

PhotonResult PhotonGtSegmentStartAckError_Serialize(PhotonGtSegmentStartAckError* self, PhotonWriter* writer);

PhotonResult PhotonGtSegmentStartAckError_Deserialize(PhotonGtSegmentStartAckError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif