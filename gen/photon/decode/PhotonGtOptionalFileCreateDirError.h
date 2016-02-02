/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_FILE_CREATE_DIR_ERROR_H_63ba0b82a6f42eca24b9d45c233db2aa__
#define __PHOTON_GT_OPTIONAL_FILE_CREATE_DIR_ERROR_H_63ba0b82a6f42eca24b9d45c233db2aa__ 

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