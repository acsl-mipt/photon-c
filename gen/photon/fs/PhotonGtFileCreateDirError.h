/* Type header */
#ifndef __PHOTON_GT_FILE_CREATE_DIR_ERROR_H_adbbc1d67da9c4cb34462f9df2204ba4__
#define __PHOTON_GT_FILE_CREATE_DIR_ERROR_H_adbbc1d67da9c4cb34462f9df2204ba4__ 

#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_FILE_CREATE_DIR_ERROR_NOT_FOUND = 1
  , PHOTON_GT_FILE_CREATE_DIR_ERROR_CANT_WRITE = 2
} PhotonGtFileCreateDirError;

PhotonResult PhotonGtFileCreateDirError_Serialize(PhotonGtFileCreateDirError* self, PhotonWriter* writer);

PhotonResult PhotonGtFileCreateDirError_Deserialize(PhotonGtFileCreateDirError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif