/** @file nim_global.h
 * @brief 辅助能力 接口头文件，包括内存管理和代理相关设置
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Harrison
 * @date 2015/2/1
 */
#ifndef NIM_SDK_DLL_API_NIM_GLOBAL_H_
#define NIM_SDK_DLL_API_NIM_GLOBAL_H_

#include "nim_global_def.h"
#include "nim_sdk_dll.h"

#ifdef __cplusplus
extern "C" {
#endif
/** @fn void nim_global_free_str_buf(char *str)
 * 释放SDK内部分配的内存
 * @param[in] str 由SDK内部分配内存的字符串
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_global_free_str_buf(char* str);

/** @fn void nim_global_free_buf(void *data)
 * 释放SDK内部分配的内存
 * @param[in] data 由SDK内部分配的内存
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_global_free_buf(void* data);

/** @fn void nim_global_reg_sdk_log_cb(const char *json_extension, nim_sdk_log_cb_func cb, const void *user_data)
 * (PC SDK该接口无效)注册输出sdk log回调
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 输出sdk log的回调函数， nim_sdk_log_cb_func回调函数定义见nim_global_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_global_reg_sdk_log_cb(const char* json_extension,
    nim_sdk_log_cb_func cb,
    const void* user_data);

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_API_NIM_GLOBAL_H_