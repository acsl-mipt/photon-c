/* Component Router interface */
#ifndef __PHOTON_GC_ROUTER_H_9a30630450e0f9809ee9e5d2261b2eab__
#define __PHOTON_GC_ROUTER_H_9a30630450e0f9809ee9e5d2261b2eab__ 

#include "photon/photon_prologue.h"

#include "photon/routing/PhotonGtAddress.h"
#include "photon/routing/PhotonGtArrRoute.h"

#ifdef __cplusplus
extern "C" {
#endif

struct PhotonGcRouterUserFunctionTable_s;

typedef struct PhotonGcRouter_s PhotonGcRouter;

struct PhotonGcRouter_s {
  PhotonGcRouterData* data;
  PhotonGtArrRoute (*routes)(PhotonGcRouter*);
  PhotonGtArrRoute (*groupRoutes)(PhotonGcRouter*);
  void (*setRoute)(PhotonGcRouter*, PhotonGtAddress, PhotonGtAddress);
  void (*delRoute)(PhotonGcRouter*, PhotonGtAddress);
  void (*setGroupRoute)(PhotonGcRouter*, PhotonGtAddress, PhotonGtAddress);
  void (*delGroupRoute)(PhotonGcRouter*, PhotonGtAddress);
};
PhotonResult PhotonGcRouter_SetRoute(PhotonGcRouter* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcRouter_DelRoute(PhotonGcRouter* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcRouter_SetGroupRoute(PhotonGcRouter* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcRouter_DelGroupRoute(PhotonGcRouter* self, PhotonReader* reader, PhotonWriter* writer);

PhotonResult PhotonGcRouter_ReadExecuteCommand(PhotonGcRouter* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcRouter_WriteMessage(PhotonGcRouter* self, PhotonWriter* writer, size_t messageId);


#ifdef __cplusplus
}
#endif
#include "photon/photon_epilogue.h"

#endif