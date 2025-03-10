/** @file nim_device.h
 * @brief 音视频设备 接口头文件，使用前请先调用音视频初始化接口
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author gq
 * @date 2015/4/30
 */

#ifndef NIM_SDK_DLL_API_NIM_DEVICE_H_
#define NIM_SDK_DLL_API_NIM_DEVICE_H_

#include "nim_base_types.h"
#include "nim_device_def.h"
#include "nim_sdk_dll.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @fn void nim_vchat_start_device(NIMDeviceType type, const char *device_path, unsigned fps, const char
 * *json_extension, nim_vchat_start_device_cb_func cb, const void *user_data) NIM VCHAT DEVICE
 * 启动设备，同一NIMDeviceType下设备将不重复启动，不同的设备会先关闭前一个设备开启新设备
 * @param[in] type NIMDeviceType 见nim_device_def.h
 * @param[in] device_path 设备路径对应kNIMDevicePath，如果是kNIMDeviceTypeAudioHook，对应播放器本地全路径
 * [Linux平台暂时只支持视频采集]
 * @param[in] fps
 * 摄像头为采样频率（一般取30）,其他NIMDeviceType无效（麦克风采样频率由底层控制，播放器采样频率也由底层控制）
 * @param[in] json_extension 打开摄像头是允许设置 kNIMDeviceWidth 和 kNIMDeviceHeight，最后取最接近设置值的画面模式
 * @param[in] cb 结果回调见nim_device_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_vchat_start_device(enum NIMDeviceType type,
    const char* device_path,
    unsigned fps,
    const char* json_extension,
    nim_vchat_start_device_cb_func cb,
    const void* user_data);

/** @fn void nim_vchat_end_device(NIMDeviceType type, const char *json_extension)
 * NIM VCHAT DEVICE 结束设备
 * @param[in] type NIMDeviceType 见nim_device_def.h
 * @param[in] json_extension 无效的扩展字段
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_vchat_end_device(enum NIMDeviceType type, const char* json_extension);

/** @fn void nim_vchat_set_audio_data_cb(bool capture, const char *json_extension, nim_vchat_audio_data_cb_func cb,
 * const void *user_data) NIM VCHAT DEVICE
 * 监听音频数据（可以不监听，通过启动设备kNIMDeviceTypeAudioOut和kNIMDeviceTypeAudioOutChat由底层播放）
 * @param[in] capture true 标识监听麦克风采集数据，false 标识监听通话中对方音频数据
 * @param[in] json_extension 扩展Json
 * string：kNIMDeviceSampleRate（要求返回的音频数据为指定的采样频，缺省为0使用默认采样频）[Linux sdk下无效]
 * @param[in] cb 结果回调见nim_device_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_vchat_set_audio_data_cb(bool capture,
    const char* json_extension,
    nim_vchat_audio_data_cb_func cb,
    const void* user_data);

/** @fn void nim_vchat_custom_audio_data(uint64_t time, const char *data, uint32_t size, const char *json_extension);
 * NIM VCHAT 自定义音频数据接口, 采样位深只支持16或32,[Linux sdk只支持16]
 * kNIMDeviceSampleRate支持8000，16000，32000，44100,数据必须是10ms采样率的整数倍
 * @param[in] time 时间毫秒级
 * @param[in] data 音频数据pcm格式
 * @param[in] size data的数据长度
 * @param[in] json_extension 扩展Json string kNIMDeviceSampleRate采样频和kNIMDeviceSampleBit采样位深
 * 默认如{"sample_rate":16000, "sample_bit":16}
 * @return bool true 调用成功，false 调用失败
 */
NIM_SDK_DLL_API bool nim_vchat_custom_audio_data(uint64_t time,
    const char* data,
    uint32_t size,
    const char* json_extension);

/** @typedef void nim_vchat_custom_video_data(uint64_t time, const char *data, uint32_t size, uint32_t width, uint32_t
 * height, const char *json_extension) NIM VCHAT 自定义视频数据接口
 * @param[in] time 时间毫秒级
 * @param[in] data 视频数据， 默认为yuv420格式
 * @param[in] size data的数据长度
 * @param[in] width  画面宽度，必须是偶数
 * @param[in] height  画面高度，必须是偶数
 * @param[in] json_extension  扩展Json string，kNIMVideoSubType视频数据格式（缺省为kNIMVideoSubTypeI420）
 * @return bool true 调用成功，false 调用失败
 */
NIM_SDK_DLL_API bool nim_vchat_custom_video_data(uint64_t time,
    const char* data,
    uint32_t size,
    uint32_t width,
    uint32_t height,
    const char* json_extension);

/** @fn void nim_vchat_set_video_data_cb(bool capture, const char *json_extension, nim_vchat_video_data_cb_func cb,
 * const void *user_data) NIM VCHAT DEVICE 监听视频数据
 * @param[in] capture true 标识监听采集数据（包括辅助摄像头数据），false 标识监听通话中对方视频数据
 * @param[in] json_extension 扩展Json string：kNIMVideoSubType（缺省为kNIMVideoSubTypeARGB）
 * @param[in] cb 结果回调见nim_device_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_vchat_set_video_data_cb(bool capture,
    const char* json_extension,
    nim_vchat_video_data_cb_func cb,
    const void* user_data);

/** @fn void nim_vchat_enum_device_devpath(NIMDeviceType type, const char *json_extension,
 * nim_vchat_enum_device_devpath_sync_cb_func cb, const void *user_data) NIM VCHAT DEVICE 遍历设备
 * [Linux平台暂时只支持kNIMDeviceTypeVideo]
 * @param[in] type NIMDeviceType 见nim_device_def.h
 * @param[in] json_extension 无效的扩展字段
 * @param[in] cb 结果回调见nim_device_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_vchat_enum_device_devpath(enum NIMDeviceType type,
    const char* json_extension,
    nim_vchat_enum_device_devpath_sync_cb_func cb,
    const void* user_data);

/** @fn void nim_vchat_set_audio_process_info(bool aec, bool ns, bool vad)
 * NIM VCHAT DEVICE 设置底层针对麦克风采集数据处理开关接口，默认全开（此接口是全局接口，在sdk初始化后设置一直有效）
 * @param[in] aec true 标识打开回音消除功能，false 标识关闭
 * @param[in] ns true 标识打开降噪功能，false 标识关闭
 * @param[in] vad true 标识打开人言检测功能，false 标识关闭
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_vchat_set_audio_process_info(bool aec, bool ns, bool vad);

/** @fn void nim_vchat_set_audio_volumn(unsigned char volumn, bool capture)
 * NIM VCHAT DEVICE 设置音量 默认255,且音量均由软件换算得出,设置麦克风音量自动调节后麦克风音量参数无效
 * @param[in] volumn 结果回调见nim_device_def.h
 * @param[in] capture true 标识设置麦克风音量，false 标识设置播放音量
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_vchat_set_audio_volumn(unsigned char volumn, bool capture);

/** @fn unsigned char nim_vchat_get_audio_volumn(bool capture)
 * NIM VCHAT DEVICE 获取nim_vchat_set_audio_volumn中设置的音量
 * @param[in] capture true 标识获取麦克风音量，false 标识获取播放音量
 * @return unsigned char 音量值
 */
NIM_SDK_DLL_API unsigned char nim_vchat_get_audio_volumn(bool capture);

#ifndef NIMAPI_UNDER_UNIVERSAL
/** @fn bool nim_vchat_accompanying_sound(unsigned char id, unsigned __int64 time, const char *data, unsigned int size,
 * unsigned int rate, unsigned int channels, const char *json_extension); NIM VCHAT
 * 自定义音频伴音数据接口，不需要打开自定义数据开关, 采样时间必须为10ms的整数倍, 采样位深只支持16
 * @param[in] id 伴音数据id
 * @param[in] time 时间毫秒级
 * @param[in] data 音频数据pcm格式
 * @param[in] size data的数据长度
 * @param[in] rate 音频采样频
 * @param[in] channels 声道数
 * @param[in] json_extension 扩展
 * @return bool true 调用成功，false 调用失败
 */
NIM_SDK_DLL_API bool nim_vchat_accompanying_sound(unsigned char id,
    unsigned __int64 time,
    const char* data,
    unsigned int size,
    unsigned int rate,
    unsigned int channels,
    const char* json_extension);

/** @fn void nim_vchat_set_audio_data_cb_ex(int type, const char *json_extension, nim_vchat_audio_data_cb_func_ex cb,
 * const void *user_data) NIM VCHAT DEVICE 监听音频数据扩展接口
 * @param[in] type 指定NIMAudioDataCbType，监听伴音数据
 * @param[in] json_extension 参考NIMAudioDataCbType的说明
 * @param[in] cb 结果回调见nim_device_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_vchat_set_audio_data_cb_ex(int type,
    const char* json_extension,
    nim_vchat_audio_data_cb_func_ex cb,
    const void* user_data);

/** @fn void nim_vchat_add_device_status_cb(NIMDeviceType type, nim_vchat_device_status_cb_func cb, const void
 * *user_data) NIM VCHAT DEVICE 添加设备监听（摄像头和麦克风，伴音hook）
 * 注意监听设备后底层会定时检查设备情况，在不需要监听后请移除
 * @param[in] type NIMDeviceType（kNIMDeviceTypeAudioIn和kNIMDeviceTypeVideo、kNIMDeviceTypeAudioHook有效）
 * 见nim_device_def.h
 * @param[in] cb 结果回调见nim_device_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_vchat_add_device_status_cb(enum NIMDeviceType type,
    nim_vchat_device_status_cb_func cb,
    const void* user_data);

/** @fn void nim_vchat_remove_device_status_cb(NIMDeviceType type)
 * NIM VCHAT DEVICE 移除设备监听（摄像头和麦克风，伴音hook）
 * @param[in] type NIMDeviceType（kNIMDeviceTypeAudioIn和kNIMDeviceTypeVideo有效） 见nim_device_def.h
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_vchat_remove_device_status_cb(enum NIMDeviceType type);

/** @fn void nim_vchat_start_extend_camera(const char *id, const char *device_path, uint32_t fps, const char
 * *json_extension, nim_vchat_start_device_cb_func cb, const void *user_data) NIM VCHAT DEVICE
 * 启动辅助的摄像头，摄像头数据通过nim_vchat_set_video_data_cb设置采集回调返回，不直接通过视频通话发送给对方，并且不参与设备监听检测
 * @param[in] id
 * 摄像头标识，用于开关及数据回调时的对应，不能为空。（同一id下设备将不重复启动，如果设备device_path不同会先关闭前一个设备开启新设备）
 * @param[in] device_path 设备路径对应kNIMDevicePath
 * @param[in] fps 摄像头为采样频率
 * @param[in] json_extension 打开摄像头是允许设置 kNIMDeviceWidth 和 kNIMDeviceHeight，并取最接近设置值的画面模式
 * @param[in] cb 结果回调见nim_device_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_vchat_start_extend_camera(const char* id,
    const char* device_path,
    uint32_t fps,
    const char* json_extension,
    nim_vchat_start_device_cb_func cb,
    const void* user_data);

/** @fn void nim_vchat_stop_extend_camera(const char *id, const char *json_extension)
 * NIM VCHAT DEVICE 结束辅助摄像头
 * @param[in] id 摄像头标识id，如果为空，则关闭所有辅助摄像头
 * @param[in] json_extension 无效的扩展字段
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_vchat_stop_extend_camera(const char* id, const char* json_extension);

/** @fn void nim_vchat_set_audio_input_auto_volumn(bool auto_volumn)
 * NIM VCHAT DEVICE 设置麦克风音量自动调节
 * @param[in] auto_volumn true 标识麦克风音量自动调节，false
 * 标识麦克风音量不调节，这时nim_vchat_set_audio_volumn中麦克风音量参数起效
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_vchat_set_audio_input_auto_volumn(bool auto_volumn);

/** @fn bool nim_vchat_get_audio_input_auto_volumn()
 * NIM VCHAT DEVICE 获取是否自动调节麦克风音量
 * @return bool true 标识麦克风音量自动调节，false
 * 标识麦克风音量不调节，这时nim_vchat_set_audio_volumn中麦克风音量参数起效
 */
NIM_SDK_DLL_API bool nim_vchat_get_audio_input_auto_volumn();

#endif

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_API_NIM_DEVICE_H_