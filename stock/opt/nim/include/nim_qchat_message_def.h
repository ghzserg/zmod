/**
 * @file nim_qchat_message_def.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_MESSAGE_DEF_H__
#define __NIM_QCHAT_MESSAGE_DEF_H__

#include "nim_qchat_channel_def.h"
#include "nim_qchat_member_def.h"
#include "nim_qchat_public_def.h"

#ifdef __cplusplus
extern "C" {
#endif

/// @enum NIMQChatMessageStatus
typedef enum {
    /// 普通消息状态
    kMsgStatusNormal = 0,
    /// 被撤回的消息
    kMsgStatusRevoke,
    /// 被删除的消息
    kMsgStatusDelete,
    /// 发送失败的消息
    kMsgStatusSendFailed,
    kMsgStatusUser = 10000  // 大于10000为用户自定义状态
} NIMQChatMessageStatus;

/// @enum NIMQChatMessageNotifyReason
typedef enum {
    /// 未知原因
    kMessageNotifyReasonUnkonw = 0,
    /// 本消息发给了channel里的所有人
    kMessageNotifyReasonNotifyAll = 1,
    /// 本消息发给了channel里的订阅者
    kMessageNotifyReasonNotifySubscribe = 2,
} NIMQChatMessageNotifyReason;

/** @enum NIMQChatMsgType 圈组消息类型 */
typedef enum {
    /// 文本类型消息
    kNIMQChatMsgTypeText = 0,
    /// 图片类型消息
    kNIMQChatMsgTypeImage = 1,
    /// 音频类型消息
    kNIMQChatMsgTypeAudio = 2,
    /// 视频类型消息
    kNIMQChatMsgTypeVideo = 3,
    /// 位置类型消息
    kNIMQChatMsgTypeLocation = 4,
    /// 通知类型消息
    kNIMQChatMsgTypeNotification = 5,
    /// 文件类型消息
    kNIMQChatMsgTypeFile = 6,
    /// 提醒类型消息
    kNIMQChatMsgTypeTips = 10,
    /// 自定义消息
    kNIMQChatMsgTypeCustom = 100,
    /// 未知类型消息，作为默认值
    kNIMQChatMsgTypeUnknown = 1000,
} NIMQChatMsgType;

/// @enum NIMQChatQuickCommentOperation
typedef enum {
    /// 添加
    kNIMQChatQuickCommentAdd = 1,
    /// 删除
    kNIMQChatQuickCommentRemove,
} NIMQChatQuickCommentOperation;

/// @enum NIMQChatGetReferMessageType
typedef enum {
    /// 获取被回复的消息
    kNIMQChatGetReferMessageTypeReply = 1,
    /// 获取 thread 根消息
    kNIMQChatGetReferMessageTypeThreadRoot = 2,
    /// 获取以上两个条件的消息
    kNIMQChatGetReferMessageTypeAll = kNIMQChatGetReferMessageTypeReply | kNIMQChatGetReferMessageTypeThreadRoot
} NIMQChatGetReferMessageType;

/// @struct NIMQChatDefaultAttach
typedef struct {
    char* msg_attach;
} NIMQChatDefaultAttach;

/** @struct NIMQChatImageAttach 圈组图片消息附件定义 */
typedef struct {
    char* file_path;
    uint32_t width;
    uint32_t height;
    // 以下字段仅在收到消息时有效
    char* url;
    char* md5;
    char* ext;
    char* name;
} NIMQChatImageAttach;

/** @struct NIMQChatAudioAttach 圈组音频消息附件定义 */
typedef struct {
    char* file_path;
    uint64_t duration;
    // 以下字段仅在收到消息时有效
    char* url;
    char* md5;
    char* ext;
    char* name;
} NIMQChatAudioAttach;

/** @struct NIMQChatVideoAttach 圈组视频消息附件定义 */
typedef struct {
    char* file_path;
    uint64_t duration;
    uint32_t width;
    uint32_t height;
    // 以下字段仅在收到消息时有效
    char* url;
    char* md5;
    char* ext;
    char* name;
} NIMQChatVideoAttach;

/** @struct NIMQChatLocationAttach 圈组位置消息附件定义 */
typedef struct {
    double latitude;
    double longitude;
    char* title;
} NIMQChatLocationAttach;

/** @struct NIMQChatNotificationAttach 圈组通知消息附件定义 */
typedef struct {
    uint32_t id;
    char* data;
} NIMQChatNotificationAttach;

/** @struct NIMQChatFileAttach 圈组文件消息附件定义 */
typedef struct {
    char* file_path;
    // 以下字段仅在收到消息时有效
    char* url;
    char* md5;
    char* ext;
    char* name;
} NIMQChatFileAttach;

/** @struct NIMQChatTipsAttach 圈组提醒消息附件定义 */
typedef struct {
    uint32_t type;
    char* data;
} NIMQChatTipsAttach;

/// @struct NIMQChatMessageThreadInfo
typedef struct {
    /// 被回复的消息所有者 ID
    char* reply_from_accid;
    /// 被回复消息得创建时间
    uint64_t reply_msg_timestamp;
    /// 被回复消息得服务器消息 ID
    uint64_t reply_msg_server_id;
    /// 被回复消息得客户端消息 ID
    char* reply_msg_client_id;
    /// thread 根消息的所有者 ID
    char* thread_root_accid;
    /// thread 根消息的创建时间
    uint64_t thread_root_msg_timestamp;
    /// thread 根消息的服务器消息 ID
    uint64_t thread_root_msg_server_id;
    /// thread 根消息的客户端消息 ID
    char* thread_root_msg_client_id;
} NIMQChatMessageThreadInfo;

/// @struct NIMQChatMessageUpdateContent
typedef struct {
    /// 消息状态
    NIMQChatMessageStatus status;
    /// 消息内容
    char* msg_body;
    /// 消息扩展字段
    char* msg_ext;
} NIMQChatMessageUpdateContent;

/// @struct NIMQChatMessageUpdateOpeInfo
typedef struct {
    /// 操作者账号
    char* operator_id;
    /// 操作者客户端类型
    uint32_t operator_client_type;
    /// 操作附言
    char* postscript;
    /// 操作扩展字段
    char* extension;
    /// 推送文案
    char* push_content;
    /// 推送payload
    char* push_payload;
} NIMQChatMessageUpdateOpeInfo;

/// @struct NIMQChatMessage 圈组消息定义
typedef struct {
    /// 消息所属的server id
    uint64_t server_id;
    /// 消息所属的channel id
    uint64_t channel_id;
    /// 消息类型
    NIMQChatMsgType msg_type;
    /// 消息子类型
    uint32_t msg_sub_type;
    /// 消息内容
    char* msg_body;
    /// 消息扩展字段
    char* msg_ext;
    /// 重发标记，false:不是重发，true:是重发
    fcx_bool_t resend_flag;
    /// 是否@所有人，false:否，true:是
    fcx_bool_t mention_all;
    /// @成员列表
    char** mention_accids;
    /// @成员列表长度
    size_t mention_accids_count;
    /// @身份组列表
    uint64_t* mention_role_ids;
    /// @身份组列表长度
    size_t mention_role_ids_count;
    /// 该消息是否存储云端历史，0:不支持，1:支持
    fcx_bool_t history_enable;
    /// 自定义的推送属性，限制json
    char* push_payload;
    /// 自定义的推送内容
    char* push_content;
    /// 是否需要推送, false: 不需要, true: 需要, 默认 false
    fcx_bool_t push_enable;
    /// 是否需要消息计数, false: 不需要, true: 需要, 默认 true
    fcx_bool_t need_badge;
    /// 是否需要推送昵称, false: 不需要, true: 需要, 默认 true
    fcx_bool_t need_push_nick;
    /// 是否需要抄送, false: 不需要, true: 需要, 默认 true
    fcx_bool_t route_enable;
    /// 回复消息信息
    NIMQChatMessageThreadInfo thread_info;
    /// 反垃圾信息
    NIMQChatMessageAntiSpamInfo anti_spam_info;
    /// 是否被反垃圾拦截, false: 未被拦截, true: 已被拦截, 默认 false
    fcx_bool_t is_anti_spamed;
    /// 反垃圾结果
    char* anti_spam_result;
    /// 环境变量，用于指向不同的抄送、第三方回调等配置
    char* env;
    /// 第三方回调扩展字段
    char* callback_ext;
    union {
        /// 默认附件
        NIMQChatDefaultAttach default_attach;
        /// 图片消息附件
        NIMQChatImageAttach image_attach;
        /// 音频消息附件
        NIMQChatAudioAttach audio_attach;
        /// 视频消息附件
        NIMQChatVideoAttach video_attach;
        /// 位置消息附件
        NIMQChatLocationAttach location_attach;
        /// 通知消息附件
        NIMQChatNotificationAttach notification_attach;
        /// 文件消息附件
        NIMQChatFileAttach file_attach;
        /// 提醒消息附件
        NIMQChatTipsAttach tips_attach;
    };
    // 以下字段仅在收到消息时有效
    /// 消息状态
    NIMQChatMessageStatus status;
    /// 消息id
    char* msg_id;
    /// 消息服务器 id
    uint64_t msg_server_id;
    /// 消息发送者的accid
    char* from_accid;
    /// 消息发送者的客户端类型
    uint32_t from_client_type;
    /// 消息发送者的设备id
    char* from_device_id;
    /// 消息发送者的昵称
    char* from_nick;
    /// 消息发送时间戳
    uint64_t timestamp;
    /// 消息更新时间戳
    uint64_t update_timestamp;
    /// 消息下发原因
    NIMQChatMessageNotifyReason notify_reason;
    /// 上次消息变更内容
    NIMQChatMessageUpdateContent update_content;
    /// 上次消息变更操作信息
    NIMQChatMessageUpdateOpeInfo update_ope_info;
    // 内部字段, 无需关注
    /// @身份组所包含的accid列表是否有效
    fcx_bool_t accids_of_mentioned_roles_available;
    /// @身份组所包含的accid列表(部分)
    char** accids_of_mentioned_roles;
    /// @身份组所包含的accid列表长度(部分)
    size_t accids_of_mentioned_roles_count;
} NIMQChatMessage;

/// @struct NIMQChatMsgUpdatedResp
typedef struct {
    /// 自定义用户数据
    void* user_data;
    /// 消息更新信息
    NIMQChatMessageUpdateInfo update_info;
    /// 消息体
    NIMQChatMessage message;
} NIMQChatMsgUpdatedResp;

/// @struct NIMQChatRecvMsgResp
typedef struct {
    /// 自定义用户数据
    void* user_data;
    /// 消息体
    NIMQChatMessage message;
} NIMQChatRecvMsgResp;

/// @struct NIMQChatSendMessageResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 消息体
    NIMQChatMessage message;
} NIMQChatSendMessageResp;

/// @struct NIMQChatUpdateMessageResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 消息体
    NIMQChatMessage message;
} NIMQChatUpdateMessageResp;

/// @struct NIMQChatMarkMessageReadResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 未读数信息
    NIMQChatUnreadInfo unread_info;
} NIMQChatMarkMessageReadResp;

/// @struct NIMQChatReplyMsgResp
typedef NIMQChatSendMessageResp NIMQChatReplyMsgResp;

/// @struct NIMQChatGetMessagesResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 消息数量
    size_t messages_count;
    /// 消息列表
    NIMQChatMessage* messages;
} NIMQChatGetMessagesResp;

/// @struct NIMQChatGetLastMessagesResp
typedef NIMQChatGetMessagesResp NIMQChatGetLastMessagesResp;

/// @struct NIMQChatGetMessageHistoryByIdsResp
typedef NIMQChatGetMessagesResp NIMQChatGetMessageHistoryByIdsResp;

/// @struct NIMQChatGetReferMessagesResp
typedef NIMQChatGetMessagesResp NIMQChatGetReferMessagesResp;

/// @struct NIMQChatGetMessagesCacheResp
typedef NIMQChatGetMessagesResp NIMQChatGetMessagesCacheResp;

/// @struct NIMQChatAddQuickCommentResp
typedef NIMQChatBaseResp NIMQChatAddQuickCommentResp;

/// @struct NIMQChatRemoveQuickCommentResp
typedef NIMQChatBaseResp NIMQChatRemoveQuickCommentResp;

/// @struct NIMQChatQuickCommentDetail
typedef struct {
    /// 评论类型
    uint64_t type;
    /// 这个评论的数量
    uint64_t count;
    /// 创建时间
    uint64_t create_time;
    /// 是否包含自己
    fcx_bool_t include_yourself;
    /// 若干个添加过评论的 account ID
    char** accids;
    /// account ID 总数
    size_t account_count;
} NIMQChatQuickCommentDetail;

/// @struct NIMQChatQuickCommentInfo
typedef struct {
    /// 评论所在服务器 ID
    uint64_t server_id;
    /// 评论所在频道 ID
    uint64_t channel_id;
    /// 评论所属消息服务器 ID
    uint64_t msg_server_id;
    /// 总的评论数量
    uint64_t count;
    /// 最后一次操作的时间
    uint64_t timestamp;
    /// 评论详情
    NIMQChatQuickCommentDetail* detail;
    /// 评论详情数量
    size_t detail_count;
} NIMQChatQuickCommentInfo;

/// @struct NIMQChatGetQuickCommentsResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    NIMQChatQuickCommentInfo* comments;
    size_t comments_count;
} NIMQChatGetQuickCommentsResp;

/// @struct NIMQChatThreadMessageMetaInfo
typedef struct {
    /// 总数
    uint32_t total;
    /// 最后一条消息时间戳
    uint64_t timestamp;
    /// thread 消息服务器 ID
    uint64_t thread_msg_server_id;
    /// thread 消息时间戳
    uint64_t thread_msg_timestamp;
} NIMQChatThreadMessageMetaInfo;

/// @struct NIMQChatGetThreadMessagesResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    NIMQChatThreadMessageMetaInfo meta_info;
    NIMQChatMessage root_message;
    NIMQChatMessage* messages;
    size_t messages_count;
} NIMQChatGetThreadMessagesResp;

/// @struct NIMQChatGetThreadRootMessagesMetaResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 消息元信息
    NIMQChatThreadMessageMetaInfo* meta_infos;
    /// 消息元信息数量
    size_t meta_info_count;
    /// 自定义用户数据
    void* user_data;
} NIMQChatGetThreadRootMessagesMetaResp;

/// @struct NIMQChatMessageSearchPageResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 分页信息
    NIMQChatPageInfo page_info;
    /// 消息数量
    size_t messages_count;
    /// 消息列表
    NIMQChatMessage* messages;
} NIMQChatMessageSearchPageResp;

/// @struct NIMQChatGetMentionedMeMessagesResp
typedef NIMQChatMessageSearchPageResp NIMQChatGetMentionedMeMessagesResp;

/// @struct NIMQChatMentionedResult
typedef struct {
    /// 消息 id
    char* msg_id;
    /// 是否被提及
    fcx_bool_t mentioned_me;
} NIMQChatMentionedResult;

/// @struct NIMQChatAreMentionedMeMessagesResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 结果数量
    size_t result_count;
    /// 结果列表
    NIMQChatMentionedResult* result;
} NIMQChatAreMentionedMeMessagesResp;

/// @struct NIMQChatGetTextCacheResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 文本内容
    const char* value;
} NIMQChatGetTextCacheResp;

/* ---------------------------- 接口回调声明 --------------------------- */

/// 接收消息回调
typedef void (*nim_qchat_recv_msg_cb_func)(const NIMQChatRecvMsgResp* resp);
/// 消息更新通知回调
typedef void (*nim_qchat_msg_updated_cb_func)(const NIMQChatMsgUpdatedResp* resp);
/// 发送消息回调
typedef void (*nim_qchat_send_msg_cb_func)(const NIMQChatSendMessageResp* resp);
/// 更新消息回调
typedef void (*nim_qchat_update_msg_cb_func)(const NIMQChatUpdateMessageResp* resp);
/// 消息标记已读回调
typedef void (*nim_qchat_ack_cb_func)(const NIMQChatMarkMessageReadResp* resp);
/// 查询历史消息回调
typedef void (*nim_qchat_query_history_msg_cb_func)(const NIMQChatGetMessagesResp* resp);
/// 查询频道最后一条消息回调
typedef void (*nim_qchat_get_last_messages_cb_func)(const NIMQChatGetLastMessagesResp* resp);
/// 回复消息回调
typedef void (*nim_qchat_reply_msg_cb_func)(const NIMQChatReplyMsgResp* resp);
/// 根据消息 ID 查询消息回调
typedef void (*nim_qchat_get_message_history_by_ids_cb_func)(const NIMQChatGetMessageHistoryByIdsResp* resp);
/// 查询未读消息中 @ 当前用户的消息回调
typedef void (*nim_qchat_get_mentioned_me_messages_cb_func)(const NIMQChatGetMentionedMeMessagesResp* resp);
/// 查询消息是否 @ 当前用户回调
typedef void (*nim_qchat_are_mentioned_me_messages_cb_func)(const NIMQChatAreMentionedMeMessagesResp* resp);
/// 获取关联消息回调
typedef void (*nim_qchat_get_refer_messages_cb_func)(const NIMQChatGetReferMessagesResp* resp);
/// 查询本地缓存消息历史
typedef void (*nim_qchat_query_history_msg_cache_cb_func)(const NIMQChatGetMessagesCacheResp* resp);
/// 查询Thread消息回调
typedef void (*nim_qchat_get_thread_messages_cb_func)(const NIMQChatGetThreadMessagesResp* resp);
/// 查询Thread消息元信息回调
typedef void (*nim_qchat_get_thread_messages_meta_cb_func)(const NIMQChatGetThreadRootMessagesMetaResp* resp);
/// 添加快捷回复回调
typedef void (*nim_qchat_add_quick_comment_cb_func)(const NIMQChatAddQuickCommentResp* resp);
/// 删除快捷回复回调
typedef void (*nim_qchat_remove_quick_comment_cb_func)(const NIMQChatRemoveQuickCommentResp* resp);
/// 查询快捷回复回调
typedef void (*nim_qchat_get_quick_comments_cb_func)(const NIMQChatGetQuickCommentsResp* resp);
/// 消息搜索回调
typedef void (*nim_qchat_message_search_page_cb_func)(const NIMQChatMessageSearchPageResp* resp);
/// 写入文本缓存回调
typedef void (*nim_qchat_write_text_cache_cb_func)(const NIMQChatBaseResp* resp);
/// 文本缓存回调
typedef void (*nim_qchat_get_text_cache_cb_func)(const NIMQChatGetTextCacheResp* resp);

/* ---------------------------- 接口调用参数 --------------------------- */

/// @struct NIMQChatRegRecvMsgCbParam
typedef struct {
    /// 接收消息异步回调
    nim_qchat_recv_msg_cb_func cb;
    /// 自定义用户数据
    void* user_data;
} NIMQChatRegRecvMsgCbParam;

/// @struct NIMQChatRegMsgUpdatedCbParam
typedef struct {
    /// 消息更新异步回调
    nim_qchat_msg_updated_cb_func cb;
    /// 自定义用户数据
    void* user_data;
} NIMQChatRegMsgUpdatedCbParam;

/// @struct NIMQChatSendMessageParam
typedef struct {
    /// 发送消息异步回调
    nim_qchat_send_msg_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 消息体
    NIMQChatMessage message;
} NIMQChatSendMessageParam;

/// @struct NIMQChatUpdateMessageParam
typedef struct {
    /// 发送消息异步回调
    nim_qchat_update_msg_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 频道ID信息
    NIMQChatChannelIDInfo id_info;
    /// 消息服务器 id
    uint64_t msg_server_id;
    /// 消息发送时间戳
    uint64_t timestamp;
    /// 更新信息
    NIMQChatMessageUpdateInfo update_info;
    /// 反垃圾信息
    NIMQChatMessageAntiSpamInfo anti_spam_info;
    // 以下为待更新的消息属性
    /// 消息状态, 不允许更新为删除或撤回
    NIMQChatMessageStatus status;
    /// 消息体
    char* msg_body;
    /// 消息扩展字段
    char* msg_ext;
    /// 消息子类型
    uint32_t msg_sub_type;
} NIMQChatUpdateMessageParam;

/// @struct NIMQChatRevokeMessageParam
typedef struct {
    /// 发送消息异步回调
    nim_qchat_update_msg_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 频道ID信息
    NIMQChatChannelIDInfo id_info;
    /// 消息服务器 id
    uint64_t msg_server_id;
    /// 消息发送时间戳
    uint64_t timestamp;
    /// 更新信息
    NIMQChatMessageUpdateInfo update_info;
} NIMQChatRevokeMessageParam;

/// @struct NIMQChatDeleteMessageParam
typedef struct {
    /// 发送消息异步回调
    nim_qchat_update_msg_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 频道ID信息
    NIMQChatChannelIDInfo id_info;
    /// 消息服务器 id
    uint64_t msg_server_id;
    /// 消息发送时间戳
    uint64_t timestamp;
    /// 更新信息
    NIMQChatMessageUpdateInfo update_info;
} NIMQChatDeleteMessageParam;

/// @struct NIMQChatGetMessagesParam
typedef struct {
    /// 查询历史消息异步回调
    nim_qchat_query_history_msg_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 查询开始时间
    uint64_t from_time;
    /// 查询结束时间
    uint64_t to_time;
    /// 排除某条消息, msg server id
    uint64_t exclude_msg_server_id;
    /// 查询条数
    uint32_t limit;
    /// 是否倒序, false: 否, true: 是
    fcx_bool_t reverse;
    /// 是否包含本地消息
    fcx_bool_t include_local_messages;
} NIMQChatGetMessagesParam;

/// @struct NIMQChatGetMentionedMeMessagesParam
typedef struct {
    /// 查询未读消息中 @ 当前用户的消息异步回调
    nim_qchat_get_mentioned_me_messages_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 查询的起始时间位置, 0表示当前时间
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
} NIMQChatGetMentionedMeMessagesParam;

/// @struct NIMQChatAreMentionedMeMessagesParam
typedef struct {
    /// 查询消息是否 @ 当前用户的异步回调
    nim_qchat_are_mentioned_me_messages_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 要查询的息数量
    size_t message_count;
    /// 要查询的消息列表
    NIMQChatMessage* messages;
} NIMQChatAreMentionedMeMessagesParam;

/// @struct NIMQChatGetLastMessagesParam
typedef struct {
    /// 查询历史消息异步回调
    nim_qchat_get_last_messages_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t* channel_ids;
    /// 频道ID数量
    size_t channel_ids_count;
} NIMQChatGetLastMessagesParam;

/// @struct NIMQChatGetMessagesCacheParam
typedef struct {
    /// 查询本地缓存消息历史异步回调
    nim_qchat_query_history_msg_cache_cb_func cb;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道 ID
    uint64_t channel_id;
    /// 自定义用户数据
    void* user_data;
} NIMQChatGetMessagesCacheParam;

/// @struct NIMQChatMarkMessageReadParam
typedef struct {
    /// 标记消息已读异步回调
    nim_qchat_ack_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 标记已读channel ID
    NIMQChatChannelIDInfo id_info;
    /// 标记消息已读时间戳
    uint64_t timestamp;
} NIMQChatMarkMessageReadParam;

/// @struct NIMQChatReplyMessageParam
typedef struct {
    /// 发送消息异步回调
    nim_qchat_reply_msg_cb_func cb;
    /// 被引用的消息体
    NIMQChatMessage quote_message;
    /// 消息体
    NIMQChatMessage message;
    /// 自定义用户数据
    void* user_data;
} NIMQChatReplyMessageParam;

/// @struct NIMQChatGetMessageColumns
typedef struct {
    /// 消息服务器 ID
    uint64_t msg_server_id;
    /// 消息发送时间戳
    uint64_t timestamp;
} NIMQChatGetMessageColumns;

/// @struct NIMQChatGetMessageHistoryByIdsParam
typedef struct {
    nim_qchat_get_message_history_by_ids_cb_func cb;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道 ID
    uint64_t channel_id;
    /// 消息列表
    NIMQChatGetMessageColumns* columns;
    /// 查询的消息数量
    size_t column_count;
    /// 自定义用户数据
    void* user_data;
} NIMQChatGetMessageHistoryByIdsParam;

/// @struct NIMQChatGetReferMessagesParam
typedef struct {
    /// 获取引用消息异步回调
    nim_qchat_get_refer_messages_cb_func cb;
    /// 查询的类型
    NIMQChatGetReferMessageType type;
    /// 要查询的消息体
    NIMQChatMessage message;
    /// 自定义用户数据
    void* user_data;
} NIMQChatGetReferMessagesParam;

/// @struct NIMQChatGetThreadMessagesParam
typedef struct {
    /// 查询 thread 消息异步回调
    nim_qchat_get_thread_messages_cb_func cb;
    /// 消息体
    NIMQChatMessage message;
    /// 查询开始时间
    uint64_t from_time;
    /// 查询结束时间
    uint64_t to_time;
    /// 排除某条消息, message server id
    uint64_t exclude_msg_server_id;
    /// 查询条数
    uint32_t limit;
    /// 是否倒序, false: 否, true: 是
    fcx_bool_t reverse;
    /// 自定义用户数据
    void* user_data;
} NIMQChatGetThreadMessagesParam;

/// @struct NIMQChatGetThreadRootMessagesMetaParam
typedef struct {
    /// 查询 thread 消息元信息异步回调
    nim_qchat_get_thread_messages_meta_cb_func cb;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 要查询的 thread root 消息列表
    NIMQChatMessage* messages;
    /// 要查询的 thread root 消息数量
    size_t message_count;
    /// 自定义用户数据
    void* user_data;
} NIMQChatGetThreadRootMessagesMetaParam;

/// @struct NIMQChatAddQuickCommentParam
typedef struct {
    /// 发送消息异步回调
    nim_qchat_add_quick_comment_cb_func cb;
    /// 要被添加快捷评论的消息体
    NIMQChatMessage quote_message;
    /// 快捷评论类型，是一个数字，大于0
    uint32_t type;
    /// 快捷评论操作，1 是添加，2 是删除
    NIMQChatQuickCommentOperation operation;
    /// 自定义用户数据
    void* user_data;
} NIMQChatAddQuickCommentParam;

/// @struct NIMQChatRemoveQuickCommentParam
typedef NIMQChatAddQuickCommentParam NIMQChatRemoveQuickCommentParam;

/// @struct NIMQChatGetQuickCommentsParam
typedef struct {
    /// 获取快捷评论异步回调
    nim_qchat_get_quick_comments_cb_func cb;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 消息服务器 ID 列表
    uint64_t* msg_server_id_list;
    /// 消息服务器 ID 列表数量
    size_t msg_server_id_count;
    /// 自定义用户数据
    void* user_data;
} NIMQChatGetQuickCommentsParam;

/// @struct NIMQChatMessageSearchPageParam
typedef struct {
    /// 消息搜索异步回调
    nim_qchat_message_search_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 搜索的关键字
    char* keyword;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 消息发送者ID
    char* from_accid;
    /// 搜索的开始时间
    uint64_t from_time;
    /// 搜索的结束时间
    uint64_t to_time;
    /// 搜索的消息类型数量
    size_t msg_types_count;
    /// 搜索的消息类型
    NIMQChatMsgType* msg_types;
    /// 搜索的消息子类型数量
    size_t sub_types_count;
    /// 搜索的消息子类型
    uint32_t* sub_types;
    /// 是否包含自己的消息
    fcx_bool_t include_self;
    /// 排序顺序
    NIMQChatSearchOrder order;
    /// 排序规则
    NIMQChatMessageSearchSort sort;
    /// 查询条数
    uint32_t limit;
    /// 查询游标, 查询的起始位置
    char* cursor;
} NIMQChatMessageSearchPageParam;

/// @struct NIMQChatInsertOrReplaceTextCacheParam
typedef struct {
    /// 写入文本缓存异步回调
    nim_qchat_write_text_cache_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 缓存的内容
    char* value;
} NIMQChatInsertOrReplaceTextCacheParam;

/// @struct 插入或替换文本缓存回包
typedef NIMQChatBaseResp NIMQChatInsertOrReplaceTextCacheResp;

/// @struct NIMQChatDeleteTextCacheParam
typedef struct {
    /// 写入文本缓存异步回调
    nim_qchat_write_text_cache_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
} NIMQChatDeleteTextCacheParam;

/// @broef 删除文本缓存回包
typedef NIMQChatBaseResp NIMQChatDeleteTextCacheResp;

/// @struct NIMQChatGetTextCacheParam
typedef struct {
    /// 获取文本缓存异步回调
    nim_qchat_get_text_cache_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
} NIMQChatGetTextCacheParam;

#ifdef __cplusplus
}
#endif

#endif  // __NIM_QCHAT_MESSAGE_DEF_H__
