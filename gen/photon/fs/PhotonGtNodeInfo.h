/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_FS_PHOTON_GT_NODE_INFO_H__
#define __PHOTON_FS_PHOTON_GT_NODE_INFO_H__ 
#include "photon/prologue.h"

#include "photon/foundation/PhotonGtString.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtString name;
  PhotonGtB8 isDir;
  PhotonGtBer attrs;
} PhotonGtNodeInfo;

PhotonResult PhotonGtNodeInfo_Serialize(const PhotonGtNodeInfo* self, PhotonWriter* writer);

PhotonResult PhotonGtNodeInfo_Deserialize(PhotonGtNodeInfo* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif