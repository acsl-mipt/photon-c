/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_TM_PHOTON_GT_TM_CMD_ERROR_H__
#define __PHOTON_TM_PHOTON_GT_TM_CMD_ERROR_H__ 
#include "photon/prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_TM_CMD_ERROR_OK = 0
  , PHOTON_GT_TM_CMD_ERROR_INVALID_ARGUMENT = 1
  , PHOTON_GT_TM_CMD_ERROR_INVALID_STATE = 2
  , PHOTON_GT_TM_CMD_ERROR_INVALID_MESSAGE_NUM = 3
} PhotonGtTmCmdError;

PhotonResult PhotonGtTmCmdError_Serialize(PhotonGtTmCmdError self, PhotonWriter* writer);

PhotonResult PhotonGtTmCmdError_Deserialize(PhotonGtTmCmdError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif