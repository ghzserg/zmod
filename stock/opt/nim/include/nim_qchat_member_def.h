/**
 * @file nim_qchat_member_def.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_MEMBER_DEF_H__
#define __NIM_QCHAT_MEMBER_DEF_H__

#include "nim_qchat_public_def.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @struct NIMQChatMemberInfo 圈组服务器成员信息 */
typedef struct {
    /// server id
    uint64_t server_id;
    /// channel id
    uint64_t channel_id;
    /// 用户accid
    char* accid;
    /// 昵称
    char* nick;
    /// 头像url
    char* avatar;
    /// 自定义字段
    char* custom;
    /// 用户类型，0:普通用户 1:所有者
    uint32_t type;
    /// 加入时间
    uint64_t join_time;
    /// 邀请人
    char* inviter;
    /// 有效标记，false:无效 true:有效
    fcx_bool_t valid_flag;
    /// 创建时间
    uint64_t create_time;
    /// 更新时间
    uint64_t update_time;
} NIMQChatMemberInfo;

/** @struct NIMQChatMemberBanInfo 圈组服务器成员封禁信息 */
typedef struct {
    /// server id
    uint64_t server_id;
    /// 用户accid
    char* accid;
    /// 自定义字段
    char* custom;
    /// 封禁时间
    uint64_t ban_time;
    /// 有效标记，false:无效 true:有效
    fcx_bool_t valid_flag;
    /// 创建时间
    uint64_t create_time;
    /// 更新时间
    uint64_t update_time;
} NIMQChatMemberBanInfo;

#ifdef __cplusplus
}
#endif

#endif  // __NIM_QCHAT_MEMBER_DEF_H__
