/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_FILE_UPLOAD_ERROR_H_1d95fb7f9fcc62bc91475c184dec3bc4__
#define __PHOTON_GT_OPTIONAL_FILE_UPLOAD_ERROR_H_1d95fb7f9fcc62bc91475c184dec3bc4__ 
#include "photon/photon_prologue.h"

#include "photon/fs/PhotonGtFileUploadError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtB8 flag;
  PhotonGtFileUploadError value;
} PhotonGtOptionalFileUploadError;

PhotonResult PhotonGtOptionalFileUploadError_Serialize(PhotonGtOptionalFileUploadError* self, PhotonWriter* writer);

PhotonResult PhotonGtOptionalFileUploadError_Deserialize(PhotonGtOptionalFileUploadError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif