/* Type header */
#ifndef __PHOTON_GT_COMP_MSG_H_57fbac95ad899a89a3a154b173ded7f4__
#define __PHOTON_GT_COMP_MSG_H_57fbac95ad899a89a3a154b173ded7f4__ 

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