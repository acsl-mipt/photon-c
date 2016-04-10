#include "photon/Time.h"
#include "photon/Ber.h"

PhotonResult PhotonTime_Serialize(const PhotonTime* self, PhotonWriter* dest)
{
    if (PhotonWriter_WritableSize(dest) < 2) {
        return PhotonResult_NotEnoughSpace;
    }

    PhotonWriter_WriteUint8(dest, self->type);

    switch(self->type) {
    case PhotonTimePrecision_Seconds:
        PHOTON_TRY(PhotonBer_Serialize(self->secs.seconds, dest));
        break;
    case PhotonTimePrecision_SecondsMilliseconds:
        PHOTON_TRY(PhotonBer_Serialize(self->secsMsecs.seconds, dest));
        PHOTON_TRY(PhotonBer_Serialize(self->secsMsecs.milliseconds, dest));
        break;
    case PhotonTimePrecision_SecondsMicroseconds:
        PHOTON_TRY(PhotonBer_Serialize(self->secsUsecs.seconds, dest));
        PHOTON_TRY(PhotonBer_Serialize(self->secsUsecs.microseconds, dest));
        break;
    case PhotonTimePrecision_SecondsNanoseconds:
        PHOTON_TRY(PhotonBer_Serialize(self->secsNsecs.seconds, dest));
        PHOTON_TRY(PhotonBer_Serialize(self->secsNsecs.nanoseconds, dest));
        break;
    default:
        return PhotonResult_InvalidTimeType;
    };

    return PhotonResult_Ok;
}

static PhotonResult deserializeValue(uint32_t* value, uint32_t max, PhotonReader* src)
{
    PhotonBer berValue;
    PHOTON_TRY(PhotonBer_Deserialize(&berValue, src));
    if (berValue > max) {
        return PhotonResult_InvalidTimeValue;
    }
    *value = berValue;
    return PhotonResult_Ok;
}

PhotonResult PhotonTime_Deserialize(PhotonTime* self, PhotonReader* src)
{
    if (PhotonReader_ReadableSize(src) < 2) {
        return PhotonResult_NotEnoughSpace;
    }

    self->type = PhotonReader_ReadUint8(src);

    switch(self->type) {
    case PhotonTimePrecision_Seconds:
        PHOTON_TRY(deserializeValue(&self->secs.seconds, UINT32_MAX, src));
        break;
    case PhotonTimePrecision_SecondsMilliseconds: {
        PHOTON_TRY(deserializeValue(&self->secsMsecs.seconds, UINT32_MAX, src));
        PhotonBer berValue;
        PHOTON_TRY(PhotonBer_Deserialize(&berValue, src));
        if (berValue > 999) {
            return PhotonResult_InvalidTimeValue;
        }
        self->secsMsecs.milliseconds = berValue;
        break;
    }
    case PhotonTimePrecision_SecondsMicroseconds:
        PHOTON_TRY(deserializeValue(&self->secsUsecs.seconds, UINT32_MAX, src));
        PHOTON_TRY(deserializeValue(&self->secsUsecs.microseconds, 999999, src));
        break;
    case PhotonTimePrecision_SecondsNanoseconds:
        PHOTON_TRY(deserializeValue(&self->secsNsecs.seconds, UINT32_MAX, src));
        PHOTON_TRY(deserializeValue(&self->secsNsecs.nanoseconds, 999999999, src));
        break;
    default:
        return PhotonResult_InvalidTimeType;
    };

    return PhotonResult_Ok;
}
