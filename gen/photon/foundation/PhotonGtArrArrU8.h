/* Type header */
#ifndef __PHOTON_GT_ARR_ARR_U8_H_17064cd190ec9c16efd51345a6c3c2df__
#define __PHOTON_GT_ARR_ARR_U8_H_17064cd190ec9c16efd51345a6c3c2df__ 

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