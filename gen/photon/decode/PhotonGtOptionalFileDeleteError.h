/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_FILE_DELETE_ERROR_H_0f7a0cde502edef97417b283e9224e18__
#define __PHOTON_GT_OPTIONAL_FILE_DELETE_ERROR_H_0f7a0cde502edef97417b283e9224e18__ 

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