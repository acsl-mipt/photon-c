/* Type header */
#ifndef __PHOTON_GT_SEGMENT_PROCESS_ACK_ERROR_H_86be35f661f4995dce578e7e2fa0ccaf__
#define __PHOTON_GT_SEGMENT_PROCESS_ACK_ERROR_H_86be35f661f4995dce578e7e2fa0ccaf__ 

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