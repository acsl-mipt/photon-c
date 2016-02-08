/* Type header */
#ifndef __PHOTON_GT_ROUTE_H_452ad0444c11301838547ae157a78041__
#define __PHOTON_GT_ROUTE_H_452ad0444c11301838547ae157a78041__ 
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