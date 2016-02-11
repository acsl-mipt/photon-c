/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_DECODE_PHOTON_GT_OR_BER_FILE_LIST_ERROR_H__
#define __PHOTON_DECODE_PHOTON_GT_OR_BER_FILE_LIST_ERROR_H__ 
#include "photon/photon_prologue.h"

#include "photon/fs/PhotonGtFileListError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonBer _1;
  PhotonGtFileListError _2;
  PhotonBer tag;
} PhotonGtOrBerFileListError;

PhotonResult PhotonGtOrBerFileListError_Serialize(PhotonGtOrBerFileListError self, PhotonWriter* writer);

PhotonResult PhotonGtOrBerFileListError_Deserialize(PhotonGtOrBerFileListError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif