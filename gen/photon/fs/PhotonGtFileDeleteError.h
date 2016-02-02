/* Type header */
#ifndef __PHOTON_GT_FILE_DELETE_ERROR_H_773b124d6ccee142a19a49451b33a123__
#define __PHOTON_GT_FILE_DELETE_ERROR_H_773b124d6ccee142a19a49451b33a123__ 

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