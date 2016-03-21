#ifndef __PHOTON_SCRIPTING_H__
#define __PHOTON_SCRIPTING_H__

#include "photon/PhotonGcMain.h"

#ifdef __cplusplus
extern "C" {
#endif

void PhotonScripting_Init();
void PhotonScripting_Run();
PhotonResult PhotonScripting_ExecuteCommands(PhotonReader* src, PhotonWriter* results);

#ifdef __cplusplus
}
#endif

#endif
