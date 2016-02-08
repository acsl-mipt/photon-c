/* Type header */
#ifndef __PHOTON_GT_FILE_LIST_ERROR_H_a78cf79b58f1d9c60ab957dffe34aa22__
#define __PHOTON_GT_FILE_LIST_ERROR_H_a78cf79b58f1d9c60ab957dffe34aa22__ 
#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_FILE_LIST_ERROR_NOT_FOUND = 1
  , PHOTON_GT_FILE_LIST_ERROR_CANT_READ = 2
  , PHOTON_GT_FILE_LIST_ERROR_NOT_DIR = 3
} PhotonGtFileListError;

PhotonResult PhotonGtFileListError_Serialize(PhotonGtFileListError* self, PhotonWriter* writer);

PhotonResult PhotonGtFileListError_Deserialize(PhotonGtFileListError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif