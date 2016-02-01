/* Type header */
#ifndef __PHOTON_GT_FULL_FILE_INFO_H_159dacdc586b1c5921609175897ea6bc__
#define __PHOTON_GT_FULL_FILE_INFO_H_159dacdc586b1c5921609175897ea6bc__ 

#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtString.h"
#include "photon/foundation/PhotonGtArrU8.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtString filePath;
  PhotonBer fileAttrs;
  PhotonGtArrU8 fileContents;
} PhotonGtFullFileInfo;

PhotonResult PhotonGtFullFileInfo_Serialize(PhotonGtFullFileInfo* self, PhotonWriter* writer);

PhotonResult PhotonGtFullFileInfo_Deserialize(PhotonGtFullFileInfo* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif