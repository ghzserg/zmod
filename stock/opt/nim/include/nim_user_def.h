/** @file nim_user_def.h
 * @brief 用户数据 接口相关的常量函数等定义头文件
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Harrison
 * @date 2015/2/1
 */

#ifndef NIM_SDK_DLL_EXPORT_HEADERS_NIM_USER_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_NIM_USER_DEF_H_

#include "nim_global_def.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @enum NIMUserSpecialRelationshipChangeType 用户特殊关系数据变更类型 */
enum NIMUserSpecialRelationshipChangeType {
    kNIMUserSpecialRelationshipChangeTypeMarkBlack = 1,            /**< 添加删除黑名单 */
    kNIMUserSpecialRelationshipChangeTypeMarkMute = 2,             /**< 添加删除静音名单 */
    kNIMUserSpecialRelationshipChangeTypeSyncMuteAndBlackList = 3, /**< 同步黑名单和静音名单 */
};

/** @name 用户特殊关系（黑名单、静音名单） Json Keys
 * 例子 [{"accid" : "litianyi01","is_mute" : 1},{"accid" : "litianyi03","is_black" : 1},...]
 * @{
 */
// 协议定义
static const char* kNIMSpecialRelationKeyAccid = "accid";               /**< string, 用户帐号 */
static const char* kNIMSpecialRelationKeyIsMute = "is_mute";            /**< bool, 是静音帐号 */
static const char* kNIMSpecialRelationKeyIsBlackList = "is_black";      /**< bool, 是黑名单帐号 */
static const char* kNIMSpecialRelationKeyCreateTime = "create_timetag"; /**< long, 记录创建时间 */
static const char* kNIMSpecialRelationKeyUpdateTime = "update_timetag"; /**< long, 记录更新时间 */
/** @}*/  // 用户特殊关系（黑名单、静音名单） Json Keys

/** @name 用户名片 Json Keys
 * 例子  { "accid" : "litianyi01", "create_timetag" : 1430101821372, "gender" : 0, "name" : "oleg01", "update_timetag" :
 * 1430101821372 }
 * @{
 */
// 协议定义
static const char* kNIMNameCardKeyAccid = "accid";   /**< string 帐号*/
static const char* kNIMNameCardKeyName = "name";     /**< string 昵称*/
static const char* kNIMNameCardKeyIcon = "icon";     /**< string 头像*/
static const char* kNIMNameCardKeySign = "sign";     /**< string 签名*/
static const char* kNIMNameCardKeyGender = "gender"; /**< int 性别*/
static const char* kNIMNameCardKeyEmail = "email";   /**< string 邮箱*/
static const char* kNIMNameCardKeyBirth = "birth";   /**< string 生日*/
static const char* kNIMNameCardKeyMobile = "mobile"; /**< string 电话*/
static const char* kNIMNameCardKeyEx = "ex"; /**< string 扩展字段, 必须为可以解析为json的非格式化的字符串*/
static const char* kNIMNameCardKeyCreateTime = "create_timetag"; /**< long 创建时间戳 毫秒*/
static const char* kNIMNameCardKeyUpdateTime = "update_timetag"; /**< long 更新时间戳 毫秒*/
/** @}*/                                                         // 用户名片 Json Keys

/** @typedef void (*nim_user_special_relationship_change_cb_func)(enum NIMUserSpecialRelationshipChangeType type, const
 * char *result_json ,const char *json_extension, const void *user_data)
 * 用户多端同步类型（黑名单、静音名单）的监听回调函数定义
 * @param[out] type		NIMUserSpecialRelationshipChangeType，用户多端同步类型
 * @param[out] result_json		同步内容，kNIMUserSpecialRelationshipChangeTypeMarkBlack: {"accid" : "abc", "black"
 * : bool} , kNIMUserSpecialRelationshipChangeTypeMarkMute: {"accid" : "abc", "mute" : bool},
 * kNIMUserSpecialRelationshipChangeTypeSyncMuteAndBlackList: {a, b, c ...}(a,b,c为json value array -
 * 用户特殊关系（黑名单、静音名单） Json Keys)
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_user_special_relationship_change_cb_func)(enum NIMUserSpecialRelationshipChangeType type,
    const char* result_json,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_user_opt_cb_func)(int res_code, const char *id, bool opt, const char *json_extension, const void
 * *user_data) 用户操作（加黑或取消加黑，加静音或取消静音）的回调函数定义
 * @param[out] res_code		结果代码，一切正常200
 * @param[out] accid		好友id
 * @param[out] opt		mark（加黑或取消加黑，加静音或取消静音）
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_user_opt_cb_func)(int res_code,
    const char* accid,
    bool opt,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_user_sync_muteandblacklist_cb_func)(int res_code, const char *black_list_json, const char
 * *json_extension, const void *user_data) 获取黑名单、静音列表
 * @param[out] res_code		结果代码，一切正常200
 * @param[out] black_list_json		黑名单和静音列表Json字符串（{a , b , ...}(a,b,c为json value array -
 * 用户特殊关系（黑名单、静音名单） Json Keys)）
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_user_sync_muteandblacklist_cb_func)(int res_code,
    const char* black_list_json,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_user_name_card_change_cb_func)(const char *result_json ,const char *json_extension, const void
 * *user_data) 用户名片的监听回调函数定义
 * @param[out] result_json	json object array 例 [{ "accid" : "litianyi01", "create_timetag" : 1430101821372,
 * "gender" : 0, "name" : "oleg01", "update_timetag" : 1430101821372 }, ...]
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (
    *nim_user_name_card_change_cb_func)(const char* result_json, const char* json_extension, const void* user_data);

/** @typedef void (*nim_user_get_user_name_card_cb_func)(const char *result_json ,const char *json_extension, const void
 * *user_data) 获取用户名片回调函数
 * @param[out] result_json json object array 例 [{ "accid" : "litianyi01", "create_timetag" : 1430101821372, "gender" :
 * 0, "name" : "oleg01", "update_timetag" : 1430101821372 }, ...]
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (
    *nim_user_get_user_name_card_cb_func)(const char* result_json, const char* json_extension, const void* user_data);

/** @typedef void (*nim_user_update_my_name_card_cb_func)(int res_code, const char *accid, const char *json_extension,
 * const void *user_data) 更新自己的用户名片回调函数
 * @param[out] res_code		结果代码，一切正常200
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_user_update_my_name_card_cb_func)(int res_code, const char* json_extension, const void* user_data);

#ifdef __cplusplus
};
#endif  //__cplusplus

#endif  // NIM_SDK_DLL_EXPORT_HEADERS_NIM_USER_DEF_H_