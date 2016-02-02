/* Type header */
#ifndef __PHOTON_GT_EVENT_INFO_H_6c87f67824fd16fc67a6cd4b0b7abdb1__
#define __PHOTON_GT_EVENT_INFO_H_6c87f67824fd16fc67a6cd4b0b7abdb1__ 

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