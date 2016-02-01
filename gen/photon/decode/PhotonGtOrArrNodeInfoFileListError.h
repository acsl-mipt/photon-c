/* Type header */
#ifndef __PHOTON_GT_OR_ARR_NODE_INFO_FILE_LIST_ERROR_H_1aeca4953b00e1793e46e63c9b5adee5__
#define __PHOTON_GT_OR_ARR_NODE_INFO_FILE_LIST_ERROR_H_1aeca4953b00e1793e46e63c9b5adee5__ 

#include "photon/photon_prologue.h"

#include "photon/fs/PhotonGtArrNodeInfo.h"
#include "photon/fs/PhotonGtFileListError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonBer tag;
  PhotonGtArrNodeInfo _1;
  PhotonGtFileListError _2;
} PhotonGtOrArrNodeInfoFileListError;

PhotonResult PhotonGtOrArrNodeInfoFileListError_Serialize(PhotonGtOrArrNodeInfoFileListError* self, PhotonWriter* writer);

PhotonResult PhotonGtOrArrNodeInfoFileListError_Deserialize(PhotonGtOrArrNodeInfoFileListError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif