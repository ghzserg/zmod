/** @file nim_subscribe_event_def.h
 * @brief 事件订阅 接口相关的常量函数等定义头文件
 * @copyright (c) 2017, NetEase Inc. All rights reserved
 * @author Redrain
 * @date 2017/03/23
 */
#ifndef NIM_SDK_DLL_EXPORT_HEADERS_SUBSCRIBE_EVENT_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_SUBSCRIBE_EVENT_DEF_H_

#include "nim_base_types.h"
#include "nim_build_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @name 事件信息 Json Keys
 * @{
 */
static const char* kNIMEventEventType = "event_type";     /**< int,事件类型 */
static const char* kNIMEventEventValue = "event_value";   /**< int,事件值 */
static const char* kNIMEventMsgIdClient = "msgid_client"; /**< string,客户端生成的消息id */
static const char* kNIMEventConfig = "config";            /**< string,用户自定义事件扩展属性，最长4K */
static const char* kNIMEventTTL = "ttl"; /**< long,事件有效期，单位：秒，时间范围：60s到7天 */
static const char* kNIMEventBroadcastType = "broadcast_type"; /**< int,事件广播类型：1:仅在线 2:在线和离线 */
static const char* kNIMEventSyncSelf = "sync_seft"; /**< int,0:不同步给自己的其他端，1：同步给自己的其他端 */

static const char* kNIMEventTTLType = "ttltype"; /**< int,TtlType枚举值(客户端不填写) */
static const char* kNIMEventDurable =
    "durable"; /**< int,是否需要持久化(可选字段)，默认为需要持久化,0:不需要持久化，1：需要持久化(客户端不填写) */
static const char* kNIMEventEventTime = "event_time"; /**< long,事件发布的时间戳，服务器补充(客户端不填写) */
static const char* kNIMEventMsgIdServer = "msgid_server"; /**< string,服务端生成的消息id(客户端不填写) */
static const char* kNIMEventClientType = "client_type";   /**< int,发送客户端类型(客户端不填写) */
static const char* kNIMEventNimConfig =
    "nim_config"; /**< string,预定义事件的扩展字段（在线状态事件：在线的客户端类型Json */
static const char* kNIMEventMultiConfig =
    "multi_config"; /**< string,多端配置信息字段，JSON格式{"clent_type":"clent_config","1":"xxx","2":"xxx"} */

static const char* kNIMEventPublisherAccid = "publisher_accid"; /**< string,事件发布者的accid(客户端不填写) */
static const char* kNIMEventConsid = "consid";                  /**< string,发送设备id(客户端不填写) */
/** @}*/                                                        // 事件信息Json Keys

/** @name 在线状态事件kNIMEventNimConfig字段Json Keys，只用于在线状态事件
 * @{
 */
static const char* kNIMEventNimConfigOnlineClient = "online"; /**< string,预定义事件的扩展字段中的在线的客户端类型 */
/** @}*/  // 在线状态事件kNIMEventNimConfig字段Json Keys，只用于在线状态事件

/** @name 事件订阅信息 Json Keys
 * @{
 */
static const char* kNIMEventSubscribeEventType = "type"; /**< int,事件类型 */
static const char* kNIMEventSubscribeTTL = "ttl"; /**< long,订阅有效期，单位：秒，范围：60s到30天 */
static const char* kNIMEventSubscribeSyncEvent = "syncevent"; /**< int,订阅后是否立即同步最新事件 */

static const char* kNIMEventSubscribePublisherAccid =
    "publisher_accid"; /**< string,被订阅人（事件发布人）的accid(客户端不填写) */
static const char* kNIMEventSubscribeSubscribeAccid = "subscribe_accid"; /**< string,订阅人的accid(客户端不填写) */
static const char* kNIMEventSubscribeSubscribeTime = "subscribe_time"; /**< long,订阅时间戳(客户端不填写) */
/** @}*/                                                               // 事件订阅信息Json Keys

/** @enum NIMEventBroadcastType 事件广播类型 */
enum NIMEventBroadcastType {
    kNIMEventBroadcastTypeOnline = 1, /**< 仅在线 */
    kNIMEventBroadcastTypeAll = 2,    /**< 在线和离线 */
};

/** @enum NIMEventSyncType 事件同步类型 */
enum NIMEventSyncType {
    kNIMEventSyncTypeNoSelf = 0, /**< 事件不同步给自己其他端 */
    kNIMEventSyncTypeSelf = 1,   /**< 事件同步给自己其他端 */
};

/** @enum NIMEventSubscribeSyncEventType 订阅的事件的同步类型 */
enum NIMEventSubscribeSyncEventType {
    kNIMEventSubscribeSyncTypeUnSync = 0, /**< 订阅后不同步最新事件 */
    kNIMEventSubscribeSyncTypeSync = 1,   /**< 订阅后立即同步最新事件 */
};

/** @enum NIMEventType 服务器预定义的事件类型 */
enum NIMEventType {
    kNIMEventTypeOnlineState = 1, /**< 在线状态事件(客户端可发送) */
    kNIMEventTypeSyncEvent = 2,   /**< 同步“订阅事件”事件(客户端不可发送) */
    kNIMEventTypeCustom = 100000, /**< 服务器保留1～99999的事件类型，客户端自定义事件类型需大于99999 */
};

/** @enum NIMEventOnlineStateValue 在线状态事件值 */
enum NIMEventOnlineStateValue {
    kNIMEventOnlineStateValueLogin = 1,      /**< 登录 */
    kNIMEventOnlineStateValueLogout = 2,     /**< 登出 */
    kNIMEventOnlineStateValueDisconnect = 3, /**< 断开连接 */
    kNIMEventOnlineStateValueCustom = 10000, /**< 在线状态事件服务器保留1～9999的事件值，客户端自定义事件值需大于9999 */
    kNIMEventOnlineStateValueUpdateConfig =
        kNIMEventOnlineStateValueCustom + 1 /**< 自己的其他端更新了自己端的multi_config信息 */
};

/** @typedef void (*nim_push_event_cb_func)(int res_code, const char *event_info_json, const char *json_extension, const
 * void *user_data) 接收订阅的事件的回调函数定义
 * @param[out] res_code		结果代码，一切正常200
 * @param[out] event_info_json	事件信息的json字符串
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_push_event_cb_func)(int res_code,
    const char* event_info_json,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_batch_push_event_cb_func)(int res_code, const char *event_list_json, const char *json_extension,
 * const void *user_data) 批量接收订阅的事件的回调函数定义
 * @param[out] res_code		结果代码，一切正常200
 * @param[out] event_list_json	事件信息数组的json字符串
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_batch_push_event_cb_func)(int res_code,
    const char* event_list_json,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_publish_event_cb_func)(int res_code, int event_type, const char *event_info_json, const char
 * *json_extension, const void *user_data) 发布事件的回调函数定义
 * @param[out] res_code		结果代码，一切正常200
 * @param[out] event_type		发布的事件类型
 * @param[out] event_info_json	发布的事件信息
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_publish_event_cb_func)(int res_code,
    int event_type,
    const char* event_info_json,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_subscribe_event_cb_func)(int res_code, int event_type, const char *faild_list_json, const char
 * *json_extension, const void *user_data) 订阅事件的回调函数定义
 * @param[out] res_code		结果代码，一切正常200
 * @param[out] event_type		订阅的事件类型
 * @param[out] faild_list_json	订阅失败的帐号数组
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_subscribe_event_cb_func)(int res_code,
    int event_type,
    const char* faild_list_json,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_unsubscribe_event_cb_func)(int res_code, int event_type, const char *faild_list_json, const char
 * *json_extension, const void *user_data) 按账号取消指定事件的订阅关系的回调函数定义
 * @param[out] res_code		结果代码，一切正常200
 * @param[out] event_type		取消订阅的事件类型
 * @param[out] faild_list_json	取消订阅失败的帐号数组
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_unsubscribe_event_cb_func)(int res_code,
    int event_type,
    const char* faild_list_json,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_batch_unsubscribe_event_cb_func)(int res_code, int event_type, const char *json_extension, const
 * void *user_data) 取消指定事件的全部订阅关系的回调函数定义
 * @param[out] res_code		结果代码，一切正常200
 * @param[out] event_type		取消的事件类型
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_batch_unsubscribe_event_cb_func)(int res_code,
    int event_type,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_query_subscribe_event_cb_func)(int res_code, int event_type, const char *subscribe_list_json,
 * const char *json_extension, const void *user_data) 按帐号查询指定事件的订阅关系的回调函数定义
 * @param[out] res_code			结果代码，一切正常200
 * @param[out] event_type			查询的事件类型
 * @param[out] subscribe_list_json	订阅关系信息数组
 * @param[out] json_extension		json扩展数据（备用）
 * @param[out] user_data			APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_query_subscribe_event_cb_func)(int res_code,
    int event_type,
    const char* subscribe_list_json,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_batch_query_subscribe_event_cb_func)(int res_code, int event_type, const char
 * *subscribe_list_json, const char *json_extension, const void *user_data) 查询指定事件的全部订阅关系的回调函数定义
 * @param[out] res_code			结果代码，一切正常200
 * @param[out] event_type			查询的事件类型
 * @param[out] subscribe_list_json	订阅关系信息数组
 * @param[out] json_extension		json扩展数据（备用）
 * @param[out] user_data			APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_batch_query_subscribe_event_cb_func)(int res_code,
    int event_type,
    const char* subscribe_list_json,
    const char* json_extension,
    const void* user_data);

#ifdef __cplusplus
}
#endif

#endif  // NIM_SDK_DLL_EXPORT_HEADERS_SUBSCRIBE_EVENT_DEF_H_
