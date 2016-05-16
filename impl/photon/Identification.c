#include "photon/Identification.h"
#include "photon/PhotonGcMain.h"

static PhotonGtFullId _fullId;

void PhotonIdentification_Init()
{
}

PhotonGtShortId PhotonGcMain_IdentificationRequestShortId()
{
    return _fullId.shortId;
}

const PhotonGtFullId* PhotonGcMain_IdentificationRequestFullId()
{
    return &_fullId;
}

PhotonGtGuid PhotonGcMain_IdentificationRequestComponentGuid(PhotonBer componentNumber)
{
    (void)componentNumber;
    // TODO
    return 0;
}

const PhotonGtFullId* PhotonGcMain_IdentificationFullId()
{
    return &_fullId;
}
