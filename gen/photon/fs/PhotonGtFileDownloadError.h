/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_FS_PHOTON_GT_FILE_DOWNLOAD_ERROR_H__
#define __PHOTON_FS_PHOTON_GT_FILE_DOWNLOAD_ERROR_H__ 
#include "photon/prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_FILE_DOWNLOAD_ERROR_OK = 0
  , PHOTON_GT_FILE_DOWNLOAD_ERROR_NOT_FOUND = 1
  , PHOTON_GT_FILE_DOWNLOAD_ERROR_CANT_READ = 2
  , PHOTON_GT_FILE_DOWNLOAD_ERROR_NOT_FILE = 3
  , PHOTON_GT_FILE_DOWNLOAD_ERROR_EOF = 4
} PhotonGtFileDownloadError;

PhotonResult PhotonGtFileDownloadError_Serialize(PhotonGtFileDownloadError self, PhotonWriter* writer);

PhotonResult PhotonGtFileDownloadError_Deserialize(PhotonGtFileDownloadError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif