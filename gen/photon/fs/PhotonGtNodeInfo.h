/* Type header */
#ifndef __PHOTON_GT_NODE_INFO_H_2cc24c17cb741787abe76f8d614fda21__
#define __PHOTON_GT_NODE_INFO_H_2cc24c17cb741787abe76f8d614fda21__ 

#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtString.h"
#include "photon/foundation/PhotonGtB8.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtString name;
  PhotonGtB8 isDir;
  PhotonBer attrs;
} PhotonGtNodeInfo;

PhotonResult PhotonGtNodeInfo_Serialize(PhotonGtNodeInfo* self, PhotonWriter* writer);

PhotonResult PhotonGtNodeInfo_Deserialize(PhotonGtNodeInfo* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif