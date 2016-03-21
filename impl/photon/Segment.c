#include "photon/PhotonGcMain.h"

PhotonGtArrBerMin1 PhotonGcMain_SegmentReceiverRequestSegmentsAck()
{
}

PhotonGtSegmentStartAckError PhotonGcMain_SegmentStartSegmentAckMode()
{
    return PHOTON_GT_SEGMENT_START_ACK_ERROR_OK;
}

PhotonGtSegmentStopAckError PhotonGcMain_SegmentStopSegmentAckMode()
{
    return PHOTON_GT_SEGMENT_STOP_ACK_ERROR_OK;
}

PhotonGtB8 PhotonGcMain_SegmentRequestAckModeStatus()
{
    return false;
}

PhotonGtSegmentProcessAckError PhotonGcMain_SegmentProcessAckModeStatus(PhotonGtB8 isSegmentationAckModeActive)
{
    return PHOTON_GT_SEGMENT_PROCESS_ACK_ERROR_OK;
}

PhotonGtSegmentStartAckError PhotonGcMain_SegmentStartAckOnEverySegmentMode()
{
    return PHOTON_GT_SEGMENT_START_ACK_ERROR_OK;
}

PhotonGtSegmentStopAckError PhotonGcMain_SegmentStopAckOnEverySegmentMode()
{
    return PHOTON_GT_SEGMENT_STOP_ACK_ERROR_OK;
}

PhotonGtSegmentProcessAckError PhotonGcMain_SegmentSenderProcessSegmentsAck(PhotonGtArrBerMin1 segmentsReceived)
{
    return PHOTON_GT_SEGMENT_PROCESS_ACK_ERROR_OK;
}

PhotonGtArrBerMin1 PhotonGcMain_SegmentReceiverSegmentsReceived()
{
    PhotonGtArrBerMin1 rv;
    rv.size = 0;
    rv.data = 0;
    return rv;
}

PhotonGtB8 PhotonGcMain_SegmentIsSegmentationAckModeActive()
{
    return false;
}

PhotonGtBer PhotonGcMain_SegmentMaxSegmentNumber()
{
    return 0;
}

PhotonGtB8 PhotonGcMain_SegmentIsAckOnEverySegmentModeActive()
{
    return false;
}
