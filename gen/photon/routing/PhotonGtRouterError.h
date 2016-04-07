/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_ROUTING_PHOTON_GT_ROUTER_ERROR_H__
#define __PHOTON_ROUTING_PHOTON_GT_ROUTER_ERROR_H__ 
#include "photon/prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_ROUTER_ERROR_OK = 0
  , PHOTON_GT_ROUTER_ERROR_MAXIMUM_ROUTES_REACHED = 1
  , PHOTON_GT_ROUTER_ERROR_NO_SUCH_ADDRESS = 2
  , PHOTON_GT_ROUTER_ERROR_CANNOUT_ROUTE = 3
} PhotonGtRouterError;

PhotonResult PhotonGtRouterError_Serialize(PhotonGtRouterError self, PhotonWriter* writer);

PhotonResult PhotonGtRouterError_Deserialize(PhotonGtRouterError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif