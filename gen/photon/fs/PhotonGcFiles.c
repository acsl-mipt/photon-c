/* Component Files implementation */
#include "photon/fs/PhotonGcFiles.h"

PhotonResult PhotonGcFiles_UploadFile(PhotonGcFiles* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtFullFileInfo fileInfo;
  PHOTON_TRY(PhotonGtFullFileInfo_Deserialize(&fileInfo, reader));
  PhotonGtOptionalFileUploadError cmdResult = self->uploadFile(self, &fileInfo);
  return PhotonGtOptionalFileUploadError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcFiles_DownloadFile(PhotonGcFiles* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtString path;
  PHOTON_TRY(PhotonGtString_Deserialize(&path, reader));
  PhotonGtOrFullFileInfoFileDownloadError cmdResult = self->downloadFile(self, &path);
  return PhotonGtOrFullFileInfoFileDownloadError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcFiles_DeleteNode(PhotonGcFiles* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtString path;
  PHOTON_TRY(PhotonGtString_Deserialize(&path, reader));
  PhotonGtOptionalFileDeleteError cmdResult = self->deleteNode(self, &path);
  return PhotonGtOptionalFileDeleteError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcFiles_RequestFileList(PhotonGcFiles* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtString path;
  PHOTON_TRY(PhotonGtString_Deserialize(&path, reader));
  PhotonGtOrArrNodeInfoFileListError cmdResult = self->requestFileList(self, &path);
  return PhotonGtOrArrNodeInfoFileListError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcFiles_CreateDir(PhotonGcFiles* self, PhotonReader* reader, PhotonWriter* writer) {
  PhotonGtString path;
  PHOTON_TRY(PhotonGtString_Deserialize(&path, reader));
  PhotonGtOptionalFileCreateDirError cmdResult = self->createDir(self, &path);
  return PhotonGtOptionalFileCreateDirError_Serialize(&cmdResult, writer);
}

PhotonResult PhotonGcFiles_ExecuteCommand(PhotonGcFiles* self, PhotonReader* reader, PhotonWriter* writer, size_t commandId) {
  switch (commandId) {
    case 0:
      return PhotonGcFiles_UploadFile(self, reader, writer);
    case 1:
      return PhotonGcFiles_DownloadFile(self, reader, writer);
    case 2:
      return PhotonGcFiles_DeleteNode(self, reader, writer);
    case 3:
      return PhotonGcFiles_RequestFileList(self, reader, writer);
    case 4:
      return PhotonGcFiles_CreateDir(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}

PhotonResult PhotonGcFiles_ReadExecuteCommand(PhotonGcFiles* self, PhotonReader* reader, PhotonWriter* writer) {
  size_t commandId;
  PHOTON_TRY(PhotonBer_Deserialize(&commandId, reader));
  return PhotonGcFiles_ExecuteCommand(self, reader, writer, commandId);
}

PhotonResult PhotonGcFiles_WriteMessage(PhotonGcFiles* self, PhotonWriter* writer, size_t messageId) {
  switch (messageId) {
    default:
      return PhotonResult_InvalidMessageId;
  }
}