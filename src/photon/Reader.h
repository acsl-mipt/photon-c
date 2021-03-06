#ifndef __PHOTON_READER_H__
#define __PHOTON_READER_H__

#include "photon/Config.h"
#include "photon/Result.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    const uint8_t* current;
    const uint8_t* start;
    const uint8_t* end;
} PhotonReader;

void PhotonReader_Init(PhotonReader* self, const void* data, size_t size);

bool PhotonReader_IsAtEnd(const PhotonReader* self);

const uint8_t* PhotonReader_CurrentPtr(const PhotonReader* self);

size_t PhotonReader_ReadableSize(const PhotonReader* self);

void PhotonReader_Skip(PhotonReader* self, size_t size);

void PhotonReader_Read(PhotonReader* self, void* dest, size_t size);

uint8_t PhotonReader_PeekUint8(const PhotonReader* self);
uint8_t PhotonReader_ReadUint8(PhotonReader* self);

uint16_t PhotonReader_ReadUint16Be(PhotonReader* self);
uint32_t PhotonReader_ReadUint32Be(PhotonReader* self);
uint64_t PhotonReader_ReadUint64Be(PhotonReader* self);

uint16_t PhotonReader_ReadUint16Le(PhotonReader* self);
uint32_t PhotonReader_ReadUint32Le(PhotonReader* self);
uint64_t PhotonReader_ReadUint64Le(PhotonReader* self);

uint16_t PhotonReader_PeakUint16Be(const PhotonReader* self);

void PhotonReader_Slice(PhotonReader* self, size_t length, PhotonReader* dest);
void PhotonReader_SliceToEnd(PhotonReader* self, PhotonReader* dest);

#ifdef __cplusplus
}
#endif

#endif
