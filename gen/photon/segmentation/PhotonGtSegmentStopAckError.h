/* Type header */
#ifndef __PHOTON_GT_SEGMENT_STOP_ACK_ERROR_H_831e61b4db7daca8cca99bd5c190729b__
#define __PHOTON_GT_SEGMENT_STOP_ACK_ERROR_H_831e61b4db7daca8cca99bd5c190729b__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_SEGMENT_STOP_ACK_ERROR_NOT_STARTED = 1
  , PHOTON_GT_SEGMENT_STOP_ACK_ERROR_INVALID_STATE = 2
} PhotonGtSegmentStopAckError;

PhotonResult PhotonGtSegmentStopAckError_Serialize(PhotonGtSegmentStopAckError* self, PhotonWriter* writer);

PhotonResult PhotonGtSegmentStopAckError_Deserialize(PhotonGtSegmentStopAckError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif