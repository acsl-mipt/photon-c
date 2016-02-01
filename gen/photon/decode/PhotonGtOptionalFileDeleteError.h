/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_FILE_DELETE_ERROR_H_7595dd61e8cc4cd1f81fe05282ca3187__
#define __PHOTON_GT_OPTIONAL_FILE_DELETE_ERROR_H_7595dd61e8cc4cd1f81fe05282ca3187__ 

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