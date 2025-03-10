/** @file nim_data_sync_def.h
 * @brief 数据同步 接口相关的常量函数等定义头文件
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Harrison
 * @date 2015/2/1
 */

#ifndef NIM_SDK_DLL_EXPORT_HEADERS_DATA_SYNC_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_DATA_SYNC_DEF_H_

#ifdef __cplusplus
extern "C" {
#endif
/** @enum NIMDataSyncType 数据同步类型 */
enum NIMDataSyncType {
    kNIMDataSyncTypeUnreadMsg = 2, /**< 未读消息同步*/
    kNIMDataSyncTypeTeamInfo = 3,  /**< 所有群的信息同步, json_attachment为同步到的team_info json array*/
    kNIMDataSyncTypeRoamMsg = 7,   /**< 漫游消息同步,每个会话同步到漫游消息都会触发该类通知*/
    kNIMDataSyncTypeTeamUserList = 1000,    /**< 群成员列表同步, json_attachment为同步到的tid*/
    kNIMDataSyncTypeAllTeamUserList = 1001, /**< 所有群的成员列表同步完毕, json_attachment为空*/
};

/** @enum NIMDataSyncStatus 数据同步状态 */
enum NIMDataSyncStatus {
    kNIMDataSyncStatusComplete = 1, /**< 同步完成*/
};

/** @typedef void (*nim_data_sync_cb_func)(NIMDataSyncType sync_type, NIMDataSyncStatus status, const char
 * *json_attachment, const void *user_data) nim callback function that has been registered in
 * nim_data_sync_reg_complete_cb API
 * @param[out] sync_type 数据同步类型
 * @param[out] status 数据同步状态
 * @param[out] json_attachment 输出的json字符串内容
 * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_data_sync_cb_func)(enum NIMDataSyncType sync_type,
    enum NIMDataSyncStatus status,
    const char* json_attachment,
    const void* user_data);

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_EXPORT_HEADERS_DATA_SYNC_DEF_H_