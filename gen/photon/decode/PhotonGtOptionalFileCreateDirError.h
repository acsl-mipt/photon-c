/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_FILE_CREATE_DIR_ERROR_H_385c98b91a2d8ac66b24552c054b1169__
#define __PHOTON_GT_OPTIONAL_FILE_CREATE_DIR_ERROR_H_385c98b91a2d8ac66b24552c054b1169__ 

#include "photon/photon_prologue.h"

#include "photon/fs/PhotonGtFileCreateDirError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtB8 flag;
  PhotonGtFileCreateDirError value;
} PhotonGtOptionalFileCreateDirError;

PhotonResult PhotonGtOptionalFileCreateDirError_Serialize(PhotonGtOptionalFileCreateDirError* self, PhotonWriter* writer);

PhotonResult PhotonGtOptionalFileCreateDirError_Deserialize(PhotonGtOptionalFileCreateDirError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif