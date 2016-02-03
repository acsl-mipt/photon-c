/* Component SegmentReceiver implementation */
#include "photon/segmentation/PhotonGcSegmentReceiver.h"

PhotonResult PhotonGcSegmentReceiver_RequestSegmentsAck(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtArrBer cmdResult = self->requestSegmentsAck(self);
  return PhotonGtArrBer_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegmentReceiver_SegmentStartSegmentAckMode(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStartAckError cmdResult = self->segmentStartSegmentAckMode(self);
  return PhotonGtOptionalSegmentStartAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegmentReceiver_SegmentStopSegmentAckMode(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStopAckError cmdResult = self->segmentStopSegmentAckMode(self);
  return PhotonGtOptionalSegmentStopAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegmentReceiver_SegmentRequestAckModeStatus(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtB8 cmdResult = self->segmentRequestAckModeStatus(self);
  return PhotonGtB8_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegmentReceiver_SegmentProcessAckModeStatus(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtB8 isSegmentationAckModeActive;
  PHOTON_TRY(PhotonGtB8_Deserialize(&isSegmentationAckModeActive, reader));
  PhotonGtOptionalSegmentProcessAckError cmdResult = self->segmentProcessAckModeStatus(self, &isSegmentationAckModeActive);
  return PhotonGtOptionalSegmentProcessAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegmentReceiver_SegmentStartAckOnEverySegmentMode(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStartAckError cmdResult = self->segmentStartAckOnEverySegmentMode(self);
  return PhotonGtOptionalSegmentStartAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegmentReceiver_SegmentStopAckOnEverySegmentMode(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStopAckError cmdResult = self->segmentStopAckOnEverySegmentMode(self);
  return PhotonGtOptionalSegmentStopAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegmentReceiver_WriteSegmentsReceived(PhotonGcSegmentReceiver* self, PhotonWriter* writer) {
  PhotonGtArrBer segmentsreceived = self->segmentsReceived(self);
  PHOTON_TRY(PhotonGtArrBer_Serialize(&segmentsreceived, writer));
  return PhotonResult_Ok;
}

PhotonResult PhotonGcSegmentReceiver_ExecuteCommand(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcSegmentReceiver_RequestSegmentsAck(self, reader, writer);
    case 1:
      return PhotonGcSegmentReceiver_SegmentStartSegmentAckMode(self, reader, writer);
    case 2:
      return PhotonGcSegmentReceiver_SegmentStopSegmentAckMode(self, reader, writer);
    case 3:
      return PhotonGcSegmentReceiver_SegmentRequestAckModeStatus(self, reader, writer);
    case 4:
      return PhotonGcSegmentReceiver_SegmentProcessAckModeStatus(self, reader, writer);
    case 5:
      return PhotonGcSegmentReceiver_SegmentStartAckOnEverySegmentMode(self, reader, writer);
    case 6:
      return PhotonGcSegmentReceiver_SegmentStopAckOnEverySegmentMode(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcSegmentReceiver_ReadExecuteCommand(PhotonGcSegmentReceiver* self, PhotonReader* reader, PhotonWriter* writer) {
  size_t commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcSegmentReceiver_ExecuteCommand(self, reader, writer, commandId);
}

PhotonResult PhotonGcSegmentReceiver_WriteMessage(PhotonGcSegmentReceiver* self, PhotonWriter* writer, size_t messageId) {
  switch (messageId) {
    case 0:
      return PhotonGcSegmentReceiver_WriteSegmentsReceived(self, writer);
    default:
      return PhotonResult_InvalidMessageId;
  }
}