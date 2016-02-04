/* Type header */
#ifndef __PHOTON_GT_FILE_DELETE_ERROR_H_320b8b584a8b296c2d6ac80657cbf5e4__
#define __PHOTON_GT_FILE_DELETE_ERROR_H_320b8b584a8b296c2d6ac80657cbf5e4__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_FILE_DELETE_ERROR_CANT_DELETE = 2
  , PHOTON_GT_FILE_DELETE_ERROR_NOT_FOUND = 1
} PhotonGtFileDeleteError;

PhotonResult PhotonGtFileDeleteError_Serialize(PhotonGtFileDeleteError* self, PhotonWriter* writer);

PhotonResult PhotonGtFileDeleteError_Deserialize(PhotonGtFileDeleteError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif