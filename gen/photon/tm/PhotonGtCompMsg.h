/* Type header */

/* DO NOT EDIT! FILE IS AUTO GENERATED */

#ifndef __PHOTON_TM_PHOTON_GT_COMP_MSG_H__
#define __PHOTON_TM_PHOTON_GT_COMP_MSG_H__ 
#include "photon/prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonGtBer componentNum;
  PhotonGtBer messageNum;
} PhotonGtCompMsg;

PhotonResult PhotonGtCompMsg_Serialize(PhotonGtCompMsg self, PhotonWriter* writer);

PhotonResult PhotonGtCompMsg_Deserialize(PhotonGtCompMsg* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#endif