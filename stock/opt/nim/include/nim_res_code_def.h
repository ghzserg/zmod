/** @file nim_res_code_def.h
 * @brief NIM SDK提供给外部使用的错误号定义（包含客户端自定义和服务器返回的所有错误号）
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Harrison
 * @date 2015/2/1
 */

#ifndef NIM_SDK_DLL_EXPORT_HEADERS_NIM_RES_CODE_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_NIM_RES_CODE_DEF_H_

#ifdef __cplusplus
extern "C" {
#endif
/** @enum NIMResCode 返回的错误号（只定义需要客户端处理的） */
enum NIMResCode {
    // 通用错误码
    /// 错误
    kNIMResError = 0,
    /// 没有错误，一切正常
    kNIMResSuccess = 200,
    /// 客户端版本不正确
    kNIMResVersionError = 201,
    /// 用户名或密码错误
    kNIMResUidPassError = 302,
    /// 错误请求
    kNIMResBadRequest = 400,
    /// 禁止操作
    kNIMResForbidden = 403,
    /// 请求的目标（用户或对象）不存在
    kNIMResNotExist = 404,
    /// 数据自上次查询以来未发生变化（用于增量更新）
    kNIMResNoModify = 406,
    /// 请求过程超时
    kNIMResTimeoutError = 408,
    /// 参数错误
    kNIMResParameterError = 414,
    /// 网络连接出现错误
    kNIMResConnectionError = 415,
    /// 操作太过频繁
    kNIMResFrequently = 416,
    /// 对象已经存在/重复操作
    kNIMResExist = 417,
    /// 超限
    kNIMResOverrun = 419,
    /// 帐号被禁用
    kNIMResAccountBlock = 422,
    /// 未知错误，或者不方便告诉你
    kNIMResUnknownError = 500,
    /// 服务器数据错误
    kNIMResServerDataError = 501,
    /// 服务器太忙
    kNIMResTooBuzy = 503,
    /// 超过配置有效期
    kNIMResExceedLimit = 508,
    /// 协议无效, 不允许访问的协议
    kNIMResInvalid = 509,
    // 批量标记会话已读时间戳部分成功
    kNIMResBatchMarkReadPartSuccess = 700,
    // 群错误码
    /// 已达到人数限制
    kNIMResTeamECountLimit = 801,
    /// 没有权限
    kNIMResTeamENAccess = 802,
    /// 群不存在
    kNIMResTeamENotExist = 803,
    /// 用户不在兴趣组里面
    kNIMResTeamEMemberNotExist = 804,
    /// 群类型不对
    kNIMResTeamErrType = 805,
    /// 创建群数量限制
    kNIMResTeamLimit = 806,
    /// 群成员状态不对
    kNIMResTeamUserStatusErr = 807,
    /// 申请成功
    kNIMResTeamApplySuccess = 808,
    /// 已经在群里
    kNIMResTeamAlreadyIn = 809,
    /// 邀请成功
    kNIMResTeamInviteSuccess = 810,
    /// 强推列表账号数量超限
    kNIMResForcePushCountLimit = 811,
    /// 操作成功，但部分成员的群数量超限
    kNIMResTeamMemberLimit = 813,
    /// 批量查询群信息部分成功
    kNIMResTeamGetInfoListPartSuccess = 816,
    // 数据解编错误代码
    /// 协议已失效
    kNIMResInvalidProtocol = 997,
    /// 解包错误
    kNIMResEUnpacket = 998,
    /// 打包错误
    kNIMResEPacket = 999,
    /// 被接收方加入黑名单 SDK版本大于2.5.0支持
    kNIMResInBlack = 7101,
    // 独立信令错误代码
    /// 房间不存在
    kNIMResRoomNotExists = 10404,
    /// 房间已存在
    kNIMResRoomHasExists = 10405,
    /// 不在房间内
    kNIMResRoomMemberNotExists = 10406,
    /// 已经在房间内
    kNIMResRoomMemberHasExists = 10407,
    /// 邀请不存在或已过期
    kNIMResRoomInviteNotExists = 10408,
    /// 邀请已经拒绝
    kNIMResRoomInviteHasReject = 10409,
    /// 邀请已经接受了
    kNIMResRoomInviteHasAccept = 10410,
    /// 对方云信不在线
    kNIMResPeerNimOffline = 10201,
    /// 对方推送亦不可达
    kNIMResPeerPushOffline = 10202,
    /// uid冲突
    kNIMResRoomUidConflict = 10417,
    /// 房间人数超限
    kNIMResRoomMemberExceed = 10419,
    /// 已经在房间内（自己的其他端）
    kNIMResRoomMemberHasExistsOtherClient = 10420,

    // 客户端自定义的错误号
    /// 值大于该错误号的都是客户端自定义的错误号。不能随意更改其值！
    kNIMLocalRes = 10000,
    /// 客户端本地错误号，需要重新向IM服务器获取进入聊天室权限
    kNIMResRoomLocalNeedRequestAgain = 10001,
    /// 客户端本地错误号，本地网络错误，需要检查本地网络
    kNIMLocalResNetworkError = 10010,

    // 客户端自定义的消息错误号
    /// (发送文件消息或者stop_upload_ex)HTTP upload to NOS上传暂停
    kNIMLocalResMsgNosUploadCancel = 10200,
    /// (收到文件消息或者stop_download_ex)HTTP download from NOS下载暂停
    kNIMLocalResMsgNosDownloadCancel = 10206,
    /// 收到文件消息，NOS下载完成后本地文件检查错误，一般为下载的文件大小与文件信息不符
    kNIMLocalResMsgNosDownloadCheckError = 10207,
    /// 无访问权限
    kNIMLocalResMsgAccessDenied = 10403,
    /// 本地资源不存在
    kNIMLocalResMsgFileNotExist = 10404,
    /// 本地错误码，参数错误
    kNIMLocalResParameterError = 10414,
    /// 本地错误码，操作太过频繁
    kNIMLocalResFrequently = 10416,
    /// 本地错误码，对象已经存在/重复操作，(收到消息，本地资源已存在，不需要重复下载)
    kNIMLocalResExist = 10417,
    /// 调用api，传入的参数有误
    kNIMLocalResParaError = 10450,
    /// 发送消息，上传NOS失败
    kNIMLocalResMsgSendNosError = 10502,
    /// 附件资源上传或下载失败
    kNIMLocalResTransferAttachmentError = 10503,
    /// 本地错误码,超过配置有效期或者所需参数不存在
    kNIMLocalResExceedLimit = 10508,
    /// 导入消息历史时验证身份和加密密钥不通过
    kNIMLocalResCheckMsgDBFailed = 10600,
    /// 导入消息历史时写记录失败
    kNIMLocalResImportMsgDBFailed = 10601,
    /// 群成员尚同步完成
    kNIMLocalResTMembersSyncUndone = 10602,
    // 客户端自定义的RTS错误号
    /// rts会话 未知错误
    kNIMLocalResRtsError = 11100,
    /// rts会话 id不存在
    kNIMLocalResRtsIdNotExist = 11101,
    /// rts会话 音视频已存在
    kNIMLocalResRtsVChatExist = 11417,
    /// rts会话 通道状态不正确
    kNIMLocalResRtsStatusError = 11501,
    /// rts会话 通道不存在
    kNIMLocalResRtsChannelNotExist = 11510,
    /// 主链接错误
    kNIMResRoomLinkError = 13001,
    /// 聊天室状态异常
    kNIMResRoomError = 13002,
    /// 黑名单用户禁止进入
    kNIMResRoomBlackBeOut = 13003,
    /// 被禁言
    kNIMResRoomBeMuted = 13004,
    /// 聊天室处于整体禁言状态,只有管理员能发言
    kNIMResRoomAllMuted = 13006,
    // 客户端自定义的api调用问题
    /// 还未初始化或初始化未正常完成
    kNIMLocalResAPIErrorInitUndone = 20000,
    /// 还未登陆或登录未完成
    kNIMLocalResAPIErrorLoginUndone = 20001,
    /// 已经登录
    kNIMLocalResAPIErrorLogined = 20002,
    /// SDK版本不对，可能会引发其他问题
    kNIMLocalResAPIErrorVersionError = 20003,
    /// 聊天室模式混用错误，不支持同时以登陆状态和匿名状态登陆聊天室
    kNIMLocalResAPIErrorChatroomMixError = 20005,
    /// 登录失败，超过重试次数
    kNIMLocalResAPIErrorLoginExceedRetryCount = 20006,
    /// 连接地址用完了
    kNIMLocalResAPIErrorRunOutOfLinkAddress = 20007,
};

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_EXPORT_HEADERS_NIM_RES_CODE_DEF_H_