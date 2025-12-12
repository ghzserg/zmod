/**
 * @file nim_qchat_role_def.h
 * @author NetEase Yunxin
 * @brief 圈组身份组相关数据结构声明
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_ROLE_DEF_H__
#define __NIM_QCHAT_ROLE_DEF_H__

#include "nim_qchat_member_def.h"
#include "nim_qchat_public_def.h"

/// @enum NIMQChatPermissions
typedef enum {
    /// 管理服务器，Server
    kPermissionManageServer = 1,
    /// 管理频道，Server/Channel
    kPermissionManageChannel,
    /// 管理角色，Server/Channel
    kPermissionManageRole,
    /// 发送消息，Server/Channel
    kPermissionSendMessage,
    /// 修改自己信息，Server
    kPermissionUpdateMyInfo,
    /// 邀请他人，Server
    kPermissionIviteMember,
    /// 踢除他人，Server
    kPermissionKickMember,
    /// 修改他人信息，Server
    kPermissionUpdateMemberInfo,
    /// 撤回他人信息，Server/Channel
    kPermissionRevokeMemberMessage,
    /// 删除他人消息，Server/Channel
    kPermissionDeleteMemberMessage,
    /// @ 他人，Server/Channel
    kPermissionAtMember,
    /// @ 所有人，Server/Channel
    kPermissionAtAll,
    /// 管理白/黑名单，Server/Channel
    kPermissionManageBlackWhiteList,
    /// 封禁他人，Server
    kPermissionBanServerMember,
    /// RTC频道: 连接的权限，Server/Channel
    kPermissionRTCConnect,
    /// RTC频道: 断开他人连接的权限，Server/Channel
    kPermissionRTCDisconnectOther,
    /// RTC频道: 开启自己麦克风的权限，Server/Channel
    kPermissionRTCOpenMic,
    /// RTC频道: 开启自己摄像头的权限，Server/Channel
    kPermissionRTCOpenCamera,
    /// RTC频道: 禁用/解禁他人麦克风的权限，Server/Channel
    kPermissionRTCOpenMuteOthersMic,
    /// RTC频道: 禁用/解禁他人摄像头的权限，Server/Channel
    kPermissionRTCOpenMuteOthersCamera,
    /// RTC频道: 禁用/解禁全员麦克风的权限，Server/Channel
    kPermissionRTCOpenMuteAllMic,
    /// RTC频道: 禁用/解禁全员摄像头的权限，Server/Channel
    kPermissionRTCOpenMuteAllCamera,
    /// RTC频道: 打开自己共享屏幕的权限，Server/Channel
    kPermissionRTCOpenScreenShare,
    /// RTC频道: 关闭他人共享屏幕的权限，Server/Channel
    kPermissionRTCCloseOthersScreenShare,
    /// 服务器申请处理权限，Server
    kPermissionServerHandleApply,
    /// 申请邀请历史查看权限，有这个权限才可以查询server级别的申请/邀请记录，Server
    kPermissionGetServerInviteApplyRecords,
    /// @ 身份组的权限，Server/Channel
    kPermissionMentionRole,
} NIMQChatPermissions;

/// @enum NIMQChatPermissionsOption
typedef enum {
    /// 拒绝
    kPermissionSwitchDeny = -1,
    /// 继承
    kPermissionSwitchExtend,
    /// 允许
    kPermissionSwitchAllow
} NIMQChatPermissionsOption;

/// @struct NIMQChatPermissionGroup
typedef struct {
    /// 权限, 见 NIMQChatPermissions 以及自定义权限
    uint32_t permission;
    /// 开关
    NIMQChatPermissionsOption option;
} NIMQChatPermissionGroup;

/// @enum NIMQChatRoleType
typedef enum {
    /// 未知
    kRoleTypeUnkonwn = 0,
    /// 默认 Everyone 身份组
    kRoleTypeEveryone,
    /// 自定义身份组
    kRoleTypeCustom
} NIMQChatRoleType;

/** @struct NIMQChatRoleMemberInfo 圈组身份组成员信息 */
typedef struct {
    /// member info
    NIMQChatMemberInfo member_info;
    /// 所在身份组role id
    uint64_t role_id;
} NIMQChatRoleMemberInfo;

/// @struct NIMQChatRoleInfo
typedef struct {
    /// 服务器ID
    uint64_t server_id;
    /// 身份组id
    uint64_t role_id;
    /// 身份组名称
    char* role_name;
    /// 身份组图片 URL
    char* role_icon;
    /// 身份组扩展字段
    char* extension;
    /// 身份组权限设定
    NIMQChatPermissionGroup* permissions;
    /// 身份组权限组合数量
    size_t permissions_count;
    /// 身份组类型 1 表示 Everyone，2 表示定制身份组
    NIMQChatRoleType role_type;
    /// 身份组创建时间
    uint64_t create_time;
    /// 身份组修改时间
    uint64_t update_time;
} NIMQChatRoleInfo;

/// @struct NIMQChatServerRoleInfo
typedef struct {
    /// 该身份组的成员数量，Everyone 身份组数量为 -1
    uint32_t member_count;
    /// 身份组优先级，Everyone 最低为 0，数字越大优先级越低
    uint64_t priority;
    NIMQChatRoleInfo role_info;
} NIMQChatServerRoleInfo;

/// @struct NIMQChatChannelRoleInfo
typedef struct {
    /// 频道 ID
    uint64_t channel_id;
    /// 继承的服务器身份组 ID
    uint64_t parent_role_id;

    NIMQChatRoleInfo role_info;
} NIMQChatChannelRoleInfo;

/// @struct NIMQChatChannelCategoryRoleInfo
typedef struct {
    /// 频道分组 ID
    uint64_t category_id;
    /// 继承的服务器身份组 ID
    uint64_t parent_role_id;
    /// 有效标志
    fcx_bool_t valid_flag;

    NIMQChatRoleInfo role_info;
} NIMQChatChannelCategoryRoleInfo;

/// @struct NIMQChatMemberRoleInfo
typedef struct {
    /// 该定制权限所在的频道 ID
    uint64_t channel_id;
    /// 该定制权限所在的身份组 ID
    uint64_t role_id;
    /// 定制权限的用户信息
    NIMQChatMemberInfo member_info;
    /// 身份组权限设定
    NIMQChatPermissionGroup* permissions;
    /// 身份组权限组合数量
    size_t permissions_count;
    /// 身份组创建时间
    uint64_t create_time;
    /// 身份组修改时间
    uint64_t update_time;
} NIMQChatMemberRoleInfo;

/// @struct NIMQChatChannelCategoryMemberRoleInfo
typedef struct {
    /// 该定制权限所在的频道分组 ID
    uint64_t category_id;
    /// 该定制权限所在的身份组 ID
    uint64_t role_id;
    /// 定制权限的用户信息
    NIMQChatMemberInfo member_info;
    /// 身份组权限设定
    NIMQChatPermissionGroup* permissions;
    /// 身份组权限组合数量
    size_t permissions_count;
    /// 身份组创建时间
    uint64_t create_time;
    /// 身份组修改时间
    uint64_t update_time;
} NIMQChatChannelCategoryMemberRoleInfo;

/// @struct NIMQChatCreateServerRoleResp
typedef struct {
    uint32_t res_code;
    void* user_data;
    NIMQChatRoleInfo role_info;
} NIMQChatCreateServerRoleResp;

/// @struct NIMQChatUpdateServerRoleResp
typedef struct {
    uint32_t res_code;
    void* user_data;
    NIMQChatRoleInfo role_info;
} NIMQChatUpdateServerRoleResp;

/// @struct NIMQChatDeleteServerRoleResp
typedef NIMQChatBaseResp NIMQChatDeleteServerRoleResp;

/// @struct NIMQChatGetServerRolesResp
typedef struct {
    uint32_t res_code;
    void* user_data;
    NIMQChatRoleInfo* roles;
    size_t role_count;
    NIMQChatRoleInfo* joined_roles;
    size_t joined_role_count;
} NIMQChatGetServerRolesResp;

/// @struct QChatMemberAccountId
typedef char* QChatMemberAccountId;

/// @struct NIMQChatAddMembersToServerRoleResp
/// @struct NIMQChatAddMembersToServerRoleResp
typedef struct {
    uint32_t res_code;
    void* user_data;
    QChatMemberAccountId* succeed_list;
    size_t succeed_count;
    QChatMemberAccountId* failed_list;
    size_t failed_count;
} NIMQChatAddMembersToServerRoleResp;

/// @struct NIMQChatRemoveMembersFromServerRoleResp
typedef NIMQChatAddMembersToServerRoleResp NIMQChatRemoveMembersFromServerRoleResp;

/// @struct NIMQChatGetMembersFromServerRoleResp
typedef struct {
    uint32_t res_code;
    void* user_data;
    NIMQChatRoleMemberInfo* members;
    size_t member_count;
} NIMQChatGetMembersFromServerRoleResp;

/// @struct NIMQChatAddChannelRoleResp
typedef struct {
    uint32_t res_code;
    void* user_data;
    NIMQChatRoleInfo role_info;
} NIMQChatAddChannelRoleResp;

/// @struct NIMQChatUpdateChannelRoleResp
typedef NIMQChatAddChannelRoleResp NIMQChatUpdateChannelRoleResp;

/// @struct NIMQChatAddChannelCategoryRoleResp
typedef NIMQChatAddChannelRoleResp NIMQChatAddChannelCategoryRoleResp;

/// @struct NIMQChatUpdateChannelCategoryRoleResp
typedef NIMQChatAddChannelRoleResp NIMQChatUpdateChannelCategoryRoleResp;

/// @struct NIMQChatRemoveChannelRoleResp
typedef NIMQChatBaseResp NIMQChatRemoveChannelRoleResp;

/// @struct NIMQChatRemoveChannelCategoryRoleResp
typedef NIMQChatBaseResp NIMQChatRemoveChannelCategoryRoleResp;

/// @struct NIMQChatGetChannelRolesResp
typedef struct {
    uint32_t res_code;
    void* user_data;
    NIMQChatRoleInfo* role_infos;
    size_t role_count;
} NIMQChatGetChannelRolesResp;

/// @struct NIMQChatGetChannelCategoryRolesPageResp
typedef NIMQChatGetChannelRolesResp NIMQChatGetChannelCategoryRolesPageResp;

/// @struct NIMQChatAddMemberRoleResp
typedef struct {
    uint32_t res_code;
    void* user_data;
    NIMQChatMemberRoleInfo role_info;
} NIMQChatAddMemberRoleResp;

/// @struct NIMQChatAddChannelCategoryMemberRoleResp
typedef struct {
    uint32_t res_code;
    void* user_data;
    NIMQChatChannelCategoryMemberRoleInfo role_info;
} NIMQChatAddChannelCategoryMemberRoleResp;

/// @struct NIMQChatUpdateMemberRoleResp
typedef NIMQChatAddMemberRoleResp NIMQChatUpdateMemberRoleResp;

/// @struct NIMQChatUpdateChannelCategoryMemberRoleResp
typedef NIMQChatAddChannelCategoryMemberRoleResp NIMQChatUpdateChannelCategoryMemberRoleResp;

/// @struct NIMQChatRemoveMemberRoleResp
typedef NIMQChatBaseResp NIMQChatRemoveMemberRoleResp;

/// @struct NIMQChatRemoveChannelCategoryMemberRoleResp
typedef NIMQChatBaseResp NIMQChatRemoveChannelCategoryMemberRoleResp;

/// @struct NIMQChatGetMemberRolesResp
typedef struct {
    uint32_t res_code;
    void* user_data;
    NIMQChatMemberRoleInfo* role_infos;
    size_t member_role_count;
} NIMQChatGetMemberRolesResp;

/// @struct NIMQChatGetChannelCategoryMemberRolesPageResp
typedef struct {
    uint32_t res_code;
    void* user_data;
    NIMQChatChannelCategoryMemberRoleInfo* role_infos;
    size_t member_role_count;
} NIMQChatGetChannelCategoryMemberRolesPageResp;

/// @struct NIMQChatGetServerRolesByMembersIdResp
typedef NIMQChatGetServerRolesResp NIMQChatGetServerRolesByMembersIdResp;

/// @struct NIMQChatRoleInfoOfMember
typedef struct {
    char* member_id;
    NIMQChatRoleInfo* roles;
    size_t role_count;
} NIMQChatRoleInfoOfMember;

/// @struct NIMQChatGetServerRolesByMemberIdsResp
typedef struct {
    uint32_t res_code;
    void* user_data;
    NIMQChatRoleInfoOfMember* roles_of_member;
    size_t count;
} NIMQChatGetServerRolesByMemberIdsResp;

/// @struct NIMQChatGetExistingRolesInChannelResp
typedef NIMQChatGetChannelRolesResp NIMQChatGetExistingRolesInChannelResp;

/// @struct NIMQChatUpdateServerRolePrioritiesResp
typedef NIMQChatGetServerRolesResp NIMQChatUpdateServerRolePrioritiesResp;

/// @struct NIMQChatGetExistingAccidsOfMemberRolesResp
typedef struct {
    uint32_t res_code;
    void* user_data;
    QChatMemberAccountId* member_ids;
    size_t member_ids_count;
} NIMQChatGetExistingAccidsOfMemberRolesResp;

/// @struct NIMQChatCheckPermissionResp
typedef struct {
    uint32_t res_code;
    void* user_data;
    fcx_bool_t has_permission;
} NIMQChatCheckPermissionResp;

/// @struct NIMQChatCheckPermissionsResp
typedef struct {
    uint32_t res_code;
    void* user_data;
    /// 身份组权限组合数量
    size_t permissions_count;
    /// 身份组权限类型
    uint32_t* permissions;
    /// 身份组权限开关
    NIMQChatPermissionsOption* options;
} NIMQChatCheckPermissionsResp;

/// @struct NIMQChatGetExistingAccidsInServerRoleResp
typedef NIMQChatGetExistingAccidsOfMemberRolesResp NIMQChatGetExistingAccidsInServerRoleResp;

/// 创建服务器身份组回调
typedef void (*nim_qchat_role_server_create_cb_func)(const NIMQChatCreateServerRoleResp* resp);
/// 更新服务器身份组回调
typedef void (*nim_qchat_role_server_update_cb_func)(const NIMQChatUpdateServerRoleResp* resp);
/// 批量服务器身份组权限回调
typedef void (*nim_qchat_role_server_batch_update_priorities_cb_func)(
    const NIMQChatUpdateServerRolePrioritiesResp* resp);
/// 删除服务器身份组回调
typedef void (*nim_qchat_role_server_delete_cb_func)(const NIMQChatDeleteServerRoleResp* resp);
/// 查询服务器身份组回调
typedef void (*nim_qchat_role_server_get_list_cb_func)(const NIMQChatGetServerRolesResp* resp);
/// 服务器身份组添加成员回调
typedef void (*nim_qchat_role_server_add_member_cb_func)(const NIMQChatAddMembersToServerRoleResp* resp);
/// 服务器身份组删除成员回调
typedef void (*nim_qchat_role_server_remove_members_cb_func)(const NIMQChatRemoveMembersFromServerRoleResp* resp);
/// 服务器身份组查询成员回调
typedef void (*nim_qchat_role_server_get_members_cb_func)(const NIMQChatGetMembersFromServerRoleResp* resp);
/// 创建频道身份组回调
typedef void (*nim_qchat_role_channel_add_cb_func)(const NIMQChatAddChannelRoleResp* resp);
/// 更新频道身份组回调
typedef void (*nim_qchat_role_channel_update_cb_func)(const NIMQChatUpdateChannelRoleResp* resp);
/// 删除频道身份组回调
typedef void (*nim_qchat_role_channel_remove_cb_func)(const NIMQChatRemoveChannelRoleResp* resp);
/// 查询频道身份组回调
typedef void (*nim_qchat_role_channel_get_list_cb_func)(const NIMQChatGetChannelRolesResp* resp);
/// 创建频道个人定制权限回调
typedef void (*nim_qchat_role_member_add_cb_func)(const NIMQChatAddMemberRoleResp* resp);
/// 更新频道个人定制权限回调
typedef void (*nim_qchat_role_member_update_cb_func)(const NIMQChatUpdateMemberRoleResp* resp);
/// 删除频道个人定制权限回调
typedef void (*nim_qchat_role_member_remove_cb_func)(const NIMQChatRemoveMemberRoleResp* resp);
/// 查询频道个人定制权限回调
typedef void (*nim_qchat_role_member_get_list_cb_func)(const NIMQChatGetMemberRolesResp* resp);
/// 根据ACCID查询服务器身份组回调
typedef void (*nim_qchat_role_member_roles_cb_func)(const NIMQChatGetServerRolesByMembersIdResp* resp);
/// 查询一批查询一批accids的服务器的自定义身份组列表首页
typedef void (*nim_qchat_role_member_get_roles_by_ids_cb_func)(const NIMQChatGetServerRolesByMemberIdsResp* resp);
/// 查询一批服务器身份组在频道中的身份组信息，只会返回存在的
typedef void (*nim_qchat_role_get_existing_roles_in_channel_cb_func)(const NIMQChatGetExistingRolesInChannelResp* resp);
/// 查询一批accids在频道中配置的权限，只会返回存在的
typedef void (*nim_qhcat_role_get_existing_accids_of_member_roles_cb_func)(
    const NIMQChatGetExistingAccidsOfMemberRolesResp* resp);
/// 查询一批accids是否在某个服务器身份组，返回在的成员信息
typedef void (*nim_qchat_role_get_accids_in_server_role_cb_func)(const NIMQChatGetExistingAccidsInServerRoleResp* resp);
/// 查询自己是否拥有某个权限
typedef void (*nim_qchat_role_check_permission_cb_func)(const NIMQChatCheckPermissionResp* resp);
/// 批量查询自己的权限
typedef void (*nim_qchat_role_check_permissions_cb_func)(const NIMQChatCheckPermissionsResp* resp);
/// 创建频道分组身份组回调
typedef void (*nim_qchat_role_channel_category_add_cb_func)(const NIMQChatAddChannelCategoryRoleResp* resp);
/// 更新频道分组身份组回调
typedef void (*nim_qchat_role_channel_category_update_cb_func)(const NIMQChatUpdateChannelCategoryRoleResp* resp);
/// 删除频道分组身份组回调
typedef void (*nim_qchat_role_channel_category_remove_cb_func)(const NIMQChatRemoveChannelCategoryRoleResp* resp);
/// 查询频道分组身份组回调
typedef void (*nim_qchat_role_channel_category_get_list_page_cb_func)(
    const NIMQChatGetChannelCategoryRolesPageResp* resp);
/// 创建频道分组个人定制权限回调
typedef void (*nim_qchat_role_channel_category_member_role_add_cb_func)(
    const NIMQChatAddChannelCategoryMemberRoleResp* resp);
/// 更新频道分组个人定制权限回调
typedef void (*nim_qchat_role_channel_category_member_role_update_cb_func)(
    const NIMQChatUpdateChannelCategoryMemberRoleResp* resp);
/// 删除频道分组个人定制权限回调
typedef void (*nim_qchat_role_channel_category_member_role_remove_cb_func)(
    const NIMQChatRemoveChannelCategoryMemberRoleResp* resp);
/// 查询频道分组个人定制权限回调
typedef void (*nim_qchat_role_channel_category_member_role_get_list_page_cb_func)(
    const NIMQChatGetChannelCategoryMemberRolesPageResp* resp);

/// @struct NIMQChatCreateServerRoleParam
typedef struct {
    nim_qchat_role_server_create_cb_func cb;
    void* user_data;
    /// 服务器身份组信息结构体
    NIMQChatRoleInfo role_info;
    /// 反垃圾信息
    NIMQChatBusinessAntiSpamInfo anti_spam_info;
} NIMQChatCreateServerRoleParam;

/// @struct NIMQChatUpdateServerRoleParam
/// @struct NIMQChatUpdateServerRoleParam
typedef struct {
    nim_qchat_role_server_update_cb_func cb;
    void* user_data;
    /// 服务器身份组信息结构体
    NIMQChatRoleInfo role_info;
    /// 反垃圾信息
    NIMQChatBusinessAntiSpamInfo anti_spam_info;
} NIMQChatUpdateServerRoleParam;

/// @struct NIMQChatBatchUpdateServeRolePriorityGroup
typedef struct {
    uint64_t role_id;
    uint64_t priority;
} NIMQChatBatchUpdateServeRolePriorityGroup;

/// @struct NIMQChatBatchUpdateServerRolePrioritiesParam
typedef struct {
    nim_qchat_role_server_batch_update_priorities_cb_func cb;
    void* user_data;
    uint64_t server_id;
    /// 要更新的身份组 ID 及优先级组合
    NIMQChatBatchUpdateServeRolePriorityGroup* update_priority_info;
    size_t update_count;
} NIMQChatBatchUpdateServerRolePrioritiesParam;

/// @struct NIMQChatDeleteServerRoleParam
typedef struct {
    nim_qchat_role_server_delete_cb_func cb;
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 身份组 ID
    uint64_t role_id;
} NIMQChatDeleteServerRoleParam;

/// @struct NIMQChatGetServerRolesParam
typedef struct {
    nim_qchat_role_server_get_list_cb_func cb;
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 限制返回数量
    uint32_t limit;
    /// 起查的身份组优先级
    uint64_t priority;
    /// 频道 ID, 如果非空，则只需要有该channel的管理权限即可，否则需要有server的管理权限
    uint64_t channel_id;
    /// 频道分组 ID, 如果非空，则只需要有该channel_category的管理权限即可，否则需要有server的管理权限
    uint64_t channel_category_id;
} NIMQChatGetServerRolesParam;

/// @struct NIMQChatAddMembersToServerRoleParam
typedef struct {
    nim_qchat_role_server_add_member_cb_func cb;
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 身份组 ID
    uint64_t role_id;
    /// 用户数据指针首地址
    char** members;
    /// 要加入的用户数量
    size_t member_count;
} NIMQChatAddMembersToServerRoleParam;

/// @struct NIMQChatRemoveMembersFromServerRoleParam
typedef NIMQChatAddMembersToServerRoleParam NIMQChatRemoveMembersFromServerRoleParam;

/// @struct NIMQChatGetMembersFromServerRoleParam
typedef struct {
    nim_qchat_role_server_get_members_cb_func cb;
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 身份组 ID
    uint64_t role_id;
    /// 时间戳，从最新起查使用 0
    uint64_t timestamp;
    /// 限制返回数量
    uint32_t limit;
    /// 起查 account ID
    char* begin_accid;
} NIMQChatGetMembersFromServerRoleParam;

/// @struct NIMQChatAddChannelRoleParam
typedef struct {
    nim_qchat_role_channel_add_cb_func cb;
    void* user_data;
    uint64_t server_id;
    uint64_t parent_role_id;
    uint64_t channel_id;
} NIMQChatAddChannelRoleParam;

/// @struct NIMQChatUpdateChannelRoleParam
typedef struct {
    nim_qchat_role_channel_update_cb_func cb;
    void* user_data;
    uint64_t server_id;
    uint64_t role_id;
    uint64_t channel_id;
    NIMQChatPermissionGroup* permissions;
    size_t permission_count;
} NIMQChatUpdateChannelRoleParam;

/// @struct NIMQChatRemoveChannelRoleParam
typedef struct {
    nim_qchat_role_channel_remove_cb_func cb;
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道 ID
    uint64_t channel_id;
    /// 身份组 ID
    uint64_t role_id;
} NIMQChatRemoveChannelRoleParam;

/// @struct NIMQChatGetChannelRolesParam
typedef struct {
    nim_qchat_role_channel_get_list_cb_func cb;
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道 ID
    uint64_t channel_id;
    /// 时间戳，查询最新指定为 0
    uint64_t timestamp;
    /// 限制查询返回数量
    uint32_t limit;
} NIMQChatGetChannelRolesParam;

/// @struct NIMQChatAddMemberRoleParam
typedef struct {
    nim_qchat_role_member_add_cb_func cb;
    void* user_data;
    uint64_t server_id;
    uint64_t channel_id;
    char* accid;
} NIMQChatAddMemberRoleParam;

/// @struct NIMQChatUpdateMemberRoleParam
typedef struct {
    nim_qchat_role_member_update_cb_func cb;
    void* user_data;
    uint64_t server_id;
    uint64_t channel_id;
    char* accid;
    NIMQChatPermissionGroup* permissions;
    size_t permission_count;
} NIMQChatUpdateMemberRoleParam;

/// @struct NIMQChatRemoveMemberRoleParam
typedef struct {
    nim_qchat_role_member_remove_cb_func cb;
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 身份组 ID
    uint64_t channel_id;
    /// 用户账号
    char* accid;
} NIMQChatRemoveMemberRoleParam;

/// @struct NIMQChatGetMemberRolesParam
typedef struct {
    nim_qchat_role_member_get_list_cb_func cb;
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道 ID
    uint64_t channel_id;
    /// 时间戳，查询最新指定为 0
    uint64_t timestamp;
    /// 限制返回数量
    uint32_t limit;
} NIMQChatGetMemberRolesParam;

/// @struct NIMQChatGetServerRolesByMembersIdParam
typedef struct {
    nim_qchat_role_member_roles_cb_func cb;
    void* user_data;
    uint64_t server_id;
    char* accid;
    uint64_t timestamp;
    uint32_t limit;
} NIMQChatGetServerRolesByMembersIdParam;

/// @enum NIMQChatSortType 身份组排序类型
typedef enum {
    /// 按创建时间排序
    kNIMQChatSortByCreateTime = 1,
    /// 按优先级排序
    kNIMQChatSortByPriority,
} NIMQChatSortType;

/// @struct NIMQChatGetServerRolesByMemberIdsParam
typedef struct {
    nim_qchat_role_member_get_roles_by_ids_cb_func cb;
    void* user_data;
    uint64_t server_id;
    QChatMemberAccountId* accids;
    size_t account_count;
    NIMQChatSortType sort_type;
    NIMQChatSearchOrder search_order;
} NIMQChatGetServerRolesByMemberIdsParam;

/// @struct NIMQChatGetExistingRolesInChannelParam
typedef struct {
    nim_qchat_role_get_existing_roles_in_channel_cb_func cb;
    void* user_data;
    uint64_t server_id;
    uint64_t channel_id;
    uint64_t* role_ids;
    size_t role_count;
} NIMQChatGetExistingRolesInChannelParam;

/// @struct NIMQChatGetExistingAccidsOfMemberRolesParam
typedef struct {
    nim_qhcat_role_get_existing_accids_of_member_roles_cb_func cb;
    void* user_data;
    uint64_t server_id;
    uint64_t channel_id;
    QChatMemberAccountId* accids;
    size_t account_count;
} NIMQChatGetExistingAccidsOfMemberRolesParam;

/// @struct NIMQChatGetExistingAccidsInServerRoleParam
typedef struct {
    nim_qchat_role_get_accids_in_server_role_cb_func cb;
    void* user_data;
    uint64_t server_id;
    uint64_t role_id;
    char** accids;
    size_t account_count;
} NIMQChatGetExistingAccidsInServerRoleParam;

/// @struct NIMQChatCheckPermissionParam
typedef struct {
    nim_qchat_role_check_permission_cb_func cb;
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// channel_id == 0 means check permission in server
    uint64_t channel_id;
    /// 权限
    uint32_t permission;
} NIMQChatCheckPermissionParam;

/// @struct NIMQChatCheckPermissionsParam
typedef struct {
    nim_qchat_role_check_permissions_cb_func cb;
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// channel_id == 0 means check permission in server
    uint64_t channel_id;
    /// 权限列表长度
    size_t permission_count;
    /// 权限列表
    uint32_t* permissions;
} NIMQChatCheckPermissionsParam;

/// @struct NIMQChatAddChannelCategoryRoleParam
typedef struct {
    nim_qchat_role_channel_category_add_cb_func cb;
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道分组 ID
    uint64_t category_id;
    /// 服务器身份组ID
    uint64_t parent_role_id;
} NIMQChatAddChannelCategoryRoleParam;

/// @struct NIMQChatUpdateChannelCategoryRoleParam
typedef struct {
    nim_qchat_role_channel_category_update_cb_func cb;
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道分组 ID
    uint64_t category_id;
    /// 身份组 ID
    uint64_t role_id;
    /// 身份组权限设定
    NIMQChatPermissionGroup* permissions;
    /// 权限设定数量
    size_t permission_count;
} NIMQChatUpdateChannelCategoryRoleParam;

/// @struct NIMQChatRemoveChannelCategoryRoleParam
typedef struct {
    nim_qchat_role_channel_category_remove_cb_func cb;
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道分组 ID
    uint64_t category_id;
    /// 身份组 ID
    uint64_t role_id;
} NIMQChatRemoveChannelCategoryRoleParam;

/// @struct NIMQChatGetChannelCategoryRolesPageParam
typedef struct {
    nim_qchat_role_channel_category_get_list_page_cb_func cb;
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道分组 ID
    uint64_t category_id;
    /// 时间戳，查询最新指定为 0
    uint64_t timestamp;
    /// 限制查询返回数量
    uint32_t limit;
} NIMQChatGetChannelCategoryRolesPageParam;

/// @struct NIMQChatAddChannelCategoryMemberRoleParam
typedef struct {
    nim_qchat_role_channel_category_member_role_add_cb_func cb;
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道分组 ID
    uint64_t category_id;
    /// 用户 ID
    char* accid;
} NIMQChatAddChannelCategoryMemberRoleParam;

/// @struct NIMQChatUpdateChannelCategoryMemberRoleParam
typedef struct {
    nim_qchat_role_channel_category_member_role_update_cb_func cb;
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道分组 ID
    uint64_t category_id;
    /// 用户 ID
    char* accid;
    /// 身份组权限设定
    NIMQChatPermissionGroup* permissions;
    /// 权限设定数量
    size_t permission_count;
} NIMQChatUpdateChannelCategoryMemberRoleParam;

/// @struct NIMQChatRemoveChannelCategoryMemberRoleParam
typedef struct {
    nim_qchat_role_channel_category_member_role_remove_cb_func cb;
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道分组 ID
    uint64_t category_id;
    /// 用户账号
    char* accid;
} NIMQChatRemoveChannelCategoryMemberRoleParam;

/// @struct NIMQChatGetChannelCategoryMemberRolesPageParam
typedef struct {
    nim_qchat_role_channel_category_member_role_get_list_page_cb_func cb;
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道分组 ID
    uint64_t category_id;
    /// 时间戳，查询最新指定为 0
    uint64_t timestamp;
    /// 限制返回数量
    uint32_t limit;
} NIMQChatGetChannelCategoryMemberRolesPageParam;

#endif  // __NIM_QCHAT_ROLE_DEF_H__
