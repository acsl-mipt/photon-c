#include "photon/Components.h"

#include <assert.h>
#include <string.h>

// Однострочные методы инлайнить

void PhotonGtString_Init(PhotonGtString* self)
{
    self->size = 0;
}

size_t PhotonGtString_Size(const PhotonGtString* self)
{
    return self->size;
}

size_t PhotonGtString_MaxSize(const PhotonGtString* self)
{
    return PHOTON_GT_STRING_MAX_DATA_SIZE;
}

PhotonResult PhotonGtString_Serialize(const PhotonGtString* self, PhotonWriter* dest)
{
    PHOTON_TRY(PhotonWriter_WriteBer(dest, self->size));

    if (PhotonWriter_WritableSize(dest) < self->size) {
        return PhotonResult_NotEnoughSpace;
    }

    //для простых типов memcpy, для сложных типов цикл по каждому элементу с serialize
    PhotonWriter_Write(dest, self->data, self->size * sizeof(self->data[0]));
    return PhotonResult_Ok;
}

uint8_t PhotonGtString_At(PhotonGtString* self, size_t position)
{
    assert(position < self->size);
    return self->data[self->size];
}

void PhotonGtString_Remove(PhotonGtString* self, size_t position)
{
    assert(self->size != 0);
    assert(position < self->size);
    memmove(self->data[position], self->data[position + 1], self->size - position);
}

void PhotonGtString_Append(PhotonGtString* self, uint8_t value)
{
    assert(self->size < PHOTON_GT_STRING_MAX_DATA_SIZE);
    // для простых типов копия опертором= в массив, для сложных memcpy
    self->data[self->size] = value;
    self->size++;
}

void PhotonGtString_Insert(PhotonGtString* self, uint8_t value, size_t position)
{
    assert(self->size < PHOTON_GT_STRING_MAX_DATA_SIZE);
    assert(position <= self->size);
    if (position != self->size) {
        memmove(self->data[position + 1], self->data[position], self->size - position);
    }
    self->data[position] = value;
    self->size++;
}

void PhotonGtString_Clear(PhotonGtString* self)
{
    self->size = 0;
}

void PhotonGtComponentNumberGuidPair_Init(PhotonGtComponentNumberGuidPair* self, const PhotonGuid* guid, PhotonBerValue number)
{
    self->guid = *guid;
    self->number = number;
}

PhotonResult PhotonGtComponentNumberGuidPair_Serialize(const PhotonGtComponentNumberGuidPair* self, PhotonWriter* dest)
{
    PHOTON_TRY(PhotonGuid_Serialize(&self->guid, dest));
    PHOTON_TRY(PhotonWriter_WriteBer(self->number, dest));
    return PhotonResult_Ok;
}

void PhotonGtShortId_Init(PhotonGtShortId* self, const PhotonGuid* deviceGuid, const PhotonGuid* rootComponentGuid)
{
    self->deviceGuid = *deviceGuid;
    self->rootComponentGuid = *rootComponentGuid;
}

PhotonResult PhotonGtShortId_Serialize(const PhotonGtShortId* self, PhotonWriter* dest)
{
    PHOTON_TRY(PhotonGuid_Serialize(&self->deviceGuid, dest));
    PHOTON_TRY(PhotonGuid_Serialize(&self->rootComponentGuid, dest));
    return PhotonResult_Ok;
}

void PhotonGtFullId_Init(PhotonGtFullId* self, const PhotonGtShortId* shortId)
{
    self->shortId = *shortId;
    self->_pairsSize = 0;
}

void PhotonGtFullId_AppendToPairs(PhotonGtFullId* self, const PhotonGtComponentNumberGuidPair* value)
{
    assert(self->_pairsSize < PHOTON_GT_FULL_ID_MAX_PAIRS_SIZE);
    // для простых типов копия опертором= в массив, для сложных memcpy
    memcpy(&self->pairs[self->_pairsSize], value, sizeof(PhotonGtComponentNumberGuidPair));
    self->_pairsSize++;
}

void PhotonGtFullId_ClearPairs(PhotonGtFullId* self)
{
    self->_pairsSize = 0;
}

void PhotonGtFullId_InsertIntoPairs(PhotonGtFullId* self, const PhotonGtComponentNumberGuidPair* value, size_t position)
{
    assert(self->_pairsSize < PHOTON_GT_FULL_ID_MAX_PAIRS_SIZE);
    assert(position <= self->_pairsSize);
    if (position != self->_pairsSize) {
        memmove(self->pairs[position + 1], self->pairs[position], self->_pairsSize - position);
    }
    self->pairs[position] = value;
    self->_pairsSize++;
}

PhotonGtComponentNumberGuidPair* PhotonGtFullId_PairsAt(const PhotonGtFullId* self, size_t position)
{
    assert(position < self->_pairsSize);
    return self->pairs[self->_pairsSize];
}

size_t PhotonGtFullId_PairsMaxSize(const PhotonGtFullId* self)
{
    return PHOTON_GT_FULL_ID_MAX_PAIRS_SIZE;
}

size_t PhotonGtFullId_PairsSize(const PhotonGtFullId* self)
{
    return self->_pairsSize;
}

void PhotonGtFullId_RemoveFromPairs(PhotonGtFullId* self, size_t position)
{
    assert(self->_pairsSize != 0);
    assert(position < self->_pairsSize);
    memmove(self->pairs[position], self->pairs[position + 1], self->_pairsSize - position);
}

PhotonResult PhotonGtFullId_Serialize(const PhotonGtFullId* self, PhotonWriter* dest)
{
    PHOTON_TRY(PhotonGtShortId_Serialize(&self->shortId, dest));
    for (int i = 0; i < self->_pairsSize; i++) {
        PHOTON_TRY(PhotonGtComponentNumberGuidPair_Serialize(&self->pairs[i], dest));
    }
    return PhotonResult_Ok;
}


static PhotonComponentsDesc desc;

typedef struct {
    size_t cmdCount;
    PhotonResult (*cmdHandlers[])(PhotonReader* src, PhotonWriter* dest);
    size_t tmCount;
    PhotonResult (*tmGens[])(PhotonWriter* dest);
} PhotonComponentFuncTable;

static PhotonUserFunctionTable userTable;

// хендлеры команд выполняют распаковку аргрументов, дергание пользовательской функции и запаковку возвращаемого значения

static PhotonResult cmd_0_0(PhotonReader* src, PhotonWriter* dest)
{
    if (PhotonReader_ReadableSize(src) != 0) {
        return PhotonResult_InvalidDataSize;
    }
    PhotonGtShortId* shortId;                                        // эти 2 строки можно автоматом
    PHOTON_TRY(userTable.identificationRequestShortId(&shortId));    // сгенерировать при помощи аннотаций
    PHOTON_TRY(PhotonGtShortId_Serialize(shortId, dest));
    return PhotonResult_Ok;
}

static PhotonResult cmd_0_1(PhotonReader* src, PhotonWriter* dest)
{
    if (PhotonReader_ReadableSize(src) != 0) {
        return PhotonResult_InvalidDataSize;
    }
    PhotonGtFullId* fullId;
    PHOTON_TRY(userTable.identificationRequestFullId(&fullId));
    PHOTON_TRY(PhotonGtFullId_Serialize(fullId, dest));
    return PhotonResult_Ok;
}

static PhotonResult cmd_0_2(PhotonReader* src, PhotonWriter* dest)
{
    PhotonBerValue componentNumber;
    PHOTON_TRY(PhotonReader_ReadBer(src, &componentNumber));
    PhotonGuid* guid;
    PHOTON_TRY(userTable.identificationRequestComponentGuid(componentNumber, &guid));
    PHOTON_TRY(PhotonGtFullId_Serialize(guid, dest));
    return PhotonResult_Ok;
}

static PhotonResult tm_param_0_0(PhotonWriter* dest)
{
    PHOTON_TRY(PhotonGtFullId_Serialize(&desc.identification.fullId, dest));
    return PhotonResult_Ok;
}

static PhotonComponentFuncTable allComponentsTable[] = {
    {3, {cmd_0_0, cmd_0_1, cmd_0_2}, 1, {tm_param_0_0}}
};

