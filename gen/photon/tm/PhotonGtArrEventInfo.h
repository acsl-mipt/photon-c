/* Type header */
#ifndef __PHOTON_GT_ARR_EVENT_INFO_H_0847082464165643a52c7a0ac027c5f7__
#define __PHOTON_GT_ARR_EVENT_INFO_H_0847082464165643a52c7a0ac027c5f7__ 

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