/** @file nim_device_mobile.h
 * @brief 音视频设备 接口头文件，使用前请先调用音视频初始化接口,该文件的接口只适用于移动端设备[ios,android]
 * @copyright (c) 2015-2018, NetEase Inc. All rights reserved
 */

#ifndef NIM_SDK_DLL_API_NIM_DEVICE_MOBILE_H_
#define NIM_SDK_DLL_API_NIM_DEVICE_MOBILE_H_

#include "nim_base_types.h"
#include "nim_device_def.h"
#include "nim_sdk_dll.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef NIMAPI_UNDER_UNIVERSAL
/** @fn void nim_vchat_set_audio_data_sync_cb(nim_vchat_audio_data_sync_cb_func cb, const char *json_extension,const
 * void *user_data); NIM VCHAT DEVICE 音频数据回调,该方法是同步方法
 * @param[in] json_extension 扩展Json string：kNIMDeviceSampleRate
 * @param[in] cb 结果回调见nim_device_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_vchat_set_audio_data_sync_cb(nim_vchat_audio_data_sync_cb_func cb,
    const char* json_extension,
    const void* user_data);

/** @fn void nim_vchat_set_speaker(bool speaker_on);
 * NIM VCHAT DEVICE设置扬声器，设置当前语音播放是否采用扬声器或者听筒。
 * @param[in] speaker_on 扬声器开关 true:开启
 */
NIM_SDK_DLL_API void nim_vchat_set_speaker(bool speaker_on);

/**@fn bool nim_vchat_speaker_enabled();
 * NIM VCHAT DEVICE 获取当前语音播放的方式
 * @return bool true:扬声器已开启
 */
NIM_SDK_DLL_API bool nim_vchat_speaker_enabled();

/** @fn void nim_vchat_nrtc_set_microphone_mute(bool mute);
 * NIM VCHAT DEVICE设置麦克风是否静音
 * @param[in] mute 静音.true:静音开启
 **/
NIM_SDK_DLL_API void nim_vchat_set_microphone_mute(bool mute);

/** @fn bool nim_vchat_is_microphone_mute();
 * NIM VCHAT DEVICE 检查麦克风是否静音
 * @return bool ture:静音开启
 */
NIM_SDK_DLL_API bool nim_vchat_is_microphone_mute();

/** @fn bool nim_vchat_start_audio_mixing(const char* filePath, bool loopback, bool replace, int cycle, float volume);
 * NIM VCHAT DEVICE 指定本地音频文件来和麦克风采集的音频流进行混音和替换
 * @param[in] filepath 本地文件路径
 * @param[in] loopback 是否循环播放
 * @param[in] replace 是否替换麦克风采集的音频数据
 * @param[in] cycle 循环的次数
 * @param[in] volume 音量[0.0f - 1.0f]
 * @return bool true：方法调用成功 false:方法调用失败
 */
NIM_SDK_DLL_API bool nim_vchat_start_audio_mixing(const char* filePath,
    bool loopback,
    bool replace,
    int cycle,
    float volume);

/** @fn bool nim_vchat_pause_audio_mixing();
 * NIM VCHAT DEVICE 停止伴音 [ios][android]有效
 * @return bool true:方法调用成功 false:方法调用失败
 */
NIM_SDK_DLL_API bool nim_vchat_pause_audio_mixing();

/** @fn bool nim_vchat_resume_audio_mixing();
 * NIM VCHAT DEVICE 语音伴音恢复 [ios][android]有效
 * @return bool true:方法调用成功 false:方法调用失败
 */
NIM_SDK_DLL_API bool nim_vchat_resume_audio_mixing();

/** @fn bool nim_vchat_stop_audio_mixing();
 * NIM VCHAT DEVICE语音伴音停止
 * @return bool true:方法调用成功 false:方法调用失败
 */
NIM_SDK_DLL_API bool nim_vchat_stop_audio_mixing();

/** @fn bool nim_vchat_stop_play_captured_audio();
 * NIM VCHAT DEVICE 伴音音量设置
 * @param[in] volume  伴音音量值
 * @return bool true:方法调用成功 false:方法调用失败
 */
NIM_SDK_DLL_API bool nim_vchat_set_audio_mixing_volume(float volume);

/** @fn bool nim_vchat_set_earphone_monitor_audio_volume(float volume);
 * NIM VCHAT DEVICE 耳返音量
 * @param[in] volume  播放耳返音量 [0.0f - 1.0f]
 * @return bool true:方法调用成功 false:方法调用失败
 */
NIM_SDK_DLL_API bool nim_vchat_set_earphone_monitor_audio_volume(float volume);

/**@fn void nim_vchat_set_audio_play_delay_time(int time);
 *
 *
 *
 */
NIM_SDK_DLL_API void nim_vchat_set_audio_play_delay_time(int time);
#endif

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_API_NIM_DEVICE_H_