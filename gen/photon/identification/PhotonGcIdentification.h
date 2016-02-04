/* Component Identification interface */
#ifndef __PHOTON_GC_IDENTIFICATION_H_8ab4c119f6bf894ee78cd0a3ad7563f2__
#define __PHOTON_GC_IDENTIFICATION_H_8ab4c119f6bf894ee78cd0a3ad7563f2__ 

#include "photon/photon_prologue.h"

#include "photon/identification/PhotonGtFullId.h"
#include "photon/identification/PhotonGtShortId.h"
#include "photon/foundation/PhotonGtGuid.h"

#ifdef __cplusplus
extern "C" {
#endif

struct PhotonGcIdentificationUserFunctionTable_s;

typedef struct PhotonGcIdentification_s PhotonGcIdentification;

struct PhotonGcIdentification_s {
  PhotonGcIdentificationData* data;
  PhotonGtFullId (*fullId)(PhotonGcIdentification*);
  PhotonGtShortId (*requestShortId)(PhotonGcIdentification*);
  PhotonGtFullId (*requestFullId)(PhotonGcIdentification*);
  PhotonGtGuid (*requestComponentGuid)(PhotonGcIdentification*, PhotonBer);
};
PhotonResult PhotonGcIdentification_RequestShortId(PhotonGcIdentification* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcIdentification_RequestFullId(PhotonGcIdentification* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcIdentification_RequestComponentGuid(PhotonGcIdentification* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcIdentification_WriteFullId(PhotonGcIdentification* self, PhotonWriter* writer);
PhotonResult PhotonGcIdentification_ExecuteCommand(PhotonGcIdentification* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcIdentification_ReadExecuteCommand(PhotonGcIdentification* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcIdentification_WriteMessage(PhotonGcIdentification* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcIdentification_IsStatusMessage(size_t messageId);


#ifdef __cplusplus
}
#endif
#include "photon/photon_epilogue.h"

#endif