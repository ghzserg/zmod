/** @file nim_session_def.h
 * @brief 最近会话列表 接口相关的常量函数等定义头文件
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Oleg
 * @date 2015/2/1
 */
#ifndef NIM_SDK_DLL_EXPORT_HEADERS_SESSION_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_SESSION_DEF_H_
#include "nim_base_types.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif
/** @typedef void (*nim_session_change_cb_func)(int rescode, const char *result, int total_unread_counts, const char
 * *json_extension, const void *user_data) 最近会话项更新通知的回调函数定义
 * @param[out] res_code		操作结果，成功200
 * @param[out] result			最近会话Json string (『会话列表的Json Keys』 as follows 不包含消息的字段)
 * @param[out] total_unread_counts 总的未读数目
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_session_change_cb_func)(int rescode,
    const char* result,
    int total_unread_counts,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_session_query_recent_session_cb_func)(int total_unread_count, const char *result, const char
 * *json_extension, const void *user_data) 查询所有最近会话项的回调函数定义
 * @param[out] total_unread_counts 总的未读数目
 * @param[out] result			最近会话列表Json string (『会话列表的Json Keys』 as follows)
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_session_query_recent_session_cb_func)(int total_unread_count,
    const char* result,
    const char* json_extension,
    const void* user_data);

/** @typedef int(*nim_session_badge_count_cb_func)(const char *json_extension, const void *user_data)
 * 获取badge回调
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return int badge数量
 */
typedef int (*nim_session_badge_count_cb_func)(const char* json_extension, const void* user_data);

/** @name 会话列表的Json Keys
 * @{
 */
static const char* kNIMSessionListCount = "count";               /**< int, 会话列表项数量 */
static const char* kNIMSessionListUnreadCount = "unread_counts"; /**< int, 总未读数 */
static const char* kNIMSessionListContent = "content"; /**< json object (Keys as follows), 会话列表项内容 */
static const char* kNIMSessionId = "id";               /**< string, 会话id */
static const char* kNIMSessionType = "type";           /**< int, 会话类型(见NIMSessionType 个人0 群组1 etc) */
static const char* kNIMSessionUnreadCount = "unread_count"; /**< int, 本地消息历史中该会话未读消息数量 */
static const char* kNIMSessionCommand = "command";          /**< int, 会话项操作命令NIMSessionCommand */
static const char* kNIMSessionMsgClientID =
    "msg_client_id"; /**< string, 本地消息历史中该会话最后一条消息的客户端ID唯一标识，即消息uuid */
static const char* kNIMSessionMsgFromAccount =
    "msg_from_account"; /**< string, 本地消息历史中该会话最后一条消息的发送方帐号 */
static const char* kNIMSessionMsgTime = "msg_time"; /**< long, 本地消息历史中该会话最后一条消息的时间 */
static const char* kNIMSessionMsgType = "msg_type"; /**< int, 本地消息历史中该会话最后一条消息的类型 见NIMMessageType*/
static const char* kNIMSessionMsgBody = "msg_body"; /**< string, 本地消息历史中该会话最后一条消息的内容 */
static const char* kNIMSessionMsgAttach = "msg_attach"; /**< string, 本地消息历史中该会话最后一条消息的attach */
static const char* kNIMSessionMsgStatus =
    "msg_status"; /**< int, 本地消息历史中该会话最后一条消息的状态，见NIMMsgLogStatus */
static const char* kNIMSessionMsgSubStatus =
    "msg_sub_status"; /**< int, 本地消息历史中该会话最后一条消息的子状态，见NIMMsgLogSubStatus */
static const char* kNIMSessionLastUpdatedMsg =
    "last_updated_msg"; /**< bool, (批量)消息变更或增加时是否是最后一条变更的信息 */
static const char* kNIMSessionOnTop = "top";                /**< bool, 是否置顶 */
static const char* kNIMSessionExtendedData = "extend_data"; /**< string, 本地扩展字段, 限4096 */
static const char* kNIMSessionRobotFlag = "robot_session";  /**< bool, 是否为机器人会话, 默认为false */
/** @}*/                                                    // 会话列表的Json Keys

/** @enum NIMSessionType 会话类型 */
enum NIMSessionType {
    kNIMSessionTypeP2P = 0,  /**< 个人，即点对点 */
    kNIMSessionTypeTeam = 1, /**< 群组 */
};

/** @enum NIMSessionCommand 会话操作命令 */
enum NIMSessionCommand {
    kNIMSessionCommandAdd = 0,               /**< 添加会话项 */
    kNIMSessionCommandRemove = 1,            /**< 删除单个会话项 */
    kNIMSessionCommandRemoveAll = 2,         /**< 删除所有会话项 */
    kNIMSessionCommandRemoveAllP2P = 3,      /**< 删除所有点对点的会话项 */
    kNIMSessionCommandRemoveAllTeam = 4,     /**< 删除所有群的会话项 */
    kNIMSessionCommandMsgDeleted = 5,        /**< 单个会话项的消息已删除 */
    kNIMSessionCommandAllMsgDeleted = 6,     /**< 所有会话项的消息已删除 */
    kNIMSessionCommandAllP2PMsgDeleted = 7,  /**< 所有点对点会话项的消息已删除 */
    kNIMSessionCommandAllTeamMsgDeleted = 8, /**< 所有群会话项的消息已删除 */
    kNIMSessionCommandUpdate = 9,            /**< 更新会话项 */
};

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_EXPORT_HEADERS_SESSION_DEF_H_
