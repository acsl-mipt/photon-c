/* Component SegmentSender interface */
#ifndef __PHOTON_GC_SEGMENT_SENDER_H_b77f3c70071c2b4b3c3bb07d3c5204dc__
#define __PHOTON_GC_SEGMENT_SENDER_H_b77f3c70071c2b4b3c3bb07d3c5204dc__ 

#include "photon/photon_prologue.h"

#include "photon/segmentation/PhotonGcSegment.h"

#include "photon/decode/PhotonGtOptionalSegmentProcessAckError.h"
#include "photon/decode/PhotonGtArrBerMin1.h"

#ifdef __cplusplus
extern "C" {
#endif

struct PhotonGcSegmentSenderUserFunctionTable_s;

typedef struct PhotonGcSegmentSender_s PhotonGcSegmentSender;

struct PhotonGcSegmentSender_s {
  PhotonGcSegmentSenderData* data;
  PhotonGtOptionalSegmentStartAckError (*segmentStartSegmentAckMode)(PhotonGcSegment*);
  PhotonGtOptionalSegmentStopAckError (*segmentStopSegmentAckMode)(PhotonGcSegment*);
  PhotonGtB8 (*segmentRequestAckModeStatus)(PhotonGcSegment*);
  PhotonGtOptionalSegmentProcessAckError (*segmentProcessAckModeStatus)(PhotonGcSegment*, PhotonGtB8*);
  PhotonGtOptionalSegmentStartAckError (*segmentStartAckOnEverySegmentMode)(PhotonGcSegment*);
  PhotonGtOptionalSegmentStopAckError (*segmentStopAckOnEverySegmentMode)(PhotonGcSegment*);
  PhotonGtOptionalSegmentProcessAckError (*processSegmentsAck)(PhotonGcSegmentSender*, PhotonGtArrBerMin1*);
};
PhotonResult PhotonGcSegmentSender_ProcessSegmentsAck(PhotonGcSegmentSender* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcSegmentSender_SegmentStartSegmentAckMode(PhotonGcSegmentSender* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcSegmentSender_SegmentStopSegmentAckMode(PhotonGcSegmentSender* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcSegmentSender_SegmentRequestAckModeStatus(PhotonGcSegmentSender* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcSegmentSender_SegmentProcessAckModeStatus(PhotonGcSegmentSender* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcSegmentSender_SegmentStartAckOnEverySegmentMode(PhotonGcSegmentSender* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcSegmentSender_SegmentStopAckOnEverySegmentMode(PhotonGcSegmentSender* self, PhotonReader* reader, PhotonWriter* writer);

PhotonResult PhotonGcSegmentSender_ExecuteCommand(PhotonGcSegmentSender* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);

PhotonResult PhotonGcSegmentSender_ReadExecuteCommand(PhotonGcSegmentSender* self, PhotonReader* reader, PhotonWriter* writer);


#ifdef __cplusplus
}
#endif
#include "photon/photon_epilogue.h"

#endif