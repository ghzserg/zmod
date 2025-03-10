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
    kNIMResError = 0,             /**< 错误 */
    kNIMResSuccess = 200,         /**< 没有错误，一切正常 */
    kNIMResVersionError = 201,    /**< 客户端版本不正确 */
    kNIMResUidPassError = 302,    /**< 用户名或密码错误 */
    kNIMResForbidden = 403,       /**< 禁止操作 */
    kNIMResNotExist = 404,        /**< 请求的目标（用户或对象）不存在 */
    kNIMResNoModify = 406,        /**< 数据自上次查询以来未发生变化（用于增量更新） */
    kNIMResTimeoutError = 408,    /**< 请求过程超时 */
    kNIMResParameterError = 414,  /**< 参数错误 */
    kNIMResConnectionError = 415, /**< 网络连接出现错误 */
    kNIMResFrequently = 416,      /**< 操作太过频繁 */
    kNIMResExist = 417,           /**< 对象已经存在/重复操作 */
    kNIMResOverrun = 419,         /**< 超限 */
    kNIMResAccountBlock = 422,    /**< 帐号被禁用 */
    kNIMResUnknownError = 500,    /**< 未知错误，或者不方便告诉你 */
    kNIMResServerDataError = 501, /**< 服务器数据错误 */
    kNIMResTooBuzy = 503,         /**< 服务器太忙 */
    kNIMResExceedLimit = 508,     /**< 超过配置有效期 */
    kNIMResInvalid = 509,         /**< 协议无效, 不允许访问的协议 */
    // 群错误码
    kNIMResTeamECountLimit = 801,     /**< 已达到人数限制 */
    kNIMResTeamENAccess = 802,        /**< 没有权限 */
    kNIMResTeamENotExist = 803,       /**< 群不存在 */
    kNIMResTeamEMemberNotExist = 804, /**< 用户不在兴趣组里面 */
    kNIMResTeamErrType = 805,         /**< 群类型不对 */
    kNIMResTeamLimit = 806,           /**< 创建群数量限制 */
    kNIMResTeamUserStatusErr = 807,   /**< 群成员状态不对 */
    kNIMResTeamApplySuccess = 808,    /**< 申请成功 */
    kNIMResTeamAlreadyIn = 809,       /**< 已经在群里 */
    kNIMResTeamInviteSuccess = 810,   /**< 邀请成功 */
    kNIMResForcePushCountLimit = 811, /**< 强推列表账号数量超限 */
    kNIMResTeamMemberLimit = 813,     /**< 操作成功，但部分成员的群数量超限 */
    // 数据解编错误代码
    kNIMResInvalidProtocol = 997, /**< 协议已失效 */
    kNIMResEUnpacket = 998,       /**< 解包错误 */
    kNIMResEPacket = 999,         /**< 打包错误 */
    //
    kNIMResInBlack = 7101, /**< 被接收方加入黑名单 SDK版本大于2.5.0支持*/

    // 独立信令错误代码
    kNIMResRoomNotExists = 10404,                  /**< 房间不存在 */
    kNIMResRoomHasExists = 10405,                  /**< 房间已存在 */
    kNIMResRoomMemberNotExists = 10406,            /**< 不在房间内 */
    kNIMResRoomMemberHasExists = 10407,            /**< 已经在房间内 */
    kNIMResRoomInviteNotExists = 10408,            /**< 邀请不存在或已过期 */
    kNIMResRoomInviteHasReject = 10409,            /**< 邀请已经拒绝 */
    kNIMResRoomInviteHasAccept = 10410,            /**< 邀请已经接受了 */
    kNIMResPeerNimOffline = 10201,                 /**< 对方云信不在线 */
    kNIMResPeerPushOffline = 10202,                /**< 对方推送亦不可达 */
    kNIMResRoomUidConflict = 10417,                /**< uid冲突 */
    kNIMResRoomMemberExceed = 10419,               /**< 房间人数超限 */
    kNIMResRoomMemberHasExistsOtherClient = 10420, /**< 已经在房间内（自己的其他端） */

    // 客户端自定义的错误号
    kNIMLocalRes = 10000, /**< 值大于该错误号的都是客户端自定义的错误号。不能随意更改其值！ */
    kNIMResRoomLocalNeedRequestAgain = 10001, /**< 客户端本地错误号，需要重新向IM服务器获取进入聊天室权限 */
    kNIMLocalResNetworkError = 10010, /**< 客户端本地错误号，本地网络错误，需要检查本地网络 */

    // 客户端自定义的消息错误号
    kNIMLocalResMsgNosUploadCancel = 10200, /**< (发送文件消息或者stop_upload_ex)HTTP upload to NOS上传暂停 */
    kNIMLocalResMsgNosDownloadCancel = 10206, /**< (收到文件消息或者stop_download_ex)HTTP download from NOS下载暂停 */
    kNIMLocalResMsgNosDownloadCheckError =
        10207, /**< 收到文件消息，NOS下载完成后本地文件检查错误，一般为下载的文件大小与文件信息不符 */
    kNIMLocalResMsgFileNotExist = 10404, /**< 本地资源不存在 */
    kNIMLocalResParameterError = 10414, /**< 本地错误码，参数错误，(收到消息，资源下载地址无效，无法下载) */
    kNIMLocalResExist = 10417, /**< 本地错误码，对象已经存在/重复操作，(收到消息，本地资源已存在，不需要重复下载) */
    kNIMLocalResParaError = 10450,         /**< 调用api，传入的参数有误 */
    kNIMLocalResMsgSendNosError = 10502,   /**< 发送消息，上传NOS失败 */
    kNIMLocalResExceedLimit = 10508,       /**< 本地错误码,超过配置有效期或者所需参数不存在 */
    kNIMLocalResCheckMsgDBFailed = 10600,  /**< 导入消息历史时验证身份和加密密钥不通过 */
    kNIMLocalResImportMsgDBFailed = 10601, /**< 导入消息历史时写记录失败 */
    // 客户端自定义的RTS错误号
    kNIMLocalResRtsError = 11100,           /**< rts会话 未知错误 */
    kNIMLocalResRtsIdNotExist = 11101,      /**< rts会话 id不存在 */
    kNIMLocalResRtsVChatExist = 11417,      /**< rts会话 音视频已存在 */
    kNIMLocalResRtsStatusError = 11501,     /**< rts会话 通道状态不正确 */
    kNIMLocalResRtsChannelNotExist = 11510, /**< rts会话 通道不存在 */

    kNIMResRoomLinkError = 13001,  /**< 主链接错误 */
    kNIMResRoomError = 13002,      /**< 聊天室状态异常 */
    kNIMResRoomBlackBeOut = 13003, /**< 黑名单用户禁止进入 */
    kNIMResRoomBeMuted = 13004,    /**< 被禁言 */
    kNIMResRoomAllMuted = 13006,   /**< 聊天室处于整体禁言状态,只有管理员能发言 */

    // 客户端自定义的api调用问题
    kNIMLocalResAPIErrorInitUndone = 20000,   /**< 还未初始化或初始化未正常完成 */
    kNIMLocalResAPIErrorLoginUndone = 20001,  /**< 还未登陆或登录未完成 */
    kNIMLocalResAPIErrorLogined = 20002,      /**< 已经登录 */
    kNIMLocalResAPIErrorVersionError = 20003, /**< SDK版本不对，可能会引发其他问题 */
    kNIMLocalResAPIErrorChatroomMixError = 20004, /**< 聊天室模式混用错误，不支持同时以登陆状态和匿名状态登陆聊天室 */
};

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_EXPORT_HEADERS_NIM_RES_CODE_DEF_H_