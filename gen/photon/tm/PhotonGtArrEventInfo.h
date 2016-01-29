/* Type header */
#ifndef __PHOTON_GT_ARR_EVENT_INFO_H_4ba0b3b60955171612b5ace619fccbe1__
#define __PHOTON_GT_ARR_EVENT_INFO_H_4ba0b3b60955171612b5ace619fccbe1__ 

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