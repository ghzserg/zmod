/** @file nim_client.h
 * @brief SDK接入 接口头文件，主要包括SDK初始化/清理、客户端登录/退出/重连/掉线/被踢等流程
 * NIM SDK所有接口命名说明: nim_***(模块)_***(功能)，如nim_client_init
 * NIM SDK所有接口参数说明: 所有与字符串相关的参数(char *)全部为UTF-8编码。
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Harrison
 * @date 2015/2/1
 */

#ifndef NIM_SDK_DLL_API_NIM_CLIENT_H_
#define NIM_SDK_DLL_API_NIM_CLIENT_H_

#include "nim_client_def.h"
#include "nim_sdk_dll.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif
/** @fn bool nim_client_init(const char *app_data_dir, const char *app_install_dir, const char *json_extension)
 * NIM SDK初始化，传入的JSON参数定义见nim_client_def.h
 * @param[in] app_data_dir
 * 使用默认路径时只需传入单个目录名（不以反斜杠结尾)，使用自定义路径时需传入完整路径（以反斜杠结尾，并确保有正确的读写权限！）
 * @param[in] app_install_dir 目前不需要传入（SDK可以自动获取）
 * @param[in] json_extension
 * json扩展参数。目前可以用于支持一些全局配置（如数据库的加密密钥等）和私有服务器的设置（选填）
 * @return bool 返回值true: 成功， false: 失败
 */
NIM_SDK_DLL_API bool nim_client_init(const char* app_data_dir, const char* app_install_dir, const char* json_extension);

/** @fn void nim_client_cleanup(const char *json_extension)
 * NIM SDK清理，传入的JSON参数定义见nim_client_def.h
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_client_cleanup(const char* json_extension);

/** @fn void nim_client_update_apns_token(const char *device_token)
 * (PC SDK该接口无效)更新Device Token，iOS推送使用
 * @param[in] device_token device token
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_client_update_apns_token(const char* device_token);

/** @fn void nim_client_login(const char *app_key, const char *account, const char *token, const char *json_extension,
 *nim_json_transport_cb_func cb, const void *user_data) NIM客户端登录，传入的JSON参数定义见nim_client_def.h
 * @param[in] app_key APP key
 * @param[in] account APP account
 * @param[in] token 令牌 (在后台绑定的登录token)
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 登录流程的回调函数， nim_json_transport_cb_func回调函数定义见nim_global_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				302:账号或密码错误
 *				403:禁止操作
 *				408:请求超时
 *				414:参数错误
 *				415:网络连接出现错误
 *				416:频率超限
 *				422:账号被禁用
 *				20002:账号已经处于登录状态
 */
NIM_SDK_DLL_API void nim_client_login(const char* app_key,
    const char* account,
    const char* token,
    const char* json_extension,
    nim_json_transport_cb_func cb,
    const void* user_data);

/** @fn 	void nim_client_login_ex(const char *app_key, const char *account, const char *token,
 * nim_login_result_cb_func cb, const void *user_data); NIM客户端登录，登录失败时自动执行重试，如果账号密码错误(即error
 * code为302)不进行登录
 * @param[in] app_key APP key
 * @param[in] account APP account
 * @param[in] token 令牌 (在后台绑定的登录token)
 * @param[in] cb 登录流程的回调函数， nim_login_result_cb_func回调函数定义见nim_global_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_client_login_ex(const char* app_key,
    const char* account,
    const char* token,
    nim_login_result_cb_func cb,
    const void* user_data);

/** @fn int nim_client_get_login_state(const char *json_extension)
 * 获取NIM客户端登录状态
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @return int 登录状态见nim_client_def.h 中 NIMLoginState
 */
NIM_SDK_DLL_API int nim_client_get_login_state(const char* json_extension);

/** @fn void nim_client_relogin(const char *json_extension)
 * NIM客户端手动重连（注意
 * APP需要统一处理自动重连/手动重连的回调，因为如果处于某次自动重连的过程中调用手动重连接口，不起作用！）
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_client_relogin(const char* json_extension);

/** @fn void nim_client_logout(enum NIMLogoutType logout_type, const char *json_extension, nim_json_transport_cb_func
 *cb, const void *user_data) NIM客户端注销/退出，传入的JSON参数定义见nim_client_def.h
 * @param[in] logout_type Logout操作类型，其定义见nim_client_def.h
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 注销/退出的回调函数， nim_json_transport_cb_func回调函数定义见nim_global_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				500:未知错误
 */
NIM_SDK_DLL_API void nim_client_logout(enum NIMLogoutType logout_type,
    const char* json_extension,
    nim_json_transport_cb_func cb,
    const void* user_data);

/** @fn void nim_client_kick_other_client(const char *json_extension)
 * 将本帐号的其他端踢下线
 * @param[in] json_extension 设备标识，其定义见nim_client_def.h
 * @return void 无返回值 通过注册nim_client_reg_kickout_other_client_cb回调得到结果
 */
NIM_SDK_DLL_API void nim_client_kick_other_client(const char* json_extension);

/** @fn void nim_client_reg_auto_relogin_cb(const char *json_extension, nim_json_transport_cb_func cb, const void
 **user_data)
 * (全局回调)注册NIM客户端自动重连回调。重连失败时，如果不是网络错误引起的（网络相关的错误号为kNIMResTimeoutError和kNIMResConnectionError），而是服务器返回了非kNIMResSuccess的错误号，
 * 则说明重连的机制已经失效，需要APP层调用nim_client_logout执行注销操作并退回到登录界面后进行重新登录。
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 自动重连的回调函数， nim_json_transport_cb_func回调函数定义见nim_global_def.h。
 *				  如果返回错误号kNIMResExist，说明无法继续重连，App层必须调用nim_client_logout退出到登录界面，以便用户重新进行登录。
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				403:禁止操作
 *				408:请求超时
 *				414:参数错误
 *				415:网络连接出现错误
 *				416:频率超限
 *				422:账号被禁用
 */
NIM_SDK_DLL_API void nim_client_reg_auto_relogin_cb(const char* json_extension,
    nim_json_transport_cb_func cb,
    const void* user_data);

/** @fn void nim_client_reg_kickout_cb(const char *json_extension, nim_json_transport_cb_func cb, const void *user_data)
 * (全局回调)注册NIM客户端被踢回调
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 被踢的回调函数， nim_json_transport_cb_func回调函数定义见nim_global_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_client_reg_kickout_cb(const char* json_extension,
    nim_json_transport_cb_func cb,
    const void* user_data);

/** @fn nim_client_reg_disconnect_cb(const char *json_extension, nim_json_transport_cb_func cb, const void *user_data)
 * (全局回调)注册NIM客户端掉线回调
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 掉线的回调函数， nim_json_transport_cb_func回调函数定义见nim_global_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_client_reg_disconnect_cb(const char* json_extension,
    nim_json_transport_cb_func cb,
    const void* user_data);

/** @fn void nim_client_reg_multispot_login_notify_cb(const char *json_extension, nim_json_transport_cb_func cb, const
 * void *user_data) (全局回调)注册NIM客户端多点登录通知回调
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 多点登录通知的回调函数， nim_json_transport_cb_func回调函数定义见nim_global_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_client_reg_multispot_login_notify_cb(const char* json_extension,
    nim_json_transport_cb_func cb,
    const void* user_data);

/** @fn void nim_client_reg_kickout_other_client_cb(const char *json_extension, nim_json_transport_cb_func cb, const
 * void *user_data) (全局回调)注册NIM客户端将本帐号的其他端踢下线结果回调
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 操作结果的回调函数， nim_json_transport_cb_func回调函数定义见nim_global_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 */
NIM_SDK_DLL_API void nim_client_reg_kickout_other_client_cb(const char* json_extension,
    nim_json_transport_cb_func cb,
    const void* user_data);

/** @fn void nim_client_reg_sync_multiport_push_config_cb(const char *json_extension,
 * nim_client_multiport_push_config_cb_func cb, const void *user_data); (全局回调)注册多端推送设置同步回调
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_client_reg_sync_multiport_push_config_cb(const char* json_extension,
    nim_client_multiport_push_config_cb_func cb,
    const void* user_data);

/**
 * @brief 注册登录请求 token 回调。当登录鉴权方式非默认的静态 token
 * 鉴权方式登录时，调用登录接口会触发此回调以让业务层动态获取登录 token 同时在非默认的静态 token 鉴权方式登录时，SDK
 * 出现断网重连也会触发此回调
 * @param json_extension
 * @param cb
 * @param user_data
 */
NIM_SDK_DLL_API void nim_client_reg_login_request_token_cb(const char* json_extension,
    nim_client_login_request_token_cb_func cb,
    const void* user_data);

/** @fn nim_client_set_multiport_push_config(const char *switch_content, const char *json_extension,
 * nim_client_multiport_push_config_cb_func cb, const void *user_data); 设置多端推送控制开关
 * @param[in] switch_content 开关内容
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 操作结果的回调函数
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值 通过注册nim_client_reg_kickout_other_client_cb回调得到结果
 * @note 错误码	200:成功
 */
NIM_SDK_DLL_API void nim_client_set_multiport_push_config(const char* switch_content,
    const char* json_extension,
    nim_client_multiport_push_config_cb_func cb,
    const void* user_data);

/** @fn nim_client_get_multiport_push_config(const char *json_extension, nim_client_multiport_push_config_cb_func cb,
 * const void *user_data); 获取多端推送控制开关
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 操作结果的回调函数
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值 通过注册nim_client_reg_kickout_other_client_cb回调得到结果
 */
NIM_SDK_DLL_API void nim_client_get_multiport_push_config(const char* json_extension,
    nim_client_multiport_push_config_cb_func cb,
    const void* user_data);

/** @fn nim_client_set_dnd_config(const char* cfg_json, const char *json_extension, nim_client_dnd_cb_func cb, const
 * void *user_data); (PC SDK该接口无效)ios 免打扰设置
 * @param[in] cfg_json 免打扰设置
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 操作结果的回调函数
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值 通过注册nim_client_reg_kickout_other_client_cb回调得到结果
 */
NIM_SDK_DLL_API void nim_client_set_dnd_config(const char* cfg_json,
    const char* json_extension,
    nim_client_dnd_cb_func cb,
    const void* user_data);

/** @fn nim_client_get_dnd_config(nim_client_dnd_cb_func cb, const void *user_data);
 * (PC SDK该接口无效)获取ios 免打扰设置
 * @param[in] cb 操作结果的回调函数
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值 通过注册nim_client_reg_kickout_other_client_cb回调得到结果
 */
NIM_SDK_DLL_API void nim_client_get_dnd_config(nim_client_dnd_cb_func cb, const void* user_data);

/** @fn const char * nim_tool_get_version()
 * (PC SDK该接口无效)获取SDK 版本号
 * @return const char * SDK 版本号
 */
NIM_SDK_DLL_API const char* nim_client_get_version();

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_API_NIM_CLIENT_H_
