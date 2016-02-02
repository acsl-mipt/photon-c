/* Type header */
#ifndef __PHOTON_GT_FILE_DELETE_ERROR_H_c767cecf49d67d58fcd62c9bfdfb22eb__
#define __PHOTON_GT_FILE_DELETE_ERROR_H_c767cecf49d67d58fcd62c9bfdfb22eb__ 

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