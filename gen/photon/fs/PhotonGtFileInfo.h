/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_FS_PHOTON_GT_FILE_INFO_H__
#define __PHOTON_FS_PHOTON_GT_FILE_INFO_H__ 
#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtString.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtString path;
  PhotonGtBer byteSize;
  PhotonGtBer attrs;
} PhotonGtFileInfo;

PhotonResult PhotonGtFileInfo_Serialize(const PhotonGtFileInfo* self, PhotonWriter* writer);

PhotonResult PhotonGtFileInfo_Deserialize(PhotonGtFileInfo* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif