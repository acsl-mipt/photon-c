#include "photon/PhotonGcMain.h"
#include "photon/RingBuffer.h"
#include "photon/Encoder.h"

#include <stdbool.h>

#define _MSG_COUNT PHOTON_GC_MAIN_STATUS_MESSAGE_IDS_SIZE
#define _MSG_PRIORITIES PHOTON_GC_MAIN_STATUS_MESSAGE_PRIORITIES

typedef struct {
    unsigned priority;
    int interest;
    bool isAllowed;
} PhotonTmMessageDesc;

typedef struct {
    unsigned currentMessage;
    unsigned allowedMessages;
    PhotonTmMessageDesc descriptors[_MSG_COUNT];
    PhotonTmStatusMessageGen statusEnc;
} PhotonTelemetry;

static PhotonTelemetry _tm;

static PhotonResult genNextStatusMessage(void* data, PhotonWriter* dest)
{
    (void)data;
    return PhotonGcMain_WriteStatusMessage(dest, _tm.currentMessage);
}

void PhotonTm_Init()
{
    _tm.currentMessage = 0;
    const unsigned priorities[_MSG_COUNT] = _MSG_PRIORITIES;
    for (unsigned i = 0; i < _MSG_COUNT; i++) {
        PhotonTmMessageDesc* desc = &_tm.descriptors[i];
        desc->priority = priorities[i];
        desc->interest = 0;
        if (desc->priority) {
            _tm.allowedMessages++;
        }
    }
    _tm.statusEnc.gen = genNextStatusMessage;
    _tm.statusEnc.data = 0;
    _tm.statusEnc.componentNumber = 0;
    _tm.statusEnc.messageNumber = 0;
    _tm.statusEnc.messageNumber = 0;
    _tm.statusEnc.maxSegmentNumber = 0;
}

static void selectNextMessage()
{
    _tm.currentMessage++;
    if (_tm.currentMessage >= _MSG_COUNT) {
        _tm.currentMessage = 0;
    }
}

PhotonResult PhotonTelemetry_CollectStatusMessages(PhotonWriter* dest)
{
    if (_tm.allowedMessages == 0) {
        return PhotonResult_Ok;
    }
    unsigned totalMessages = 0;
    while (true) {
        _tm.statusEnc.messageNumber = _tm.currentMessage;
        //FIXME: set component number
        PhotonResult rv = PhotonEncoder_EncodeTmStatusMessage(&_tm.statusEnc, dest);
        if (rv == PhotonResult_Ok) {
            selectNextMessage();
            totalMessages++;
            continue;
        } else if (rv == PhotonResult_NotEnoughSpace) {
            if (totalMessages == 0) {
                return PhotonResult_NotEnoughSpace;
            }
            return PhotonResult_Ok;
        } else {
            return rv;
        }
    }
    return PhotonResult_Ok;
}

PhotonResult PhotonTelemetry_CollectEventMessages(PhotonWriter* dest)
{
    // TODO
}

// commands

PhotonGtTmCmdError PhotonGcMain_TmSendStatusMessage(PhotonGtCompMsg componentMessage)
{
    // TODO
}

PhotonGtTmCmdError PhotonGcMain_TmSetMessageRequest(PhotonGtCompMsg componentMessage, PhotonBer priority)
{
    if (componentMessage.messageNum >= _MSG_COUNT) {
        return PHOTON_GT_TM_CMD_ERROR_INVALID_MESSAGE_NUM;
    }
    _tm.descriptors[componentMessage.messageNum].priority = priority;
    return PHOTON_GT_TM_CMD_ERROR_OK;
}

PhotonGtTmCmdError PhotonGcMain_TmClearMessageRequest(PhotonGtCompMsg componentMessage)
{
    return PhotonGcMain_TmSetMessageRequest(componentMessage, 0);
}

static PhotonGtTmCmdError allowMessage(PhotonGtCompMsg componentMessage, bool isAllowed)
{
    if (componentMessage.messageNum >= _MSG_COUNT) {
        return PHOTON_GT_TM_CMD_ERROR_INVALID_MESSAGE_NUM;
    }
    _tm.descriptors[componentMessage.messageNum].isAllowed = isAllowed;
    if (isAllowed) {
        _tm.allowedMessages++;
    } else {
        _tm.allowedMessages--;
    }
    return PHOTON_GT_TM_CMD_ERROR_OK;
}

PhotonGtTmCmdError PhotonGcMain_TmDenyMessage(PhotonGtCompMsg componentMessage)
{
    return allowMessage(componentMessage, false);
}

PhotonGtTmCmdError PhotonGcMain_TmAllowMessage(PhotonGtCompMsg componentMessage)
{
    return allowMessage(componentMessage, true);
}

PhotonGtTmCmdError PhotonGcMain_TmDenyEvent(const PhotonGtEventInfo* eventInfo)
{
    // TODO
}

PhotonGtTmCmdError PhotonGcMain_TmAllowEvent(const PhotonGtEventInfo* eventInfo)
{
    // TODO
}

// params

PhotonBer PhotonGcMain_TmAllowedMessages()
{
    return _tm.allowedMessages;
}

// other

PhotonGtB8 PhotonGcMain_IsEventAllowed(PhotonBer messageId, PhotonBer eventId)
{
    // TODO
}

