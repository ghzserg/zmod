/** @file nim_vchat_embedded.h
 * @brief 音视频 接口头文件,文件中的接口跨平台sdk [windows,linux]平台有效
 * @copyright (c) 2015-2018, NetEase Inc. All rights reserved
 * @author
 */

#ifndef NIM_SDK_DLL_API_NIM_VCHAT_EMBEDDED_H_
#define NIM_SDK_DLL_API_NIM_VCHAT_EMBEDDED_H_

#include "nim_sdk_dll.h"
#include "nim_vchat_def.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef NIMAPI_UNDER_UNIVERSAL
/** @fn void nim_vchat_set_vchat_low_energy(bool low_energy);
 * NIM VCHAT 设置音视频通话能耗模式，需在通话开始前设置
 * @param[in] low_energy 是否开启低能耗模式
 * @return
 */
NIM_SDK_DLL_API void nim_vchat_set_vchat_low_energy(bool low_energy);
#endif

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_API_NIM_VCHAT_H_