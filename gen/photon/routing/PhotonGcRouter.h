/* Component Router interface */
#ifndef __PHOTON_GC_ROUTER_H_d9ea7a0f25cac06fb9471754fa9071af__
#define __PHOTON_GC_ROUTER_H_d9ea7a0f25cac06fb9471754fa9071af__ 

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
  void (*setRoute)(PhotonGcRouter*, PhotonGtAddress*, PhotonGtAddress*);
  void (*delRoute)(PhotonGcRouter*, PhotonGtAddress*);
  void (*setGroupRoute)(PhotonGcRouter*, PhotonGtAddress*, PhotonGtAddress*);
  void (*delGroupRoute)(PhotonGcRouter*, PhotonGtAddress*);
};
PhotonResult PhotonGcRouter_SetRoute(PhotonGcRouter* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcRouter_DelRoute(PhotonGcRouter* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcRouter_SetGroupRoute(PhotonGcRouter* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcRouter_DelGroupRoute(PhotonGcRouter* self, PhotonReader* reader, PhotonWriter* writer);

PhotonResult PhotonGcRouter_ReadExecuteCommand(PhotonGcRouter* self, PhotonReader* reader, PhotonWriter* writer);


#ifdef __cplusplus
}
#endif
#include "photon/photon_epilogue.h"

#endif