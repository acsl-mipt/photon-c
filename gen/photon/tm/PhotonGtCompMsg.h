/* Type header */
#ifndef __PHOTON_GT_COMP_MSG_H_e8ba4023183b9a972ae33f2c51988ef8__
#define __PHOTON_GT_COMP_MSG_H_e8ba4023183b9a972ae33f2c51988ef8__ 

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