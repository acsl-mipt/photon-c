/* Type header */
#ifndef __PHOTON_GT_FILE_LIST_ERROR_H_f6a14b3158ca01beea21b91768f8dd9e__
#define __PHOTON_GT_FILE_LIST_ERROR_H_f6a14b3158ca01beea21b91768f8dd9e__ 

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