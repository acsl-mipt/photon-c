/* Type header */
#ifndef __PHOTON_GT_EVENT_INFO_H_a10b6e00d2f17e367f0770031f2a3eea__
#define __PHOTON_GT_EVENT_INFO_H_a10b6e00d2f17e367f0770031f2a3eea__ 
#include "photon/photon_prologue.h"

#include "photon/tm/PhotonGtCompMsg.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtCompMsg componentMessage;
  PhotonBer eventNum;
} PhotonGtEventInfo;

PhotonResult PhotonGtEventInfo_Serialize(PhotonGtEventInfo* self, PhotonWriter* writer);

PhotonResult PhotonGtEventInfo_Deserialize(PhotonGtEventInfo* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif