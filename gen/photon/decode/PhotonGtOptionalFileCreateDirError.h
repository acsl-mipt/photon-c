/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_DECODE_PHOTON_GT_OPTIONAL_FILE_CREATE_DIR_ERROR_H__
#define __PHOTON_DECODE_PHOTON_GT_OPTIONAL_FILE_CREATE_DIR_ERROR_H__ 
#include "photon/photon_prologue.h"

#include "photon/fs/PhotonGtFileCreateDirError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtFileCreateDirError value;
  PhotonGtB8 flag;
} PhotonGtOptionalFileCreateDirError;

PhotonResult PhotonGtOptionalFileCreateDirError_Serialize(PhotonGtOptionalFileCreateDirError self, PhotonWriter* writer);

PhotonResult PhotonGtOptionalFileCreateDirError_Deserialize(PhotonGtOptionalFileCreateDirError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif