/** @file nim_talk_def.h
 * @brief P2P和群组聊天 接口相关的常量函数等定义头文件
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Oleg
 * @date 2015/02/02
 */
#ifndef NIM_SDK_DLL_EXPORT_HEADERS_TALK_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_TALK_DEF_H_

#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif
/** @typedef void (*nim_talk_ack_cb_func)(const char *result, const void *user_data)
 * 发送消息回执的回调函数定义
 * @param[out] result		json string (Keys SEE MORE 『发送消息回执Json Keys』 as follows)
 * @param[out] user_data	APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_talk_ack_cb_func)(const char* result, const void* user_data);

/** @typedef void (*nim_talk_receive_cb_func)(const char *content, const char *json_extension, const void *user_data)
 * 接收消息的回调函数定义(如果是初始化时设置了自动下载图片和语音附件，开发者需要通过监听nim_nos_reg_download_cb返回的事件来保证附件已经成功缓存到本地)
 * @param[out] content			json string (Keys SEE MORE 『接收消息Json Keys』),批量接口回调时，内容为json string
 * array
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_talk_receive_cb_func)(const char* content, const char* json_extension, const void* user_data);

/** @typedef bool (*nim_talk_team_notification_filter_func)(const char *content, const char *json_extension, const void
 * *user_data) 接收群通知是否需要过滤的函数定义（堵塞线程，谨慎使用，避免耗时行为）
 * @param[out] content			json string (Keys SEE MORE 『接收消息Json Keys』),批量接口回调时，内容为json string
 * array
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef bool (
    *nim_talk_team_notification_filter_func)(const char* content, const char* json_extension, const void* user_data);

/** @typedef void (*nim_talk_recall_msg_func)(int rescode, const char *content, const char *json_extension, const void
 * *user_data) 消息撤回通知
 * @param[out] rescode			错误码
 * @param[out] content			json string array string(Keys 『消息撤回通知Json Keys』)
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (
    *nim_talk_recall_msg_func)(int rescode, const char* content, const char* json_extension, const void* user_data);

/** @typedef void (*nim_talk_receive_broadcast_cb_func)(const char *content, const char *json_extension, const void
 * *user_data) 接收广播消息的回调函数定义
 * @param[out] content			json string (Keys SEE MORE 『接收广播消息Json Keys』),批量接口回调时，内容为json
 * string array
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (
    *nim_talk_receive_broadcast_cb_func)(const char* content, const char* json_extension, const void* user_data);

/** @name 消息撤回通知Json Keys
 * @{
 */
static const char* kNIMRecallMsgKeyToType = "to_type";        /**< int,会话类型(NIMSessionType) */
static const char* kNIMRecallMsgKeyFromAccID = "from_id";     /**< string,消息发送方ID */
static const char* kNIMRecallMsgKeyToAccID = "to_id";         /**< string,消息接收方ID */
static const char* kNIMRecallMsgKeyMsgId = "msg_id";          /**< string,客户端消息ID */
static const char* kNIMRecallMsgKeyNotify = "notify";         /**< string,自定义通知文案,按需填 */
static const char* kNIMRecallMsgKeyTime = "time";             /**< long,撤回操作的消息时间戳(毫秒) */
static const char* kNIMRecallMsgKeyNotifyFeature = "feature"; /**< int,撤回通知种类（NIMMessageFeature） */
static const char* kNIMRecallMsgKeyMsgExist =
    "msg_exist"; /**< bool,撤回的消息本地是否存在,比如对方离线时发一条消息又撤回,对方上线收到离线撤回通知该tag为false */
static const char* kNIMRecallMsgKeyMsgTime = "msg_time";      /**< long,要撤回消息的创建时间戳(毫秒) */
static const char* kNIMRecallMsgKeyMsgFromNick = "from_nick"; /**< string,要撤回消息的发送者昵称 */
static const char* kNIMRecallMsgKeyOpeAccID = "operator_id";  /**< string,操作者ID */
/** @}*/                                                      // 消息撤回通知Json Keys

/** @name 接收消息Json Keys
 * 本地定义的error code如下：
 * kNIMResSuccess(200) : no error
 * kNIMLocalResParameterError(414) : url invalid
 * kNIMLocalResExist(417) : local file has exists
 * for example:
 * {"rescode": 200,
 *  "feature": 1,
 *  "content": "***"
 * }
 * @{
 */
static const char* kNIMMsgKeyLocalRescode = "rescode";    /**< int,消息错误码(NIMResCode) */
static const char* kNIMMsgKeyLocalMsgFeature = "feature"; /**< int,消息种类(NIMMessageFeature),SDK本地维护 */
static const char* kNIMMsgKeyLocalReceiveMsgContent = "content"; /**< json string,消息内容，协议定义的消息结构 */
/** @}*/                                                         // 接收消息Json Keys

/** @name 消息结构 Json Keys
 * 例子 {"client_msg_id" : "c0d1167459fc754098a531482b51a1da","local_res_path" : "","log_status" : 4,"log_sub_status" :
 * 0,"msg_attach" : "","msg_body" : "发送文本消息正文", "msg_type" : 0, "resend_flag" : 0, "time" : 1437014897000,
 * "to_accid" : "4045", "to_type" : 1}
 * @{
 */
// 协议定义
static const char* kNIMMsgKeyToType = "to_type";     /**< int,会话类型(NIMSessionType) */
static const char* kNIMMsgKeyToAccount = "to_accid"; /**< string,消息接收方id,给自己发送消息时填写自己id */
static const char* kNIMMsgKeyFromAccount = "from_id"; /**< string,消息发送方id,服务器填写,发送方不需要填写 */
static const char* kNIMMsgKeyFromClientType =
    "from_client_type"; /**< int,消息发送方客户端类型（NIMClientType）,服务器填写,发送方不需要填写 */
static const char* kNIMMsgKeyFromDeviceId =
    "from_device_id"; /**< string,消息发送方设备id,服务器填写,发送方不需要填写 */
static const char* kNIMMsgKeyFromNick = "from_nick"; /**< string,消息发送方昵称,服务器填写,发送方不需要填写 */
static const char* kNIMMsgKeyTime = "time"; /**< long,消息时间戳(毫秒) */
static const char* kNIMMsgKeyEnv = "env"; /**< string,环境变量，用于指向不同的抄送、第三方回调等配置 */
static const char* kNIMMsgKeyType = "msg_type"; /**< int,消息类型(NIMMessageType) */
static const char* kNIMMsgKeyBody = "msg_body"; /**< string,消息正文,长度限制：5000字符 */
static const char* kNIMMsgKeyAttach =
    "msg_attach"; /**< string,消息多媒体资源参数,不同类型多媒体参数不同,发送非多媒体消息时不需要填写,如需使用json
                     string,必须为可以解析为json的非格式化的字符串 */
static const char* kNIMMsgKeyClientMsgid = "client_msg_id"; /**< string,客户端消息id */
static const char* kNIMMsgKeyServerMsgid = "server_msg_id"; /**< long,服务器端消息id */
static const char* kNIMMsgKeyResendFlag = "resend_flag";    /**< int,消息重发标记位,第一次发送0,重发1 */
static const char* kNIMMsgKeyHistorySave =
    "cloud_history"; /**< int,(可选)该消息是否存储云端历史,可选，0:不支持,1:支持, 默认1 */
static const char* kNIMMsgKeyMsgRoaming = "roam_msg"; /**< int,(可选)该消息是否支持漫游,可选,0:不支持,1:支持, 默认1 */
static const char* kNIMMsgKeyMsgSync =
    "sync_msg"; /**< int,(可选)该消息是否支持发送者多端同步,可选,0:不支持,1:支持, 默认1 */
static const char* kNIMMsgKeyPushNeedBadge =
    "push_need_badge"; /**< int,(可选)推送是否要做消息计数(角标)，0:不需要，1:需要，默认1 */
static const char* kNIMMsgKeyServerExt =
    "server_ext"; /**< string,(可选)自定义扩展字段,必须为可以解析为json的非格式化的字符串,长度限制1024 */
static const char* kNIMMsgKeyPushPayload =
    "push_payload"; /**< string,(可选)第三方自定义的推送属性，必须为可以解析为json的非格式化的字符串，长度2048 */
static const char* kNIMMsgKeyPushContent = "push_content"; /**< string,(可选)自定义推送文案，长度限制200字节 */
static const char* kNIMMsgKeyPushEnable =
    "push_enable"; /**< int,(可选)是否需要推送, 0:不需要,1:需要,默认1,aos在收到0是不要模拟本地推送 */
static const char* kNIMMsgKeyPushNeedPrefix = "push_prefix"; /**< int,(可选)推送是否需要前缀，0:不需要，1:需要，默认1 */
static const char* kNIMMsgKeyMsgRoutable =
    "routable_msg"; /**< int,(可选)该消息是否抄送,0:不支持,1:支持,默认按照app的路由开关 */
static const char* kNIMMsgKeySetMsgOffline = "offline_msg"; /**< int,(可选)消息是否要存离线,0:不需要, 1:需要，默认1*/
static const char* kNIMMsgKeyForcePushList =
    "force_push_list"; /**< string,(可选)群组消息强推列表,推送指定账号id string array json, 如果推送全员不填*/
static const char* kNIMMsgKeyForcePushContent = "force_push_content"; /**< string,(可选)群组消息强推文本 */
static const char* kNIMMsgKeyIsForcePush =
    "is_force_push"; /**< int,(可选)群组消息是否强推,0:不强推, 1:强推，属性只针对群组消息强推列表 */
static const char* kNIMMsgKeyAntiSpamEnable =
    "anti_spam_enable"; /**< int, 是否需要过易盾反垃圾, 0:不需要,1:需要, 默认0 */
static const char* kNIMMsgKeyAntiSpamContent =
    "anti_spam_content"; /**< string, (可选)开发者自定义的反垃圾字段,长度限制：5000字符, 格式为json string,{"type" :
                            1:文本，2：图片，3视频, "data" : "文本内容or图片地址or视频地址"}*/
static const char* kNIMMsgKeyClientAntiSpam =
    "client_anti_spam_hitting"; /**< int, (可选) 是否命中客户端反垃圾,命中:1 未命中：0 或者不填写*/
static const char* kNIMMsgKeyAntiSpamBizId =
    "anti_spam_business_id"; /**< string,  (可选)用户配置的对某些单条消息另外的反垃圾的业务ID*/
static const char* kNIMMsgKeyAntiSpamUsingYiDun =
    "anti_spam_using_yidun";                              /**< int,  (可选) 单条消息是否使用易盾反垃圾
                                                             0:(在开通易盾的情况下)不过易盾反垃圾而是通用反垃圾 其他都是按照原来的规则*/
static const char* kNIMMsgKeyTeamMsgAck = "team_msg_ack"; /**< (可选)int, 群消息是否需要已读业务，0：不需要，1：需要*/
static const char* kNIMMsgKeyYidunAntiSpamExt =
    "yidun_anti_spam_ext"; /**< (可选)String, 易盾反垃圾扩展字段，限制json，长度限制1024*/
static const char* kNIMMsgKeyYidunAntiSpamRes =
    "yidun_anti_spam_result"; /**< (可选)int, 群消息是否需要已读业务，0：不需要，1：需要*/

// 本地定义
static const char* kNIMMsgKeyLocalKeyTeamMsgAckSent = "team_msg_ack_sent"; /**< bool 是否已经发送群消息已读回执 */
static const char* kNIMMsgKeyLocalKeyTeamMsgUnreadCount = "team_msg_unread_count"; /**< int, 群消息未读数 */
static const char* kNIMMsgKeyLocalFilePath =
    "local_res_path"; /**< string,多媒体消息资源本地绝对路径,SDK本地维护,发送多媒体消息时必填 */
static const char* kNIMMsgKeyLocalTalkId = "talk_id"; /**< string,会话id,发送方选填,接收方收到的是消息发送方id */
static const char* kNIMMsgKeyLocalResId = "res_id"; /**< string,多媒体资源id,发送方选填,接收方收到的是客户端消息id */
static const char* kNIMMsgKeyLocalLogStatus = "log_status";        /**< int,消息状态(NIMMsgLogStatus)  */
static const char* kNIMMsgKeyLocalLogSubStatus = "log_sub_status"; /**< int,消息二级状态(NIMMsgLogSubStatus) */
static const char* kNIMMsgKeyLocalExt =
    "local_ext"; /**< string,只维护在本地的扩展字段,必须为可以解析为json的非格式化的字符串 */
/** @}*/         // 消息结构 Json Keys

/** @name 发送消息回执Json Keys
 * @{
 */
static const char* kNIMSendAckKeyMsgId = "msg_id";    /**< string,客户端消息id */
static const char* kNIMSendAckKeyTalkId = "talk_id";  /**< string,会话id */
static const char* kNIMSendAckKeyRescode = "rescode"; /**< int,消息错误码(NIMResCode) */
static const char* kNIMSendAckKeyTimetag =
    "msg_timetag"; /**< long,消息时间戳(毫秒),收到ack包时更新上层缓存的消息时间戳 */
static const char* kNIMSendAckKeyClientAntiSpam = "client_anti_spam"; /**< int, 是否命中客户端反垃圾,命中:1 未命中：0*/
static const char* kNIMSendAckKeyYidunAntiSpamRes =
    "yidun_anti_spam_result"; /**< (可选)int, 群消息是否需要已读业务，0：不需要，1：需要*/

/** @}*/  // 发送消息回执Json Keys

/** @name attach多媒体资源参数通用键名定义，可替代不同类型多媒体所使用的相同的参数的键名.
 * @{
 */
static const char* kNIMMsgAttachKeyMd5 = "md5";   /**< string,资源MD5,发送方选填 */
static const char* kNIMMsgAttachKeySize = "size"; /**< long,资源大小(KB),发送方选填 */
static const char* kNIMMsgAttachKeyUrl = "url";   /**< long,资源URL, 发送方不需要填写 */
static const char* kNIMMsgAttachKeyExt =
    "ext"; /**< string,资源扩展名,不包括符号'.',发送方若选填需要保证资源本地路径包含扩展名 */
static const char* kNIMMsgAttachKeyDisplayName = "name"; /**< string,用于显示的文件名,发送方选填,默认文件名 */
static const char* kNIMMsgAttachKeyTag =
    "upload_tag"; /**< string, (可选)发送含有附件的消息时使用的场景标签(可参见nos删除策略) ,Audio Image Video File
                     或者可以被SDK解析到本地文件路径的自定义消息*/
/** @}*/  // attach多媒体资源参数通用键名定义，可替代不同类型多媒体所使用的相同的参数的键名.

/** @name attach图片类型多媒体资源参数键名定义
 * @{
 */
static const char* kNIMImgMsgKeyMd5 = "md5";   /**< string,资源MD5,发送方选填 */
static const char* kNIMImgMsgKeySize = "size"; /**< long,资源大小(KB),发送方选填 */
static const char* kNIMImgMsgKeyWidth = "w";   /**< int,图片宽度,发送方必填 */
static const char* kNIMImgMsgKeyHeight = "h";  /**< int,图片高度,发送方必填 */
static const char* kNIMImgMsgKeyUrl = "url";   /**< string,资源URL, 发送方不需要填写 */
static const char* kNIMImgMsgKeyExt =
    "ext"; /**< string,资源扩展名,不包括符号'.',发送方若选填需要保证资源本地路径包含扩展名 */
static const char* kNIMImgMsgKeyDisplayName = "name"; /**< string,用于显示的文件名,发送方选填,默认文件名 */
/** @}*/                                              // attach图片类型多媒体资源参数键名定义

/** @name attach语音类型多媒体资源参数键名定义
 * @{
 */
static const char* kNIMAudioMsgKeyMd5 = "md5";      /**< string,资源MD5,发送方选填 */
static const char* kNIMAudioMsgKeySize = "size";    /**< long,资源大小(KB),发送方选填 */
static const char* kNIMAudioMsgKeyDuration = "dur"; /**< int,语音资源时间长度(毫秒),发送方必填 */
static const char* kNIMAudioMsgKeyUrl = "url";      /**< string,资源URL, 发送方不需要填写 */
static const char* kNIMAudioMsgKeyExt =
    "ext"; /**< string,资源扩展名,不包括符号'.',发送方若选填需要保证资源本地路径包含扩展名 */
static const char* kNIMAudioMsgKeyDisplayName = "name"; /**< string,用于显示的文件名,发送方选填,默认文件名 */
/** @}*/                                                // attach语音类型多媒体资源参数键名定义

/** @name attach短视频类型多媒体资源参数键名定义
 * @{
 */
static const char* kNIMVideoMsgKeyMd5 = "md5";          /**< string,资源MD5,发送方选填 */
static const char* kNIMVideoMsgKeySize = "size";        /**< long,资源大小(KB),发送方选填 */
static const char* kNIMVideoMsgKeyDisplayName = "name"; /**< string,用于显示的文件名,发送方选填,默认文件名 */
static const char* kNIMVideoMsgKeyDuration = "dur"; /**< int,短视频资源时间长度(毫秒),发送方必填 */
static const char* kNIMVideoMsgKeyWidth = "w";      /**< int,短视频画面宽度,发送方必填 */
static const char* kNIMVideoMsgKeyHeight = "h";     /**< int,短视频画面高度,发送方必填 */
static const char* kNIMVideoMsgKeyUrl = "url";      /**< string,资源URL, 发送方不需要填写 */
static const char* kNIMVideoMsgKeyExt =
    "ext"; /**< string,资源扩展名,不包括符号'.',发送方若选填需要保证资源本地路径包含扩展名 */
/** @}*/  // attach短视频类型多媒体资源参数键名定义

/** @name attach文件类型多媒体资源参数键名定义
 * @{
 */
static const char* kNIMFileMsgKeyMd5 = "md5";          /**< string,资源MD5,发送方选填 */
static const char* kNIMFileMsgKeySize = "size";        /**< long,资源大小(KB),发送方选填 */
static const char* kNIMFileMsgKeyDisplayName = "name"; /**< string,用于显示的文件名,发送方选填,默认文件名 */
static const char* kNIMFileMsgKeyUrl = "url";          /**< string,资源URL, 发送方不需要填写 */
static const char* kNIMFileMsgKeyExt =
    "ext"; /**< string,资源扩展名,不包括符号'.',发送方若选填需要保证资源本地路径包含扩展名 */
/** @}*/  // attach文件类型多媒体资源参数键名定义

/** @name attach位置类型多媒体资源参数键名定义
 * @{
 */
static const char* kNIMLocationMsgKeyLatitude = "lat";  /**< double,纬度 */
static const char* kNIMLocationMsgKeyLongitude = "lng"; /**< double,经度 */
static const char* kNIMLocationMsgKeyTitle = "title";   /**< string,位置信息 */
/** @}*/                                                // attach位置类型多媒体资源参数键名定义

/** @name attach波特机器人类型多媒体资源参数键名定义
 * @{
 */
static const char* kNIMBotRobotMsgKeyRobotID = "robotAccid"; /**< string，机器人云信ID */
static const char* kNIMBotRobotSentMsgKeyParam =
    "param"; /**< json string，给机器人发送时需要填的字段，字段内容定义可见Demo源码或参考波特开发文档 */
static const char* kNIMBotRobotReceivedMsgKeyClientMsgID =
    "clientMsgId"; /**< string，机器人回复时带的字段，表示该条回复相关联的消息ID */
static const char* kNIMBotRobotReceivedMsgKeyMsgOut = "msgOut"; /**< bool，是否为机器人回复，默认为true */
static const char* kNIMBotRobotReceivedMsgKeyRobotMsg =
    "robotMsg"; /**< json string，机器人回复时带的字段，波特机器人消息 */
static const char* kNIMBotRobotReceivedMsgKeyRobotMsgFlag =
    "flag"; /**< string，机器人回复时带的字段，表示该条回复类型，类型定义可见Demo源码或参考波特开发文档，bot或faq */
static const char* kNIMBotRobotReceivedMsgKeyRobotMsgMessage =
    "message"; /**< json object，机器人回复时带的字段，表示该条回复内容，字段内容定义可见Demo源码或参考波特开发文档 */
// static const char *kNIMBotRobotReceivedMsgKeyRobotMsgS		= "s";			/**< string，未知 */
/** @}*/  // attach波特机器人类型多媒体资源参数键名定义

/** @name 广播消息 Json Keys
 * @{
 */
static const char* kNIMBroadcastMsgKeyID = "id";                /**< int64，消息ID */
static const char* kNIMBroadcastMsgKeyFromAccid = "from_accid"; /**< jstring，发送者accid，可能不存在 */
static const char* kNIMBroadcastMsgKeyTime = "time";            /**< int64， 时间戳*/
static const char* kNIMBroadcastMsgKeyBody = "body";            /**< string，内容 */
/** @}*/                                                        // 广播消息 Json Keys

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_EXPORT_HEADERS_TALK_DEF_H_