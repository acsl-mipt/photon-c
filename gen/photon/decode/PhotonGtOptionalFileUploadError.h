/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_FILE_UPLOAD_ERROR_H_ea8df14dc0145f56d20797bf9fff3aa4__
#define __PHOTON_GT_OPTIONAL_FILE_UPLOAD_ERROR_H_ea8df14dc0145f56d20797bf9fff3aa4__ 

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