/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_DECODE_PHOTON_GT_OR_FILE_INFO_FILE_DOWNLOAD_ERROR_H__
#define __PHOTON_DECODE_PHOTON_GT_OR_FILE_INFO_FILE_DOWNLOAD_ERROR_H__ 
#include "photon/photon_prologue.h"

#include "photon/fs/PhotonGtFileInfo.h"
#include "photon/fs/PhotonGtFileDownloadError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonBer tag;
  PhotonGtFileInfo _1;
  PhotonGtFileDownloadError _2;
} PhotonGtOrFileInfoFileDownloadError;

PhotonResult PhotonGtOrFileInfoFileDownloadError_Serialize(const PhotonGtOrFileInfoFileDownloadError* self, PhotonWriter* writer);

PhotonResult PhotonGtOrFileInfoFileDownloadError_Deserialize(PhotonGtOrFileInfoFileDownloadError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif