/* Component Segment implementation */
#include "photon/segmentation/PhotonGcSegment.h"

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
      return PhotonGcSegment_StartSegmentAckMode(self, reader, writer);
    case 1:
      return PhotonGcSegment_StopSegmentAckMode(self, reader, writer);
    case 2:
      return PhotonGcSegment_RequestAckModeStatus(self, reader, writer);
    case 3:
      return PhotonGcSegment_ProcessAckModeStatus(self, reader, writer);
    case 4:
      return PhotonGcSegment_StartAckOnEverySegmentMode(self, reader, writer);
    case 5:
      return PhotonGcSegment_StopAckOnEverySegmentMode(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcSegment_ReadExecuteCommand(PhotonGcSegment* self, PhotonReader* reader, PhotonWriter* writer) {
  size_t commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcSegment_ExecuteCommand(self, reader, writer, commandId);
}

PhotonResult PhotonGcSegment_WriteMessage(PhotonGcSegment* self, PhotonWriter* writer, size_t messageId) {
  PHOTON_TRY(PhotonBer_Serialize(messageId, writer));
  switch (messageId) {
    default:
      return PhotonResult_InvalidMessageId;
  }
}

PhotonGtB8 PhotonGcSegment_IsStatusMessage(size_t messageId) {
  switch (messageId) {
    default:
      return false;
  }
}

