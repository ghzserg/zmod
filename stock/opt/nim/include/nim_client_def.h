/** @file nim_client_def.h
 * @brief SDK接入 接口相关的常量函数等定义头文件
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Harrison
 * @date 2015/2/1
 */

#ifndef NIM_SDK_DLL_EXPORT_HEADERS_NIM_CLIENT_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_NIM_CLIENT_DEF_H_

#include "nim_global_def.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @typedef void (*nim_client_multiport_push_config_cb_func)(const char *content, const char *json_params, const void
 * *user_data) 多端推送设置/同步回调
 * @param[out] rescode
 * @param[out] content
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_client_multiport_push_config_cb_func)(int rescode,
    const char* content,
    const char* json_params,
    const void* user_data);

/** @typedef void (*nim_client_dnd_cb_func)(const char *content, const char *json_params, const void *user_data)
 * (PC SDK该接口无效)ios免打扰设置/同步回调
 * @param[out] rescode
 * @param[out] content
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (
    *nim_client_dnd_cb_func)(int rescode, const char* content, const char* json_params, const void* user_data);

/** @typedef void (*nim_client_auth_token_handler)(const char* json_params, const void* user_data)
 * 登录 token 处理对象，当需要请求登录 token 时，通过 nim_client_login_request_token_cb_func 回调携带
 * 业务层在异步获取到 token 后调用此 handler 传入 token 和回调时携带的 user_data 交由 SDK 继续登录流程
 * @param[in] token 登录 token 信息
 * @param[in] handler_data 由 nim_client_login_request_token_cb_func 回调携带的 user_data 指针
 * @return void 无返回值
 */
typedef void (*nim_client_auth_token_handler)(const char* token, const void* handler_data);

/** @typedef void (*nim_client_login_request_token_cb_func)(nim_client_auth_handler_cb_func cb, const void*
 * handler_data, const char* user_data) 登录 token 请求回调，当使用了非默认静态 token 方式登录时 SDK
 * 会调用此回调，通过此回调通知业务层获取 token 业务层异步获取 token 完成后调用 handler 传入 token 和回调时携带的
 * handler_data 交由 SDK 继续登录流程
 * @param[out] handler 业务层获取到 token 后调用的回调函数
 * @param[out] handler_data 业务层获取到 token 后调用的回调函数携带的数据
 * @param[out] user_data 业务层获取 token 时传入的数据
 * @return void 无返回值
 */
typedef void (*nim_client_login_request_token_cb_func)(nim_client_auth_token_handler handler,
    const void* handler_data,
    const char* user_data);

/** @name 多端推送设置/同步 内容Json key
 * @{
 */
/// int, 1开启，即桌面端在线时移动端不需推送；2关闭，即桌面端在线时移动端需推送
static const char* kNIMMultiportPushConfigContentKeyOpen = "switch_open";
/** @}*/  // 多端推送设置/同步 内容Json key

/** @name (PC SDK该设置无效)免打扰设置 内容Json key
 * 客户端传入的属性（如果开启免打扰，请让第三方确保把时间转成东八区，即北京时间，小时是24小时制)
 * @{
 */
/// 是否显示详情，1显示详情，2不显示详情，其它按1处理(Integer)
static const char* kNIMDndShowDetail = "show_detail";
/// 是否开启免打扰，1开启，2关闭，其它按2处理(Integer)
static const char* kNIMDndOpened = "switch_open";
/// 如果开启免打扰，开始小时数(Integer)
static const char* kNIMDndFromH = "fromh";
/// 如果开启免打扰，开始分钟数(Integer)
static const char* kNIMDndFromM = "fromm";
/// 如果开启免打扰，截止小时数(Integer)
static const char* kNIMDndToH = "toh";
/// 如果开启免打扰，截止分钟数(Integer)
static const char* kNIMDndToM = "tom";
/** @}*/  // 免打扰设置 内容Json key

/** @enum NIMLoginState 登录状态 */
enum NIMLoginState {
    /// 登录状态
    kNIMLoginStateLogin = 1,
    /// 未登录状态
    kNIMLoginStateUnLogin = 2,
};

/** @enum NIMLogoutType Logout类型 */
enum NIMLogoutType {
    /// 注销/切换帐号（返回到登录界面）
    kNIMLogoutChangeAccout = 1,
    /// 被踢（返回到登录界面）
    kNIMLogoutKickout = 2,
    /// 程序退出
    kNIMLogoutAppExit = 3,
    /// 重连操作，包括保存密码时启动程序伪登录后的重连操作以及掉线后的重连操作（帐号未变化）
    kNIMLogoutRelogin = 4,
};

/** @enum NIMKickReason 被踢原因 */
enum NIMKickReason {
    /// 互斥类型的客户端互踢
    kNIMKickReasonSameGeneric = 1,
    /// 服务器端发起踢客户端指令
    kNIMKickReasonServerKick = 2,
    /// 被自己的其他端踢掉
    kNIMKickReasonKickBySelfOtherClient = 3,
};

/** @enum NIMClientType 客户端类型 */
enum NIMClientType {
    /// Default, unset
    kNIMClientTypeDefault = 0,
    /// Android
    kNIMClientTypeAndroid = 1,
    /// iOS
    kNIMClientTypeiOS = 2,
    /// PC Windows
    kNIMClientTypePCWindows = 4,
    /// Web
    kNIMClientTypeWeb = 16,
    /// RestAPI
    kNIMClientTypeRestAPI = 32,
    /// Mac
    kNIMClientTypeMacOS = 64,
};

/** @enum NIMLoginStep 登录步骤 */
enum NIMLoginStep {
    /// 正在连接
    kNIMLoginStepLinking = 0,
    /// 连接服务器
    kNIMLoginStepLink = 1,
    /// 正在登录
    kNIMLoginStepLogining = 2,
    /// 登录验证
    kNIMLoginStepLogin = 3,
};

/** @enum NIMMultiSpotNotifyType 多点登录通知类型 */
enum NIMMultiSpotNotifyType {
    /// 通知其他在线端自己登录了
    kNIMMultiSpotNotifyTypeImIn = 2,
    /// 通知其他在线端自己退出
    kNIMMultiSpotNotifyTypeImOut = 3,
};

/// @enum NIMAuthType 鉴权类型
enum NIMAuthType {
    /// 默认鉴权类型，静态 token
    kNIMAuthTypeDefault = 0,
    /// 基于 app secret 生成的动态 token 鉴权
    kNIMAuthTypeDynamicToken = 1,
    /// 基于第三方回调的 token 鉴权方式
    kNIMAuthTypeThirdpartyCallback = 2,
};

/** @name json extension params for nim_client_init API
 * for example:
 * {"app_key":"45c6af3c98409b18a84451215d0bdd6e",
 *  "global_config":{"db_encrypt_key":"xxxxx","preload_attach":true,"sdk_log_level":1,"push_cer_name":"xxxxx"},
 *  "private_server_setting":{"lbs":"xxxxx","nos_lbs":"xxxxx","default_link":["xxxxx"],"default_nos_upload":["xxxxx"],"default_nos_download":["xxxxx"],"rsa_public_key_module":"xxxxx"}
 * }
 * @{
 */
/// string, （必填，APP KEY）
static const char* kNIMAppKey = "app_key";
/// json object, Global Config
static const char* kNIMGlobalConfig = "global_config";
/// string, 必填，目前只支持最多32个字符的加密密钥！建议使用32个字符
static const char* kNIMDataBaseEncryptKey = "db_encrypt_key";
/// bool,
/// 是否需要预下载附件(图片和语音),选填,默认为true,如果有对带宽流量有较高要求的请关闭该选项，改为上层开发者按需下载附件文件
static const char* kNIMPreloadAttach = "preload_attach";
static const char* kNIMQChatAutoSub = "qchat_auto_sub";
/// int, 预下载图片质量,选填,范围0-100
static const char* kNIMPreloadImageQuality = "preload_image_quality";
/// string, 预下载图片基于长宽做内缩略,选填,比如宽100高50,则赋值为100x50,中间为字母小写x
static const char* kNIMPreloadImageResize = "preload_image_resize";
/// int，定义见NIMSDKLogLevel（选填，SDK默认的内置级别为kNIMSDKLogLevelPro）
static const char* kNIMSDKLogLevel = "sdk_log_level";
/// string，推送证书名（选填，iOS端需要,PC SDK该设置无效）
static const char* kNIMPushCerName = "push_cer_name";
/// bool，设置是否已读未读状态多端同步，默认true
static const char* kNIMSyncSessionAck = "sync_session_ack";
/// int，登录重试最大次数，如需设置建议设置大于3次，默认填0，SDK默认设置次数
static const char* kNIMLoginRetryMaxTimes = "login_retry_max_times";
/// bool，是否启用HTTPS协议，默认为false
static const char* kNIMUseHttps = "use_https";
/// bool，群通知是否计入未读数，默认为false
static const char* kNIMTeamNotificationUnreadCount = "team_notification_unread_count";
/// bool，开启对动图缩略图的支持，默认为false，开启后获取的缩略图为原格式，关闭后获取的缩略图为第一帧静态图
static const char* kNIMAnimatedImageThumbnailEnabled = "animated_image_thumbnail_enabled";
/// bool，是否不保存自定义(kNIMMessageTypeCustom)消息（对PC版本SDK不支持，仅对跨平台通用版SDK有效），默认为 false
static const char* kNIMNotNeedSaveCustomMsg = "not_need_save_custom_msg";
/// int, 选填，消息重发队列容量限制
static const char* kNIMResendListCapacity = "resend_list_capacity";
/// string, 下载地址拼接模板，用于拼接最终得到的下载地址
static const char* kNIMDownloadAddressTemplate = "download_address_template";
/// string, 需要被加速主机名
static const char* kNIMAccelerateHost = "accelerate_host";
/// string, 加速地址拼接模板，用于获得加速后的下载地址
static const char* kNIMAccelerateAddressTemplate = "accelerate_address_template";
/// string,  部分 IM 错误信息统计上报地址
static const char* kNIMNtserverAddress = "ntserver_address";
/// bool, 错误信息统计是否上报,私有化如果不上传相应数据，此项配置应为 false
static const char* kNIMUploadStatisticsData = "is_upload_statistics_data";
/// json object, 私有服务器配置（一旦设置了私有服务器，则全部连私有服务器，必须确保配置正确！）
static const char* kNIMPrivateServerSetting = "private_server_setting";
/// string, （必填，lbs地址）
static const char* kNIMLbsAddress = "lbs";
/// string, （必填，nos lbs地址）
static const char* kNIMNosLbsAddress = "nos_lbs";
/// string array, （必填，默认link服务器地址）
static const char* kNIMDefaultLinkAddress = "default_link";
/// string array, （必填，默认nos 上传服务器地址）
static const char* kNIMDefaultNosUploadAddress = "default_nos_upload";
/// string array, （必填，默认nos 下载服务器地址）
static const char* kNIMDefaultNosDownloadAddress = "default_nos_download";
/// string array, （必填，默认nos access服务器地址）
static const char* kNIMDefaultNosAccessAddress = "default_nos_access";
/// string, （必填，RSA public key）
static const char* kNIMRsaPublicKeyModule = "rsa_public_key_module";
/// int, （必填，RSA version）
static const char* kNIMRsaVersion = "rsa_version";
/// int，上层使用的开发框架
static const char* kNIMDevelopmentFramework = "development_framework";
/// string，ca 证书文件路径，默认为空，如果需要使用 websocket 链接则必须指定
static const char* kNIMClientCAFilePath = "client_ca_file_path";

/** @}*/  // json extension params for nim_client_init API

/** @name json extension params for nim_client_kick_other_client API
 * for example:
 * {
 *  "device_ids":["1","2"]
 * }
 * @{
 */
/// string array, 设备 id，uuid
static const char* kNIMKickoutOtherDeviceIDs = "device_ids";
/** @}*/  // json extension params for nim_client_kick_other_client API

/** @name json params for nim_json_transport_cb_func that has been registered in nim_client_login and
 * nim_client_reg_auto_relogin_cb API for example:
 * {"err_code": 200, "relogin": false, "login_step": 3, "retrying": false,
 *  "other_clients_pres":[{"app_account":"abc","client_os":"***","client_type":1,"device_id":"***","mac":"***","login_time":"123456789"}]
 * }
 * @{
 */
/// int, 返回的错误码 NIMResCode
static const char* kNIMErrorCode = "err_code";
/// bool, 是否属于重连
static const char* kNIMRelogin = "relogin";
/// int, 登录步骤NIMLoginStep
static const char* kNIMLoginStep = "login_step";
/// bool, SDK是否在重试，如果为false，开发者需要检查登录步骤和错误码，明确问题后调用手动重连接口进行登录操作
static const char* kNIMRetrying = "retrying";
/// json object array， 其他端的在线状态列表，Keys SEE MORE in "kNIMPres***" Json Keys（登录成功才会返回这部分内容
static const char* kNIMOtherClientsPres = "other_clients_pres";

/// string, 第三方帐号
static const char* kNIMPresAppAccount = "app_account";
/// int, 客户端类型, 见NIMClientType
static const char* kNIMPresClientType = "client_type";
/// string, 登录系统类型,比如ios 6.0.1
static const char* kNIMPresOS = "client_os";
/// string, 登录设备的mac地址
static const char* kNIMPresMac = "mac";
/// string, 设备id，uuid
static const char* kNIMPresDeviceID = "device_id";
/// long, 本次登录时间, 精度到ms
static const char* kNIMPresLoginTime = "login_time";
/// string, 本次登录用户自定义字段 */
static const char* kNIMPresCustomTag = "custom_tag";
/// int, 登录认证类型，0 为默认鉴权类型，1 为基于 app secret 生成的 token 鉴权，2 表示基于第三方回调的 token 鉴权方式
static const char* kNIMPresAuthType = "auth_type";
/// string, 登录自定义字段，用于提交给用户第三方回调服务器进行登录检测，不会同步给其他端。只有在 auth_type = 2 时生效
static const char* kNIMPresLoginExData = "login_ex";
/// string，当 auth_type 不等于 0 时断线并调用 nim_client_relogin 时需要传入该字段
static const char* kNIMPresCustomLoginToken = "token";
/** @}*/  // json params for nim_json_transport_cb_func that has been registered in nim_client_login and
          // nim_client_reg_auto_relogin_cb API

/** @name json params for nim_json_transport_cb_func that has been registered in
 * nim_client_reg_multispot_login_notify_cb API for example:
 * {"multi_spot_notiy_type":2,
 *  "other_clients_pres":[{"app_account":"abc","client_os":"***","client_type":1,"device_id":"***","mac":"***","login_time":"123456789"}]
 * }
 * @{
 */
/// int，多点登录通知类型NIMMultiSpotNotifyType，其他端的状态列表json格式同kNIMOtherClientsPres
static const char* kNIMMultiSpotNotifyType = "multi_spot_notiy_type";

/** @}*/  // json params for nim_json_transport_cb_func that has been registered in
          // nim_client_reg_multispot_login_notify_cb API

/** @name json params for nim_json_transport_cb_func that has been registered in nim_client_logout API
 * for example:
 * {"err_code":200
 * }
 * @{
 */
/// int, 返回的错误码NIMResCode
static const char* kNIMLogoutErrorCode = "err_code" /*kNIMResCode*/;
/** @}*/  // json params for nim_json_transport_cb_func that has been registered in nim_client_logout API

/** @name json params for nim_json_transport_cb_func that has been registered in nim_client_reg_kickout_cb API
 * for example:
 * {"client_type":2,
 *  "reason_code":1
 * }
 * @{
 */
/// int, 客户端类型NIMClientType
static const char* kNIMKickoutClientType = "client_type";
/// int, 返回的被踢原因NIMKickReason
static const char* kNIMKickoutReasonCode = "reason_code";
/** @}*/  // json params for nim_json_transport_cb_func that has been registered in nim_client_reg_kickout_cb API

/** @name json params for nim_json_transport_cb_func that has been registered in nim_client_reg_kickout_other_client_cb
 * API for example:
 * {"err_code":200,
 *  "device_ids":["1","2"]
 * }
 * @{
 */
/// int, 返回的错误码NIMResCode
static const char* kNIMKickoutOtherResErrorCode = "err_code" /*kNIMResCode*/;
/// string array, 设备id，uuid
static const char* kNIMKickoutOtherResDeviceIDs = "device_ids";
/** @}*/  // json params for nim_json_transport_cb_func that has been registered in
          // nim_client_reg_kickout_other_client_cb API
#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_EXPORT_HEADERS_NIM_CLIENT_DEF_H_
