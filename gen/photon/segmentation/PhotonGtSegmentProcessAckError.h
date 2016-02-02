/* Type header */
#ifndef __PHOTON_GT_SEGMENT_PROCESS_ACK_ERROR_H_eb41e5535403a976b1c5988338f4a714__
#define __PHOTON_GT_SEGMENT_PROCESS_ACK_ERROR_H_eb41e5535403a976b1c5988338f4a714__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_SEGMENT_PROCESS_ACK_ERROR_INVALID_STATE = 1
} PhotonGtSegmentProcessAckError;

PhotonResult PhotonGtSegmentProcessAckError_Serialize(PhotonGtSegmentProcessAckError* self, PhotonWriter* writer);

PhotonResult PhotonGtSegmentProcessAckError_Deserialize(PhotonGtSegmentProcessAckError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif