/* Type header */
#ifndef __PHOTON_GT_OR_ARR_NODE_INFO_FILE_LIST_ERROR_H_5a8507fa15a0054f13381a8dfdee63c1__
#define __PHOTON_GT_OR_ARR_NODE_INFO_FILE_LIST_ERROR_H_5a8507fa15a0054f13381a8dfdee63c1__ 

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