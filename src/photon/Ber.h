#ifndef __PHOTON_BER_H__
#define __PHOTON_BER_H__

#include "photon/Result.h"
#include "photon/Reader.h"
#include "photon/Writer.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uint64_t PhotonBer;

PhotonResult PhotonBer_Deserialize(PhotonBer* self, PhotonReader* src);
PhotonResult PhotonBer_Serialize(PhotonBer self, PhotonWriter* dest);
unsigned int PhotonBer_ByteSize(PhotonBer self);

#ifdef __cplusplus
}
#endif

#endif
