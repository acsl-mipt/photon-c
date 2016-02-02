/* Component SegmentReceiver interface */
#ifndef __PHOTON_GC_SEGMENT_RECEIVER_H_ca6c7cec10e70563591a134132ddd24b__
#define __PHOTON_GC_SEGMENT_RECEIVER_H_ca6c7cec10e70563591a134132ddd24b__ 

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
  PhotonGtOptionalSegmentStartAckError (*segmentStartSegmentAckMode)(PhotonGcSegmentReceiver*);
  PhotonGtOptionalSegmentStopAckError (*segmentStopSegmentAckMode)(PhotonGcSegmentReceiver*);
  PhotonGtB8 (*segmentRequestAckModeStatus)(PhotonGcSegmentReceiver*);
  PhotonGtOptionalSegmentProcessAckError (*segmentProcessAckModeStatus)(PhotonGcSegmentReceiver*, PhotonGtB8*);
  PhotonGtOptionalSegmentStartAckError (*segmentStartAckOnEverySegmentMode)(PhotonGcSegmentReceiver*);
  PhotonGtOptionalSegmentStopAckError (*segmentStopAckOnEverySegmentMode)(PhotonGcSegmentReceiver*);
  PhotonGtB8 (*segmentIsSegmentationAckModeActive)(PhotonGcSegmentReceiver*);
  PhotonBer (*segmentMaxSegmentNumber)(PhotonGcSegmentReceiver*);
  PhotonGtB8 (*segmentIsAckOnEverySegmentModeActive)(PhotonGcSegmentReceiver*);
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

PhotonResult PhotonGcSegmentReceiver_ReadExecuteCommand(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer);


#ifdef __cplusplus
}
#endif
#include "photon/photon_epilogue.h"

#endif