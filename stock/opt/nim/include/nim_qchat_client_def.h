/**
 * @file nim_qchat_client_def.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_DEF_H__
#define __NIM_QCHAT_DEF_H__

#include "nim_qchat_public_def.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @enum NIMQChatLoginAuthType 圈组登录鉴权类型 */
typedef enum {
    /// 默认login token鉴权方式
    kNIMQChatLoginAuthTypeDefault = 0,
    /// app secret鉴权方式
    kNIMQChatLoginAuthTypeAppSecret = 1,
    /// 基于第三方回调的token鉴权方式, 圈组暂不支持
    kNIMQChatLoginAuthTypeAppThirdParty = 2,
} NIMQChatLoginAuthType;

/// @enum NIMQChatClientType
typedef enum {
    kQChatClientTypeUnknown = 0,
    /// Android
    kQChatClientTypeAOS = 1,
    /// iOS
    kQChatClientTypeIOS = 2,
    /// Desktop PC (Windows/macOS/Linux)
    kQChatClientTypePC = 4,
    /// WP
    kQChatClientTypeWP = 8,
    /// Web
    kQChatClientTypeWeb = 16,
    /// macOS
    kQChatClientTypeMacOS = 64,
    /// HarmonyOS
    kQChatClientTypeHarmonyOS = 65
} NIMQChatClientType;

/// @enum NIMQChatLoginStep
typedef enum {
    /// 连接 Link 地址阶段
    kLoginStepLink,
    kLoginStepAuth  // 认证阶段
} NIMQChatLoginStep;

/// @enum NIMQChatLoginStatus
typedef enum {
    kLoginStatusUnlogin = 0,
    kLoginStatusLogging = 1,
    kLoginStatusLogin = 2,
    kLoginStatusKicked = 3,
} NIMQChatLoginStatus;

/** @struct NIMQChatLoginClientInfo 多端登录信息 */
typedef struct {
    /// 终端类型
    NIMQChatClientType client_type;
    /// 设备 ID
    char* device_id;
    /// 客户端 IP
    char* client_ip;
    /// 会话 ID
    char* consid_;
    /// 客户端端口
    uint16_t client_port;
    /// 时间戳
    uint64_t timestamp;
    /// 自定义终端类型
    uint32_t custom_client_type_;
    /// 自定义标签
    char* custom_tag_;
    /// 操作系统名称
    char* os_name_;
} NIMQChatLoginClientInfo;

/// @struct NIMQChatKickedResp
typedef struct {
    /// 自定义用户数据
    void* user_data;
    /// 客户端类型
    NIMQChatClientType client_type;
    /// 被踢原因
    uint32_t kick_reason;
    /// 扩展字段
    char* ext;
    /// 自定义客户端类型
    uint32_t custom_client_type;
} NIMQChatKickedResp;

/// @struct NIMQChatLoginStatusResp
typedef struct {
    /// 自定义用户数据
    void* user_data;
    /// 登录状态
    NIMQChatLoginStatus login_status;
} NIMQChatLoginStatusResp;

/// @struct NIMQChatCustomTokenResp
typedef struct {
    /// 自定义用户数据
    void* user_data;
    /// appkey
    char* appkey;
    /// accid
    char* accid;
    /// 将该指针指向零结尾的token字符串的起始地址
    char* token;
} NIMQChatCustomTokenResp;

/// @struct NIMQChatMultispotLoginResp
typedef struct {
    /// 自定义用户数据
    void* user_data;
    /// 通知类型 1:登录 2:登出
    uint32_t notify_type;
    /// 客户端信息
    NIMQChatLoginClientInfo client_info;
} NIMQChatMultispotLoginResp;

/// @struct NIMQChatSDKLogResp
typedef struct {
    /// 自定义用户数据
    void* user_data;
    /// 日志内容
    char* log_content;
} NIMQChatSDKLogResp;

/// @struct NIMQChatLoginResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 客户端信息
    NIMQChatLoginClientInfo client_info;
    /// 其他客户端数量
    size_t other_clients_count;
    /// 其他客户端信息
    NIMQChatLoginClientInfo* other_clients;
} NIMQChatLoginResp;

/// @struct NIMQChatLogoutResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
} NIMQChatLogoutResp;

/// @struct NIMQChatKickResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 被踢的设备id列表
    char** kicked_device_ids;
    /// 被踢的设备数量
    size_t kicked_device_ids_count;
} NIMQChatKickResp;

/// @struct NIMQChatGetRTCTokenResp
typedef struct {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// token
    char* token;
    /// ttl, 单位秒
    uint32_t ttl;
} NIMQChatGetRTCTokenResp;

/* ------------------------------- 接口回调模板 ------------------------------- */

/// 获取自定义token回调
typedef NIMQChatCustomTokenResp (*nim_qchat_custom_token_cb_func)(const NIMQChatCustomTokenResp* resp);
/// 接收被踢回调
typedef void (*nim_qchat_kicked_cb_func)(const NIMQChatKickedResp* resp);
/// 登录状态回调
typedef void (*nim_qchat_login_status_cb_func)(const NIMQChatLoginStatusResp* resp);
/// 多端登录回调
typedef void (*nim_qchat_multispot_login_cb_func)(const NIMQChatMultispotLoginResp* resp);
/// SDK日志回调
typedef void (*nim_qchat_sdk_log_cb_func)(const NIMQChatSDKLogResp* resp);
/// 登录回调
typedef void (*nim_qchat_login_cb_func)(const NIMQChatLoginResp* resp);
/// 登出回调
typedef void (*nim_qchat_logout_cb_func)(const NIMQChatLogoutResp* resp);
/// 踢掉其他端回调
typedef void (*nim_qchat_kick_cb_func)(const NIMQChatKickResp* resp);
/// 获取RTC token回调
typedef void (*nim_qchat_get_rtc_token_cb_func)(const NIMQChatGetRTCTokenResp* resp);

/* ------------------------------- 接口所需参数  ------------------------------ */

/// @struct NIMQChatRegCustomTokenCbParam
typedef struct {
    /// 自定义token回调
    nim_qchat_custom_token_cb_func cb;
    /// 自定义用户数据
    void* user_data;
} NIMQChatRegCustomTokenCbParam;

/// @struct NIMQChatRegKickedCbParam
typedef struct {
    /// 被踢异步回调
    nim_qchat_kicked_cb_func cb;
    /// 自定义用户数据
    void* user_data;
} NIMQChatRegKickedCbParam;

/// @struct NIMQChatRegLoginStatusCbParam
typedef struct {
    /// 登录状态回调
    nim_qchat_login_status_cb_func cb;
    /// 自定义用户数据
    void* user_data;
} NIMQChatRegLoginStatusCbParam;

/// @struct NIMQChatRegMultispotLoginCbParam
typedef struct {
    /// 多端登录异步回调
    nim_qchat_multispot_login_cb_func cb;
    /// 自定义用户数据
    void* user_data;
} NIMQChatRegMultispotLoginCbParam;

/** @struct NIMQChatExchangeKeyEncryptionAlgorithm
 * @brief 握手协议加密算法枚举
 */
typedef enum {
    /// RSA 加密
    kNIMQChatEncryptionAlgorithmRSA = 1,
    /// SM2 加密
    kNIMQChatEncryptionAlgorithmSM2 = 2,
} NIMQChatExchangeKeyEncryptionAlgorithm;

/** @struct NIMQChatCommEncryptionAlgorithm
 * @brief 通信协议加密算法
 */
typedef enum {
    kNIMQChatCommEncryptionAlgorithmBase = 1,
    /// RC4 加密
    kNIMQChatCommEncryptionAlgorithmRC4 = kNIMQChatCommEncryptionAlgorithmBase,
    /// AES128 加密
    kNIMQChatCommEncryptionAlgorithmAES128 = kNIMQChatCommEncryptionAlgorithmBase << 1,
    kNIMQChatCommEncryptionAlgorithmSM4 = kNIMQChatCommEncryptionAlgorithmBase << 2  // SM4 加密
} NIMQChatCommEncryptionAlgorithm;

/// @enum NIMQChatHandShakeType
typedef enum {
    /// 支持配置多种对称与非对称加密算法
    kNIMQChatHandShakeTypeMulti = 0,
    kNIMQChatHandShakeTypeRASRC4  // 支持RAS + RC4
} NIMQChatHandShakeType;

/** @struct NIMQChatEncryptionConfiguration
 * @brief 圈组协议加密配置
 */
typedef struct {
    /// "交换密钥"协议加密算法
    NIMQChatExchangeKeyEncryptionAlgorithm nego_key_neca;
    /// 通信加密算法 {1(RC4),2(AES128),4(SM4)} def:1(RC4) 对称加密
    NIMQChatCommEncryptionAlgorithm comm_neca;
    /// 握手协议类型 0:支持配置多种对称与非对称加密算法,1:只支持RAS + RC4
    NIMQChatHandShakeType hand_shake_type;
    /// "交换密钥"协议加密算法密钥, 为空使用默认值
    char* nego_key_neca_key_parta;
    /// 非对称加密算法 key
    char* nego_key_neca_key_partb;
    /// 非对称加密算法的 key version
    uint32_t nego_key_neca_key_version;
} NIMQChatEncryptionConfiguration;

/// @enum NIMQChatFCSAuthenticationType
typedef enum {
    kNIMQChatFCSAuthenticationTypeRefer = 1,
    kNIMQChatFCSAuthenticationTypeToken,
    kNIMQChatFCSAuthenticationTypeURLToken,
    kNIMQChatFCSAuthenticationTypeCustom
} NIMQChatFCSAuthenticationType;

/** @struct NIMQChatFCSConfiguration
 * @brief 圈组云端数据存储配置信息
 */
typedef struct {
    /// 缩略图宽度
    uint32_t thumbnail_width;
    /// 缩略图高度
    uint32_t thumbnail_height;
    /// 是否自动下载历史消息附件
    fcx_bool_t auto_download_history_msg_attach_;
    /// 是否自动下载图片缩略图
    fcx_bool_t auto_download_image_thumb;
    /// 是否自动下载视频缩略图
    fcx_bool_t auto_download_video_thumb;
    /// 是否自动下载图片
    fcx_bool_t auto_download_image;
    /// 是否自动下载音频
    fcx_bool_t auto_download_audio;
    /// 是否自动下载视频
    fcx_bool_t auto_download_video;
    /// 是否自动下载文件
    fcx_bool_t auto_download_file;
    /// 下载附件类数据的鉴权方式
    NIMQChatFCSAuthenticationType fcs_auth_type;
    /// mock user-agent
    char* mock_ua;
    /// mock refer
    char* mock_refer;
} NIMQChatFCSConfiguration;

/**
 * @struct NIMQChatSwitches
 * @breif 圈组初始化相关开关配置
 */
typedef struct {
    /// 是否开启缓存消息，默认开启
    fcx_bool_t enable_message_cache;
    /// 最大缓存消息得频道数量，默认缓存 100 个频道
    size_t max_cache_channel_count;
    /// 每个频道中最大缓存消息数量，默认缓存 20 条消息
    size_t max_cache_message_count;
} NIMQChatMessageCacheConfiguration;

/// @struct NIMQChatInitParam
typedef struct {
    /// 云信appkey
    char* appkey;
    /// APP 数据存储路径，如果为空，则使用系统默认路径
    char* app_data_path;
    /// 自定义通信超时时间，单位秒, 为 0 使用默认值
    uint32_t custom_timeout;
    /// 自定义鉴权超时时间，单位秒, 为 0 使用默认值
    uint32_t auth_timeout;
    /// 数据库加密密钥，如果为空，则使用默认值
    char* database_encrypt_key;
    /// 自动订阅
    fcx_bool_t auto_subscribe;
    /// 圈组协议加密配置
    NIMQChatEncryptionConfiguration encryption_configuration;
    /// 圈组云端数据存储配置信息
    NIMQChatFCSConfiguration fcs_configuration;
    /// 圈组消息缓存配置
    NIMQChatMessageCacheConfiguration message_cache_configuration;
} NIMQChatInitParam;

/// @struct NIMQChatCleanupParam
typedef struct {
    fcx_bool_t unused_flag;
} NIMQChatCleanupParam;

/// @struct NIMQChatLoginParam
typedef struct {
    /// 登录异步回调
    nim_qchat_login_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// app唯一标识符
    char* appkey;
    /// 用户帐号
    char* accid;
    /// 鉴权方式
    NIMQChatLoginAuthType auth_type;
    /// 自定义终端类型
    uint32_t custom_client_type;
    /// 登陆的token
    char* login_token;
    /// 登录自定义字段
    char* login_ext;
    /// 链接地址 json array
    char* link_address;
} NIMQChatLoginParam;

/// @struct NIMQChatLogoutParam
typedef struct {
    /// 登出异步回调
    nim_qchat_logout_cb_func cb;
    /// 自定义用户数据
    void* user_data;
} NIMQChatLogoutParam;

/// @struct NIMQChatKickParam
typedef struct {
    /// 踢掉自己其他端回调
    nim_qchat_kick_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 被踢的设备id
    char** device_ids;
    /// 被踢的设备数量
    size_t device_ids_count;
} NIMQChatKickParam;

/// @struct NIMQChatRegSDKLogCbParam
typedef struct {
    /// 接收日志异步回调
    nim_qchat_sdk_log_cb_func cb;
    /// 自定义用户数据
    void* user_data;
} NIMQChatRegSDKLogCbParam;

/// @struct NIMQChatGetRTCTokenParam
typedef struct {
    /// 获取RTC token回调
    nim_qchat_get_rtc_token_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// device_id
    char* device_id;
} NIMQChatGetRTCTokenParam;

#ifdef __cplusplus
}
#endif

#endif  // __NIM_QCHAT_DEF_H__
