/**
 * @file nim_qchat_message.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_MESSAGE_H__
#define __NIM_QCHAT_MESSAGE_H__

#include "nim_qchat_message_def.h"
#include "nim_sdk_dll.h"
// #include "public_defines.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @fn void nim_qchat_reg_recv_msg_cb(const NIMQChatRegRecvMsgCbParam* param)
 * @brief 注册接收消息回调
 * @param[in] param 接口参数 @see NIMQChatRegRecvMsgCbParam
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_reg_recv_msg_cb(const NIMQChatRegRecvMsgCbParam* param);

/** @fn void nim_qchat_reg_msg_updated_cb(const NIMQChatRegMsgUpdatedCbParam* param)
 * @brief 注册消息更新回调
 * @param[in] param 接口参数 @see NIMQChatRegMsgUpdatedCbParam
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_reg_msg_updated_cb(const NIMQChatRegMsgUpdatedCbParam* param);

/** @fn void nim_qchat_send_msg(const NIMQChatSendMessageParam* param)
 * @brief 发送圈组消息
 * @param[in] param 接口参数 @see NIMQChatSendMessageParam
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_send_msg(const NIMQChatSendMessageParam* param);

/** @fn void nim_qchat_update_msg(const NIMQChatUpdateMessageParam* param)
 * @brief 更新圈组消息
 * @param param 更新的消息内容 @see NIMQChatUpdateMessageParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_update_msg(const NIMQChatUpdateMessageParam* param);

/** @fn void nim_qchat_revoke_msg(const NIMQChatRevokeMessageParam* param)
 * @brief 撤回圈组消息，撤回未读消息不影响未读数
 * @param param 更新的消息内容 @see NIMQChatRevokeMessageParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_revoke_msg(const NIMQChatRevokeMessageParam* param);

/** @fn nim_qchat_delete_msg(const NIMQChatDeleteMessageParam* param)
 * @brief 删除圈组消息，删除未读消息影响未读数
 * @param param 更新的消息内容 @see NIMQChatDeleteMessageParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_delete_msg(const NIMQChatDeleteMessageParam* param);

/** @fn void nim_qchat_query_history_msg(const NIMQChatGetMessagesParam* param)
 * @brief 查询历史消息
 * @param[in] param 接口参数 @see NIMQChatGetMessagesParam
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_query_history_msg(const NIMQChatGetMessagesParam* param);

/** @fn void nim_qchat_query_history_msg_cache(const NIMQChatGetMessagesCacheParam* param)
 * @brief 从本地缓存中查询消息历史, 仅用于无网络情况或加速页面显示时使用，恢复通信后应使用GetMessages的结果进行覆盖
 *
 * @param param 要查询的服务器、频道 @see NIMQChatGetMessagesCacheParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_query_history_msg_cache(const NIMQChatGetMessagesCacheParam* param);

/** @fn void nim_qchat_get_last_messages(const NIMQChatGetLastMessagesParam* param)
 * @brief 查询频道最后一条消息
 * @param[in] param 接口参数 @see NIMQChatGetLastMessagesParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_get_last_messages(const NIMQChatGetLastMessagesParam* param);

/** @fn void nim_qchat_mark_message_read(const NIMQChatMarkMessageReadParam* param)
 * @brief 标记消息已读
 * @param[in] param 接口参数 @see NIMQChatMarkMessageReadParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_mark_message_read(const NIMQChatMarkMessageReadParam* param);

/** @fn void nim_qchat_reply_message(const NIMQChatReplyMessageParam* param)
 * @brief 回复指定消息
 * @since v9.1.0
 * @param param 接口参数 @see NIMQChatReplyMessageParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_reply_message(const NIMQChatReplyMessageParam* param);

/** @fn void nim_qchat_get_message_history_by_ids(const NIMQChatGetMessageHistoryByIdsParam* param)
 * @brief 根据一批消息 ID 查询消息详情
 * @since v9.1.0
 * @param param 接口参数 @see NIMQChatGetMessageHistoryByIdsParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_get_message_history_by_ids(const NIMQChatGetMessageHistoryByIdsParam* param);

/** void nim_qchat_get_refer_messages(const NIMQChatGetReferMessagesParam* param)
 * @brief 检索一条消息得依赖消息
 * @since v9.1.0
 * @param param 接口参数 @see NIMQChatGetReferMessagesParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_get_refer_messages(const NIMQChatGetReferMessagesParam* param);

/** void nim_qchat_get_mentioned_me_messages(const NIMQChatGetMentionedMeMessagesParam* param)
 * @brief 查询未读消息中 @ 当前用户的消息
 * @since v9.9.0
 * @param param 接口参数 @see NIMQChatGetMentionedMeMessagesParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_get_mentioned_me_messages(const NIMQChatGetMentionedMeMessagesParam* param);

/** void nim_qchat_are_mentioned_me_messages(const NIMQChatAreMentionedMeMessagesParam* param)
 * @brief 查询消息是否 @ 当前用户
 * @since v9.9.0
 * @param param 接口参数 @see NIMQChatAreMentionedMeMessagesParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_are_mentioned_me_messages(const NIMQChatAreMentionedMeMessagesParam* param);

/** @fn void nim_qchat_get_thread_messages(const NIMQChatGetThreadMessagesParam* param)
 * @brief 获取 thread 消息列表
 * @since v9.1.0
 * @param param 接口参数 @see NIMQChatGetMessagesThreadParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_get_thread_messages(const NIMQChatGetThreadMessagesParam* param);

/** @fn void nim_qchat_get_thread_root_messages_meta(const NIMQChatGetThreadRootMessagesMetaParam* param)
 * @brief 查询一批 thread root 消息的基本信息（回复数量、最后回复时间）
 * @since v9.1.0
 * @param param 接口参数 @see NIMQChatGetThreadRootMessagesMetaParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_get_thread_root_messages_meta(const NIMQChatGetThreadRootMessagesMetaParam* param);

/** @fn void nim_qchat_add_quick_comment(const NIMQChatAddQuickCommentParam* param)
 * @brief 添加快捷评论
 * @since v9.1.0
 * @param param 接口参数 @see NIMQChatAddQuickCommentParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_add_quick_comment(const NIMQChatAddQuickCommentParam* param);

/** void nim_qchat_remove_quick_comment(const NIMQChatRemoveQuickCommentParam* param)
 * @brief 移除指定快捷评论
 * @since v9.1.0
 * @param param 接口参数 @see NIMQChatRemoveQuickCommentParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_remove_quick_comment(const NIMQChatRemoveQuickCommentParam* param);

/** void nim_qchat_get_quick_comments(const NIMQChatGetQuickCommentsParam* param)
 * @brief 批量获取一个消息关联的快捷评论列表
 * @since v9.1.0
 * @param param 接口参数 @see NIMQChatGetQuickCommentsParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_get_quick_comments(const NIMQChatGetQuickCommentsParam* param);

/** void nim_qchat_search_msg_by_page(const NIMQChatMessageSearchPageParam* param)
 * @brief 消息搜索
 * @since v9.4.0
 * @param param 接口参数 @see NIMQChatMessageSearchPageParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_search_msg_by_page(const NIMQChatMessageSearchPageParam* param);

/** void nim_qchat_insert_or_replace_text_cache(const NIMQChatInsertOrReplaceTextCacheParam* param)
 * @brief 插入或更新自定义文本缓存
 * @param param 接口参数 @see NIMQChatInsertOrReplaceTextCacheParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_insert_or_replace_text_cache(const NIMQChatInsertOrReplaceTextCacheParam* param);

/** void nim_qchat_delete_text_cache(const NIMQChatDeleteTextCacheParam* param)
 * @brief 删除自定义文本缓存
 * @param param 接口参数 @see NIMQChatDeleteTextCacheParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_delete_text_cache(const NIMQChatDeleteTextCacheParam* param);

/** void nim_qchat_get_text_cache(const NIMQChatGetTextCacheParam* param)
 * @brief 获取自定义文本缓存
 * @param param 接口参数 @see NIMQChatGetTextCacheParam
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_get_text_cache(const NIMQChatGetTextCacheParam* param);

#ifdef __cplusplus
}
#endif

#endif  // __NIM_QCHAT_MESSAGE_H__
