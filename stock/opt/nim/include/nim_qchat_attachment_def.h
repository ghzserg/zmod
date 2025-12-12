/**
 * @file nim_qchat_attachment_def.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_ATTACHMENT_DEF_H__
#define __NIM_QCHAT_ATTACHMENT_DEF_H__

#include "nim_qchat_public_def.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    /// 原文件
    NIMQChatDownloadResTypeSource = 1,
    /// 图片缩略图
    NIMQChatDownloadResTypeImageThumnail = 2,
    /// 视频封面
    NIMQChatDownloadResTypeVideoCover = 3,
} NIMQChatDownloadResType;

/// @struct NIMQChatAttachmentCustomTokenResp
typedef struct {
    /// 自定义用户数据
    void* user_data;
    /// 上传/下载的url
    char* url;
    /// 将该指针指向零结尾的token字符串的起始地址
    char* token;
} NIMQChatAttachmentCustomTokenResp;

/// @struct NIMQChatAttachmentUploadResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 任务id
    char* task_id;
    /// 上传后的url
    char* url;
} NIMQChatAttachmentUploadResp;

/// @struct NIMQChatAttachmentDownloadResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 下载资源类型
    NIMQChatDownloadResType res_type;
    /// 任务id, 自动下载的任务则为消息id
    char* task_id;
    /// 下载后的文件路径
    char* file_path;
} NIMQChatAttachmentDownloadResp;

/// @struct NIMQChatAttachmentProgressResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 下载任务id
    char* task_id;
    /// 文件总大小
    uint64_t total_size;
    /// 当前已经上传/下载的大小
    uint64_t cur_size;
} NIMQChatAttachmentProgressResp;

/// 获取附件上传下载自定义token回调
typedef NIMQChatAttachmentCustomTokenResp (*nim_qchat_attachment_custom_token_cb_func)(
    const NIMQChatAttachmentCustomTokenResp* resp);
/// 上传附件回调
typedef void (*nim_qchat_attachment_upload_cb_func)(const NIMQChatAttachmentUploadResp* resp);
/// 下载附件回调
typedef void (*nim_qchat_attachment_download_cb_func)(const NIMQChatAttachmentDownloadResp* resp);
/// 删除附件回调
typedef void (*nim_qchat_attachment_progress_cb_func)(const NIMQChatAttachmentProgressResp* resp);

/// @struct NIMQChatAttachmentRegCustomTokenCbParam
typedef struct {
    /// 自定义token回调
    nim_qchat_attachment_custom_token_cb_func cb;
    /// 自定义用户数据
    void* user_data;
} NIMQChatAttachmentRegCustomTokenCbParam;

/// @struct NIMQChatAttachmentRegUploadCbParam
typedef struct {
    /// 上传附件全局异步回调
    nim_qchat_attachment_upload_cb_func cb;
    /// 自定义用户数据
    void* user_data;
} NIMQChatAttachmentRegUploadCbParam;

/// @struct NIMQChatAttachmentRegDownloadCbParam
typedef struct {
    /// 下载附件全局异步回调
    nim_qchat_attachment_download_cb_func cb;
    /// 自定义用户数据
    void* user_data;
} NIMQChatAttachmentRegDownloadCbParam;

/// @struct NIMQChatAttachmentRegProgressCbParam
typedef struct {
    /// 上传/下载全局进度回调
    nim_qchat_attachment_progress_cb_func cb;
    /// 自定义用户数据
    void* user_data;
} NIMQChatAttachmentRegProgressCbParam;

/// @struct NIMQChatAttachmentUploadParam
typedef struct {
    /// 上传附件异步回调
    nim_qchat_attachment_upload_cb_func cb;
    /// 上传附件进度回调
    nim_qchat_attachment_progress_cb_func progress_cb;
    /// 自定义用户数据
    void* user_data;
    /// 任务id, 为空时自动生成
    char* task_id;
    /// 附件路径
    char* file_path;
} NIMQChatAttachmentUploadParam;

/// @struct NIMQChatAttachmentStopUploadParam
typedef struct {
    /// 任务id, 为空时自动生成
    char* task_id;
} NIMQChatAttachmentStopUploadParam;

/// @struct NIMQChatAttachmentDownloadParam
typedef struct {
    /// 下载附件异步回调
    nim_qchat_attachment_download_cb_func cb;
    /// 下载附件进度回调
    nim_qchat_attachment_progress_cb_func progress_cb;
    /// 自定义用户数据
    void* user_data;
    /// 下载资源类型
    NIMQChatDownloadResType res_type;
    /// 任务id, 为空时自动生成
    char* task_id;
    /// 附件url
    char* url;
    /// 附件路径
    char* file_path;
} NIMQChatAttachmentDownloadParam;

/// @struct NIMQChatAttachmentStopDownloadParam
typedef struct {
    /// 任务id, 为空时自动生成
    char* task_id;
} NIMQChatAttachmentStopDownloadParam;
#ifdef __cplusplus
}
#endif

#endif  // __NIM_QCHAT_ATTACHMENT_DEF_H__
