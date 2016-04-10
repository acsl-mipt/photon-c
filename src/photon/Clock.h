#ifndef __PHOTON_CLOCK_H__
#define __PHOTON_CLOCK_H__

#include "photon/Time.h"
#include "photon/System.h"

void PhotonClock_Init();

void PhotonClock_GetTime(PhotonTime* dest);

void PhotonClock_SetTimePrecision(PhotonTimePrecision prec);

void PhotonClock_SetSystemStartTime(const PhotonAbsoluteTime* time);

#endif
