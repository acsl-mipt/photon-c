/* Type header */
#ifndef __PHOTON_GT_FILE_DOWNLOAD_ERROR_H_683f9a0cf93a76673780ffe2729324e5__
#define __PHOTON_GT_FILE_DOWNLOAD_ERROR_H_683f9a0cf93a76673780ffe2729324e5__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_FILE_DOWNLOAD_ERROR_NOT_FILE = 3
  , PHOTON_GT_FILE_DOWNLOAD_ERROR_CANT_READ = 2
  , PHOTON_GT_FILE_DOWNLOAD_ERROR_NOT_FOUND = 1
} PhotonGtFileDownloadError;

PhotonResult PhotonGtFileDownloadError_Serialize(PhotonGtFileDownloadError* self, PhotonWriter* writer);

PhotonResult PhotonGtFileDownloadError_Deserialize(PhotonGtFileDownloadError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif