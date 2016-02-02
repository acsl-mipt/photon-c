/* Type header */
#ifndef __PHOTON_GT_SEGMENT_START_ACK_ERROR_H_ed7b2cbc1bc5a525309b0dc854113ab8__
#define __PHOTON_GT_SEGMENT_START_ACK_ERROR_H_ed7b2cbc1bc5a525309b0dc854113ab8__ 

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