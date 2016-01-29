/* Component SegmentSender implementation */
#include "PhotonGcSegmentSender.h"

PhotonResult PhotonGcSegmentSender_ProcessSegmentsAck(PhotonGcSegmentSender* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtArrBerMin1 segmentsReceived;
  PHOTON_TRY(PhotonGtArrBerMin1_Deserialize(&segmentsReceived, reader));
  PhotonGtOptionalSegmentProcessAckError cmdResult = self->processSegmentsAck(self, &segmentsReceived);
  return PhotonGtOptionalSegmentProcessAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegmentSender_SegmentStartSegmentAckMode(PhotonGcSegmentSender* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStartAckError cmdResult = self->segmentStartSegmentAckMode(self);
  return PhotonGtOptionalSegmentStartAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegmentSender_SegmentStopSegmentAckMode(PhotonGcSegmentSender* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStopAckError cmdResult = self->segmentStopSegmentAckMode(self);
  return PhotonGtOptionalSegmentStopAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegmentSender_SegmentRequestAckModeStatus(PhotonGcSegmentSender* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtB8 cmdResult = self->segmentRequestAckModeStatus(self);
  return PhotonGtB8_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegmentSender_SegmentProcessAckModeStatus(PhotonGcSegmentSender* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtB8 isSegmentationAckModeActive;
  PHOTON_TRY(PhotonGtB8_Deserialize(&isSegmentationAckModeActive, reader));
  PhotonGtOptionalSegmentProcessAckError cmdResult = self->segmentProcessAckModeStatus(self, &isSegmentationAckModeActive);
  return PhotonGtOptionalSegmentProcessAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegmentSender_SegmentStartAckOnEverySegmentMode(PhotonGcSegmentSender* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStartAckError cmdResult = self->segmentStartAckOnEverySegmentMode(self);
  return PhotonGtOptionalSegmentStartAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegmentSender_SegmentStopAckOnEverySegmentMode(PhotonGcSegmentSender* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtOptionalSegmentStopAckError cmdResult = self->segmentStopAckOnEverySegmentMode(self);
  return PhotonGtOptionalSegmentStopAckError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcSegmentSender_ExecuteCommand(PhotonGcSegmentSender* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcSegmentSender_SegmentSenderProcessSegmentsAck(self, reader, writer);
    case 1:
      return PhotonGcSegmentSender_SegmentStartSegmentAckMode(self, reader, writer);
    case 2:
      return PhotonGcSegmentSender_SegmentStopSegmentAckMode(self, reader, writer);
    case 3:
      return PhotonGcSegmentSender_SegmentRequestAckModeStatus(self, reader, writer);
    case 4:
      return PhotonGcSegmentSender_SegmentProcessAckModeStatus(self, reader, writer);
    case 5:
      return PhotonGcSegmentSender_SegmentStartAckOnEverySegmentMode(self, reader, writer);
    case 6:
      return PhotonGcSegmentSender_SegmentStopAckOnEverySegmentMode(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}