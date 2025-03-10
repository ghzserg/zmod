/** @file nim_friend_def.h
 * @brief 好友 接口相关的常量函数等定义头文件
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Oleg
 * @date 2015/08/13
 */
#ifndef NIM_SDK_DLL_EXPORT_HEADERS_FRIEND_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_FRIEND_DEF_H_

#ifdef __cplusplus
extern "C" {
#endif

static const char* kNIMFriendKey = "list"; /**< 好友简况 json array, */

/** @name 好友简况 Json Keys
 * 例子 {"list" : [{"accid" : "litianyi01","beflag" : 1,"bits" : 0,"create_timetag" : 1439871983864,"flag" : 1,"source"
 * : 0,"update_timetag" : 1439872006079}, ...]}
 * @{
 */
// 协议定义
static const char* kNIMFriendKeyAccid = "accid"; /**< string, 好友帐号*/
static const char* kNIMFriendKeyFlag = "flag"; /**< NIMFriendFlag, 好友关系，修改时需要同步更新反向好友关系beflag */
static const char* kNIMFriendKeyBeFlag = "beflag"; /**< NIMFriendFlag, 反向好友关系 */
static const char* kNIMFriendKeySource = "source"; /**< NIMFriendSource, 好友来源 */
static const char* kNIMFriendKeyAlias = "alias";   /**< string, 备注名 */
static const char* kNIMFriendKeyBits = "bits";     /**< long, 扩展字段,位运算型 */
static const char* kNIMFriendKeyEx = "ex"; /**< string, 扩展字段,必须为可以解析为json的非格式化的字符串 */
static const char* kNIMFriendKeyCreateTime = "create_timetag"; /**< long, 创建时间戳(ms)*/
static const char* kNIMFriendKeyUpdateTime = "update_timetag"; /**< long, 更新时间戳(ms)*/
static const char* kNIMFriendServerEx = "server_ex"; /**< string, 服务端扩展字段，此字段客户端sdk只读，服务端api读写*/
/** @}*/                                             // 好友简况 Json Keys

/** @enum NIMFriendFlag 好友类型  */
enum NIMFriendFlag {
    kNIMFriendFlagNotFriend = 0, /**< 陌生人 */
    kNIMFriendFlagNormal = 1,    /**< 普通好友 */
};

/** @enum NIMFriendSource 好友来源 */
enum NIMFriendSource {
    kNIMFriendSourceDefault = 0, /**< 默认 */
};

/** @enum NIMVerifyType 好友验证方式 */
enum NIMVerifyType {
    kNIMVerifyTypeAdd = 1,    /**< 直接加好友 */
    kNIMVerifyTypeAsk = 2,    /**< 请求加好友 */
    kNIMVerifyTypeAgree = 3,  /**< 同意 */
    kNIMVerifyTypeReject = 4, /**< 拒绝 */
};

/** @enum NIMFriendChangeType 好友数据变化类型 */
enum NIMFriendChangeType {
    kNIMFriendChangeTypeRequest = 1,  /**< 加好友/处理好友请求 */
    kNIMFriendChangeTypeDel = 2,      /**< 删除好友 */
    kNIMFriendChangeTypeUpdate = 3,   /**< 更新好友 */
    kNIMFriendChangeTypeSyncList = 5, /**< 好友列表同步与更新 */
};

/** @typedef void (*nim_friend_opt_cb_func)(int res_code, const char *json_extension, const void *user_data)
 * 好友操作（添加、删除、更新）的回调函数定义
 * @param[out] res_code		结果代码，一切正常200
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_friend_opt_cb_func)(int res_code, const char* json_extension, const void* user_data);

/** @typedef void (*nim_friend_get_list_cb_func)(int res_code, const char *friend_list_json, const char *json_extension,
 * const void *user_data) 增量获取好友列表的回调函数定义
 * @param[out] res_code		结果代码，一切正常200
 * @param[out] friend_list_json		好友列表和好友资料Json字符串（{"list":[a , b , ...]}）
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_friend_get_list_cb_func)(int res_code,
    const char* friend_list_json,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_friend_get_profile_cb_func)(const char *accid, const char *friend_profile_json, const char
 * *json_extension, const void *user_data) 获取好友信息的回调函数定义
 * @param[out] accid		好友ID
 * @param[out] friend_profile_json		好友简况
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_friend_get_profile_cb_func)(const char* accid,
    const char* friend_profile_json,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_friend_change_cb_func)(NIMFriendChangeType type, const char *result_json ,const char
 * *json_extension, const void *user_data) 好友数据变化（添加、删除、更新）的监听回调函数定义
 * @param[out] type		NIMFriendChangeType，数据变化类型
 * @param[out] result_json		同步内容，kNIMFriendChangeTypeAdd: {"accid" : "abc", "type" : "NIMVerifyType", "msg"
 * : "msg"} , kNIMFriendChangeTypeDel: {"accid" : "abc"}, kNIMFriendChangeTypeUpdate: {"info" : 好友简况 Json value },
 * kNIMFriendChangeTypeSyncList: {"list":[a , b , ...]}
 * @param[out] json_extension	json扩展数据（备用）
 * @param[out] user_data		APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_friend_change_cb_func)(enum NIMFriendChangeType type,
    const char* result_json,
    const char* json_extension,
    const void* user_data);

#ifdef __cplusplus
}
#endif

#endif  // NIM_SDK_DLL_EXPORT_HEADERS_FRIEND_DEF_H_
