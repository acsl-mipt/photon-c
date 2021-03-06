/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_FS_PHOTON_GT_FILE_DELETE_ERROR_H__
#define __PHOTON_FS_PHOTON_GT_FILE_DELETE_ERROR_H__ 
#include "photon/prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_FILE_DELETE_ERROR_OK = 0
  , PHOTON_GT_FILE_DELETE_ERROR_NOT_FOUND = 1
  , PHOTON_GT_FILE_DELETE_ERROR_CANT_DELETE = 2
} PhotonGtFileDeleteError;

PhotonResult PhotonGtFileDeleteError_Serialize(PhotonGtFileDeleteError self, PhotonWriter* writer);

PhotonResult PhotonGtFileDeleteError_Deserialize(PhotonGtFileDeleteError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif