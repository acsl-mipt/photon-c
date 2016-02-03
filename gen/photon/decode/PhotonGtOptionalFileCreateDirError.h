/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_FILE_CREATE_DIR_ERROR_H_b0e7199ec5af02e32834df1967e85696__
#define __PHOTON_GT_OPTIONAL_FILE_CREATE_DIR_ERROR_H_b0e7199ec5af02e32834df1967e85696__ 

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