/**
 * @file nim_qchat_channel_def.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_CHANNEL_DEF_H__
#define __NIM_QCHAT_CHANNEL_DEF_H__

#include "nim_qchat_member_def.h"
#include "nim_qchat_public_def.h"
#include "nim_qchat_role_def.h"
#include "nim_qchat_server_def.h"

#ifdef __cplusplus
extern "C" {
#endif

/// @enum NIMQChatChannelType 圈组频道类型
typedef enum {
    /// 普通文本频道
    kNIMQChatChannelTypeText,
    /// RTC频道
    kNIMQChatChannelTypeRTC,
    /// 自定义频道类型
    kNIMQChatChannelTypeCustom = 100
} NIMQChatChannelType;

/// @enum NIMQChatChannelMemberIdentifyType
typedef enum {
    kNIMQChatWhite = 1,
    kNIMQChatBlack = 2,
} NIMQChatChannelMemberIdentifyType;

/// @enum NIMQChatChannelMemberIdentifyOpeType
typedef enum {
    kNIMQChatChannelMemberIdentifyOpeTypeAdd = 1,
    kNIMQChatChannelMemberIdentifyOpeTypeRemove = 2,
} NIMQChatChannelMemberIdentifyOpeType;

/// @enum NIMQChatChannelWhiteBlackType
typedef enum {
    kNIMQChatChannelWhite = 1,
    kNIMQChatChannelBlack = 2,
} NIMQChatChannelWhiteBlackType;

/// @enum NIMQChatChannelWhiteBlackOpeType
typedef enum {
    kNIMQChatChannelWhiteBlackOpeTypeAdd = 1,
    kNIMQChatChannelWhiteBlackOpeTypeRemove = 2,
} NIMQChatChannelWhiteBlackOpeType;

/// @struct NIMQChatChannelInfo 圈组频道信息
typedef struct {
    /// server id
    uint64_t server_id;
    /// channel id
    uint64_t channel_id;
    /// 名称
    char* name;
    /// 主题
    char* topic;
    /// 自定义字段
    char* custom;
    /// 频道类型
    NIMQChatChannelType type;
    /// 拥有者
    char* owner;
    /// 查看模式，只有在category_id为0或sync_mode为kNIMQChatChannelSyncModeNoSync时有效
    NIMQChatChannelViewMode view_mode;
    /// 游客访问模式
    NIMQChatChannelVisitorMode visitor_mode;
    /// 有效标记，false:无效 true:有效
    fcx_bool_t valid_flag;
    /// 创建时间
    uint64_t create_time;
    /// 更新时间
    uint64_t update_time;
    /// 频道分组ID
    uint64_t category_id;
    /// 频道分组同步模式
    NIMQChatChannelSyncMode sync_mode;
    /// 自定义排序权重值
    uint64_t reorder_weight;
} NIMQChatChannelInfo;

/// @struct NIMQChatChannelRTCAudioInfo 圈组RTC频道音频信息
typedef struct {
    /// 音频属性
    char* profile;
    /// 音频应用场景
    char* scenario;
} NIMQChatChannelRTCAudioInfo;

/// @struct NIMQChatChannelRTCVideoInfo 圈组RTC频道视频信息
typedef struct {
    /// 分辨率宽
    uint32_t width;
    /// 分辨率高
    uint32_t height;
    /// 帧率
    uint32_t fps;
} NIMQChatChannelRTCVideoInfo;

/// @struct NIMQChatChannelRTCInfo 圈组频道RTC信息
typedef struct {
    /// 在线人数限制
    uint32_t limit;
    /// 音频配置
    NIMQChatChannelRTCAudioInfo audio;
    /// 视频配置
    NIMQChatChannelRTCVideoInfo video;
} NIMQChatChannelRTCInfo;

/// @struct NIMQChatChannelCategoryInfo
typedef struct {
    /// 服务器ID
    uint64_t server_id;
    /// 分组ID
    uint64_t category_id;
    /// 名称
    char* name;
    /// 自定义字段
    char* custom;
    /// 拥有者
    char* owner;
    /// 查看模式
    NIMQChatChannelViewMode view_mode;
    /// 有效标记，false:无效 true:有效
    fcx_bool_t valid_flag;
    /// 创建时间
    uint64_t create_time;
    /// 更新时间
    uint64_t update_time;
    /// 频道数量
    uint32_t channel_number;
} NIMQChatChannelCategoryInfo;

/// @struct NIMQChatChannelCreateResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 频道信息
    NIMQChatChannelInfo channel_info;
} NIMQChatChannelCreateResp;

/// @struct NIMQChatChannelUpdateResp
typedef NIMQChatChannelCreateResp NIMQChatChannelUpdateResp;

/// @struct NIMQChatChannelUpdateCategoryInfoResp
typedef NIMQChatChannelCreateResp NIMQChatChannelUpdateCategoryInfoResp;

/// @struct NIMQChatChannelDeleteResp
typedef NIMQChatBaseResp NIMQChatChannelDeleteResp;

/// @struct NIMQChatChannelGetChannelsResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 频道列表数量
    size_t channel_list_count;
    /// 频道列表
    NIMQChatChannelInfo* channel_list;
} NIMQChatChannelGetChannelsResp;

/// @struct NIMQChatChannelGetChannelsPageResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 分页信息
    NIMQChatPageInfo page_info;
    /// 频道列表数量
    size_t channel_list_count;
    /// 频道列表
    NIMQChatChannelInfo* channel_list;
} NIMQChatChannelGetChannelsPageResp;

/// @struct NIMQChatChannelGetMembersPageResp
typedef NIMQChatServerGetMembersPageResp NIMQChatChannelGetMembersPageResp;

/// @struct NIMQChatChannelQueryUnreadInfoResp
typedef struct {
    NIMQChatUnreadInfo* unread_infos;
    size_t unread_info_count;
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
} NIMQChatChannelQueryUnreadInfoResp;

/// @struct NIMQChatChannelSubscribeResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 失败列表
    NIMQChatChannelIDInfo* failed_channels;
    /// 失败列表数量
    size_t failed_channels_count;
    /// 频道未读信息, 内部使用，未读相关变更关注RegUnreadCb回调
    NIMQChatUnreadInfo* unread_infos;
    /// 频道未读信息数量
    size_t unread_infos_count;
} NIMQChatChannelSubscribeResp;

/// @struct NIMQChatChannelUnreadResp
typedef struct {
    /// 自定义用户数据
    void* user_data;
    /// 未读数信息数量
    size_t unread_infos_count;
    /// 未读数信息
    NIMQChatUnreadInfo* unread_infos;
} NIMQChatChannelUnreadResp;

/// @struct NIMQChatChannelUpdateWhiteBlackRoleResp
typedef NIMQChatBaseResp NIMQChatChannelUpdateWhiteBlackRoleResp;

/// @struct NIMQChatChannelUpdateWhiteBlackMembersResp
typedef NIMQChatBaseResp NIMQChatChannelUpdateWhiteBlackMembersResp;

/// @struct NIMQChatChannelGetWhiteBlackRolesPageResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 分页信息
    NIMQChatPageInfo page_info;
    /// 身份组列表
    NIMQChatRoleInfo* roles;
    /// 身份组数量
    size_t role_count;
} NIMQChatChannelGetWhiteBlackRolesPageResp;

/// @struct NIMQChatChannelGetWhiteBlackMembersPageResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 分页信息
    NIMQChatPageInfo page_info;
    /// 成员列表
    NIMQChatMemberInfo* members;
    /// 成员数量
    size_t member_count;
} NIMQChatChannelGetWhiteBlackMembersPageResp;

/// @struct NIMQChatChannelGetExistingWhiteBlackRolesResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 身份组列表
    NIMQChatRoleInfo* roles;
    /// 身份组数量
    size_t role_count;
} NIMQChatChannelGetExistingWhiteBlackRolesResp;

/// @struct NIMQChatChannelGetExistingWhiteBlackMembersResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 成员列表
    NIMQChatMemberInfo* members;
    /// 成员数量
    size_t member_count;
} NIMQChatChannelGetExistingWhiteBlackMembersResp;

/// @struct NIMQChatChannelSearchPageResp
typedef NIMQChatChannelGetChannelsPageResp NIMQChatChannelSearchPageResp;

/// @struct NIMQChatChannelMemberSearchResp
typedef struct {
    /// 操作结果, 参考 NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 成员信息列表数量
    size_t member_list_count;
    /// 成员信息列表
    NIMQChatMemberInfo* member_list;
} NIMQChatChannelMemberSearchResp;

/// @struct NIMQChatChannelCategoryCreateResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 频道分组信息
    NIMQChatChannelCategoryInfo category_info;
} NIMQChatChannelCategoryCreateResp;

/// @struct NIMQChatChannelCategoryRemoveResp
typedef NIMQChatBaseResp NIMQChatChannelCategoryRemoveResp;

/// @struct NIMQChatChannelCategoryUpdateResp
typedef NIMQChatChannelCategoryCreateResp NIMQChatChannelCategoryUpdateResp;

/// @struct NIMQChatChannelGetCategoriesByIDResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 分组列表
    NIMQChatChannelCategoryInfo* categories;
    /// 分组数量
    size_t category_count;
} NIMQChatChannelGetCategoriesByIDResp;

/// @struct NIMQChatChannelGetCategoriesPageResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 分页信息
    NIMQChatPageInfo page_info;
    /// 分组列表
    NIMQChatChannelCategoryInfo* categories;
    /// 分组数量
    size_t category_count;
} NIMQChatChannelGetCategoriesPageResp;

/// @struct NIMQChatChannelGetCategoryChannelsResp
typedef NIMQChatChannelGetChannelsPageResp NIMQChatChannelGetCategoryChannelsPageResp;

/// @struct NIMQChatChannelCategoryUpdateWhiteBlackRoleResp
typedef NIMQChatBaseResp NIMQChatChannelCategoryUpdateWhiteBlackRoleResp;

/// @struct NIMQChatChannelCategoryGetWhiteBlackRolesPageResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 分页信息
    NIMQChatPageInfo page_info;
    /// 身份组列表
    NIMQChatRoleInfo* roles;
    /// 身份组数量
    size_t role_count;
} NIMQChatChannelCategoryGetWhiteBlackRolesPageResp;

/// @struct NIMQChatChannelCategoryGetExistingWhiteBlackRolesResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 身份组列表
    NIMQChatRoleInfo* roles;
    /// 身份组数量
    size_t role_count;
} NIMQChatChannelCategoryGetExistingWhiteBlackRolesResp;

/// @struct NIMQChatChannelCategoryUpdateWhiteBlackMembersResp
typedef NIMQChatBaseResp NIMQChatChannelCategoryUpdateWhiteBlackMembersResp;

/// @struct NIMQChatChannelCategoryGetWhiteBlackMembersPageResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 分页信息
    NIMQChatPageInfo page_info;
    /// 成员列表
    NIMQChatMemberInfo* members;
    /// 成员数量
    size_t member_count;
} NIMQChatChannelCategoryGetWhiteBlackMembersPageResp;

/// @struct NIMQChatChannelCategoryGetWhiteBlackMembersResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 成员列表
    NIMQChatMemberInfo* members;
    /// 成员数量
    size_t member_count;
} NIMQChatChannelCategoryGetWhiteBlackMembersResp;

/// @struct NIMQChatChannelUpdateRTCInfoResp
typedef NIMQChatBaseResp NIMQChatChannelUpdateRTCInfoResp;

/// @struct NIMQChatChannelGetRTCInfoResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// RTC信息
    NIMQChatChannelRTCInfo rtc_info;
} NIMQChatChannelGetRTCInfoResp;

/// @struct NIMQChatChannelGetRTCOnlineMembersResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 成员列表
    NIMQChatMemberInfo* members;
    /// 成员数量
    size_t member_count;
} NIMQChatChannelGetRTCOnlineMembersResp;

/// @struct NIMQChatChannelSubscribeAsVisitorResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 失败列表
    NIMQChatChannelIDInfo* failed_channels;
    /// 失败列表数量
    size_t failed_channels_count;
} NIMQChatChannelSubscribeAsVisitorResp;

/* ------------------------------- 接口回调模板 -------------------------------- */
/// 未读数回调
typedef void (*nim_qchat_channel_unread_cb_func)(const NIMQChatChannelUnreadResp* resp);
/// 创建频道回调
typedef void (*nim_qchat_channel_create_cb_func)(const NIMQChatChannelCreateResp* resp);
/// 删除频道回调
typedef void (*nim_qchat_channel_remove_cb_func)(const NIMQChatChannelDeleteResp* resp);
/// 更新频道回调
typedef void (*nim_qchat_channel_update_cb_func)(const NIMQChatChannelUpdateResp* resp);
/// 更新频道的分组信息回调
typedef void (*nim_qchat_channel_update_category_info_cb_func)(const NIMQChatChannelUpdateCategoryInfoResp* resp);
/// 查询频道列表回调
typedef void (*nim_qchat_channel_get_channels_cb_func)(const NIMQChatChannelGetChannelsResp* resp);
/// 分页查询频道列表回调
typedef void (*nim_qchat_channel_get_channels_page_cb_func)(const NIMQChatChannelGetChannelsPageResp* resp);
/// 分页查询成员列表回调
typedef void (*nim_qchat_channel_get_members_page_cb_func)(const NIMQChatChannelGetMembersPageResp* resp);
/// 查询未读消息数回调
typedef void (*nim_qchat_channel_query_unread_info_cb_func)(const NIMQChatChannelQueryUnreadInfoResp* resp);
/// 订阅回调
typedef void (*nim_qchat_channel_subscribe_cb_func)(const NIMQChatChannelSubscribeResp* resp);
/// 更新白/黑名单身份组回调
typedef void (*nim_qchat_channel_update_white_black_role_cb_func)(const NIMQChatChannelUpdateWhiteBlackRoleResp* resp);
/// 更新白/黑名单成员回调
typedef void (*nim_qchat_channel_update_white_black_members_cb_func)(
    const NIMQChatChannelUpdateWhiteBlackMembersResp* resp);
/// 分页查询白/黑名单身份组回调
typedef void (*nim_qchat_channel_get_white_black_roles_page_cb_func)(
    const NIMQChatChannelGetWhiteBlackRolesPageResp* resp);
/// 分页查询白/黑名单成员回调
typedef void (*nim_qchat_channel_get_white_black_members_page_cb_func)(
    const NIMQChatChannelGetWhiteBlackMembersPageResp* resp);
/// 查询已存在白/黑名单身份组回调
typedef void (*nim_qchat_channel_get_existing_white_black_roles_cb_func)(
    const NIMQChatChannelGetExistingWhiteBlackRolesResp* resp);
/// 查询已存在白/黑名单成员回调
typedef void (*nim_qchat_channel_get_existing_white_black_members_cb_func)(
    const NIMQChatChannelGetExistingWhiteBlackMembersResp* resp);
/// 搜索频道分页回调
typedef nim_qchat_channel_get_channels_page_cb_func nim_qchat_channel_search_page_cb_func;
/// 搜索频道成员回调
typedef void (*nim_qchat_channel_member_search_cb_func)(const NIMQChatChannelMemberSearchResp* resp);
/// 创建频道分组回调
typedef void (*nim_qchat_channel_create_category_cb_func)(const NIMQChatChannelCategoryCreateResp* resp);
/// 删除频道分组回调
typedef void (*nim_qchat_channel_remove_category_cb_func)(const NIMQChatChannelCategoryRemoveResp* resp);
/// 更新频道分组回调
typedef void (*nim_qchat_channel_update_category_cb_func)(const NIMQChatChannelCategoryUpdateResp* resp);
/// 根据ID查询频道分组列表回调
typedef void (*nim_qchat_channel_get_categories_cb_func)(const NIMQChatChannelGetCategoriesByIDResp* resp);
/// 分页查询频道分组列表回调
typedef void (*nim_qchat_channel_get_categories_page_cb_func)(const NIMQChatChannelGetCategoriesPageResp* resp);
/// 分页查询频道分组中的频道
typedef void (*nim_qchat_channel_get_category_channels_page_cb_func)(
    const NIMQChatChannelGetCategoryChannelsPageResp* resp);
/// 更新频道分组白/黑名单身份组回调
typedef void (*nim_qchat_channel_update_category_white_black_role_cb_func)(
    const NIMQChatChannelCategoryUpdateWhiteBlackRoleResp* resp);
/// 分页查询频道分组白/黑名单身份组回调
typedef void (*nim_qchat_channel_get_category_white_black_roles_page_cb_func)(
    const NIMQChatChannelCategoryGetWhiteBlackRolesPageResp* resp);
/// 更新频道分组白/黑名单成员回调
typedef void (*nim_qchat_channel_update_category_white_black_members_cb_func)(
    const NIMQChatChannelCategoryUpdateWhiteBlackMembersResp* resp);
/// 分页查询频道分组白/黑名单成员回调
typedef void (*nim_qchat_channel_get_category_white_black_members_page_cb_func)(
    const NIMQChatChannelCategoryGetWhiteBlackMembersPageResp* resp);
/// 批量查询频道分组白/黑名单身份组回调
typedef void (*nim_qchat_channel_get_category_white_black_roles_cb_func)(
    const NIMQChatChannelCategoryGetExistingWhiteBlackRolesResp* resp);
/// 批量查询频道分组白/黑名单成员回调
typedef void (*nim_qchat_channel_get_category_white_black_members_cb_func)(
    const NIMQChatChannelCategoryGetWhiteBlackMembersResp* resp);
/// 修改RTC频道参数回调
typedef void (*nim_qchat_channel_update_rtc_info_cb_func)(const NIMQChatChannelUpdateRTCInfoResp* resp);
/// 查询RTC频道参数回调
typedef void (*nim_qchat_channel_get_rtc_info_cb_func)(const NIMQChatChannelGetRTCInfoResp* resp);
/// 查询RTC频道在线成员回调
typedef void (*nim_qchat_channel_get_rtc_online_members_cb_func)(const NIMQChatChannelGetRTCOnlineMembersResp* resp);
/// 以游客身份订阅频道回调
typedef void (*nim_qchat_channel_subscribe_as_visitor_cb_func)(const NIMQChatChannelSubscribeAsVisitorResp* resp);

/* ------------------------------- 接口调用参数 ------------------------------ */
/// @struct NIMQChatChannelRegUnreadCbParam
typedef struct {
    nim_qchat_channel_unread_cb_func cb;
    void* user_data;
} NIMQChatChannelRegUnreadCbParam;

/// @struct NIMQChatChannelCreateParam
typedef struct {
    /// 创建频道异步回调
    nim_qchat_channel_create_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 频道信息
    NIMQChatChannelInfo channel_info;
    /// 反垃圾信息
    NIMQChatBusinessAntiSpamInfo anti_spam_info;
} NIMQChatChannelCreateParam;

/// @struct NIMQChatChannelDeleteParam
typedef struct {
    /// 移除频道异步回调
    nim_qchat_channel_remove_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 频道ID
    uint64_t channel_id;
} NIMQChatChannelDeleteParam;

/// @struct NIMQChatChannelUpdateParam
typedef struct {
    /// 更新频道信息异步回调
    nim_qchat_channel_update_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 频道 ID
    uint64_t channel_id;
    /// 频道名称
    char* name;
    /// 主题
    char* topic;
    /// 自定义扩展
    char* custom;
    /// 查看权限
    NIMQChatChannelViewMode view_mode;
    /// 游客访问模式
    NIMQChatChannelVisitorMode visitor_mode;
    /// 反垃圾信息
    NIMQChatBusinessAntiSpamInfo anti_spam_info;
} NIMQChatChannelUpdateParam;

/// @struct NIMQChatChannelUpdateCategoryInfoParam
typedef struct {
    /// 更新频道的分组信息异步回调
    nim_qchat_channel_update_category_info_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 频道 ID
    uint64_t channel_id;
    /// 频道分组ID
    uint64_t category_id;
    /// 频道分组同步模式
    NIMQChatChannelSyncMode sync_mode;
} NIMQChatChannelUpdateCategoryInfoParam;

/// @struct NIMQChatChannelGetChannelsParam
typedef struct {
    /// 查询频道列表异步回调
    nim_qchat_channel_get_channels_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 频道id列表长度
    size_t channel_ids_count;
    /// 频道id列表
    uint64_t* channel_ids;
} NIMQChatChannelGetChannelsParam;

/// @struct NIMQChatChannelGetChannelsPageParam
typedef struct {
    /// 查询频道列表异步回调
    nim_qchat_channel_get_channels_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
} NIMQChatChannelGetChannelsPageParam;

/// @struct NIMQChatChannelGetMembersPageParam
typedef struct {
    /// 查询成员列表异步回调
    nim_qchat_channel_get_members_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
} NIMQChatChannelGetMembersPageParam;

/// @struct NIMQChatChannelQueryUnreadInfoParam
typedef struct {
    /// 查询未读消息数异步回调
    nim_qchat_channel_query_unread_info_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// ID 列表长度
    size_t id_infos_count;
    /// ID 列表
    NIMQChatChannelIDInfo* id_infos;
} NIMQChatChannelQueryUnreadInfoParam;

/// @struct NIMQChatChannelSubscribeParam
typedef struct {
    /// 订阅频道信息回调函数
    nim_qchat_channel_subscribe_cb_func cb;
    void* user_data;
    /// 操作类型
    NIMQChatSubscribeOpeType ope_type;
    /// 订阅类型
    NIMQChatSubscribeType sub_type;
    /// ID 列表长度
    size_t id_infos_count;
    /// ID 列表
    NIMQChatChannelIDInfo* id_infos;
} NIMQChatChannelSubscribeParam;

/// @struct NIMQChatChannelUpdateWhiteBlackRoleParam
typedef struct {
    /// 更新白/黑名单身份组回调
    nim_qchat_channel_update_white_black_role_cb_func cb;
    /// 自定义用户数据
    void* user_data;
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
} NIMQChatChannelUpdateWhiteBlackRoleParam;

/// @struct NIMQChatChannelUpdateWhiteBlackMembersParam
typedef struct {
    /// 更新白/黑名单成员回调
    nim_qchat_channel_update_white_black_members_cb_func cb;
    /// 自定义用户数据
    void* user_data;
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
} NIMQChatChannelUpdateWhiteBlackMembersParam;

/// @struct NIMQChatChannelGetWhiteBlackRolesPageParam
typedef struct {
    /// 查询白/黑名单身份组列表回调
    nim_qchat_channel_get_white_black_roles_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
} NIMQChatChannelGetWhiteBlackRolesPageParam;

/// @struct NIMQChatChannelGetWhiteBlackMembersPageParam
typedef struct {
    /// 查询白/黑名单成员列表回调
    nim_qchat_channel_get_white_black_members_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
} NIMQChatChannelGetWhiteBlackMembersPageParam;

/// @struct NIMQChatChannelGetExistingWhiteBlackRolesParam
typedef struct {
    /// 查询白/黑名单身份组列表回调
    nim_qchat_channel_get_existing_white_black_roles_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 身份组id列表
    uint64_t* role_ids;
    /// 身份组id列表长度
    size_t role_ids_count;
} NIMQChatChannelGetExistingWhiteBlackRolesParam;

/// @struct NIMQChatChannelGetExistingWhiteBlackMembersParam
typedef struct {
    /// 查询白/黑名单成员列表回调
    nim_qchat_channel_get_existing_white_black_members_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// accid列表
    char** accids;
    /// accid列表长度
    size_t accids_count;
} NIMQChatChannelGetExistingWhiteBlackMembersParam;

/// @struct NIMQChatChannelSearchPageParam
typedef struct {
    /// 搜索异步回调
    nim_qchat_channel_search_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id, 若为空则表示在所有服务器下可见频道中搜索
    uint64_t server_id;
    /// 搜索内容
    char* keyword;
    /// 起始时间
    uint64_t start_time;
    /// 结束时间
    uint64_t end_time;
    /// 排序顺序
    NIMQChatSearchOrder order;
    /// 排序规则
    NIMQChatChannelSearchSort sort;
    /// 查询条数
    uint32_t limit;
    /// 查询游标, 查询的起始位置
    char* cursor;
} NIMQChatChannelSearchPageParam;

/// @struct NIMQChatChannelMemberSearchParam
typedef struct {
    /// 搜索异步回调
    nim_qchat_channel_member_search_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 频道 id
    uint64_t channel_id;
    /// 搜索内容
    char* keyword;
    /// 查询条数
    uint32_t limit;
} NIMQChatChannelMemberSearchParam;

/// @struct NIMQChatChannelCategoryCreateParam
typedef struct {
    /// 创建频道分组回调
    nim_qchat_channel_create_category_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 名称
    char* name;
    /// 自定义字段
    char* custom;
    /// 查看模式
    NIMQChatChannelViewMode view_mode;
} NIMQChatChannelCategoryCreateParam;

/// @struct NIMQChatChannelCategoryRemoveParam
typedef struct {
    /// 删除频道分组回调
    nim_qchat_channel_remove_category_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 分组 id
    uint64_t category_id;
} NIMQChatChannelCategoryRemoveParam;

/// @struct NIMQChatChannelCategoryUpdateParam
typedef struct {
    /// 更新频道分组回调
    nim_qchat_channel_update_category_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 分组 id
    uint64_t category_id;
    /// 名称
    char* name;
    /// 自定义字段
    char* custom;
    /// 查看模式
    NIMQChatChannelViewMode view_mode;
} NIMQChatChannelCategoryUpdateParam;

/// @struct NIMQChatChannelGetCategoriesByIDParam
typedef struct {
    /// 获取频道分组回调
    nim_qchat_channel_get_categories_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 分组ID列表
    uint64_t* category_ids;
    /// 分组ID列表长度
    size_t category_ids_count;
} NIMQChatChannelGetCategoriesByIDParam;

/// @struct NIMQChatChannelGetCategoriesPageParam
typedef struct {
    /// 分页获取频道分组回调
    nim_qchat_channel_get_categories_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
} NIMQChatChannelGetCategoriesPageParam;

/// @struct NIMQChatChannelGetCategoryChannelsPageParam
typedef struct {
    /// 分页获取频道分组回调
    nim_qchat_channel_get_category_channels_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 分组 id
    uint64_t category_id;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
} NIMQChatChannelGetCategoryChannelsPageParam;

/// @struct NIMQChatChannelCategoryUpdateWhiteBlackRoleParam
typedef struct {
    /// 更新频道分组白/黑名单身份组回调
    nim_qchat_channel_update_category_white_black_role_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 分组ID
    uint64_t category_id;
    /// 身份组ID
    uint64_t role_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 操作类型
    NIMQChatChannelWhiteBlackOpeType ope_type;
} NIMQChatChannelCategoryUpdateWhiteBlackRoleParam;

/// @struct NIMQChatChannelCategoryGetWhiteBlackRolesPageParam
typedef struct {
    /// 获取频道分组白/黑名单身份组回调
    nim_qchat_channel_get_category_white_black_roles_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 分组ID
    uint64_t category_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
} NIMQChatChannelCategoryGetWhiteBlackRolesPageParam;

/// @struct NIMQChatChannelCategoryGetExistingWhiteBlackRolesParam
typedef struct {
    /// 获取频道分组白/黑名单身份组回调
    nim_qchat_channel_get_category_white_black_roles_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 分组ID
    uint64_t category_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 身份组ID列表
    uint64_t* role_ids;
    /// 身份组ID列表长度
    size_t role_ids_count;
} NIMQChatChannelCategoryGetExistingWhiteBlackRolesParam;

/// @struct NIMQChatChannelCategoryUpdateWhiteBlackMembersParam
typedef struct {
    /// 更新频道分组白/黑名单成员回调
    nim_qchat_channel_update_category_white_black_members_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 分组ID
    uint64_t category_id;
    /// 成员ID列表
    char** accids;
    /// 成员ID列表长度
    size_t accids_count;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 操作类型
    NIMQChatChannelWhiteBlackOpeType ope_type;
} NIMQChatChannelCategoryUpdateWhiteBlackMembersParam;

/// @struct NIMQChatChannelCategoryGetWhiteBlackMembersPageParam
typedef struct {
    /// 获取频道分组白/黑名单成员回调
    nim_qchat_channel_get_category_white_black_members_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 分组ID
    uint64_t category_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
} NIMQChatChannelCategoryGetWhiteBlackMembersPageParam;

/// @struct NIMQChatChannelCategoryGetExistingWhiteBlackMembersParam
typedef struct {
    /// 获取频道分组白/黑名单成员回调
    nim_qchat_channel_get_category_white_black_members_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 分组ID
    uint64_t category_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 成员ID列表
    char** accids;
    /// 成员ID列表长度
    size_t accids_count;
} NIMQChatChannelCategoryGetExistingWhiteBlackMembersParam;

/// @struct NIMQChatChannelUpdateRTCInfoParam
typedef struct {
    /// 更新频道RTC信息回调
    nim_qchat_channel_update_rtc_info_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// RTC信息
    NIMQChatChannelRTCInfo rtc_info;
} NIMQChatChannelUpdateRTCInfoParam;

/// @struct NIMQChatChannelGetRTCInfoParam
typedef struct {
    /// 获取频道RTC信息回调
    nim_qchat_channel_get_rtc_info_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
} NIMQChatChannelGetRTCInfoParam;

/// @struct NIMQChatChannelGetRTCOnlineMembersParam
typedef struct {
    /// 获取频道RTC在线成员回调
    nim_qchat_channel_get_rtc_online_members_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
} NIMQChatChannelGetRTCOnlineMembersParam;

/// @struct NIMQChatChannelSubscribeAsVisitorParam
typedef struct {
    /// 以游客身份订阅服务器异步回调
    nim_qchat_channel_subscribe_as_visitor_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 操作类型
    NIMQChatSubscribeOpeType ope_type;
    /// ID 列表长度
    size_t id_infos_count;
    /// ID 列表
    NIMQChatChannelIDInfo* id_infos;

    // 以下字段为内部使用
    NIMQChatSubscribeType sub_type;
} NIMQChatChannelSubscribeAsVisitorParam;

#ifdef __cplusplus
}
#endif

#endif  // __NIM_QCHAT_CHANNEL_DEF_H__
