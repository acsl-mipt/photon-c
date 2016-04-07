/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_DECODE_PHOTON_GT_OR_ARR_NODE_INFO_FILE_LIST_ERROR_H__
#define __PHOTON_DECODE_PHOTON_GT_OR_ARR_NODE_INFO_FILE_LIST_ERROR_H__ 
#include "photon/prologue.h"

#include "photon/fs/PhotonGtArrNodeInfo.h"
#include "photon/fs/PhotonGtFileListError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtArrNodeInfo _1;
  PhotonGtFileListError _2;
  PhotonBer tag;
} PhotonGtOrArrNodeInfoFileListError;

PhotonResult PhotonGtOrArrNodeInfoFileListError_Serialize(PhotonGtOrArrNodeInfoFileListError self, PhotonWriter* writer);

PhotonResult PhotonGtOrArrNodeInfoFileListError_Deserialize(PhotonGtOrArrNodeInfoFileListError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif