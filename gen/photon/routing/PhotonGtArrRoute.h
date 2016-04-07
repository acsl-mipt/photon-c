/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_ROUTING_PHOTON_GT_ARR_ROUTE_H__
#define __PHOTON_ROUTING_PHOTON_GT_ARR_ROUTE_H__ 
#include "photon/prologue.h"

#include "photon/routing/PhotonGtRoute.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_GT_ARR_ROUTE_MIN_SIZE 0
#define PHOTON_GT_ARR_ROUTE_MAX_SIZE 0

typedef struct {
  size_t size;
  PhotonGtRoute* data;
} PhotonGtArrRoute;

PhotonResult PhotonGtArrRoute_Serialize(PhotonGtArrRoute self, PhotonWriter* writer);

PhotonResult PhotonGtArrRoute_Deserialize(PhotonGtArrRoute* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif