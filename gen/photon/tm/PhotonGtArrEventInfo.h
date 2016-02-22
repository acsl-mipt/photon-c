/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_TM_PHOTON_GT_ARR_EVENT_INFO_H__
#define __PHOTON_TM_PHOTON_GT_ARR_EVENT_INFO_H__ 
#include "photon/photon_prologue.h"

#include "photon/tm/PhotonGtEventInfo.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PHOTON_GT_ARR_EVENT_INFO_MIN_SIZE 0
#define PHOTON_GT_ARR_EVENT_INFO_MAX_SIZE 0

typedef struct {
  size_t size;
  PhotonGtEventInfo* data;
} PhotonGtArrEventInfo;

PhotonResult PhotonGtArrEventInfo_Serialize(PhotonGtArrEventInfo self, PhotonWriter* writer);

PhotonResult PhotonGtArrEventInfo_Deserialize(PhotonGtArrEventInfo* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif