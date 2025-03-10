/** @file nim_team_def.h
 * @brief 群组 接口相关的常量函数等定义头文件
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Oleg
 * @date 2015/03/04
 */

#ifndef NIM_SDK_DLL_EXPORT_HEADERS_TEAM_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_TEAM_DEF_H_

#include "nim_build_config.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif
/** @typedef void (*nim_team_event_cb_func)(int res_code, int notification_id, const char *tid, const char *result,
 * const char *json_extension, const void *user_data) 群组通知的回调函数定义
 * @param[out] res_code		结果代码，一切正常200
 * @param[out] notification_id	通知类型枚举值 ('nim_msglog_def.h' NIMNotificationId)
 * @param[out] tid				群组id
 * @param[out] result			Json string (Keys SEE MORE `nim_msglog_def.h` 『群组通知 Json Keys』)
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_team_event_cb_func)(int res_code,
    int notification_id,
    const char* tid,
    const char* result,
    const char* json_extension,
    const void* user_data);

/** @typedef nim_team_event_cb_func nim_team_opt_cb_func
 * 群组操作的回调函数定义
 */
typedef nim_team_event_cb_func nim_team_opt_cb_func;

/** @typedef void (*nim_team_query_all_my_teams_cb_func)(int team_count, const char *result, const char *json_extension,
 * const void *user_data) 查询我的所有群组的回调函数定义
 * @param[out] team_count		有效群组数量
 * @param[out] result			tids Json string array
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_team_query_all_my_teams_cb_func)(int team_count,
    const char* result,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_team_query_all_my_teams_info_cb_func)(int team_count, const char *result, const char
 * *json_extension, const void *user_data) 查询我的所有群组信息的回调函数定义
 * @param[out] team_count		有效群组数量
 * @param[out] result			Json string array (Keys SEE MORE `nim_team_def.h` 『群组信息 Json Keys』)
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_team_query_all_my_teams_info_cb_func)(int team_count,
    const char* result,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_team_query_team_members_cb_func)(const char *tid, int member_count, bool include_user_info,
 * const char *result, const char *json_extension, const void *user_data) 查询群成员的回调函数定义
 * @param[out] tid				群组id
 * @param[out] member_count	有效群成员数量
 * @param[out] include_user_info 返回结果里是否包含user_info
 * @param[out] result			群成员id json string array
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_team_query_team_members_cb_func)(const char* tid,
    int member_count,
    bool include_user_info,
    const char* result,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_team_query_team_member_cb_func)(const char *tid, const char *user_id, const char *result, const
 * char *json_extension, const void *user_data) 查询(单个)群成员的回调函数定义
 * @param[out] tid				群组id
 * @param[out] user_id			群成员id
 * @param[out] result			群成员信息 json string
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_team_query_team_member_cb_func)(const char* tid,
    const char* user_id,
    const char* result,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_team_query_team_info_cb_func)(const char *tid, const char *result, const char *json_extension,
 * const void *user_data) 查询群信息的回调函数定义
 * @param[out] tid				群组id
 * @param[out] result			Json string (Keys SEE MORE `nim_team_def.h` 『群组信息 Json Keys』)
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_team_query_team_info_cb_func)(const char* tid,
    const char* result,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_team_query_mute_list_cb_func)(int res_code, int member_count, const char *tid, const char
 * *result, const char *json_extension, const void *user_data) 获取群禁言成员列表的回调函数定义
 * @param[out] res_code		结果代码，一切正常200
 * @param[out] member_count	禁言列表人数
 * @param[out] tid				群组id
 * @param[out] result			Json string(群组成员信息 json object array)
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_team_query_mute_list_cb_func)(int res_code,
    int member_count,
    const char* tid,
    const char* result,
    const char* json_extension,
    const void* user_data);

/** @enum NIMTeamBeInviteMode 被邀请人同意方式 */
enum NIMTeamBeInviteMode {
    kNIMTeamBeInviteModeNeedAgree = 0,    /**< 需要同意 */
    kNIMTeamBeInviteModeNotNeedAgree = 1, /**< 不需要同意 */
};

/** @enum NIMTeamInviteMode 谁可以邀请他人入群 */
enum NIMTeamInviteMode {
    kNIMTeamInviteModeManager = 0,  /**< 管理员 */
    kNIMTeamInviteModeEveryone = 1, /**< 所有人 */
};

/** @enum NIMTeamUpdateInfoMode 谁可以修改群资料 */
enum NIMTeamUpdateInfoMode {
    kNIMTeamUpdateInfoModeManager = 0,  /**< 管理员 */
    kNIMTeamUpdateInfoModeEveryone = 1, /**< 所有人 */
};

/** @enum NIMTeamUpdateCustomMode 谁可以更新群自定义属性 */
enum NIMTeamUpdateCustomMode {
    kNIMTeamUpdateCustomModeManager = 0,  /**< 管理员 */
    kNIMTeamUpdateCustomModeEveryone = 1, /**< 所有人 */
};

/** @name 群组信息 Json Keys
 * @{
 */
static const char* kNIMTeamInfoKeyID = "tid"; /**< string,群id,通常情况下由SDK维护,开发者作为只读无需设置 */
static const char* kNIMTeamInfoKeyName = "name"; /**< string,群名称 */
static const char* kNIMTeamInfoKeyType = "type"; /**< int,群类型(NIMTeamType) */
static const char* kNIMTeamInfoKeyCreator =
    "creator"; /**< string 群拥有者ID,通常情况下由SDK维护,开发者作为只读无需设置*/
static const char* kNIMTeamInfoKeyLevel = "level"; /**< int,群等级,通常情况下由SDK维护,开发者作为只读无需设置 */
static const char* kNIMTeamInfoKeyProperty = "prop"; /**< string,群性质,长度限制：6000字符 */
static const char* kNIMTeamInfoKeyValidFlag =
    "valid"; /**< int,群有效性标记位,有效1,无效0,通常情况下由SDK维护,开发者作为只读无需设置 */
static const char* kNIMTeamInfoKeyMemberCount =
    "member_count"; /**< int,群成员数量,通常情况下由SDK维护,开发者作为只读无需设置 */
static const char* kNIMTeamInfoKeyListTime =
    "list_timetag"; /**< long,群列表时间戳(毫秒),通常情况下由SDK维护,开发者作为只读无需设置 */
static const char* kNIMTeamInfoKeyCreateTime =
    "create_timetag"; /**< long,群创建时间戳(毫秒),通常情况下由SDK维护,开发者作为只读无需设置 */
static const char* kNIMTeamInfoKeyUpdateTime =
    "update_timetag"; /**< long,群信息上次更新时间戳(毫秒),通常情况下由SDK维护,开发者作为只读无需设置 */
static const char* kNIMTeamInfoKeyMemberValid =
    "member_valid"; /**< int,群有效性标记位,客户端用,有效1,无效0,通常情况下由SDK维护,开发者作为只读无需设置 */
static const char* kNIMTeamInfoKeyIntro = "intro";               /**< string,群介绍,长度限制：255字符 */
static const char* kNIMTeamInfoKeyAnnouncement = "announcement"; /**< string,群公告,长度限制：5000字符 */
static const char* kNIMTeamInfoKeyJoinMode =
    "join_mode"; /**< int,入群模式(NIMTeamJoinMode),默认为kNIMTeamJoinModeNoAuth(0),不需要验证 */
static const char* kNIMTeamInfoKeyBits = "bits";     /**< long, 群属性,开发者无需关注 20161011 by Oleg*/
static const char* kNIMTeamInfoKeyCustom = "custom"; /**< string, 第三方扩展字段（仅负责存储和透传） */
static const char* kNIMTeamInfoKeyServerCustom =
    "server_custom"; /**< string, 第三方服务器扩展字段（该配置项只能通过服务器接口设置，对客户端只读） */
static const char* kNIMTeamInfoKeyIcon = "icon";                   /**< string, 群头像,长度限制：1024字符 */
static const char* kNIMTeamInfoKeyBeInviteMode = "be_invite_mode"; /**< int,
                                                                      被邀请人同意方式，属性本身只有群主管理员可以修改,默认kNIMTeamBeInviteModeNeedAgree(0)/kNIMTeamBeInviteModeNotNeedAgree(1)
                                                                    */
static const char* kNIMTeamInfoKeyInviteMode = "invite_mode";      /**< int,
                                                                      谁可以邀请他人入群，属性本身只有群主管理员可以修改,默认kNIMTeamInviteModeManager(0)/kNIMTeamInviteModeEveryone(1)
                                                                    */
static const char* kNIMTeamInfoKeyUpdateInfoMode = "update_info_mode";     /**< int,
                                                                              谁可以修改群资料，属性本身只有群主管理员可以修改,默认kNIMTeamUpdateInfoModeManager(0)/kNIMTeamUpdateInfoModeEveryone(1)
                                                                            */
static const char* kNIMTeamInfoKeyUpdateCustomMode = "update_custom_mode"; /**< int,
                                                                              谁可以更新群自定义属性，属性本身只有群主管理员可以修改,默认kNIMTeamUpdateCustomModeManager(0)/kNIMTeamUpdateCustomModeEveryone(1)
                                                                            */
static const char* kNIMTeamInfoKeyMuteAll =
    "mute_all"; /**< int, 群全员禁言标记 0:未禁言，1:禁言, 开发者只读 无法设置 */
static const char* kNIMTeamInfoKeyMuteType = "mute_type"; /**<NIMTeamMuteType, 群禁言0不禁言 1普通成员禁言 3全部禁言
                                                             包括群主 开发者可以通过设置该属性调整群禁言状态*/
/** @}*/                                                  // 群组信息Json Keys

/** @enum NIMTeamMuteType 群信息kNIMTeamInfoKeyMuteType的配置定义 */
enum NIMTeamMuteType {
    kNIMTeamMuteTypeNone = 0,      /**< 不禁言 */
    kNIMTeamMuteTypeNomalMute = 1, /**< 普通成员禁言 */
    kNIMTeamMuteTypeAllMute = 3,   /**< 全部禁言 */
};

/** @enum NIMTeamBitsConfigMask 群组成员信息Bits属性kNIMTeamUserKeyBits的配置定义 */
enum NIMTeamBitsConfigMask {
    kNIMTeamBitsConfigMaskMuteNotify = 1, /**< 关闭消息提醒0：开启提醒, 1：关闭提醒, */
    kNIMTeamBitsConfigMaskOnlyAdmin = 2,  /**< 只接收管理员消息0：开启提醒, 1：关闭提醒 */
};

/** @enum NIMTeamType 群组类型 */
enum NIMTeamType {
    kNIMTeamTypeNormal = 0,   /**< 普通群 */
    kNIMTeamTypeAdvanced = 1, /**< 高级群 */
};

/** @name 群组成员信息 Json Keys
 * @{
 */
static const char* kNIMTeamUserKeyID = "tid"; /**< string,群id,通常情况下由SDK维护,开发者作为只读无需设置 */
static const char* kNIMTeamUserKeyAccID = "accid"; /**< string,群成员id,通常情况下由SDK维护,开发者作为只读无需设置 */
static const char* kNIMTeamUserKeyType = "type"; /**< int,群成员类型(NIMTeamUserType),默认kNIMTeamUserTypeNomal(0) */
static const char* kNIMTeamUserKeyNick = "nick"; /**< string,群成员昵称 */
static const char* kNIMTeamUserKeyBits = "bits"; /**< long,群成员属性,位操作(NIMTeamBitsConfigMask) */
static const char* kNIMTeamUserKeyValidFlag =
    "valid"; /**< int,群成员有效性标记位,有效1,无效0,通常情况下由SDK维护,开发者作为只读无需设置 */
static const char* kNIMTeamUserKeyCreateTime =
    "create_timetag"; /**< long,入群时间戳(毫秒),通常情况下由SDK维护,开发者作为只读无需设置 */
static const char* kNIMTeamUserKeyUpdateTime =
    "update_timetag"; /**< long,群成员信息上次更新时间戳(毫秒),通常情况下由SDK维护,开发者作为只读无需设置 */
static const char* kNIMTeamUserKeyCustom =
    "custom"; /**< string,群成员自定义扩展字段,必须为可以解析为json的非格式化的字符串 */
static const char* kNIMTeamUserKeyMute = "mute"; /**< int,是否被禁言,0-非禁言(默认),1-禁言 */
/** @}*/                                         // 群组成员信息Json Keys

/** @enum NIMTeamUserType 群成员类型 */
enum NIMTeamUserType {
    kNIMTeamUserTypeNomal = 0,             /**< 普通成员 */
    kNIMTeamUserTypeCreator = 1,           /**< 创建者 */
    kNIMTeamUserTypeManager = 2,           /**< 管理员 */
    kNIMTeamUserTypeApply = 3,             /**< 申请加入用户 */
    kNIMTeamUserTypeLocalWaitAccept = 100, /**< 本地记录等待正在入群的用户 */
};

/** @enum NIMTeamJoinMode 群允许加入类型 */
enum NIMTeamJoinMode {
    kNIMTeamJoinModeNoAuth = 0,    /**< 不用验证 */
    kNIMTeamJoinModeNeedAuth = 1,  /**< 需要验证 */
    kNIMTeamJoinModeRejectAll = 2, /**< 拒绝所有人入群 */
};

/** @name 搜索本地群组相关信息扩展参数
 * @{
 */
static const char* kNIMTeamSearchKeyIncludeInvalid =
    "include_invalid"; /**< bool,是否包括无效群(成员)，不在群里（离开或被踢）或者群已经解散 */
/** @}*/               // 搜索本地群组相关信息扩展参数

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_EXPORT_HEADERS_TEAM_DEF_H_