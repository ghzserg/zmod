/**
 * @file nim_qchat_system_notification_def.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_SYSTEM_NOTIFICATION_DEF_H__
#define __NIM_QCHAT_SYSTEM_NOTIFICATION_DEF_H__

#include "nim_qchat_channel_def.h"
#include "nim_qchat_message_def.h"
#include "nim_qchat_public_def.h"
#include "nim_qchat_server_def.h"

#ifdef __cplusplus
extern "C" {
#endif

/// @enum NIMQChatSystemMsgToType 圈组系统通知目标
typedef enum {
    kNIMQChatSystemNotificationToTypeUnknown,  ///< 默认值，需要由用户修改，否则报错 10414 参数错误
    kNIMQChatSystemNotificationToTypeServer,   ///< 发送到 Server，server_id 必填
    kNIMQChatSystemNotificationToTypeChannel,  ///< 发送到 Channel，server_id 和 channel_id 必填
    kNIMQChatSystemNotificationToTypeServerAccids,  ///< 发送到 Server 中的指定用户，server_id 和 to_accids 必填
    kNIMQChatSystemNotificationToTypeChannelAccids,  ///< 发送到 Channel 中的指定用户，server_id、channel_id 和
                                                     ///< to_accids 必填
    kNIMQChatSystemNotificationToTypeAccids,  ///< 发送给指定用户，to_accids 必填
} NIMQChatSystemNotificationToType;

/** @enum NIMQChatSystemNotificationType 圈组系统通知类型 */
typedef enum {
    /// 未知类型系统通知
    kNIMQChatSystemNotificationTypeUnkonwn = 0,
    /// 服务器成员邀请 msg_data: NULL
    kNIMQChatSystemNotificationTypeMemberInvite = 1,
    /// 服务器成员邀请被拒绝 msg_data: NULL
    kNIMQChatSystemNotificationTypeMemberInviteReject = 2,
    /// 服务器成员申请 msg_data: NULL
    kNIMQChatSystemNotificationTypeMemberApply = 3,
    /// 服务器成员申请被拒绝 msg_data: NULL
    kNIMQChatSystemNotificationTypeMemberApplyReject = 4,
    /// 服务器创建 msg_data: NIMQChatSystemNotificationDataServerCreate
    kNIMQChatSystemNotificationTypeServerCreate = 5,
    /// 服务器解散 msg_data: NULL
    kNIMQChatSystemNotificationTypeServerRemove = 6,
    /// 服务器更新 msg_data: NIMQChatSystemNotificationDataServerUpdate
    kNIMQChatSystemNotificationTypeServerUpdate = 7,
    /// 服务器成员邀请完成 msg_data: NIMQChatSystemNotificationDataMemberInviteDone
    kNIMQChatSystemNotificationTypeMemberInviteDone = 8,
    /// 服务器成员邀请被接受 msg_data: NIMQChatSystemNotificationDataMemberInviteAccept
    kNIMQChatSystemNotificationTypeMemberInviteAccept = 9,
    /// 服务器成员申请完成 msg_data: NIMQChatSystemNotificationDataMemberApplyDone
    kNIMQChatSystemNotificationTypeMemberApplyDone = 10,
    /// 服务器成员申请被接受 msg_data: NIMQChatSystemNotificationDataMemberApplyAccept
    kNIMQChatSystemNotificationTypeMemberApplyAccept = 11,
    /// 服务器成员被踢出 msg_data: NIMQChatSystemNotificationDataMemberKick
    kNIMQChatSystemNotificationTypeMemberKick = 12,
    /// 服务器成员离开 msg_data: NIMQChatSystemNotificationDataMemberLeave
    kNIMQChatSystemNotificationTypeMemberLeave = 13,
    /// 服务器成员更新 msg_data: NIMQChatSystemNotificationDataMemberUpdate
    kNIMQChatSystemNotificationTypeMemberUpdate = 14,
    /// 频道创建 msg_data: NIMQChatSystemNotificationDataChannelCreate
    kNIMQChatSystemNotificationTypeChannelCreate = 15,
    /// 频道解散 msg_data: NULL
    kNIMQChatSystemNotificationTypeChannelDelete = 16,
    /// 频道更新 msg_data: NIMQChatSystemNotificationDataChannelUpdate
    kNIMQChatSystemNotificationTypeChannelUpdate = 17,
    /// 频道白/黑名单身份组更新 msg_data: NIMQChatSystemNotificationDataWhiteBlackRoleUpdate
    kNIMQChatSystemNotificationTypeWhiteBlackRoleUpdate = 18,
    /// 频道白/黑名单成员更新 msg_data: NIMQChatSystemNotificationDataWhiteBlackMembersUpdate
    kNIMQChatSystemNotificationTypeWhiteBlackMembersUpdate = 19,
    /// 添加或删除快捷评论通知 msg_data: NIMQChatSystemNotificationQuickCommentChanged
    kNIMQChatSystemNotificationTypeQuickCommentChanged = 20,
    /// 创建频道分组 msg_data: NIMQChatSystemNotificationDataChannelCategoryCreate
    kNIMQChatSystemNotificationTypeChannelCategoryCreate = 21,
    /// 删除频道分组 msg_data: NIMQChatSystemNotificationDataChannelCategoryRemove
    kNIMQChatSystemNotificationTypeChannelCategoryRemove = 22,
    /// 更新频道分组 msg_data: NIMQChatSystemNotificationDataChannelCategoryUpdate
    kNIMQChatSystemNotificationTypeChannelCategoryUpdate = 23,
    /// 频道分组白/黑名单身份组更新 msg_data: NIMQChatSystemNotificationDataChannelCategoryWhiteBlackRoleUpdate
    kNIMQChatSystemNotificationTypeChannelCategoryWhiteBlackRoleUpdate = 24,
    /// 频道分组白/黑名单成员更新 msg_data: NIMQChatSystemNotificationDataChannelCategoryWhiteBlackMembersUpdate
    kNIMQChatSystemNotificationTypeChannelCategoryWhiteBlackMembersUpdate = 25,
    /// 服务器身份组加入成员 msg_data: NIMQChatSystemNotificationDataServerRoleAddMember
    kNIMQChatSystemNotificationTypeServerRoleAddMember = 26,
    /// 服务器身份组移出成员 msg_data: NIMQChatSystemNotificationDataServerRoleRemoveMember
    kNIMQChatSystemNotificationTypeServerRoleRemoveMember = 27,
    /// 服务器身份组权限变更 msg_data: NIMQChatSystemNotificationDataServerRolePermissionChange
    kNIMQChatSystemNotificationTypeServerRolePermissionChange = 28,
    /// 频道定制身份组权限变更 msg_data: NIMQChatSystemNotificationDataChannelRolePermissionChange
    kNIMQChatSystemNotificationTypeChannelRolePermissionChange = 29,
    /// 频道个人定制权限变更 msg_data: NIMQChatSystemNotificationDataMemberRolePermissionChange
    kNIMQChatSystemNotificationTypeMemberRolePermissionChange = 30,
    /// 频道对当前用户可见性变更 msg_data: NIMQChatSystemNotificationDataChannelVisibilityChange
    kNIMQChatSystemNotificationTypeChannelVisibilityChange = 31,
    /// 当前用户进入/离开服务器 msg_data: NIMQChatSystemNotificationDataServerEnterLeave
    kNIMQChatSystemNotificationTypeServerEnterLeave = 32,
    /// 用户通过邀请码加入服务器 msg_data: NIMQChatSystemNotificationDataServerJoinByInviteCode
    kNIMQChatSystemNotificationTypeServerJoinByInviteCode = 33,
    /// 频道对游客可见性变更 msg_data: NIMQChatSystemNotificationDataChannelVisitorVisibilityChange
    kNIMQChatSystemNotificationTypeChannelVisitorVisibilityChange = 34,
    /// 当前用户服务器成员信息对IM资料的联动变更 msg_data: NIMQChatSystemNotificationDataMyMemberInfoUpdated
    kNIMQChatSystemNotificationTypeMyMemberInfoUpdated = 35,
    /// 自定义系统通知 msg_data: NULL
    kNIMQChatSystemNotificationTypeCustom = 100
} NIMQChatSystemNotificationType;

/// @struct NIMQChatSystemNotificationMarkReadInfo
typedef struct {
    /// 消息服务器 id
    uint64_t msg_server_id;
    /// 系统通知类型
    NIMQChatSystemNotificationType msg_type;
} NIMQChatSystemNotificationMarkReadInfo;

/// @enum NIMQChatSystemNotificationStatus
typedef enum {
    /// 普通状态
    kNIMQChatSystemNotificationNormal,
    kNIMQChatSystemNotificationUser = 10000  // 大于10000为用户自定义状态
} NIMQChatSystemNotificationStatus;

/** @struct NIMQChatSystemNotification 圈组系统通知定义 */
typedef struct {
    /// 消息通知目标
    NIMQChatSystemNotificationToType to_type;
    /// 消息所属的server id
    uint64_t server_id;
    /// 消息所属的channel id
    uint64_t channel_id;
    /// 系统通知类型
    NIMQChatSystemNotificationType msg_type;
    /// 消息内容
    char* msg_body;
    /// 消息附件
    char* msg_attach;
    /// 消息扩展字段
    char* msg_ext;
    /// 重发标记，false:不是重发，true:是重发
    fcx_bool_t resend_flag;
    /// 通知接受者账号列表, json array
    char* to_accids;
    /// false 或者 true, 是否存离线，只有 to_accids 不为空，才能设置为存离线，默认 false
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
    /// 环境变量，用户可以根据不同的env配置不同的抄送和回调地址
    char* env;
    // 以下字段仅在收到消息时有效
    /// 消息状态
    NIMQChatSystemNotificationStatus status;
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
    /// 系统通知数据, 根据不同的系统通知类型，数据结构不同
    void* msg_data;
    /// 回调扩展字段
    char* callback_ext;
} NIMQChatSystemNotification;

/** @struct NIMQChatTypingEvent 圈组正在输入事件定义 */
typedef struct {
    /// 事件所属的server id
    uint64_t server_id;
    /// 事件所属的channel id
    uint64_t channel_id;
    /// 事件扩展字段
    char* extension;
    // 以下字段仅在收到事件时有效
    /// 事件发送者的accid
    char* from_accid;
    /// 事件发送者的昵称
    char* from_nick;
    /// 事件发送时间戳
    uint64_t timestamp;
} NIMQChatTypingEvent;

/** @struct NIMQChatSystemNotificationDataServerInvite 系统消息为邀请服务器成员时的数据结构体 */
typedef struct {
    /// 请求ID
    uint64_t request_id;
} NIMQChatSystemNotificationDataServerInvite;

/** @struct NIMQChatSystemNotificationDataServerInviteReject 系统消息为拒绝服务器成员邀请时的数据结构体 */
typedef struct {
    /// 请求ID
    uint64_t request_id;
} NIMQChatSystemNotificationDataServerInviteReject;

/** @struct NIMQChatSystemNotificationDataServerApply 系统消息为申请加入服务器时的数据结构体 */
typedef struct {
    /// 请求ID
    uint64_t request_id;
} NIMQChatSystemNotificationDataServerApply;

/** @struct NIMQChatSystemNotificationDataServerApplyReject 系统消息为拒绝加入服务器申请时的数据结构体 */
typedef struct {
    /// 请求ID
    uint64_t request_id;
} NIMQChatSystemNotificationDataServerApplyReject;

/** @struct NIMQChatSystemNotificationDataServerCreate 系统消息为创建服务器时的数据结构体 */
typedef struct {
    /// 圈组服务器信息
    NIMQChatServerInfo server_info;
} NIMQChatSystemNotificationDataServerCreate;

/** @struct NIMQChatSystemNotificationDataServerUpdate 系统消息为删除服务器时的数据结构体 */
typedef struct {
    /// 圈组服务器信息
    NIMQChatServerInfo server_info;
} NIMQChatSystemNotificationDataServerUpdate;

/** @struct NIMQChatSystemNotificationDataChannelCreate 系统消息为创建频道时的数据结构体 */
typedef struct {
    /// 圈组频道信息
    NIMQChatChannelInfo channel_info;
} NIMQChatSystemNotificationDataChannelCreate;

/** @struct NIMQChatSystemNotificationDataChannelUpdate 系统消息为删除频道时的数据结构体 */
typedef struct {
    /// 圈组频道信息
    NIMQChatChannelInfo channel_info;
} NIMQChatSystemNotificationDataChannelUpdate;

/** @struct NIMQChatSystemNotificationDataMemberInviteDone 系统消息为邀请完成时的数据结构体 */
typedef struct {
    /// 圈组服务器信息
    NIMQChatServerInfo server_info;
    /// 邀请的accid列表 json array
    char* invite_accids;
    /// 请求ID
    uint64_t request_id;
} NIMQChatSystemNotificationDataMemberInviteDone;

/** @struct NIMQchatSystemNotificationDataMemberInviteAccept 系统消息为邀请接受时的数据结构体 */
typedef struct {
    /// 圈组服务器信息
    NIMQChatServerInfo server_info;
    /// 邀请的accid
    char* invite_accid;
    /// 请求ID
    uint64_t request_id;
} NIMQChatSystemNotificationDataMemberInviteAccept;

/** @struct NIMQChatSystemNotificationDataMemberApplyDone 系统消息为申请完成时的数据结构体 */
typedef struct {
    /// 圈组服务器信息
    NIMQChatServerInfo server_info;
    /// 请求ID
    uint64_t request_id;
} NIMQChatSystemNotificationDataMemberApplyDone;

/** @struct NIMQChatSystemNotificationDataMemberApplyAccept 系统消息为申请接受时的数据结构体 */
typedef struct {
    /// 圈组服务器信息
    NIMQChatServerInfo server_info;
    /// 申请的accid
    char* apply_accid;
    /// 请求ID
    uint64_t request_id;
} NIMQChatSystemNotificationDataMemberApplyAccept;

/** @struct NIMQChatSystemNotificationDataMemberKick 系统消息为踢出服务器成员时的数据结构体 */
typedef struct {
    /// 圈组服务器信息
    NIMQChatServerInfo server_info;
    /// 被踢的accid列表 json array
    char* kick_accids;
} NIMQChatSystemNotificationDataMemberKick;

/** @struct NIMQChatSystemNotificationDataMemberLeave 系统消息为服务器成员离开时的数据结构体 */
typedef struct {
    /// 圈组服务器信息
    NIMQChatServerInfo server_info;
} NIMQChatSystemNotificationDataMemberLeave;

/** @struct NIMQChatSystemNotificationDataMemberUpdate 系统消息为服务器成员更新时的数据结构体 */
typedef struct {
    /// 圈组成员信息
    NIMQChatMemberInfo member_info;
} NIMQChatSystemNotificationDataMemberUpdate;

/// @struct NIMQChatSystemNotificationDataWhiteBlackRoleUpdate
typedef struct {
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 身份组id
    uint64_t role_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 操作类型
    NIMQChatChannelWhiteBlackOpeType ope_type;
} NIMQChatSystemNotificationDataWhiteBlackRoleUpdate;

/// @struct NIMQChatSystemNotificationDataWhiteBlackMembersUpdate
typedef struct {
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 被踢人id列表
    char** accids;
    /// 被踢人id列表长度
    size_t accids_count;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 操作类型
    NIMQChatChannelWhiteBlackOpeType ope_type;
} NIMQChatSystemNotificationDataWhiteBlackMembersUpdate;

/// @struct NIMQChatSystemNotificationDataQuickCommentChanged
typedef struct {
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 发送者accid
    char* msg_sender_accid;
    /// 消息id
    uint64_t msg_server_id;
    /// 消息时间戳
    uint64_t msg_timestamp;
    /// 消息类型
    uint64_t type;
    /// 操作类型
    NIMQChatQuickCommentOperation operate_type;
    /// 操作者
    char* operator_accid;
} NIMQChatSystemNotificationDataQuickCommentChanged;

/// @struct NIMQChatSystemNotificationDataChannelCategoryCreate
typedef struct {
    /// 频道分组信息
    NIMQChatChannelCategoryInfo category_info;
} NIMQChatSystemNotificationDataChannelCategoryCreate;

/// @struct NIMQChatSystemNotificationDataChannelCategoryRemove
typedef struct {
    /// 频道分组id
    uint64_t category_id;
} NIMQChatSystemNotificationDataChannelCategoryRemove;

/// @struct NIMQChatSystemNotificationDataChannelCategoryUpdate
typedef NIMQChatSystemNotificationDataChannelCategoryCreate NIMQChatSystemNotificationDataChannelCategoryUpdate;

/// @struct NIMQChatSystemNotificationDataChannelCategoryWhiteBlackRoleUpdate
typedef struct {
    /// 服务器ID
    uint64_t server_id;
    /// 频道分组ID
    uint64_t category_id;
    /// 身份组id
    uint64_t role_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 操作类型
    NIMQChatChannelWhiteBlackOpeType ope_type;
} NIMQChatSystemNotificationDataChannelCategoryWhiteBlackRoleUpdate;

/// @struct NIMQChatSystemNotificationDataChannelCategoryWhiteBlackMembersUpdate
typedef struct {
    /// 服务器ID
    uint64_t server_id;
    /// 频道分组ID
    uint64_t category_id;
    /// 被踢人id列表
    char** accids;
    /// 被踢人id列表长度
    size_t accids_count;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 操作类型
    NIMQChatChannelWhiteBlackOpeType ope_type;
} NIMQChatSystemNotificationDataChannelCategoryWhiteBlackMembersUpdate;

/// @struct NIMQChatSystemNotificationDataServerRoleAddMember
typedef struct {
    /// 服务器id
    uint64_t server_id;
    /// 身份组id
    uint64_t role_id;
    /// accid列表
    char** accids;
    /// accid列表长度
    size_t accids_count;
} NIMQChatSystemNotificationDataServerRoleAddMember;

/// @struct NIMQChatSystemNotificationDataServerRoleRemoveMember
typedef NIMQChatSystemNotificationDataServerRoleAddMember NIMQChatSystemNotificationDataServerRoleRemoveMember;

/// @struct NIMQChatSystemNotificationDataServerRolePermissionChange
typedef struct {
    /// 服务器id
    uint64_t server_id;
    /// 身份组id
    uint64_t role_id;
    /// 变更的权限列表
    NIMQChatPermissionGroup* permissions;
    /// 变更的权限列表长度
    size_t permissions_count;
} NIMQChatSystemNotificationDataServerRolePermissionChange;

/// @struct NIMQChatSystemNotificationDataChannelRolePermissionChange
typedef struct {
    /// 服务器id
    uint64_t server_id;
    /// 频道id
    uint64_t channel_id;
    /// 继承的服务器身份组 ID
    uint64_t parent_role_id;
    /// 身份组id
    uint64_t role_id;
    /// 变更的权限列表
    NIMQChatPermissionGroup* permissions;
    /// 变更的权限列表长度
    size_t permissions_count;
} NIMQChatSystemNotificationDataChannelRolePermissionChange;

/// @struct NIMQChatSystemNotificationDataMemberRolePermissionChange
typedef struct {
    /// 服务器id
    uint64_t server_id;
    /// 频道id
    uint64_t channel_id;
    /// accid
    char* accid;
    /// 变更的权限列表
    NIMQChatPermissionGroup* permissions;
    /// 变更的权限列表长度
    size_t permissions_count;
} NIMQChatSystemNotificationDataMemberRolePermissionChange;

/// @struct NIMQChatSystemNotificationDataChannelVisibilityChange
typedef struct {
    /// 频道可见性
    fcx_bool_t visible;
} NIMQChatSystemNotificationDataChannelVisibilityChange;

/// @struct NIMQChatSystemNotificationDataServerEnterLeave
typedef struct {
    /// 进入/离开
    fcx_bool_t is_enter;
} NIMQChatSystemNotificationDataServerEnterLeave;

/// @struct NIMQChatSystemNotificationDataServerJoinByInviteCode
typedef struct {
    /// 圈组服务器信息
    NIMQChatServerInfo server_info;
    /// 请求id
    uint64_t request_id;
    /// 邀请码
    char* invite_code;
} NIMQChatSystemNotificationDataServerJoinByInviteCode;

/// @struct NIMQChatSystemNotificationDataChannelVisitorVisibilityChange 系统消息为频道游客可见性变更
typedef struct {
    /// 频道游客可见性
    fcx_bool_t visible;
} NIMQChatSystemNotificationDataChannelVisitorVisibilityChange;

/// @struct NIMQChatUpdatedMyMemberInfo
typedef struct {
    /// 服务器id
    uint64_t server_id;
    /// 变更后的昵称
    char* nick;
    /// 变更后的头像
    char* avatar;
} NIMQChatUpdatedMyMemberInfo;

/// @struct NIMQChatSystemNotificationDataMyMemberInfoUpdated
typedef struct {
    /// 当前用户成员信息发生变更的信息列表
    NIMQChatUpdatedMyMemberInfo* updated_infos;
    /// 当前用户成员信息发生变更的信息列表长度
    size_t updated_infos_count;
} NIMQChatSystemNotificationDataMyMemberInfoUpdated;

/// @struct NIMQChatRecvSystemNotificationResp
typedef struct {
    /// 自定义用户数据
    void* user_data;
    /// 系统通知
    NIMQChatSystemNotification notification;
    /// 是否为离线通知
    fcx_bool_t is_leave;
} NIMQChatRecvSystemNotificationResp;

/// @struct NIMQChatSystemNotificationUpdatedResp
typedef struct {
    /// 自定义用户数据
    void* user_data;
    /// 消息更新信息
    NIMQChatMessageUpdateInfo update_info;
    /// 系统通知
    NIMQChatSystemNotification notification;
} NIMQChatSystemNotificationUpdatedResp;

/// @struct NIMQChatSendSystemNotificationResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 系统通知
    NIMQChatSystemNotification notification;
} NIMQChatSendSystemNotificationResp;

/// @struct NIMQChatUpdateSystemNotificationResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 系统通知
    NIMQChatSystemNotification notification;
} NIMQChatUpdateSystemNotificationResp;

/// @struct NIMQChatMarkReadSystemNotificationResp
typedef NIMQChatBaseResp NIMQChatMarkReadSystemNotificationResp;

/// @struct NIMQChatRecvTypingEventResp
typedef struct {
    /// 自定义用户数据
    void* user_data;
    /// 正在输入事件
    NIMQChatTypingEvent typing_event;
} NIMQChatRecvTypingEventResp;

/// @struct NIMQChatSendTypingEventResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 正在输入事件
    NIMQChatTypingEvent typing_event;
} NIMQChatSendTypingEventResp;

/* --------------------------------- 接口回调模板 -----------------------------*/

/// 接收系统通知回调
typedef void (*nim_qchat_recv_notification_cb_func)(const NIMQChatRecvSystemNotificationResp* resp);
/// 消息更新通知回调
typedef void (*nim_qchat_notification_updated_cb_func)(const NIMQChatSystemNotificationUpdatedResp* resp);
/// 发送系统通知回调
typedef void (*nim_qchat_send_notification_cb_func)(const NIMQChatSendSystemNotificationResp* resp);
/// 更新系统通知回调
typedef void (*nim_qchat_update_notification_cb_func)(const NIMQChatUpdateSystemNotificationResp* resp);
/// 标记系统通知消息已读回调
typedef void (*nim_qchat_mark_read_notification_cb_func)(const NIMQChatMarkReadSystemNotificationResp* resp);
/// 接受正在输入事件回调
typedef void (*nim_qchat_recv_typing_event_cb_func)(const NIMQChatRecvTypingEventResp* resp);
/// 发送正在输入事件回调
typedef void (*nim_qchat_send_typing_event_cb_func)(const NIMQChatSendTypingEventResp* resp);

/* --------------------------------- 接口调用参数 ------------------------------- */

/// @struct NIMQChatRegRecvSystemNotificationCbParam
typedef struct {
    /// 接收系统通知异步回调
    nim_qchat_recv_notification_cb_func cb;
    /// 自定义用户数据
    void* user_data;
} NIMQChatRegRecvSystemNotificationCbParam;

/// @struct NIMQChatRegSystemNotificationUpdatedCbParam
typedef struct {
    /// 系统通知更新异步回调
    nim_qchat_notification_updated_cb_func cb;
    /// 自定义用户数据
    void* user_data;
} NIMQChatRegSystemNotificationUpdatedCbParam;

/// @struct NIMQChatSendSystemNotificationParam
typedef struct {
    /// 发送系统通知异步回调
    nim_qchat_send_notification_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 系统通知体
    NIMQChatSystemNotification notification;
} NIMQChatSendSystemNotificationParam;

/// @struct NIMQChatUpdateSystemNotificationParam
typedef struct {
    /// 发送系统通知异步回调
    nim_qchat_update_notification_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 系统通知服务器ID
    uint64_t msg_server_id;
    /// 系统通知类型
    NIMQChatSystemNotificationType msg_type;
    /// 消息状态
    NIMQChatSystemNotificationStatus status;
    /// 消息内容
    char* msg_body;
    /// 消息扩展字段
    char* msg_ext;
    /// 更新信息
    NIMQChatMessageUpdateInfo update_info;
} NIMQChatUpdateSystemNotificationParam;

/// @struct NIMQChatMarkSystemNotificationsReadParam
typedef struct {
    /// 标记消息系统通知消息已读异步回调
    nim_qchat_mark_read_notification_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 标记已读系统通知消息列表长度
    size_t mark_read_infos_count;
    /// 标记已读系统通知消息列表
    NIMQChatSystemNotificationMarkReadInfo* mark_read_infos;
} NIMQChatMarkSystemNotificationsReadParam;

/// @struct NIMQChatRegRecvTypingEventCbParam
typedef struct {
    /// 接收正在输入事件异步回调
    nim_qchat_recv_typing_event_cb_func cb;
    /// 自定义用户数据
    void* user_data;
} NIMQChatRegRecvTypingEventCbParam;

/// @struct NIMQChatSendTypingEventParam
typedef struct {
    /// 发送正在输入事件异步回调
    nim_qchat_send_typing_event_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 正在输入事件
    NIMQChatTypingEvent typing_event;
} NIMQChatSendTypingEventParam;

#ifdef __cplusplus
}
#endif

#endif  // __NIM_QCHAT_SYSTEM_NOTIFICATION_DEF_H__
