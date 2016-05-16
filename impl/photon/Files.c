#include "photon/PhotonGcMain.h"

PhotonGtFileUploadError PhotonGcMain_FilesStartFileUpload(const PhotonGtFileInfo* fileInfo)
{
    (void)fileInfo;
    return PHOTON_GT_FILE_UPLOAD_ERROR_OK;
}

PhotonGtFileUploadError PhotonGcMain_FilesUploadFilePart(PhotonGtArrU8 fileContentsPart)
{
    (void)fileContentsPart;
    return PHOTON_GT_FILE_UPLOAD_ERROR_OK;
}

PhotonGtFileUploadError PhotonGcMain_FilesStopFileUpload()
{
    return PHOTON_GT_FILE_UPLOAD_ERROR_OK;
}

PhotonGtFileDownloadError PhotonGcMain_FilesStopFileDownload()
{
    return PHOTON_GT_FILE_DOWNLOAD_ERROR_OK;
}

PhotonGtFileListError PhotonGcMain_FilesStopRequestFileList()
{
    return PHOTON_GT_FILE_LIST_ERROR_OK;
}

PhotonGtFileDeleteError PhotonGcMain_FilesDeleteNode(PhotonGtString path)
{
    (void)path;
    return PHOTON_GT_FILE_DELETE_ERROR_OK;
}

PhotonGtFileCreateDirError PhotonGcMain_FilesCreateDir(PhotonGtString path)
{
    (void)path;
    return PHOTON_GT_FILE_CREATE_DIR_ERROR_OK;
}

static PhotonGtOrFileInfoFileDownloadError stub1;

const PhotonGtOrFileInfoFileDownloadError* PhotonGcMain_FilesStartFileDownload(PhotonGtString path)
{
    (void)path;
    return &stub1;
}

PhotonGtOrArrU8FileDownloadError PhotonGcMain_FilesDownloadFilePart(PhotonGtBer byteSize)
{
    (void)byteSize;
    PhotonGtOrArrU8FileDownloadError rv;
    rv.tag = 0;
    return rv;
}

PhotonGtOrBerFileListError PhotonGcMain_FilesStartRequestFileList()
{
    PhotonGtOrBerFileListError rv;
    rv.tag = 0;
    return rv;
}

PhotonGtOrArrNodeInfoFileListError PhotonGcMain_FilesRequestFileListPart(PhotonGtBer nodeSize)
{
    (void)nodeSize;
    PhotonGtOrArrNodeInfoFileListError rv;
    rv.tag = 0;
    return rv;
}

PhotonGtFilesMode PhotonGcMain_FilesActiveMode()
{
    return PHOTON_GT_FILES_MODE_BASE;
}
