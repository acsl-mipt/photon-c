/* Type header */
#ifndef __PHOTON_GT_ARR_ROUTE_H_24edc01a7a9d7976bc57fd5420f8b05f__
#define __PHOTON_GT_ARR_ROUTE_H_24edc01a7a9d7976bc57fd5420f8b05f__ 

#include "photon/photon_prologue.h"

#include "photon/routing/PhotonGtRoute.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  size_t size;
  PhotonGtRoute data[256];
} PhotonGtArrRoute;

PhotonResult PhotonGtArrRoute_Serialize(PhotonGtArrRoute* self, PhotonWriter* writer);

PhotonResult PhotonGtArrRoute_Deserialize(PhotonGtArrRoute* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif