#ifndef __PHOTON_TELEMETRY_H__
#define __PHOTON_TELEMETRY_H__

#include "photon/PhotonGcMain.h"

#ifdef __cplusplus
extern "C" {
#endif

void PhotonTelemetry_Init();

PhotonResult PhotonTelemetry_CollectStatusMessages(PhotonWriter* dest);
PhotonResult PhotonTelemetry_CollectEventMessages(PhotonWriter* dest);

#ifdef __cplusplus
}
#endif

#endif
