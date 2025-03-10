/** @file nim_device_def.h
 * @brief 音视频设备 接口相关的常量函数等定义头文件
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author gq
 * @date 2015/4/24
 */

#ifndef NIM_SDK_DLL_EXPORT_HEADERS_NIM_DEVICE_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_NIM_DEVICE_DEF_H_

#include "nim_base_types.h"
#include "nim_build_config.h"
#include "stdbool.h"
#ifdef __cplusplus
extern "C" {
#endif
/** @enum NIMDeviceType 设备类型 */
enum NIMDeviceType {
    kNIMDeviceTypeAudioIn = 0,  /**< 麦克风设备 */
    kNIMDeviceTypeAudioOut = 1, /**< 听筒设备用于播放本地采集音频数据，麦克风试音 */
    kNIMDeviceTypeAudioOutChat =
        2, /**< 听筒设备用于通话音频数据（nim_vchat_start_device和nim_vchat_end_device中使用） */
    kNIMDeviceTypeVideo = 3, /**< 摄像头 */
};

/** @enum NIMVideoSubType 视频格式类型 */
enum NIMVideoSubType {
    kNIMVideoSubTypeARGB = 0, /**< 32位位图格式 存储 (B,G,R,A)... */
    kNIMVideoSubTypeRGB = 1,  /**< 24位位图格式 存储 (B,G,R)... */
    kNIMVideoSubTypeI420 = 2, /**< YUV格式，存储 yyyyyyyy...uu...vv... */
    kNIMVideoSubTypeH264 = 3, /**< h264格式,Linux平台有效 */

};

/** @name json extension params for vchat device key
 * @{
 */
static const char* kNIMDeviceName = "name";              /**< 设备名称 string */
static const char* kNIMDevicePath = "path";              /**< 设备路径 string */
static const char* kNIMDeviceSampleRate = "sample_rate"; /**< 采样频率int32 */
static const char* kNIMDeviceSampleBit = "sample_bit";   /**< 采样位深int32 */
static const char* kNIMDeviceDataUid = "uid";            /**< 用户id int64 */
static const char* kNIMDeviceDataAccount = "account";    /**< 用户账号 string */
static const char* kNIMDeviceWidth = "width";            /**< int32 画面宽 */
static const char* kNIMDeviceHeight = "height";          /**< int32 画面高 */
static const char* kNIMVideoSubType = "subtype";         /**< int32 视频数据类型，NIMVideoSubType */
static const char* kNIMDeviceId = "id";                  /**< string 标识ID */
static const char* kNIMVolumeWork = "volume_work"; /**< int32 大于0标识数据将使用音量参数进行换算(暂时只针对伴音数据) */
/** @}*/                                           // json extension params for vchat device key

/** @typedef void (*nim_vchat_enum_device_devpath_sync_cb_func)(bool ret, NIMDeviceType type, const char
 * *json_extension, const void *user_data) NIM Device 枚举设备返回回调同步接口
 * @param[out] ret 结果代码，true表示成功
 * @param[out] type 设备类型NIMDeviceType，其中kNIMDeviceTypeAudioOut和kNIMDeviceTypeAudioOutChat等效
 * @param[out] json_extension Json string 设备列表，可能为空"", 例：json_extension =
 * "[{"name":"Webcam","path":"\\\\?\\usb......"},{"name":"Webcam2","path":"\\\\?\\usb......"}]
 * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_vchat_enum_device_devpath_sync_cb_func)(bool ret,
    enum NIMDeviceType type,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_vchat_start_device_cb_func)(NIMDeviceType type, bool ret, const char *json_extension, const void
 * *user_data) NIM Device 启动设备异步返回接口
 * @param[out] type 设备类型NIMDeviceType
 * @param[out] ret 启动结果，true表示成功
 * @param[out] json_extension 无效的扩展字段
 * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_vchat_start_device_cb_func)(enum NIMDeviceType type,
    bool ret,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_vchat_audio_data_cb_func)(uint64_t time, const char *data, unsigned int size, const char
 * *json_extension, const void *user_data) NIM Device 音频数据监听接口
 * @param[out] time 时间毫秒级
 * @param[out] data 音频数据pcm格式
 * @param[out] size data的数据长度
 * @param[out] json_extension Json string 返回kNIMDeviceSampleRate
 * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_vchat_audio_data_cb_func)(uint64_t time,
    const char* data,
    uint32_t size,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_vchat_video_data_cb_func)(uint64_t time, const char *data, unsigned int size, unsigned int
 * width, unsigned int height, const char *json_extension, const void *user_data) NIM Device 视频数据监听接口
 * @param[out] time 时间毫秒级
 * @param[out] data 视频数据，默认为ARGB格式
 * @param[out] size data的数据长度
 * @param[out] width  画面宽度
 * @param[out] height  画面高度
 * @param[out] json_extension Json string
 * kNIMVideoSubType（缺省为kNIMVideoSubTypeARGB），收到对方视频数据返回kNIMDeviceDataUid和kNIMDeviceDataAccount，如果是辅助摄像头数据则返回kNIMDeviceId
 * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_vchat_video_data_cb_func)(uint64_t time,
    const char* data,
    uint32_t size,
    uint32_t width,
    uint32_t height,
    const char* json_extension,
    const void* user_data);

#ifdef NIMAPI_UNDER_UNIVERSAL
/** @typedef uint64_t(*nim_vchat_audio_data_sync_cb_func)(const char* data, uint64_t size, double sample_rate);
 * NIM Device 同步处理音频数据,此回调 ios,android平台有效
 * @param[out] data 音频数据pcm格式
 * @param[out] size data的数据长度
 * @param[out] sample_rate 音频采样率
 * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return uint64_t 处理完后的data长度
 */
typedef uint64_t (
    *nim_vchat_audio_data_sync_cb_func)(const int16_t* data, uint64_t size, double sample_rate, const void* user_data);
#endif
#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_EXPORT_HEADERS_NIM_DEVICE_DEF_H_
