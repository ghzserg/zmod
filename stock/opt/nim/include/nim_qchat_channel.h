/**
 * @file nim_qchat_channel.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_CHANNEL_H__
#define __NIM_QCHAT_CHANNEL_H__

#include "nim_qchat_channel_def.h"
#include "nim_sdk_dll.h"
// #include "public_defines.h"

#ifdef __cplusplus
extern "C" {
#endif
/** @fn void nim_qchat_channel_reg_unread_cb(const NIMQChatChannelRegUnreadCbParam* param)
 * @brief 注册未读数变更回调
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_channel_reg_unread_cb(const NIMQChatChannelRegUnreadCbParam* param);

/** @fn void nim_qchat_channel_create(const NIMQChatChannelCreateParam* param)
 * @brief 创建频道
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_create(const NIMQChatChannelCreateParam* param);

/** @fn void nim_qchat_channel_remove(const NIMQChatChannelDeleteParam* param)
 * @brief 删除频道
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_remove(const NIMQChatChannelDeleteParam* param);

/** @fn void nim_qchat_channel_update(const NIMQChatChannelUpdateParam* param)
 * @brief 更新频道
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_update(const NIMQChatChannelUpdateParam* param);

/** @fn void nim_qchat_channel_update_category_info(const NIMQChatChannelUpdateCategoryInfoParam* param)
 * @brief 更新频道的分组信息
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_update_category_info(const NIMQChatChannelUpdateCategoryInfoParam* param);

/** @fn void nim_qchat_channel_subscribe(const NIMQChatSubscribeParam* param)
 * @brief 订阅频道相关信息
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_subscribe(const NIMQChatChannelSubscribeParam* param);

/** @fn void nim_qchat_channel_subscribe_as_visitor(const NIMQChatChannelSubscribeAsVisitorParam* param)
 * @brief 以游客身份订阅频道相关信息
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_channel_subscribe_as_visitor(const NIMQChatChannelSubscribeAsVisitorParam* param);

/** @fn void nim_qchat_channel_query_unread_info(const NIMQChatChannelQueryUnreadInfoParam* param)
 * @brief 查询未读消息数
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_query_unread_info(const NIMQChatChannelQueryUnreadInfoParam* param);

/** @fn void nim_qchat_channel_get_channels(const NIMQChatChannelGetChannelsParam* param)
 * @brief 查询频道列表
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_get_channels(const NIMQChatChannelGetChannelsParam* param);

/** @fn void nim_qchat_channel_get_channels_page(const NIMQChatChannelGetChannelsPageParam* param)
 * @brief 查询频道列表(分页)
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_channel_get_channels_page(const NIMQChatChannelGetChannelsPageParam* param);

/** @fn void nim_qchat_channel_get_members_page(const NIMQChatChannelGetMembersPageParam* param)
 * @brief 查询频道列表(分页)
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_get_members_page(const NIMQChatChannelGetMembersPageParam* param);

/** @fn void nim_qchat_channel_update_white_black_role(const NIMQChatChannelUpdateWhiteBlackRoleParam* param)
 * @brief 更新频道白/黑名单身份组，公开频道:黑名单，私有频道:白名单
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_update_white_black_role(const NIMQChatChannelUpdateWhiteBlackRoleParam*
// param);

/** @fn void nim_qchat_channel_update_white_black_members(const NIMQChatChannelUpdateWhiteBlackMembersParam* param)
 * @brief 更新频道白/黑名单成员，公开频道:黑名单，私有频道:白名单
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_update_white_black_members(const NIMQChatChannelUpdateWhiteBlackMembersParam*
// param);

/** @fn void nim_qchat_channel_get_white_black_roles_page(const NIMQChatChannelGetWhiteBlackRolesPageParam* param)
 * @brief 查询频道白/黑名单身份组列表(分页)
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_get_white_black_roles_page(const NIMQChatChannelGetWhiteBlackRolesPageParam*
// param);

/** @fn void nim_qchat_channel_get_white_black_members_page(const NIMQChatChannelGetWhiteBlackMembersPageParam* param)
 * @brief 查询频道白/黑名单成员列表(分页)
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_get_white_black_members_page(const
// NIMQChatChannelGetWhiteBlackMembersPageParam* param);

/** @fn void nim_qchat_channel_get_existing_white_black_roles(const NIMQChatChannelGetExistingWhiteBlackRolesParam*
 * param)
 * @brief 根据身份组ID查询已存在的白/黑名单身份组
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_get_existing_white_black_roles(const
// NIMQChatChannelGetExistingWhiteBlackRolesParam* param);

/** @fn void nim_qchat_channel_get_existing_white_black_members(const NIMQChatChannelGetExistingWhiteBlackMembersParam*
 * param)
 * @brief 根据成员ID查询已存在的白/黑名单成员
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_get_existing_white_black_members(const
// NIMQChatChannelGetExistingWhiteBlackMembersParam* param);

/** @fn void nim_qchat_channel_search_page(const NIMQChatChannelSearchPageParam* param)
 * @brief 根据关键字搜索频道(分页)
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_search_page(const NIMQChatChannelSearchPageParam* param);

/** @fn void nim_qchat_channel_member_search_page(const NIMQChatChannelMemberSearchParam* param)
 * @brief 根据关键字搜索频道成员
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_member_search_page(const NIMQChatChannelMemberSearchParam* param);

/** @fn void nim_qchat_channel_update_rtc_info(const NIMQChatChannelUpdateRTCInfoParam* param)
 * @brief 更新频道RTC信息
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_update_rtc_info(const NIMQChatChannelUpdateRTCInfoParam* param);

/** @fn void nim_qchat_channel_get_rtc_info(const NIMQChatChannelGetRTCInfoParam* param)
 * @brief 获取频道RTC信息
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_get_rtc_info(const NIMQChatChannelGetRTCInfoParam* param);

/** @fn void nim_qchat_channel_get_rtc_online_members(const NIMQChatChannelGetRTCOnlineMembersParam* param)
 * @brief 获取频道RTC在线成员
 * @param[in] param 接口参数
 * @return void
 */
// NIM_SDK_DLL_API void nim_qchat_channel_get_rtc_online_members(const NIMQChatChannelGetRTCOnlineMembersParam* param);
#ifdef __cplusplus
}
#endif

#endif  // __NIM_QCHAT_CHANNEL_H__
