/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_FS_PHOTON_GT_FILES_MODE_H__
#define __PHOTON_FS_PHOTON_GT_FILES_MODE_H__ 
#include "photon/prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_FILES_MODE_BASE = 0
  , PHOTON_GT_FILES_MODE_UPLOADING_FILE = 1
  , PHOTON_GT_FILES_MODE_DOWNLOADING_FILE = 2
  , PHOTON_GT_FILES_MODE_DOWNLOADING_FILE_LIST = 3
} PhotonGtFilesMode;

PhotonResult PhotonGtFilesMode_Serialize(PhotonGtFilesMode self, PhotonWriter* writer);

PhotonResult PhotonGtFilesMode_Deserialize(PhotonGtFilesMode* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif