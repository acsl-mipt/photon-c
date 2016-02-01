/* Type header */
#ifndef __PHOTON_GT_COMP_MSG_H_a45bebf237abbbb87edbd86bc68869ac__
#define __PHOTON_GT_COMP_MSG_H_a45bebf237abbbb87edbd86bc68869ac__ 

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