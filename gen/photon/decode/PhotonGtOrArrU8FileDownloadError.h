/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_DECODE_PHOTON_GT_OR_ARR_U8_FILE_DOWNLOAD_ERROR_H__
#define __PHOTON_DECODE_PHOTON_GT_OR_ARR_U8_FILE_DOWNLOAD_ERROR_H__ 
#include "photon/photon_prologue.h"

#include "photon/decode/PhotonGtArrU8.h"
#include "photon/fs/PhotonGtFileDownloadError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtArrU8 _1;
  PhotonGtFileDownloadError _2;
  PhotonBer tag;
} PhotonGtOrArrU8FileDownloadError;

PhotonResult PhotonGtOrArrU8FileDownloadError_Serialize(PhotonGtOrArrU8FileDownloadError self, PhotonWriter* writer);

PhotonResult PhotonGtOrArrU8FileDownloadError_Deserialize(PhotonGtOrArrU8FileDownloadError* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif