/* Component Segment interface */
#ifndef __PHOTON_GC_SEGMENT_H_c92b27d91ee4a034e682d6cbba8eaac5__
#define __PHOTON_GC_SEGMENT_H_c92b27d91ee4a034e682d6cbba8eaac5__ 

#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtB8.h"
#include "photon/decode/PhotonGtOptionalSegmentStopAckError.h"
#include "photon/decode/PhotonGtOptionalSegmentStartAckError.h"
#include "photon/decode/PhotonGtOptionalSegmentProcessAckError.h"

#ifdef __cplusplus
extern "C" {
#endif

struct PhotonGcSegmentUserFunctionTable_s;

typedef struct PhotonGcSegment_s PhotonGcSegment;

struct PhotonGcSegment_s {
  PhotonGcSegmentData* data;
  PhotonGtB8 (*isSegmentationAckModeActive)(PhotonGcSegment*);
  PhotonBer (*maxSegmentNumber)(PhotonGcSegment*);
  PhotonGtB8 (*isAckOnEverySegmentModeActive)(PhotonGcSegment*);
  PhotonGtOptionalSegmentStartAckError (*startSegmentAckMode)(PhotonGcSegment*);
  PhotonGtOptionalSegmentStopAckError (*stopSegmentAckMode)(PhotonGcSegment*);
  PhotonGtB8 (*requestAckModeStatus)(PhotonGcSegment*);
  PhotonGtOptionalSegmentProcessAckError (*processAckModeStatus)(PhotonGcSegment*, PhotonGtB8);
  PhotonGtOptionalSegmentStartAckError (*startAckOnEverySegmentMode)(PhotonGcSegment*);
  PhotonGtOptionalSegmentStopAckError (*stopAckOnEverySegmentMode)(PhotonGcSegment*);
};
PhotonResult PhotonGcSegment_StartSegmentAckMode(PhotonGcSegment* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcSegment_StopSegmentAckMode(PhotonGcSegment* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcSegment_RequestAckModeStatus(PhotonGcSegment* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcSegment_ProcessAckModeStatus(PhotonGcSegment* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcSegment_StartAckOnEverySegmentMode(PhotonGcSegment* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcSegment_StopAckOnEverySegmentMode(PhotonGcSegment* self, PhotonReader* reader, PhotonWriter* writer);

PhotonResult PhotonGcSegment_ExecuteCommand(PhotonGcSegment* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);

PhotonResult PhotonGcSegment_ReadExecuteCommand(PhotonGcSegment* self, PhotonReader* reader, PhotonWriter* writer);


#ifdef __cplusplus
}
#endif
#include "photon/photon_epilogue.h"

#endif