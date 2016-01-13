#ifndef __PHOTON_COMPONENTS__
#define __PHOTON_COMPONENTS__

#include "photon/Result.h"
#include "photon/Writer.h"
#include "photon/Reader.h"
#include "photon/Guid.h"

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// попытка описания компонентов как они должны генерироваться
// Gt - generated type
// Gc - generated component
// string - пример массива

#define PHOTON_GT_STRING_MAX_DATA_SIZE 255

typedef struct {
    size_t size;
    uint8_t data[PHOTON_GT_STRING_MAX_DATA_SIZE];
} PhotonGtString;

void PhotonGtString_Init(PhotonGtString* self);
size_t PhotonGtString_Size(const PhotonGtString* self);
size_t PhotonGtString_MaxSize(const PhotonGtString* self);

// для простых типов передача по значению, для сложных по указателю
uint8_t PhotonGtString_At(PhotonGtString* self, size_t position);
void PhotonGtString_Append(PhotonGtString* self, uint8_t value);
void PhotonGtString_Insert(PhotonGtString* self, uint8_t value, size_t position);
void PhotonGtString_Remove(PhotonGtString* self, size_t position);
void PhotonGtString_Clear(PhotonGtString* self);

PhotonResult PhotonGtString_Serialize(const PhotonGtString* self, PhotonWriter* dest);

//----------------
// для структур генерируется инициализатор, сериализация

typedef struct {
    PhotonGuid guid;
    PhotonBerValue number;
} PhotonGtComponentNumberGuidPair;

void PhotonGtComponentNumberGuidPair_Init(PhotonGtComponentNumberGuidPair* self, const PhotonGuid* guid, PhotonBerValue number);
PhotonResult PhotonGtComponentNumberGuidPair_Serialize(const PhotonGtComponentNumberGuidPair* self, PhotonWriter* dest);

//-----------------

typedef struct {
    PhotonGuid deviceGuid;
    PhotonGuid rootComponentGuid;
} PhotonGtShortId;

void PhotonGtShortId_Init(PhotonGtShortId* self, const PhotonGuid* deviceGuid, const PhotonGuid* rootComponentGuid);
PhotonResult PhotonGtShortId_Serialize(const PhotonGtShortId* self, PhotonWriter* dest);

//-----------------
// генерация типов с внутренними нетайпдефнутыми массивами
// для каждого внутреннего массива генерируется набор методов с потсфиксами имени внутреннего массива

#define PHOTON_GT_FULL_ID_MAX_PAIRS_SIZE 255

// заменил deviceComponent....Pairs на pairs

typedef struct {
    PhotonGtShortId shortId;
    size_t _pairsSize; //внутренняя переменная размера с префиксом _
    PhotonGtComponentNumberGuidPair pairs[PHOTON_GT_FULL_ID_MAX_PAIRS_SIZE];
} PhotonGtFullId;

void PhotonGtFullId_Init(PhotonGtFullId* self, const PhotonGtShortId* shortId);
size_t PhotonGtFullId_PairsSize(const PhotonGtFullId* self);
size_t PhotonGtFullId_PairsMaxSize(const PhotonGtFullId* self);

PhotonGtComponentNumberGuidPair* PhotonGtFullId_PairsAt(const PhotonGtFullId* self, size_t position);
void PhotonGtFullId_AppendToPairs(PhotonGtFullId* self, const PhotonGtComponentNumberGuidPair* value);
void PhotonGtFullId_InsertIntoPairs(PhotonGtFullId* self, const PhotonGtComponentNumberGuidPair* value, size_t position);
void PhotonGtFullId_RemoveFromPairs(PhotonGtFullId* self, size_t position);
void PhotonGtFullId_ClearPairs(PhotonGtFullId* self);

PhotonResult PhotonGtFullId_Serialize(const PhotonGtFullId* self, PhotonWriter* dest);

//---------------------
// компоненты

#define PHOTON_COMPONENTS_NUMBER 1

typedef enum {
    PhotonComponentType_Identification = 0
} PhotonComponentType;

typedef struct {
    PhotonGtFullId fullId; // параметр
} PhotonGcIdentification;

// команды
// params - источник параметров команды
// retVal - место для записи ответов на команду
// данная функция десериализует параметры на команду, дергает функцию указатель юзера для исполнения команды
// и сериализует ответ на команду
// функция юзера будет в виде:
// PhotonResult func(ПростойВходнойПараметр1 p1, const СложныйВходнойПараметр* p2, ВыходнойПараметр** p3);

// 1. PhotonResult func(PhotonGtShortId** shortId);
// 2. PhotonResult func(PhotonGtFullId** shortId);
// 3. PhotonResult func(PhotonBerValue componentNumber, PhotonGuid** guid);

//NOTE: так как данные команды тупо геттеры и сериализация кусков структуры, предлагаю сделать полную автоматическую
// этих функций без участия функций указателей юзера
// например при помощи аннотаций

//   parameters
// (
//     full_id fullId,
// )
// command requestShortId() -> short_id { parameters.fullId.shortId }
// command requestFullId() -> full_id { parameters.fullId }
// command requestComponentGuid(ber componentNumber) -> guid {parameters.fullId.deviceComponentGuidPairs[componentNumber] }

typedef struct {
    PhotonGcIdentification identification;
} PhotonComponentsDesc;

typedef struct {
    PhotonResult (*identificationRequestShortId)(PhotonGtShortId** shortId);
    PhotonResult (*identificationRequestFullId)(PhotonGtFullId** shortId);
    PhotonResult (*identificationRequestComponentGuid)(PhotonBerValue, PhotonGuid** shortId);
} PhotonUserFunctionTable;

#ifdef __cplusplus
}
#endif

#endif
