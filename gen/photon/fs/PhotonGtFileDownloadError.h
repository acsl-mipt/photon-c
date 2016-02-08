/* Type header */
#ifndef __PHOTON_GT_FILE_DOWNLOAD_ERROR_H_6c9c25e3044356a98889955c22a51a49__
#define __PHOTON_GT_FILE_DOWNLOAD_ERROR_H_6c9c25e3044356a98889955c22a51a49__ 
#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_FILE_DOWNLOAD_ERROR_NOT_FOUND = 1
  , PHOTON_GT_FILE_DOWNLOAD_ERROR_CANT_READ = 2
  , PHOTON_GT_FILE_DOWNLOAD_ERROR_NOT_FILE = 3
} PhotonGtFileDownloadError;

PhotonResult PhotonGtFileDownloadError_Serialize(PhotonGtFileDownloadError* self, PhotonWriter* writer);

PhotonResult PhotonGtFileDownloadError_Deserialize(PhotonGtFileDownloadError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif