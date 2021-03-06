/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_FS_PHOTON_GT_FILE_UPLOAD_ERROR_H__
#define __PHOTON_FS_PHOTON_GT_FILE_UPLOAD_ERROR_H__ 
#include "photon/prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_FILE_UPLOAD_ERROR_OK = 0
  , PHOTON_GT_FILE_UPLOAD_ERROR_ALREADY_EXISTS = 1
  , PHOTON_GT_FILE_UPLOAD_ERROR_CANT_WRITE = 2
  , PHOTON_GT_FILE_UPLOAD_ERROR_MODE_ERROR = 3
  , PHOTON_GT_FILE_UPLOAD_ERROR_TOO_BIG = 4
} PhotonGtFileUploadError;

PhotonResult PhotonGtFileUploadError_Serialize(PhotonGtFileUploadError self, PhotonWriter* writer);

PhotonResult PhotonGtFileUploadError_Deserialize(PhotonGtFileUploadError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif