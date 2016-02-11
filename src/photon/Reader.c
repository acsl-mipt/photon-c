#include "photon/Config.h"
#include "photon/Reader.h"
#include "photon/Endian.h"

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

void PhotonReader_Init(PhotonReader* self, const void* data, size_t size)
{
    self->start = data;
    self->current = data;
    self->end = self->start + size;
}

bool PhotonReader_IsAtEnd(const PhotonReader* self)
{
    return self->current == self->end;
}

const uint8_t* PhotonReader_CurrentPtr(const PhotonReader* self)
{
    return self->current;
}

size_t PhotonReader_ReadableSize(const PhotonReader* self)
{
    return self->current - self->end;
}

uint8_t PhotonReader_PeekUint8(const PhotonReader* self)
{
    return *self->current;
}

void PhotonReader_Read(PhotonReader* self, void* dest, size_t size)
{
    memcpy(dest, self->current, size);
    self->current += size;
}

uint8_t PhotonReader_ReadUint8(PhotonReader* self)
{
    uint8_t value = *self->current;
    self->current++;
    return value;
}

void PhotonReader_Slice(PhotonReader* self, size_t length, PhotonReader* dest)
{
    dest->start = self->current;
    self->current += length;
    dest->current = dest->start;
    dest->end = dest->end + length;
}

void PhotonReader_SliceToEnd(PhotonReader* self, PhotonReader* dest)
{
    dest->start = self->current;
    dest->end = self->end;
    dest->current = dest->current;
}

uint16_t PhotonReader_ReadUint16Be(PhotonReader* self)
{
    uint16_t value = Photon_Be16Dec(self->current);
    self->current += 2;
    return value;
}

uint16_t PhotonReader_ReadUint16Le(PhotonReader* self)
{
    uint16_t value = Photon_Le16Dec(self->current);
    self->current += 2;
    return value;
}

uint32_t PhotonReader_ReadUint32Be(PhotonReader* self)
{
    uint32_t value = Photon_Be32Dec(self->current);
    self->current += 4;
    return value;
}

uint32_t PhotonReader_ReadUint32Le(PhotonReader* self)
{
    uint32_t value = Photon_Le32Dec(self->current);
    self->current += 4;
    return value;
}

uint64_t PhotonReader_ReadUint64Be(PhotonReader* self)
{
    uint64_t value = Photon_Be64Dec(self->current);
    self->current += 8;
    return value;
}

uint64_t PhotonReader_ReadUint64Le(PhotonReader* self)
{
    uint64_t value = Photon_Le64Dec(self->current);
    self->current += 8;
    return value;
}

uint16_t PhotonReader_PeakUint16Be(const PhotonReader* self)
{
    return Photon_Be16Dec(self->current);
}

void PhotonReader_Skip(PhotonReader* self, size_t size)
{
    self->current += size;
}
