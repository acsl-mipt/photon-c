/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_TM_PHOTON_GT_TM_CMD_ERROR_H__
#define __PHOTON_TM_PHOTON_GT_TM_CMD_ERROR_H__ 
#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_TM_CMD_ERROR_INVALID_ARGUMENT = 1
  , PHOTON_GT_TM_CMD_ERROR_INVALID_STATE = 2
} PhotonGtTmCmdError;

PhotonResult PhotonGtTmCmdError_Serialize(const PhotonGtTmCmdError* self, PhotonWriter* writer);

PhotonResult PhotonGtTmCmdError_Deserialize(PhotonGtTmCmdError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif