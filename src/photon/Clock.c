#include "photon/Clock.h"
#include "photon/System.h"

struct {
    PhotonAbsoluteTime systemStart;
    PhotonTimePrecision prec;
} _clock;

void PhotonClock_Init()
{
    PhotonSys_GetTime(&_clock.systemStart);
    _clock.prec = PhotonTimePrecision_SecondsMilliseconds;
}

void PhotonClock_GetTime(PhotonTime* dest)
{
    PhotonAbsoluteTime absTime;
    PhotonSys_GetTime(&absTime);
    dest->type = _clock.prec;
    switch (_clock.prec) {
    case PhotonTimePrecision_Seconds:
        dest->secs.seconds = absTime.epochTime - _clock.systemStart.epochTime;
        break;
    case PhotonTimePrecision_SecondsMilliseconds:
        dest->secsMsecs.seconds = absTime.epochTime - _clock.systemStart.epochTime;
        dest->secsMsecs.milliseconds = (absTime.nanoseconds - _clock.systemStart.nanoseconds) / 1000000;
        break;
    case PhotonTimePrecision_SecondsMicroseconds:
        dest->secsUsecs.seconds = absTime.epochTime - _clock.systemStart.epochTime;
        dest->secsUsecs.microseconds = (absTime.nanoseconds - _clock.systemStart.nanoseconds) / 1000;
        break;
    case PhotonTimePrecision_SecondsNanoseconds:
        dest->secsNsecs.seconds = absTime.epochTime - _clock.systemStart.epochTime;
        dest->secsNsecs.nanoseconds = absTime.nanoseconds - _clock.systemStart.nanoseconds;
        break;
    };
}

void PhotonClock_SetTimePrecision(PhotonTimePrecision prec)
{
    _clock.prec = prec;
}

void PhotonClock_SetSystemStartTime(const PhotonAbsoluteTime* time)
{
    _clock.systemStart = *time;
}

