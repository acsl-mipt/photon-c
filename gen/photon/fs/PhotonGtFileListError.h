/* Type header */
#ifndef __PHOTON_GT_FILE_LIST_ERROR_H_52ee3eee557f20a0a11d1c068b95143e__
#define __PHOTON_GT_FILE_LIST_ERROR_H_52ee3eee557f20a0a11d1c068b95143e__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_FILE_LIST_ERROR_CANT_READ = 2
  , PHOTON_GT_FILE_LIST_ERROR_NOT_DIR = 3
  , PHOTON_GT_FILE_LIST_ERROR_NOT_FOUND = 1
} PhotonGtFileListError;

PhotonResult PhotonGtFileListError_Serialize(PhotonGtFileListError* self, PhotonWriter* writer);

PhotonResult PhotonGtFileListError_Deserialize(PhotonGtFileListError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif