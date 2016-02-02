/* Type header */
#ifndef __PHOTON_GT_ARR_ROUTE_H_0419bb9ad0422c121c1035fd195af797__
#define __PHOTON_GT_ARR_ROUTE_H_0419bb9ad0422c121c1035fd195af797__ 

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