/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_ROUTING_PHOTON_GT_ARR_ROUTE_H__
#define __PHOTON_ROUTING_PHOTON_GT_ARR_ROUTE_H__ 
#include "photon/photon_prologue.h"

#include "photon/routing/PhotonGtRoute.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_GT_ARR_ROUTE_MIN_LEN 0
#define PHOTON_GT_ARR_ROUTE_MAX_LEN 256

typedef struct {
  size_t size;
  PhotonGtRoute* data;
} PhotonGtArrRoute;

PhotonResult PhotonGtArrRoute_Serialize(const PhotonGtArrRoute* self, PhotonWriter* writer);

PhotonResult PhotonGtArrRoute_Deserialize(PhotonGtArrRoute* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif