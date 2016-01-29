/* Component Router interface */
#ifndef __PHOTON_GC_ROUTER_H_d27678dda6e4e44f691f832c3538f6fd__
#define __PHOTON_GC_ROUTER_H_d27678dda6e4e44f691f832c3538f6fd__ 

#include "photon/photon_prologue.h"

#include "photon/routing/PhotonGtArrRoute.h"
#include "photon/routing/PhotonGtAddress.h"

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

PhotonResult PhotonGcRouter_ExecuteCommand(PhotonGcRouter* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);

PhotonResult PhotonGcRouter_ReadExecuteCommand(PhotonGcRouter* self, PhotonReader* reader, PhotonWriter* writer);


#ifdef __cplusplus
}
#endif
#include "photon/photon_epilogue.h"

#endif