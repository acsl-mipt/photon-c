/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_FS_PHOTON_GT_FILES_EVENT_H__
#define __PHOTON_FS_PHOTON_GT_FILES_EVENT_H__ 
#include "photon/prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
    PHOTON_GT_FILES_EVENT_MODE_CHANGED = 1
} PhotonGtFilesEvent;

PhotonResult PhotonGtFilesEvent_Serialize(PhotonGtFilesEvent self, PhotonWriter* writer);

PhotonResult PhotonGtFilesEvent_Deserialize(PhotonGtFilesEvent* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif