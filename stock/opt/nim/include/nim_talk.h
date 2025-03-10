/** @file nim_talk.h
 * @brief P2P和群组聊天 接口头文件
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Oleg
 * @date 2015/2/1
 */

#ifndef NIM_SDK_DLL_API_NIM_TALK_H_
#define NIM_SDK_DLL_API_NIM_TALK_H_

#include "nim_nos_def.h"
#include "nim_sdk_dll.h"
#include "nim_session_def.h"
#include "nim_talk_def.h"

#ifdef __cplusplus
extern "C" {
#endif
/** @fn void nim_talk_send_msg(const char *json_msg, const char *json_extension, nim_nos_upload_prg_cb_func prg_cb,
 * const void *prg_user_data) 发送消息
 * @param[in] json_msg		消息体Json string (Keys SEE MORE `nim_talk_def.h` 『消息结构 Json Keys』)
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] prg_cb		上传进度的回调函数, 如果发送的消息里包含了文件资源，则通过此回调函数通知上传进度,
 * nim_sysmsg_receive_cb_func回调函数定义见nim_nos_def.h
 * @param[in] prg_user_data APP的自定义用户数据，SDK只负责传回给回调函数prg_cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_talk_send_msg(const char* json_msg,
    const char* json_extension,
    nim_nos_upload_prg_cb_func prg_cb,
    const void* prg_user_data);

/** @fn void nim_talk_stop_send_msg(const char *json_msg, const char *json_extension)
 * 停止正在发送中的消息（目前只支持发送文件消息时的终止）
 * @param[in] json_msg		消息体Json string (Keys SEE MORE `nim_talk_def.h` 『消息结构 Json Keys』)
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_talk_stop_send_msg(const char* json_msg, const char* json_extension);

/** @fn void nim_talk_reg_ack_cb(const char *json_extension, nim_talk_ack_cb_func cb, const void *user_data)
 * (全局回调)注册发送消息结果回调函数
 *（必须全局注册，统一接受回调后分发消息到具体的会话。注意：客户端发包之后，服务器不一定会返回！）
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb		发送消息的回调函数, nim_talk_ack_cb_func回调函数定义见nim_talk_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				408:请求过程超时
 *				414:参数错误
 *				802:没有权限(群错误码)
 *				811:强推列表中帐号数量超限(群错误码)
 *				812:群禁言(群错误码)
 *				10200:发送文件消息，NOS上传暂停
 *				10404:本地资源不存在
 *				10414:本地错误码，参数错误
 *				10502:发送消息，上传NOS失败
 */
NIM_SDK_DLL_API void nim_talk_reg_ack_cb(const char* json_extension, nim_talk_ack_cb_func cb, const void* user_data);

/** @fn void nim_talk_reg_receive_cb(const char *json_extension, nim_talk_receive_cb_func cb, const void *user_data)
 * (全局回调)注册接收消息回调 （建议全局注册，统一接受回调后分发消息到具体的会话）
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb		接收消息的回调函数, nim_talk_receive_cb_func回调函数定义见nim_talk_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				10414:本地错误码，参数错误
 *				10417:本地错误码，对象已经存在/重复操作
 */
NIM_SDK_DLL_API void nim_talk_reg_receive_cb(const char* json_extension,
    nim_talk_receive_cb_func cb,
    const void* user_data);

/** @fn void nim_talk_reg_receive_msgs_cb(const char *json_extension, nim_talk_receive_cb_func cb, const void
 * *user_data) 注册接收批量消息(一个会话为单位)回调
 * （如果在注册了接收消息回调的同时也注册了该批量接口，当有批量消息时，会改走这个接口通知应用层，例如登录后接收到的离线消息等）
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb		接收消息的回调函数, nim_talk_receive_cb_func回调函数定义见nim_talk_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 */
NIM_SDK_DLL_API void nim_talk_reg_receive_msgs_cb(const char* json_extension,
    nim_talk_receive_cb_func cb,
    const void* user_data);

/** @fn void nim_talk_reg_notification_filter_cb(const char *json_extension, nim_talk_team_notification_filter_func cb,
 * const void *user_data) (全局回调)注册接收群通知是否需要过滤的回调
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb		nim_talk_team_notification_filter_func回调函数定义见nim_talk_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_talk_reg_notification_filter_cb(const char* json_extension,
    nim_talk_team_notification_filter_func cb,
    const void* user_data);

/** @fn char *nim_talk_create_retweet_msg(const char* src_msg_json, const char* client_msg_id, enum NIMSessionType
 * retweet_to_session_type, const char* retweet_to_session_id, const char* msg_setting, int64_t timetag)
 * 由其他消息生成转发消息
 *  @param[in] src_msg_json 原消息json
 *  @param[in] client_msg_id 新的客户端消息id,建议uuid
 *  @param[in] retweet_to_session_type 转发目标会话类型 NIMSessionType
 *  @param[in] retweet_to_session_id 转发目标ID
 *  @param[in] msg_setting 消息属性设置
 *  @param[in] timetag 消息时间
 *  @return char * 位置消息Json字符串,需要上层调用nim_global.h提供的内存释放接口释放。
 */
NIM_SDK_DLL_API char* nim_talk_create_retweet_msg(const char* src_msg_json,
    const char* client_msg_id,
    enum NIMSessionType retweet_to_session_type,
    const char* retweet_to_session_id,
    const char* msg_setting,
    int64_t timetag);

/** @fn void nim_talk_recall_msg(const char *json_msg, const char *notify, const char *json_extension,
 *nim_talk_recall_msg_func cb, const void *user_data) 撤回消息
 * @param[in] json_msg		消息体Json string (Keys SEE MORE `nim_talk_def.h` 『消息结构 Json Keys』)
 * @param[in] notify		自定义通知
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb		nim_talk_recall_msg_func回调函数定义见nim_talk_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				414:参数错误
 *				508:撤回时间超过配制有效期，默认是2分钟
 *				10414:本地错误码，参数错误
 *				10508:本地错误码,超过配置有效期或者所需参数不存在
 */
NIM_SDK_DLL_API void nim_talk_recall_msg(const char* json_msg,
    const char* notify,
    const char* json_extension,
    nim_talk_recall_msg_func cb,
    const void* user_data);

/** @fn void nim_talk_reg_recall_msg_cb(const char *json_extension, nim_talk_recall_msg_func cb, const void *user_data)
 * (全局回调)注册接收消息撤回通知的回调
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb		nim_talk_recall_msg_func回调函数定义见nim_talk_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 */
NIM_SDK_DLL_API void nim_talk_reg_recall_msg_cb(const char* json_extension,
    nim_talk_recall_msg_func cb,
    const void* user_data);

/** @fn char *nim_talk_get_attachment_path_from_msg(const char *json_msg)
 * 从消息的json字符串中获取附件（图片、语音、视频等）的本地路径
 * @param[in] json_msg	消息体Json string (Keys SEE MORE `nim_talk_def.h` 『消息结构 Json Keys』)
 * @return	 char *		消息如果有附件，不管是否已下载，返回附件的本地路径；消息如果没有附件，返回空字符串""。
 */
NIM_SDK_DLL_API char* nim_talk_get_attachment_path_from_msg(const char* json_msg);

/** @fn void nim_talk_reg_receive_broadcast_cb(const char *json_extension, nim_talk_receive_broadcast_cb_func cb, const
 *void *user_data) (全局回调)注册接收广播消息回调 （建议全局注册，统一接受回调后分发消息到具体的会话）
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb		接收消息的回调函数, nim_talk_receive_broadcast_cb_func回调函数定义见nim_talk_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				10414:本地错误码，参数错误
 *				10417:本地错误码，对象已经存在/重复操作
 */
NIM_SDK_DLL_API void nim_talk_reg_receive_broadcast_cb(const char* json_extension,
    nim_talk_receive_broadcast_cb_func cb,
    const void* user_data);

/** @fn void nim_talk_reg_receive_broadcast_msgs_cb(const char *json_extension, nim_talk_receive_broadcast_cb_func cb,
 * const void *user_data) 注册接收批量广播消息回调
 * （如果在注册了接收消息回调的同时也注册了该批量接口，当有批量消息时，会改走这个接口通知应用层，例如登录后接收到的离线消息等）
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb		接收消息的回调函数, nim_talk_receive_broadcast_cb_func回调函数定义见nim_talk_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 */
NIM_SDK_DLL_API void nim_talk_reg_receive_broadcast_msgs_cb(const char* json_extension,
    nim_talk_receive_broadcast_cb_func cb,
    const void* user_data);

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_API_NIM_TALK_H_
