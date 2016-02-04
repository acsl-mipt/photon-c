/* Type header */
#ifndef __PHOTON_GT_SEGMENT_PROCESS_ACK_ERROR_H_2865c310d700359021bd49568fb4a450__
#define __PHOTON_GT_SEGMENT_PROCESS_ACK_ERROR_H_2865c310d700359021bd49568fb4a450__ 

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