#ifndef __PHOTON_ROUTER_H__
#define __PHOTON_ROUTER_H__

#include "photon/PhotonGcMain.h"

#ifdef __cplusplus
extern "C" {
#endif

void PhotonRouter_Init();

void PhotonRouter_ClearRoutes();
void PhotonRouter_ClearGroupRoutes();

PhotonGtRouterError PhotonRouter_GetNextHop(PhotonGtAddress address, PhotonGtAddress* nextHop);
PhotonGtRouterError PhotonRouter_GetNextGroupHop(PhotonGtAddress address, PhotonGtAddress* nextHop);

PhotonGtRouterError PhotonRouter_SetRoute(PhotonGtAddress address, PhotonGtAddress nextHop);
PhotonGtRouterError PhotonRouter_DelRoute(PhotonGtAddress address);

PhotonGtRouterError PhotonRouter_SetGroupRoute(PhotonGtAddress groupAddress, PhotonGtAddress nextHop);
PhotonGtRouterError PhotonRouter_DelGroupRoute(PhotonGtAddress groupAddress);

#ifdef __cplusplus
}
#endif

#endif
