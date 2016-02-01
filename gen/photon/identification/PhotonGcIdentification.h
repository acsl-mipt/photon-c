/* Component Identification interface */
#ifndef __PHOTON_GC_IDENTIFICATION_H_22ce64848fb9326a914f45c6515a3483__
#define __PHOTON_GC_IDENTIFICATION_H_22ce64848fb9326a914f45c6515a3483__ 

#include "photon/photon_prologue.h"

#include "photon/identification/PhotonGtFullId.h"
#include "photon/foundation/PhotonGtGuid.h"
#include "photon/identification/PhotonGtShortId.h"

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
  PhotonGtGuid (*requestComponentGuid)(PhotonGcIdentification*, PhotonBer*);
};
PhotonResult PhotonGcIdentification_RequestShortId(PhotonGcIdentification* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcIdentification_RequestFullId(PhotonGcIdentification* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcIdentification_RequestComponentGuid(PhotonGcIdentification* self, PhotonReader* reader, PhotonWriter* writer);

PhotonResult PhotonGcIdentification_ExecuteCommand(PhotonGcIdentification* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);

PhotonResult PhotonGcIdentification_ReadExecuteCommand(PhotonGcIdentification* self, PhotonReader* reader, PhotonWriter* writer);


#ifdef __cplusplus
}
#endif
#include "photon/photon_epilogue.h"

#endif