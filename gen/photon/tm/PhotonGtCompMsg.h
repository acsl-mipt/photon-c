/* Type header */
#ifndef __PHOTON_GT_COMP_MSG_H_ed17c80402c4999f1b318b7d48c83ae6__
#define __PHOTON_GT_COMP_MSG_H_ed17c80402c4999f1b318b7d48c83ae6__ 
#include "photon/photon_prologue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  PhotonBer componentNum;
  PhotonBer messageNum;
} PhotonGtCompMsg;

PhotonResult PhotonGtCompMsg_Serialize(PhotonGtCompMsg* self, PhotonWriter* writer);

PhotonResult PhotonGtCompMsg_Deserialize(PhotonGtCompMsg* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif