/* Component Tm interface */
#ifndef __PHOTON_GC_TM_H_9a2b77986f95c0c618e9745b5e1c91be__
#define __PHOTON_GC_TM_H_9a2b77986f95c0c618e9745b5e1c91be__ 

#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtArrU8.h"
#include "photon/foundation/PhotonGtArrArrU8.h"
#include "photon/tm/PhotonGtArrEventInfo.h"
#include "photon/decode/PhotonGtOptionalTmCmdError.h"
#include "photon/tm/PhotonGtRingBuf.h"
#include "photon/tm/PhotonGtEventInfo.h"
#include "photon/tm/PhotonGtCompMsg.h"

#ifdef __cplusplus
extern "C" {
#endif

struct PhotonGcTmUserFunctionTable_s;

typedef struct PhotonGcTm_s PhotonGcTm;

struct PhotonGcTm_s {
  PhotonGcTmData* data;
  PhotonGtArrU8 (*onceRequests)(PhotonGcTm*);
  PhotonGtArrArrU8 (*deniedMessagesByComponent)(PhotonGcTm*);
  PhotonGtArrArrU8 (*priorityOrderedRequests)(PhotonGcTm*);
  PhotonGtRingBuf (*outOfOrderMesages)(PhotonGcTm*);
  PhotonGtArrEventInfo (*lostEvents)(PhotonGcTm*);
  PhotonGtOptionalTmCmdError (*sendEventMessage)(PhotonGcTm*, PhotonGtEventInfo*);
  PhotonGtOptionalTmCmdError (*sendStatusMessage)(PhotonGcTm*, PhotonGtCompMsg*);
  PhotonGtOptionalTmCmdError (*setMessageRequest)(PhotonGcTm*, PhotonGtCompMsg*, PhotonBer*);
  PhotonGtOptionalTmCmdError (*clearMessageRequest)(PhotonGcTm*, PhotonGtCompMsg*, PhotonBer*);
  PhotonGtOptionalTmCmdError (*denyMessage)(PhotonGcTm*, PhotonGtCompMsg*);
  PhotonGtOptionalTmCmdError (*allowMessage)(PhotonGcTm*, PhotonGtCompMsg*);
  PhotonGtOptionalTmCmdError (*denyEvent)(PhotonGcTm*, PhotonGtEventInfo*);
  PhotonGtOptionalTmCmdError (*allowEvent)(PhotonGcTm*, PhotonGtEventInfo*);
};
PhotonResult PhotonGcTm_SendEventMessage(PhotonGcTm* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcTm_SendStatusMessage(PhotonGcTm* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcTm_SetMessageRequest(PhotonGcTm* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcTm_ClearMessageRequest(PhotonGcTm* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcTm_DenyMessage(PhotonGcTm* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcTm_AllowMessage(PhotonGcTm* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcTm_DenyEvent(PhotonGcTm* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcTm_AllowEvent(PhotonGcTm* self, PhotonReader* reader, PhotonWriter* writer);

PhotonResult PhotonGcTm_ReadExecuteCommand(PhotonGcTm* self, PhotonReader* reader, PhotonWriter* writer);


#ifdef __cplusplus
}
#endif
#include "photon/photon_epilogue.h"

#endif