/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_DECODE_PHOTON_GT_OPTIONAL_ROUTER_ERROR_H__
#define __PHOTON_DECODE_PHOTON_GT_OPTIONAL_ROUTER_ERROR_H__ 
#include "photon/photon_prologue.h"

#include "photon/routing/PhotonGtRouterError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtB8 flag;
  PhotonGtRouterError value;
} PhotonGtOptionalRouterError;

PhotonResult PhotonGtOptionalRouterError_Serialize(const PhotonGtOptionalRouterError* self, PhotonWriter* writer);

PhotonResult PhotonGtOptionalRouterError_Deserialize(PhotonGtOptionalRouterError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif