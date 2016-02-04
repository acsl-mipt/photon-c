/* Type header */
#ifndef __PHOTON_GT_ARR_EVENT_INFO_H_06c1774c4ebd1b261b4bfec2ba971edb__
#define __PHOTON_GT_ARR_EVENT_INFO_H_06c1774c4ebd1b261b4bfec2ba971edb__ 

#include "photon/photon_prologue.h"

#include "photon/tm/PhotonGtEventInfo.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  size_t size;
  PhotonGtEventInfo data[256];
} PhotonGtArrEventInfo;

PhotonResult PhotonGtArrEventInfo_Serialize(PhotonGtArrEventInfo* self, PhotonWriter* writer);

PhotonResult PhotonGtArrEventInfo_Deserialize(PhotonGtArrEventInfo* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif