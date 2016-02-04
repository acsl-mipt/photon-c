/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_FILE_DELETE_ERROR_H_7d4f6a74a50c553f6d3c4cdcdb72b4a9__
#define __PHOTON_GT_OPTIONAL_FILE_DELETE_ERROR_H_7d4f6a74a50c553f6d3c4cdcdb72b4a9__ 

#include "photon/photon_prologue.h"

#include "photon/fs/PhotonGtFileDeleteError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtB8 flag;
  PhotonGtFileDeleteError value;
} PhotonGtOptionalFileDeleteError;

PhotonResult PhotonGtOptionalFileDeleteError_Serialize(PhotonGtOptionalFileDeleteError* self, PhotonWriter* writer);

PhotonResult PhotonGtOptionalFileDeleteError_Deserialize(PhotonGtOptionalFileDeleteError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif