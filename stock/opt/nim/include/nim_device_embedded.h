/** @file nim_device_embedded.h
 * @brief 音视频设备 接口头文件，使用前请先调用音视频初始化接口,该文件中的接口跨平台sdk中有效 [Windows,Linux 有效]
 * @copyright (c) 2015-2018, NetEase Inc. All rights reserved
 * @author
 */

#ifndef NIM_SDK_DLL_API_NIM_DEVICE_EMBEDDED_H_
#define NIM_SDK_DLL_API_NIM_DEVICE_EMBEDDED_H_

#include "nim_base_types.h"
#include "nim_device_def.h"
#include "nim_sdk_dll.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef NIMAPI_UNDER_UNIVERSAL

/**@fn void nim_vchat_set_audio_play_delay_time(int time);
 * NIM VCHAT 设置回声消除参数值
 * param[in] 采集与播放之间的差值 time 0-1000
 */
NIM_SDK_DLL_API void nim_vchat_set_audio_play_delay_time(int time);

#endif

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_API_NIM_DEVICE_H_