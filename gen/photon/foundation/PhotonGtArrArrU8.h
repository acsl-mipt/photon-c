/* Type header */
#ifndef __PHOTON_GT_ARR_ARR_U8_H_fdc2d69a76c8f7f90e644f2cf533ed75__
#define __PHOTON_GT_ARR_ARR_U8_H_fdc2d69a76c8f7f90e644f2cf533ed75__ 
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