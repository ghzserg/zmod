/** @file nim_global_def.h
 * @brief 辅助能力 接口相关的常量函数等定义头文件
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Harrison
 * @date 2015/2/1
 */

#ifndef NIM_SDK_DLL_EXPORT_HEADERS_NIM_GLOBAL_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_NIM_GLOBAL_DEF_H_

#include "nim_base_types.h"
#include "nim_build_config.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif
/** @name json params for NIMResCode, see nim_res_code_def.h
 * @{
 */
static const char* kNIMResCode = "err_code"; /**< int, NIMResCode */
/** @}*/                                     // json params for NIMResCode, see nim_res_code_def.h

/** @typedef void (*nim_json_transport_cb_func)(const char *json_params, const void *user_data)
 * nim callback function with json parameters from sdk and user's data from app
 * @param[out] json_params 输出的json字符串内容
 * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_json_transport_cb_func)(const char* json_params, const void* user_data);

/** @typedef void(*nim_login_result_cb_func)(const char *login_res_json, const void *user_data);
 * nim login result callback function
 * @param[out] login_count 执行登录次数
 * @param[out] res_code 登录结果错误码
 * @param[out] json_params 输出的json字符串内容
 * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return int 返回值0表示继续执行登录，非0值表示停止执行登录
 */
typedef int (
    *nim_login_result_cb_func)(int login_count, int res_code, const char* login_res_json, const void* user_data);

/** @enum NIMSDKLogLevel NIM SDK log级别，级别越高，log越详细 */
enum NIMSDKLogLevel {
    kNIMSDKLogLevelFatal = 1, /**< SDK Fatal级别Log*/
    kNIMSDKLogLevelError = 2, /**< SDK Error级别Log*/
    kNIMSDKLogLevelWarn = 3,  /**< SDK Warn级别Log*/
    kNIMSDKLogLevelApp = 5,   /**< SDK应用级别Log，正式发布时为了精简sdk log，可采用此级别*/
    kNIMSDKLogLevelPro = 6,   /**< SDK调试过程级别Log，更加详细，更有利于开发调试*/
};

/** @typedef void (*nim_sdk_log_cb_func)(int log_level, const char *log, const void *user_data)
 * 输出sdk log回调
 * @param[out] log_level log级别，见NIMSDKLogLevel
 * @param[out] log log内容
 * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_sdk_log_cb_func)(int log_level, const char* log, const void* user_data);

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_EXPORT_HEADERS_NIM_GLOBAL_DEF_H_
