/**
 * @file nim_qchat_server.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_SERVER_H__
#define __NIM_QCHAT_SERVER_H__

#include "nim_qchat_server_def.h"
#include "nim_sdk_dll.h"
// #include "public_defines.h"

#ifdef __cplusplus
extern "C" {
#endif
/** @fn void nim_qchat_server_reg_unread_cb(const NIMQChatServerRegUnreadCbParam* param)
 * @brief 注册未读数变更回调
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_server_reg_unread_cb(const NIMQChatServerRegUnreadCbParam* param);

/** @fn void nim_qchat_server_create(const NIMQChatServerCreateParam* param)
 * @brief 创建圈组服务器
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_create(const NIMQChatServerCreateParam* param);

/** @fn void nim_qchat_server_remove(const NIMQChatServerDeleteParam* param)
 * @brief 删除圈组服务器
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_remove(const NIMQChatServerDeleteParam* param);

/** @fn void nim_qchat_server_update(const NIMQChatServerUpdateParam* param)
 * @brief 更新圈组服务器信息
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_update(const NIMQChatServerUpdateParam* param);

/** @fn void nim_qchat_server_enter_as_visitor(const NIMQChatServerEnterAsVisitorParam* param)
 * @brief 以游客身份进入服务器
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_server_enter_as_visitor(const NIMQChatServerEnterAsVisitorParam* param);

/** @fn void nim_qchat_server_leave_as_visitor(const NIMQChatServerLeaveAsVisitorParam* param)
 * @brief 以游客身份离开服务器
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_server_leave_as_visitor(const NIMQChatServerLeaveAsVisitorParam* param);

/** @fn void nim_qchat_server_subscribe(const NIMQChatSubscribeParam* param)
 * @brief 订阅服务器相关信息
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_subscribe(const NIMQChatServerSubscribeParam* param);

/** @fn void nim_qchat_server_subscribe_all_channel(const NIMQChatServerSubscribeAllChannelParam* param)
 * @brief 订阅服务器下所有频道的消息
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_subscribe_all_channel(const NIMQChatServerSubscribeAllChannelParam* param);

/** @fn void nim_qchat_server_subscribe_as_visitor(const NIMQChatServerSubscribeAsVisitorParam* param)
 * @brief 以游客身份订阅服务器相关信息
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_server_subscribe_as_visitor(const NIMQChatServerSubscribeAsVisitorParam* param);

/** @fn void nim_qchat_server_mark_read(const NIMQChatServerMarkReadParam& param)
 * @brief 标记服务器下所有频道的消息为已读
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_mark_read(const NIMQChatServerMarkReadParam* param);

/** @fn void nim_qchat_server_get_servers(const NIMQChatServerGetServersParam* param)
 * @brief 查询服务器列表
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_get_servers(const NIMQChatServerGetServersParam* param);

/** @fn void nim_qchat_server_get_servers_page(const NIMQChatServerGetServersPageParam* param)
 * @brief 查询服务器列表(分页)
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_server_get_servers_page(const NIMQChatServerGetServersPageParam* param);

/** @fn void nim_qchat_server_invite(const NIMQChatServerInviteParam* param)
 * @brief 邀请用户加入服务器
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_invite(const NIMQChatServerInviteParam* param);

/** @fn void nim_qchat_server_accept_invite(const NIMQChatServerAcceptInviteParam* param)
 * @brief 接受加入服务器邀请
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_accept_invite(const NIMQChatServerAcceptInviteParam* param);

/** @fn void nim_qchat_server_reject_invite(const NIMQChatServerRejectInviteParam* param)
 * @brief 拒绝加入服务器邀请
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_reject_invite(const NIMQChatServerRejectInviteParam* param);

/** @fn void nim_qchat_server_apply(const NIMQChatServerApplyParam* param)
 * @brief 申请加入服务器
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_apply(const NIMQChatServerApplyParam* param);

/** @fn void nim_qchat_server_accept_apply(const NIMQChatServerAcceptApplyParam* param)
 * @brief 同意加入服务器申请
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_accept_apply(const NIMQChatServerAcceptApplyParam* param);

/** @fn void nim_qchat_server_reject_apply(const NIMQChatServerRejectApplyParam* param)
 * @brief 拒绝加入服务器申请
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_reject_apply(const NIMQChatServerRejectApplyParam* param);

/** @fn void nim_qchat_server_kick(const NIMQChatServerKickParam* param)
 * @brief 将指定用户踢出服务器
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_kick(const NIMQChatServerKickParam* param);

/** @fn void nim_qchat_server_leave(const NIMQChatServerLeaveParam* param)
 * @brief 离开指定服务器
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_leave(const NIMQChatServerLeaveParam* param);

/** @fn void nim_qchat_server_update_member_info(const NIMQChatServerUpdateMemberInfoParam* param)
 * @brief 更新服务器成员信息
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_update_member_info(const NIMQChatServerUpdateMemberInfoParam* param);

/** @fn void nim_qchat_server_get_members(const NIMQChatServerGetMembersParam* param)
 * @brief 查询服务器成员列表
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_get_members(const NIMQChatServerGetMembersParam* param);

/** @fn void nim_qchat_server_get_members_page(const NIMQChatServerGetMembersPageParam* param)
 * @brief 查询服务器成员列表(分页)
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_get_members_page(const NIMQChatServerGetMembersPageParam* param);

/** @fn void nim_qchat_server_ban_member(const NIMQChatServerBanMemberParam* param)
 * @brief 封禁服务器成员
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_ban_member(const NIMQChatServerBanMemberParam* param);

/** @fn void nim_qchat_server_unban_member(const NIMQChatServerUnbanMemberParam* param)
 * @brief 解封服务器成员
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_unban_member(const NIMQChatServerUnbanMemberParam* param);

/** @fn void nim_qchat_server_get_banned_members_page(const NIMQChatServerGetBannedMembersPageParam* param)
 * @brief 查询服务器封禁成员列表(分页)
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_get_banned_members_page(const NIMQChatServerGetBannedMembersPageParam* param);

/** @fn void nim_qchat_server_search_page(const NIMQChatServerSearchPageParam* param)
 * @brief 根据关键字搜索服务器(分页)
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_search_page(const NIMQChatServerSearchPageParam* param);

/** @fn void nim_qchat_server_member_search(const NIMQChatServerMemberSearchParam* param)
 * @brief 根据关键字搜索服务器成员(分页)
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_member_search(const NIMQChatServerMemberSearchParam* param);

/** @fn void nim_qchat_server_generate_invite_code(const NIMQChatServerGenerateInviteCodeParam* param)
 * @brief 生成邀请码
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_generate_invite_code(const NIMQChatServerGenerateInviteCodeParam* param);

/** @fn void nim_qchat_server_join_by_invite_code(const NIMQChatServerJoinByInviteCodeParam* param)
 * @brief 通过邀请码加入服务器
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_join_by_invite_code(const NIMQChatServerJoinByInviteCodeParam* param);

/** @fn void nim_qchat_server_get_invite_apply_record_of_server(const NIMQChatServerGetInviteApplyRecordOfServerParam*
 * param)
 * @brief 查询服务器下邀请申请历史
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_get_invite_apply_record_of_server(const
// NIMQChatServerGetInviteApplyRecordOfServerParam* param);

/** @fn void nim_qchat_server_get_invite_apply_record_by_self(const NIMQChatServerGetInviteApplyRecordOfSelfParam*
 * param)
 * @brief 查询自己邀请申请历史
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_server_get_invite_apply_record_by_self(const
// NIMQChatServerGetInviteApplyRecordOfSelfParam* param);

#ifdef __cplusplus
}
#endif

#endif  // __NIM_QCHAT_SERVER_H__
