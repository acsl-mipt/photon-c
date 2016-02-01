/* Component SegmentReceiver interface */
#ifndef __PHOTON_GC_SEGMENT_RECEIVER_H_922c6c672b583879550100f42a25535d__
#define __PHOTON_GC_SEGMENT_RECEIVER_H_922c6c672b583879550100f42a25535d__ 

#include "photon/photon_prologue.h"

#include "photon/segmentation/PhotonGcSegment.h"

#include "photon/decode/PhotonGtArrBer.h"

#ifdef __cplusplus
extern "C" {
#endif

struct PhotonGcSegmentReceiverUserFunctionTable_s;

typedef struct PhotonGcSegmentReceiver_s PhotonGcSegmentReceiver;

struct PhotonGcSegmentReceiver_s {
  PhotonGcSegmentReceiverData* data;
  PhotonGtOptionalSegmentStartAckError (*segmentStartSegmentAckMode)(PhotonGcSegment*);
  PhotonGtOptionalSegmentStopAckError (*segmentStopSegmentAckMode)(PhotonGcSegment*);
  PhotonGtB8 (*segmentRequestAckModeStatus)(PhotonGcSegment*);
  PhotonGtOptionalSegmentProcessAckError (*segmentProcessAckModeStatus)(PhotonGcSegment*, PhotonGtB8*);
  PhotonGtOptionalSegmentStartAckError (*segmentStartAckOnEverySegmentMode)(PhotonGcSegment*);
  PhotonGtOptionalSegmentStopAckError (*segmentStopAckOnEverySegmentMode)(PhotonGcSegment*);
  PhotonGtArrBer (*segmentsReceived)(PhotonGcSegmentReceiver*);
  PhotonGtArrBer (*requestSegmentsAck)(PhotonGcSegmentReceiver*);
};
PhotonResult PhotonGcSegmentReceiver_RequestSegmentsAck(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcSegmentReceiver_SegmentStartSegmentAckMode(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcSegmentReceiver_SegmentStopSegmentAckMode(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcSegmentReceiver_SegmentRequestAckModeStatus(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcSegmentReceiver_SegmentProcessAckModeStatus(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcSegmentReceiver_SegmentStartAckOnEverySegmentMode(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcSegmentReceiver_SegmentStopAckOnEverySegmentMode(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer);

PhotonResult PhotonGcSegmentReceiver_ExecuteCommand(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);

PhotonResult PhotonGcSegmentReceiver_ReadExecuteCommand(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer);


#ifdef __cplusplus
}
#endif
#include "photon/photon_epilogue.h"

#endif