/* Type header */
#ifndef __PHOTON_GT_ARR_ROUTE_H_f7d93ebfe998e10aa52f4fcb5c5cb430__
#define __PHOTON_GT_ARR_ROUTE_H_f7d93ebfe998e10aa52f4fcb5c5cb430__ 
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