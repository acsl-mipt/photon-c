/* Component Files implementation */
#include "PhotonGcFiles.h"

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
      return PhotonGcFiles_FilesUploadFile(self, reader, writer);
    case 1:
      return PhotonGcFiles_FilesDownloadFile(self, reader, writer);
    case 2:
      return PhotonGcFiles_FilesDeleteNode(self, reader, writer);
    case 3:
      return PhotonGcFiles_FilesRequestFileList(self, reader, writer);
    case 4:
      return PhotonGcFiles_FilesCreateDir(self, reader, writer);
    default:
      return PhotonResult_InvalidCommandId;
  }
}