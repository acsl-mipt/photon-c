#include "photon/Config.h"
#include "photon/Writer.h"
#include "photon/Endian.h"
#include "photon/Ber.h"

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

void PhotonWriter_Init(PhotonWriter* self, void* dest, size_t size)
{
    self->start = dest;
    self->current = dest;
    self->end = self->start + size;
}

bool PhotonWriter_IsAtEnd(const PhotonWriter* self)
{
    return self->current == self->end;
}

uint8_t* PhotonWriter_CurrentPtr(const PhotonWriter* self)
{
    return self->current;
}

void PhotonWriter_SetCurrentPtr(PhotonWriter* self, uint8_t* ptr)
{
    assert(ptr >= self->start && ptr <= self->end);
    self->current = ptr;
}

void PhotonWriter_Skip(PhotonWriter* self, size_t size)
{
    self->current += size;
}

void PhotonWriter_Write(PhotonWriter* self, const void* src, size_t size)
{
    memcpy(self->current, src, size);
    self->current += size;
}

size_t PhotonWriter_WritableSize(const PhotonWriter* self)
{
    return self->end - self->current;
}

void PhotonWriter_SliceFromBack(PhotonWriter* self, size_t length, PhotonWriter* dest)
{
    dest->start = self->current;
    dest->current = dest->start;
    dest->end = self->end - length;
    self->current = dest->end;
}

void PhotonWriter_WriteUint8(PhotonWriter* self, uint8_t value)
{
    *self->current = value;
    self->current++;
}

void PhotonWriter_WriteUint16Be(PhotonWriter* self, uint16_t value)
{
    Photon_Be16Enc(self->current, value);
    self->current += 2;
}

void PhotonWriter_WriteUint16Le(PhotonWriter* self, uint16_t value)
{
    Photon_Le16Enc(self->current, value);
    self->current += 2;
}

void PhotonWriter_WriteUint32Be(PhotonWriter* self, uint32_t value)
{
    Photon_Be32Enc(self->current, value);
    self->current += 4;
}

void PhotonWriter_WriteUint32Le(PhotonWriter* self, uint32_t value)
{
    Photon_Le32Enc(self->current, value);
    self->current += 4;
}

void PhotonWriter_WriteUint64Be(PhotonWriter* self, uint64_t value)
{
    Photon_Be64Enc(self->current, value);
    self->current += 8;
}

void PhotonWriter_WriteUint64Le(PhotonWriter* self, uint64_t value)
{
    Photon_Le64Enc(self->current, value);
    self->current += 8;
}
