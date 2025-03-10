/** @file nim_plugin_in_def.h
 * @brief 插件接入 接口相关的常量函数等定义头文件
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Oleg
 * @date 2015/12/24
 */
#ifndef NIM_SDK_DLL_EXPORT_HEADERS_NIM_PLUGIN_IN_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_NIM_PLUGIN_IN_DEF_H_
#include "nim_base_types.h"

#ifdef __cplusplus
extern "C" {
#endif
/** @typedef void (*nim_plugin_chatroom_request_enter_cb_func)(int error_code, const char *result, const void
 * *user_data) 请求获取进入聊天室信息的回调函数定义
 * @param[out] int			错误码
 * @param[out] result		登录信息，直接作为参数调用聊天室登录接口
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data	APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_plugin_chatroom_request_enter_cb_func)(int error_code,
    const char* result,
    const char* json_extension,
    const void* user_data);

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_EXPORT_HEADERS_NIM_PLUGIN_IN_DEF_H_