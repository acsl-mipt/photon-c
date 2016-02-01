/* Type header */
#ifndef __PHOTON_GT_OR_FULL_FILE_INFO_FILE_DOWNLOAD_ERROR_H_7eb92abd859d4b150ac0ec8a4f8709f8__
#define __PHOTON_GT_OR_FULL_FILE_INFO_FILE_DOWNLOAD_ERROR_H_7eb92abd859d4b150ac0ec8a4f8709f8__ 

#include "photon/photon_prologue.h"

#include "photon/fs/PhotonGtFullFileInfo.h"
#include "photon/fs/PhotonGtFileDownloadError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonBer tag;
  PhotonGtFullFileInfo _1;
  PhotonGtFileDownloadError _2;
} PhotonGtOrFullFileInfoFileDownloadError;

PhotonResult PhotonGtOrFullFileInfoFileDownloadError_Serialize(PhotonGtOrFullFileInfoFileDownloadError* self, PhotonWriter* writer);

PhotonResult PhotonGtOrFullFileInfoFileDownloadError_Deserialize(PhotonGtOrFullFileInfoFileDownloadError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif