/** @file nim_subscribe_event.h
 * @brief 事件订阅 接口头文件
 * @copyright (c) 2017, NetEase Inc. All rights reserved
 * @author Redrain
 * @date 2015/03/23
 */

#ifndef NIM_SDK_DLL_API_NIM_SUBSCRIBE_EVENT_H_
#define NIM_SDK_DLL_API_NIM_SUBSCRIBE_EVENT_H_

#include "nim_sdk_dll.h"
#include "nim_subscribe_event_def.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @fn void nim_subscribe_event_reg_push_event_cb(const char *json_extension, nim_push_event_cb_func cb, const void
 * *user_data) (全局回调)统一注册接收订阅的事件的回调函数
 * @param[in] json_extension	json扩展参数（备用，目前不需要）
 * @param[in] cb				接收订阅事件的回调函数,
 * nim_push_event_cb_func回调函数定义见nim_subscribe_event_def.h
 * @param[in] user_data		APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 */
NIM_SDK_DLL_API void nim_subscribe_event_reg_push_event_cb(const char* json_extension,
    nim_push_event_cb_func cb,
    const void* user_data);

/** @fn void nim_subscribe_event_reg_batch_push_event_cb(const char *json_extension, nim_batch_push_event_cb_func cb,
 * const void *user_data) (全局回调)统一注册批量接收订阅的事件的回调函数
 * @param[in] json_extension	json扩展参数（备用，目前不需要）
 * @param[in] cb				批量接收订阅事件的回调函数,
 * nim_batch_push_event_cb_func回调函数定义见nim_subscribe_event_def.h
 * @param[in] user_data		APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 */
NIM_SDK_DLL_API void nim_subscribe_event_reg_batch_push_event_cb(const char* json_extension,
    nim_batch_push_event_cb_func cb,
    const void* user_data);

/** @fn void nim_publish_event(const char *event_json, const char *json_extension, nim_publish_event_cb_func cb, const
 *void *user_data) 发布事件
 * @param[in] event_json		事件json字符串
 * @param[in] json_extension	json扩展参数（备用，目前不需要）
 * @param[in] cb				操作结果回调,
 *nim_publish_event_cb_func回调函数定义见nim_subscribe_event_def.h
 * @param[in] user_data		APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				403:应用没开通事件服务
 *				404:禁用了特定事件
 *				414:参数错误
 *				500:未知错误
 */
NIM_SDK_DLL_API void nim_publish_event(const char* event_json,
    const char* json_extension,
    nim_publish_event_cb_func cb,
    const void* user_data);

/** @fn void nim_subscribe_event(int event_type, int64_t ttl, int sync_event, const char *accid_list_json, const char
 **json_extension, nim_subscribe_event_cb_func cb, const void *user_data) 订阅事件
 * @param[in] event_type		事件类型
 * @param[in] ttl				订阅有效期，单位：秒，范围：60s到30天
 * @param[in] sync_event
 *订阅后是否立即同步最新事件，见nim_subscribe_event_def.h中NIMEventSubscribeSyncType定义
 * @param[in] accid_list_json	用户列表，例 ["litianyi01", "litianyi02", ...]
 * @param[in] json_extension j	son扩展参数（备用，目前不需要）
 * @param[in] cb				操作结果回调,
 *nim_subscribe_event_cb_func回调函数定义见nim_subscribe_event_def.h
 * @param[in] user_data		APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				414:参数错误
 *				500:未知错误
 */
NIM_SDK_DLL_API void nim_subscribe_event(int event_type,
    int64_t ttl,
    int sync_event,
    const char* accid_list_json,
    const char* json_extension,
    nim_subscribe_event_cb_func cb,
    const void* user_data);

/** @fn void nim_unsubscribe_event(int event_type, const char *accid_list_json, const char *json_extension,
 *nim_unsubscribe_event_cb_func cb, const void *user_data) 按账号取消指定事件的订阅关系
 * @param[in] event_type		事件类型
 * @param[in] accid_list_json	用户列表，例 ["litianyi01", "litianyi02", ...]
 * @param[in] json_extension	json扩展参数（备用，目前不需要）
 * @param[in] cb				操作结果回调,
 *nim_unsubscribe_event_cb_func回调函数定义见nim_subscribe_event_def.h
 * @param[in] user_data		APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				414:参数错误
 *				500:未知错误
 */
NIM_SDK_DLL_API void nim_unsubscribe_event(int event_type,
    const char* accid_list_json,
    const char* json_extension,
    nim_unsubscribe_event_cb_func cb,
    const void* user_data);

/** @fn void nim_batch_unsubscribe_event(int event_type, const char *json_extension, nim_batch_unsubscribe_event_cb_func
 *cb, const void *user_data) 取消指定事件的全部订阅关系
 * @param[in] event_type		事件类型
 * @param[in] json_extension	json扩展参数（备用，目前不需要）
 * @param[in] cb				操作结果回调,
 *nim_batch_unsubscribe_event_cb_func回调函数定义见nim_subscribe_event_def.h
 * @param[in] user_data		APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				414:参数错误
 *				500:未知错误
 */
NIM_SDK_DLL_API void nim_batch_unsubscribe_event(int event_type,
    const char* json_extension,
    nim_batch_unsubscribe_event_cb_func cb,
    const void* user_data);

/** @fn void nim_query_subscribe_event(int event_type, const char *accid_list_json, const char *json_extension,
 *nim_query_subscribe_event_cb_func cb, const void *user_data) 按账号查询指定事件订阅关系
 * @param[in] event_type		事件类型
 * @param[in] accid_list_json	用户列表，例 ["litianyi01", "litianyi02", ...]
 * @param[in] json_extension	json扩展参数（备用，目前不需要）
 * @param[in] cb				操作结果回调,
 *nim_query_subscribe_event_cb_func回调函数定义见nim_subscribe_event_def.h
 * @param[in] user_data		APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				414:参数错误
 *				500:未知错误
 */
NIM_SDK_DLL_API void nim_query_subscribe_event(int event_type,
    const char* accid_list_json,
    const char* json_extension,
    nim_query_subscribe_event_cb_func cb,
    const void* user_data);

/** @fn void nim_batch_query_subscribe_event(int event_type, const char *json_extension,
 *nim_batch_query_subscribe_event_cb_func cb, const void *user_data) 查询指定事件的全部订阅关系
 * @param[in] event_type		事件类型
 * @param[in] json_extension	json扩展参数（备用，目前不需要）
 * @param[in] cb				操作结果回调,
 *nim_batch_query_subscribe_event_cb_func回调函数定义见nim_subscribe_event_def.h
 * @param[in] user_data		APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				414:参数错误
 *				500:未知错误
 */
NIM_SDK_DLL_API void nim_batch_query_subscribe_event(int event_type,
    const char* json_extension,
    nim_batch_query_subscribe_event_cb_func cb,
    const void* user_data);

#ifdef __cplusplus
}
#endif

#endif  // NIM_SDK_DLL_API_NIM_SUBSCRIBE_EVENT_H_