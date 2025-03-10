/** @file nim_user.h
 * @brief 用户数据 接口头文件
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Harrison
 * @date 2015/2/1
 */
#ifndef NIM_SDK_DLL_API_NIM_USER_H_
#define NIM_SDK_DLL_API_NIM_USER_H_

#include "nim_sdk_dll.h"
#include "nim_user_def.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @fn void nim_user_reg_special_relationship_changed_cb(const char *json_extension,
 * nim_user_special_relationship_change_cb_func cb, const void *user_data)
 * (全局回调)统一注册用户属性变更通知回调函数（本地、多端同步黑名单、静音名单变更）
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 操作结果回调
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_user_reg_special_relationship_changed_cb(const char* json_extension,
    nim_user_special_relationship_change_cb_func cb,
    const void* user_data);

/** @fn void nim_user_set_black(const char *accid, bool set_black, const char *json_extension, nim_user_opt_cb_func cb,
 *const void *user_data) 设置、取消设置黑名单
 * @param[in] accid 好友id
 * @param[in] set_black 取消或设置
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 操作结果回调
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				419:黑名单数量超过上限
 */
NIM_SDK_DLL_API void nim_user_set_black(const char* accid,
    bool set_black,
    const char* json_extension,
    nim_user_opt_cb_func cb,
    const void* user_data);

/** @fn void nim_user_set_mute(const char *accid, bool set_mute, const char *json_extension, nim_user_opt_cb_func cb,
 *const void *user_data) 设置、取消设置静音名单
 * @param[in] accid 好友id
 * @param[in] set_mute 取消或设置
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 操作结果回调
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				419:静音列表数量超过上限
 */
NIM_SDK_DLL_API void nim_user_set_mute(const char* accid,
    bool set_mute,
    const char* json_extension,
    nim_user_opt_cb_func cb,
    const void* user_data);

/** @fn void nim_user_get_mute_blacklist(const char *json_extension, nim_user_sync_muteandblacklist_cb_func cb, const
 * void *user_data) 获得黑名单/静音名单
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 操作结果回调
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 */
NIM_SDK_DLL_API void nim_user_get_mute_blacklist(const char* json_extension,
    nim_user_sync_muteandblacklist_cb_func cb,
    const void* user_data);

/** @fn void nim_user_reg_user_name_card_changed_cb(const char *json_extension, nim_user_name_card_change_cb_func cb,
 * const void *user_data) (全局回调)统一注册用户名片变更通知回调函数
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 操作结果回调
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_user_reg_user_name_card_changed_cb(const char* json_extension,
    nim_user_name_card_change_cb_func cb,
    const void* user_data);

/** @fn void nim_user_get_user_name_card(const char *accids, const char *json_extension,
 *nim_user_get_user_name_card_cb_func cb, const void *user_data) 获取本地的指定帐号的用户名片
 * @param[in] accids 例 ["litianyi01", "litianyi02", ...]
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 操作结果回调
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				414:参数错误
 *				20000:还未初始化或初始化未正常完成
 *				20001:还未登陆或登录未完成
 */
NIM_SDK_DLL_API void nim_user_get_user_name_card(const char* accids,
    const char* json_extension,
    nim_user_get_user_name_card_cb_func cb,
    const void* user_data);

/** @fn void nim_user_get_user_name_card_online(const char *accids, const char *json_extension,
 *nim_user_get_user_name_card_cb_func cb, const void *user_data) 在线查询指定帐号的用户名片
 * @param[in] accids 例 ["litianyi01", "litianyi02", ...]
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 操作结果回调
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				414:参数错误
 *				419:超限
 *				20000:还未初始化或初始化未正常完成
 *				20001:还未登陆或登录未完成
 */
NIM_SDK_DLL_API void nim_user_get_user_name_card_online(const char* accids,
    const char* json_extension,
    nim_user_get_user_name_card_cb_func cb,
    const void* user_data);

/** @fn void nim_user_update_my_user_name_card(const char *info_json, const char *json_extension,
 *nim_user_update_my_name_card_cb_func cb, const void *user_data) 更新自己的用户名片
 * @param[in] info_json 用户信息json
 * @param[in] json_extension json扩展参数（备用，目前不需要）
 * @param[in] cb 操作结果回调
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 * @note 错误码	200:成功
 *				400:非法参数
 */
NIM_SDK_DLL_API void nim_user_update_my_user_name_card(const char* info_json,
    const char* json_extension,
    nim_user_update_my_name_card_cb_func cb,
    const void* user_data);

/** @fn void nim_user_update_push_token(const char* cer_name, const char* token, int type)
 * 更新推送证书和Token (Andorid/iOS)
 * @param[in] cer_name 在云信管理后台配置的推送证书名
 * @param[in] token 推送Token
 * @param[in] type 1表示pushkit,0表示apns
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_user_update_push_token(const char* cer_name, const char* token, int type);

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_API_NIM_USER_H_