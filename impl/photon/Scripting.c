#include <photon/Scripting.h>
#include <photon/Decoder.h>
#include <photon/PhotonGcMain.h>

#include <string.h>

#define _MAX_SCRIPTS 5
#define _MAX_DATA 1024

typedef struct {
    unsigned numScripts;
    unsigned dataUsed;
    PhotonGtScript scripts[_MAX_SCRIPTS];
    uint8_t data[_MAX_DATA];
} PhotonScripting;

static PhotonScripting _scripting;

void PhotonScripting_Init()
{
    _scripting.numScripts = 0;
    _scripting.dataUsed = 0;
}

void PhotonScripting_Run()
{
}

PhotonResult PhotonScripting_ExecuteCommands(PhotonReader* src, PhotonWriter* results)
{
    while (!PhotonReader_IsAtEnd(src)) {
        PhotonBer componentId;
        PHOTON_TRY(PhotonBer_Deserialize(&componentId, src));
        PhotonBer commandId;
        PHOTON_TRY(PhotonBer_Deserialize(&commandId, src));
        PhotonGcMain_ExecuteCommandForComponent(src, results, componentId, commandId);
    }
    return PhotonResult_Ok;
}

// commands

PhotonGtScriptingError PhotonGcMain_ScriptingUploadScript(const PhotonGtScriptInfo* info)
{
    if (_scripting.numScripts >= _MAX_SCRIPTS) {
        return PHOTON_GT_SCRIPTING_ERROR_MAXIMUM_SCRIPTS_REACHED;
    }
    if (info->scriptCode.size > (_MAX_DATA - _scripting.dataUsed)) {
        return PHOTON_GT_SCRIPTING_ERROR_NOT_ENOUGH_SPACE_FOR_SCRIPT;
    }
    for (unsigned i = 0; i < _scripting.numScripts; i++) {
        if (_scripting.scripts[i].info.scriptId == info->scriptId) {
            return PHOTON_GT_SCRIPTING_ERROR_CONFLICTING_SCRIPT_IDS;
        }
    }

    PhotonGtScriptInfo* currentInfo = &_scripting.scripts[_scripting.numScripts].info;
    currentInfo->scriptId = info->scriptId;
    unsigned scriptSize = info->scriptCode.size;
    currentInfo->scriptCode.size = scriptSize;
    uint8_t* scriptPtr = &_scripting.data[_scripting.dataUsed];
    currentInfo->scriptCode.data = scriptPtr;
    memcpy(scriptPtr, info->scriptCode.data, scriptSize);

    PhotonGtScriptRunTiming* runTiming = &_scripting.scripts[_scripting.numScripts].runTiming;

    _scripting.numScripts++;
    _scripting.dataUsed += scriptSize;
}

static PhotonGtScriptingError execFunctionForScriptWithId(PhotonGtScriptId scriptId, PhotonGtScriptingError (*func)(unsigned idx))
{
    for (unsigned i = 0; i < _scripting.numScripts; i++) {
        if (_scripting.scripts[i].info.scriptId == scriptId) {
            return func(i);
        }
    }
    return PHOTON_GT_SCRIPTING_ERROR_NO_SUCH_SCRIPT;
}

static PhotonGtScriptingError deleteScript(unsigned idx)
{
    PhotonGtScriptInfo* script = &_scripting.scripts[idx].info;
    unsigned size = script->scriptCode.size;
    if (idx != (_scripting.numScripts - 1)) { // not last

        PhotonGtScriptInfo* next = &_scripting.scripts[idx + 1].info;
        uint8_t* src = next->scriptCode.data;
        unsigned sizeToMove = &_scripting.data[_scripting.dataUsed] - src;
        memmove(script->scriptCode.data, src, sizeToMove);
        memmove(script, script + 1, (_scripting.numScripts - idx - 1) * sizeof(_scripting.scripts[idx]));
    }
    for (unsigned i = idx; i < _scripting.numScripts; i++) {
        _scripting.scripts[i].info.scriptCode.data -= size;
    }
    _scripting.numScripts--;
    _scripting.dataUsed -= size;
    return PHOTON_GT_SCRIPTING_ERROR_OK;
}

PhotonGtScriptingError PhotonGcMain_ScriptingDeleteScript(PhotonGtScriptId scriptId)
{
    return execFunctionForScriptWithId(scriptId, deleteScript);
}

PhotonGtScriptingError PhotonGcMain_ScriptingRunScriptNow(PhotonGtScriptId scriptId)
{
    return PHOTON_GT_SCRIPTING_ERROR_OK;
}

PhotonGtScriptingError PhotonGcMain_ScriptingScheduleScriptRun(const PhotonGtScriptRunTiming* scriptRunTiming)
{
    return PHOTON_GT_SCRIPTING_ERROR_OK;
}

PhotonGtScriptingError PhotonGcMain_ScriptingEnableScriptRunTiming(PhotonGtGuid scriptRunTimingId)
{
    return PHOTON_GT_SCRIPTING_ERROR_OK;
}

PhotonGtScriptingError PhotonGcMain_ScriptingDisableScriptRunTiming(PhotonGtGuid scriptRunTimingId)
{
    return PHOTON_GT_SCRIPTING_ERROR_OK;
}

PhotonGtArrScript PhotonGcMain_ScriptingScripts()
{
    PhotonGtArrScript scripts;
    scripts.data = &_scripting.scripts[0];
    scripts.size = _scripting.numScripts;
    return scripts;
}
