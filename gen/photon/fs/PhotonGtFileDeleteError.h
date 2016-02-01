/* Type header */
#ifndef __PHOTON_GT_FILE_DELETE_ERROR_H_89ff6a63b2da52ce327ca1dd95767d84__
#define __PHOTON_GT_FILE_DELETE_ERROR_H_89ff6a63b2da52ce327ca1dd95767d84__ 

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