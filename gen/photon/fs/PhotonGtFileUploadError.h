/* Type header */
#ifndef __PHOTON_GT_FILE_UPLOAD_ERROR_H_f8b512fd0c682bae0c2801b2d636ba11__
#define __PHOTON_GT_FILE_UPLOAD_ERROR_H_f8b512fd0c682bae0c2801b2d636ba11__ 

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