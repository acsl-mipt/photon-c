/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_DECODE_PHOTON_GT_OPTIONAL_FILE_DOWNLOAD_ERROR_H__
#define __PHOTON_DECODE_PHOTON_GT_OPTIONAL_FILE_DOWNLOAD_ERROR_H__ 
#include "photon/photon_prologue.h"

#include "photon/fs/PhotonGtFileDownloadError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtFileDownloadError value;
  PhotonGtB8 flag;
} PhotonGtOptionalFileDownloadError;

PhotonResult PhotonGtOptionalFileDownloadError_Serialize(PhotonGtOptionalFileDownloadError self, PhotonWriter* writer);

PhotonResult PhotonGtOptionalFileDownloadError_Deserialize(PhotonGtOptionalFileDownloadError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif