#ifndef __PHOTON_TIME_H__
#define __PHOTON_TIME_H__

#include "photon/Config.h"
#include "photon/Writer.h"
#include "photon/Reader.h"
#include "photon/Result.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    PhotonTimePrecision_Seconds = 0,
    PhotonTimePrecision_SecondsMilliseconds = 1,
    PhotonTimePrecision_SecondsMicroseconds = 2,
    PhotonTimePrecision_SecondsNanoseconds = 3,
} PhotonTimePrecision;

typedef struct {
    uint32_t seconds;
} PhotonTimeSecs;

typedef struct {
    uint32_t seconds;
    uint16_t milliseconds;
} PhotonTimeSecsMsecs;

typedef struct {
    uint32_t seconds;
    uint32_t microseconds;
} PhotonTimeSecsUsecs;

typedef struct {
    uint32_t seconds;
    uint32_t nanoseconds;
} PhotonTimeSecsNsecs;

typedef struct {
    union {
        PhotonTimeSecs secs;
        PhotonTimeSecsMsecs secsMsecs;
        PhotonTimeSecsUsecs secsUsecs;
        PhotonTimeSecsNsecs secsNsecs;
    };
    PhotonTimePrecision type;
} PhotonTime;

PhotonResult PhotonTime_Serialize(const PhotonTime* self, PhotonWriter* dest);
PhotonResult PhotonTime_Deserialize(PhotonTime* self, PhotonReader* src);

#ifdef __cplusplus
}
#endif

#endif
