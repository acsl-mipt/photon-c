#include "photon/Result.h"

const char* PhotonResult_ToString(PhotonResult result)
{
    switch (result) {
    case PhotonResult_Ok:
        return "Ok";
    case PhotonResult_PacketNotFound:
        return "Packet not found";
    case PhotonResult_InvalidBerLength:
        return "Invalid BER length";
    case PhotonResult_UnexpectedEndOfBerStream:
        return "Unexpected end of BER stream";
    case PhotonResult_NotEnoughSpace:
        return "Not enough space";
    case PhotonResult_NotEnoughData:
        return "Not enough data";
    case PhotonResult_InvalidSize:
        return "Invalid size";
    case PhotonResult_InvalidDataHeader:
        return "Invalid data header";
    case PhotonResult_InvalidPacketHeader:
        return "Invalid packet header";
    case PhotonResult_InvalidDataSize:
        return "Invalid data size";
    case PhotonResult_InvalidAddressType:
        return "Invalid address type";
    case PhotonResult_InvalidReservedFieldValue:
        return "Invalid reserved field value";
    case PhotonResult_InvalidStreamType:
        return "Invalid stream type";
    case PhotonResult_InvalidErrorControlType:
        return "Invalid error control type";
    case PhotonResult_InvalidWindowSize:
        return "Invalid window size";
    case PhotonResult_InvalidSequenceCounter:
        return "Invalid sequence counter";
    case PhotonResult_EventIsDenied:
        return "Event is denied";
    case PhotonResult_InvalidCommandId:
        return "Invalid command id";
    case PhotonResult_InvalidComponentId:
        return "Invalid component id";
    case PhotonResult_InvalidMessageId:
        return "Invalid message id";
    case PhotonResult_InvalidValue:
        return "Invalid value";
    }
    return "UNKNOWN";
}
