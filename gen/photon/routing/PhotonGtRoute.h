/* Type header */
#ifndef __PHOTON_GT_ROUTE_H_2b4bfe1355da72b3ea617f8551b10995__
#define __PHOTON_GT_ROUTE_H_2b4bfe1355da72b3ea617f8551b10995__ 

#include "photon/photon_prologue.h"

#include "photon/routing/PhotonGtAddress.h"
#include "photon/routing/PhotonGtAddress.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtAddress destination_address;
  PhotonGtAddress next_hop;
} PhotonGtRoute;

PhotonResult PhotonGtRoute_Serialize(PhotonGtRoute* self, PhotonWriter* writer);

PhotonResult PhotonGtRoute_Deserialize(PhotonGtRoute* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif