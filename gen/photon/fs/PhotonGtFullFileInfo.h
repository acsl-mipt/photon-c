/* Type header */
#ifndef __PHOTON_GT_FULL_FILE_INFO_H_d6a8f67a3414300cec6881cf21d704e1__
#define __PHOTON_GT_FULL_FILE_INFO_H_d6a8f67a3414300cec6881cf21d704e1__ 

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