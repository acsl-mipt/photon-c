/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_DECODE_PHOTON_GT_OR_BER_FILE_LIST_ERROR_H__
#define __PHOTON_DECODE_PHOTON_GT_OR_BER_FILE_LIST_ERROR_H__ 
#include "photon/prologue.h"

#include "photon/fs/PhotonGtFileListError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtBer _1;
  PhotonGtFileListError _2;
  PhotonBer tag;
} PhotonGtOrBerFileListError;

PhotonResult PhotonGtOrBerFileListError_Serialize(PhotonGtOrBerFileListError self, PhotonWriter* writer);

PhotonResult PhotonGtOrBerFileListError_Deserialize(PhotonGtOrBerFileListError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif