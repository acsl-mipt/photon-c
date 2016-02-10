/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_DECODE_PHOTON_GT_OPTIONAL_FILE_LIST_ERROR_H__
#define __PHOTON_DECODE_PHOTON_GT_OPTIONAL_FILE_LIST_ERROR_H__ 
#include "photon/photon_prologue.h"

#include "photon/fs/PhotonGtFileListError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtB8 flag;
  PhotonGtFileListError value;
} PhotonGtOptionalFileListError;

PhotonResult PhotonGtOptionalFileListError_Serialize(PhotonGtOptionalFileListError self, PhotonWriter* writer);

PhotonResult PhotonGtOptionalFileListError_Deserialize(PhotonGtOptionalFileListError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif