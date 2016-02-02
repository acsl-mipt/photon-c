/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_FILE_DELETE_ERROR_H_35a0efa08d5c29c42440786dd9153e78__
#define __PHOTON_GT_OPTIONAL_FILE_DELETE_ERROR_H_35a0efa08d5c29c42440786dd9153e78__ 

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