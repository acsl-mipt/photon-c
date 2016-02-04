/* Component SegmentSender interface */
#ifndef __PHOTON_GC_SEGMENT_SENDER_H_91e25663496d19bc928283633b916181__
#define __PHOTON_GC_SEGMENT_SENDER_H_91e25663496d19bc928283633b916181__ 

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
  PhotonGtOptionalSegmentStartAckError (*segmentStartSegmentAckMode)(PhotonGcSegmentSender*);
  PhotonGtOptionalSegmentStopAckError (*segmentStopSegmentAckMode)(PhotonGcSegmentSender*);
  PhotonGtB8 (*segmentRequestAckModeStatus)(PhotonGcSegmentSender*);
  PhotonGtOptionalSegmentProcessAckError (*segmentProcessAckModeStatus)(PhotonGcSegmentSender*, PhotonGtB8);
  PhotonGtOptionalSegmentStartAckError (*segmentStartAckOnEverySegmentMode)(PhotonGcSegmentSender*);
  PhotonGtOptionalSegmentStopAckError (*segmentStopAckOnEverySegmentMode)(PhotonGcSegmentSender*);
  PhotonGtB8 (*segmentIsSegmentationAckModeActive)(PhotonGcSegmentSender*);
  PhotonBer (*segmentMaxSegmentNumber)(PhotonGcSegmentSender*);
  PhotonGtB8 (*segmentIsAckOnEverySegmentModeActive)(PhotonGcSegmentSender*);
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
PhotonResult PhotonGcSegmentSender_WriteMessage(PhotonGcSegmentSender* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcSegmentSender_IsStatusMessage(size_t messageId);


#ifdef __cplusplus
}
#endif
#include "photon/photon_epilogue.h"

#endif