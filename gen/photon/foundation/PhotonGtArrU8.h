/* Type header */
#ifndef __PHOTON_GT_ARR_U8_H_99c846d5d76370e3f0ae7e35ffc0489a__
#define __PHOTON_GT_ARR_U8_H_99c846d5d76370e3f0ae7e35ffc0489a__ 

#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtU8.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  size_t size;
  PhotonGtU8 data[256];
} PhotonGtArrU8;

PhotonResult PhotonGtArrU8_Serialize(PhotonGtArrU8* self, PhotonWriter* writer);

PhotonResult PhotonGtArrU8_Deserialize(PhotonGtArrU8* self, PhotonReader* reader);

#ifdef __cplusplus
}
#endif

#include "photon/photon_epilogue.h"


#endif