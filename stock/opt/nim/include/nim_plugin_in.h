/** @file nim_plugin_in.h
 * @brief 插件接入 接口头文件
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Oleg
 * @date 2015/12/28
 */

#ifndef NIM_SDK_DLL_API_NIM_PLUGIN_IN_H_
#define NIM_SDK_DLL_API_NIM_PLUGIN_IN_H_

#include "nim_plugin_in_def.h"
#include "nim_sdk_dll.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @fn void nim_plugin_chatroom_request_enter_async(const int64_t room_id, const char *json_extension,
 *nim_plugin_chatroom_request_enter_cb_func cb, const void *user_data) 异步获取进入聊天室的信息
 * @param[in] room_id				聊天室ID
 * @param[in] json_extension		json扩展参数（备用，目前不需要）
 * @param[in] cb					回调函数, 定义见nim_plugin_in_def.h
 * @param[in] user_data			APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				414:参数错误
 *				404:聊天室不存在
 *				403:不允许进入该聊天室
 *				415:服务不可用，没有聊天室服务器可分配
 *				13003:在黑名单中
 */
NIM_SDK_DLL_API void nim_plugin_chatroom_request_enter_async(const int64_t room_id,
    const char* json_extension,
    nim_plugin_chatroom_request_enter_cb_func cb,
    const void* user_data);

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_API_NIM_PLUGIN_IN_H_