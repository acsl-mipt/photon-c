#include "photon/System.h"

#include <sys/time.h>
#include <time.h>

void PhotonSys_GetTime(PhotonAbsoluteTime* dest)
{
    struct timespec tv;
    clock_gettime(CLOCK_REALTIME, &tv, 0); //TODO: handle error
    dest->epochTime = tv.tv_sec;
    dest->nanoseconds = tv.tv_nsec;
}
