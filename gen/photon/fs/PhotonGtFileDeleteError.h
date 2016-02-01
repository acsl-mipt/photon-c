/* Type header */
#ifndef __PHOTON_GT_FILE_DELETE_ERROR_H_aad2746607a6d5ce0117020cfbca97f8__
#define __PHOTON_GT_FILE_DELETE_ERROR_H_aad2746607a6d5ce0117020cfbca97f8__ 

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