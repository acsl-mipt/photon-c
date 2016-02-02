/* Type header */
#ifndef __PHOTON_GT_OPTIONAL_TM_CMD_ERROR_H_c5c4e40f67e598b789559f63cabc5a70__
#define __PHOTON_GT_OPTIONAL_TM_CMD_ERROR_H_c5c4e40f67e598b789559f63cabc5a70__ 

#include "photon/photon_prologue.h"

#include "photon/tm/PhotonGtTmCmdError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtB8 flag;
  PhotonGtTmCmdError value;
} PhotonGtOptionalTmCmdError;

PhotonResult PhotonGtOptionalTmCmdError_Serialize(PhotonGtOptionalTmCmdError* self, PhotonWriter* writer);

PhotonResult PhotonGtOptionalTmCmdError_Deserialize(PhotonGtOptionalTmCmdError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif