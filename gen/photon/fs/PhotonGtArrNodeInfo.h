/* Type header */
#ifndef __PHOTON_GT_ARR_NODE_INFO_H_8989610b93ec77aecb3daf1c60748d26__
#define __PHOTON_GT_ARR_NODE_INFO_H_8989610b93ec77aecb3daf1c60748d26__ 

#include "photon/photon_prologue.h"

#include "photon/fs/PhotonGtNodeInfo.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  size_t size;
  PhotonGtNodeInfo data[256];
} PhotonGtArrNodeInfo;

PhotonResult PhotonGtArrNodeInfo_Serialize(PhotonGtArrNodeInfo* self, PhotonWriter* writer);

PhotonResult PhotonGtArrNodeInfo_Deserialize(PhotonGtArrNodeInfo* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif