/* Type header */
#ifndef __PHOTON_GT_OR_FULL_FILE_INFO_FILE_DOWNLOAD_ERROR_H_50a23b74d5eaba3ea2d74ea9838ea736__
#define __PHOTON_GT_OR_FULL_FILE_INFO_FILE_DOWNLOAD_ERROR_H_50a23b74d5eaba3ea2d74ea9838ea736__ 

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