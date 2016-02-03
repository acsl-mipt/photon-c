/* Type header */
#ifndef __PHOTON_GT_COMP_MSG_H_55d223067fe6d6ad090a4ae93b1f8aa7__
#define __PHOTON_GT_COMP_MSG_H_55d223067fe6d6ad090a4ae93b1f8aa7__ 

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