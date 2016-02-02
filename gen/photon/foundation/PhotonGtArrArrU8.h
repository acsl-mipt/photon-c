/* Type header */
#ifndef __PHOTON_GT_ARR_ARR_U8_H_1c116d754a889ae052aca92ea915459f__
#define __PHOTON_GT_ARR_ARR_U8_H_1c116d754a889ae052aca92ea915459f__ 

#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtArrU8.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  size_t size;
  PhotonGtArrU8 data[256];
} PhotonGtArrArrU8;

PhotonResult PhotonGtArrArrU8_Serialize(PhotonGtArrArrU8* self, PhotonWriter* writer);

PhotonResult PhotonGtArrArrU8_Deserialize(PhotonGtArrArrU8* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif