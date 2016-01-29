/* Component Segment implementation */
#include "PhotonGcSegment.h"

PhotonResult PhotonGcSegment_StartSegmentAckMode(PhotonGcSegment* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStartAckError cmdResult = self->startSegmentAckMode(self);
  return PhotonGtOptionalSegmentStartAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegment_StopSegmentAckMode(PhotonGcSegment* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStopAckError cmdResult = self->stopSegmentAckMode(self);
  return PhotonGtOptionalSegmentStopAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegment_RequestAckModeStatus(PhotonGcSegment* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtB8 cmdResult = self->requestAckModeStatus(self);
  return PhotonGtB8_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegment_ProcessAckModeStatus(PhotonGcSegment* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtB8 isSegmentationAckModeActive;
  PHOTON_TRY(PhotonGtB8_Deserialize(&isSegmentationAckModeActive, reader));
  PhotonGtOptionalSegmentProcessAckError cmdResult = self->processAckModeStatus(self, &isSegmentationAckModeActive);
  return PhotonGtOptionalSegmentProcessAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegment_StartAckOnEverySegmentMode(PhotonGcSegment* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStartAckError cmdResult = self->startAckOnEverySegmentMode(self);
  return PhotonGtOptionalSegmentStartAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegment_StopAckOnEverySegmentMode(PhotonGcSegment* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStopAckError cmdResult = self->stopAckOnEverySegmentMode(self);
  return PhotonGtOptionalSegmentStopAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegment_ExecuteCommand(PhotonGcSegment* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcSegment_SegmentStartSegmentAckMode(self, reader, writer);
    case 1:
      return PhotonGcSegment_SegmentStopSegmentAckMode(self, reader, writer);
    case 2:
      return PhotonGcSegment_SegmentRequestAckModeStatus(self, reader, writer);
    case 3:
      return PhotonGcSegment_SegmentProcessAckModeStatus(self, reader, writer);
    case 4:
      return PhotonGcSegment_SegmentStartAckOnEverySegmentMode(self, reader, writer);
    case 5:
      return PhotonGcSegment_SegmentStopAckOnEverySegmentMode(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}