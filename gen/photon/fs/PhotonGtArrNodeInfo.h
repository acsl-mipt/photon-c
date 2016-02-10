/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_FS_PHOTON_GT_ARR_NODE_INFO_H__
#define __PHOTON_FS_PHOTON_GT_ARR_NODE_INFO_H__ 
#include "photon/photon_prologue.h"

#include "photon/fs/PhotonGtNodeInfo.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_GT_ARR_NODE_INFO_MIN_LEN 0
#define PHOTON_GT_ARR_NODE_INFO_MAX_LEN 256

typedef struct {
  size_t size;
  PhotonGtNodeInfo* data;
} PhotonGtArrNodeInfo;

PhotonResult PhotonGtArrNodeInfo_Serialize(const PhotonGtArrNodeInfo* self, PhotonWriter* writer);

PhotonResult PhotonGtArrNodeInfo_Deserialize(PhotonGtArrNodeInfo* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif