/* Type header */
#ifndef __PHOTON_GT_FULL_FILE_INFO_H_7c96c8e70784a0181c386a3c5d6ffa6e__
#define __PHOTON_GT_FULL_FILE_INFO_H_7c96c8e70784a0181c386a3c5d6ffa6e__ 

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