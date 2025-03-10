/** @file nim_vchat_mobile.h
 * @brief 音视频 接口头文件 该文件的接口跨平台sdk 移动端设备[ios,android]有效
 * @copyright (c) 2015-2018, NetEase Inc. All rights reserved
 */

#ifndef NIM_SDK_DLL_API_NIM_VCHAT_MOBILE_H_
#define NIM_SDK_DLL_API_NIM_VCHAT_MOBILE_H_

#include "nim_sdk_dll.h"
#include "nim_vchat_def.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef NIMAPI_UNDER_UNIVERSAL
/** @fn bool nim_vchat_init(const char *json_extension)
 * NIM VCHAT初始化，需要在SDK的nim_client_init成功之后
 * @param[in] context android context
 * @param[in] json_extension 无效扩展参数
 * @return bool 初始化结果，如果是false则以下所有接口调用无效
 */
NIM_SDK_DLL_API bool nim_vchat_init_ex(const void* context, const char* json_extension);
#endif

#ifdef __cplusplus
};
#endif  //__cplusplus

#endif  // NIM_SDK_DLL_API_NIM_VCHAT_H_