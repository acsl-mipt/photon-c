/* Type header */
#ifndef __PHOTON_GT_ARR_EVENT_INFO_H_e158a55e5182731ad93a1a49b29fa061__
#define __PHOTON_GT_ARR_EVENT_INFO_H_e158a55e5182731ad93a1a49b29fa061__ 

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