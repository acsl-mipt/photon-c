/* Type header */
#ifndef __PHOTON_GT_FILE_UPLOAD_ERROR_H_b8374491e746ca7c68936e0c96333671__
#define __PHOTON_GT_FILE_UPLOAD_ERROR_H_b8374491e746ca7c68936e0c96333671__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_FILE_UPLOAD_ERROR_ALREADY_EXISTS = 1
  , PHOTON_GT_FILE_UPLOAD_ERROR_CANT_WRITE = 2
} PhotonGtFileUploadError;

PhotonResult PhotonGtFileUploadError_Serialize(PhotonGtFileUploadError* self, PhotonWriter* writer);

PhotonResult PhotonGtFileUploadError_Deserialize(PhotonGtFileUploadError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif