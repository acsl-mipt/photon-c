#ifndef __PHOTON_RINGBUFFER_H__
#define __PHOTON_RINGBUFFER_H__

#include "photon/Config.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t* data;
    size_t readOffset;
    size_t writeOffset;
    size_t size;
    size_t freeSpace;
} PhotonRingBuf;

void PhotonRingBuf_Init(PhotonRingBuf* self, void* data, size_t size);
void PhotonRingBuf_Peek(const PhotonRingBuf* self, void* dest, size_t size, size_t offset);
uint8_t PhotonRingBuf_PeekUint8(const PhotonRingBuf* self, size_t offset);
void PhotonRingBuf_Read(PhotonRingBuf* self, void* dest, size_t size);
void PhotonRingBuf_Erase(PhotonRingBuf* self, size_t size);
const uint8_t* PhotonRingBuf_ReadPtr(const PhotonRingBuf* self);
void PhotonRingBuf_Write(PhotonRingBuf* self, const void* src, size_t size);
size_t PhotonRingBuf_ReadableSize(const PhotonRingBuf* self);
size_t PhotonRingBuf_LinearReadableSize(const PhotonRingBuf* self);

#ifdef __cplusplus
}
#endif

#endif
