/* Component Files interface */
#ifndef __PHOTON_GC_FILES_H_c5c6add2cd6a2b9014a755cbcae433b9__
#define __PHOTON_GC_FILES_H_c5c6add2cd6a2b9014a755cbcae433b9__ 

#include "photon/photon_prologue.h"

#include "photon/foundation/PhotonGtString.h"
#include "photon/decode/PhotonGtOrArrNodeInfoFileListError.h"
#include "photon/decode/PhotonGtOptionalFileCreateDirError.h"
#include "photon/decode/PhotonGtOrFullFileInfoFileDownloadError.h"
#include "photon/decode/PhotonGtOptionalFileDeleteError.h"
#include "photon/decode/PhotonGtOptionalFileUploadError.h"
#include "photon/fs/PhotonGtFullFileInfo.h"

#ifdef __cplusplus
extern "C" {
#endif

struct PhotonGcFilesUserFunctionTable_s;

typedef struct PhotonGcFiles_s PhotonGcFiles;

struct PhotonGcFiles_s {
  PhotonGcFilesData* data;
  PhotonGtOptionalFileUploadError (*uploadFile)(PhotonGcFiles*, PhotonGtFullFileInfo*);
  PhotonGtOrFullFileInfoFileDownloadError (*downloadFile)(PhotonGcFiles*, PhotonGtString*);
  PhotonGtOptionalFileDeleteError (*deleteNode)(PhotonGcFiles*, PhotonGtString*);
  PhotonGtOrArrNodeInfoFileListError (*requestFileList)(PhotonGcFiles*, PhotonGtString*);
  PhotonGtOptionalFileCreateDirError (*createDir)(PhotonGcFiles*, PhotonGtString*);
};
PhotonResult PhotonGcFiles_UploadFile(PhotonGcFiles* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcFiles_DownloadFile(PhotonGcFiles* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcFiles_DeleteNode(PhotonGcFiles* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcFiles_RequestFileList(PhotonGcFiles* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcFiles_CreateDir(PhotonGcFiles* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcFiles_ExecuteCommand(PhotonGcFiles* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId);
PhotonResult PhotonGcFiles_ReadExecuteCommand(PhotonGcFiles* self, PhotonReader* reader, PhotonWriter* writer);
PhotonResult PhotonGcFiles_WriteMessage(PhotonGcFiles* self, PhotonWriter* writer, size_t messageId);
PhotonGtB8 PhotonGcFiles_IsStatusMessage(size_t messageId);


#ifdef __cplusplus
}
#endif
#include "photon/photon_epilogue.h"

#endif