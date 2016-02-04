/* Type header */
#ifndef __PHOTON_GT_ARR_NODE_INFO_H_d30535b8183a9aa615dec90794fec2c4__
#define __PHOTON_GT_ARR_NODE_INFO_H_d30535b8183a9aa615dec90794fec2c4__ 

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