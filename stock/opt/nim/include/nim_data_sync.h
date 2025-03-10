/** @file nim_data_sync.h
 * @brief 数据同步 接口头文件
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Harrison
 * @date 2015/2/1
 */
#ifndef NIM_SDK_DLL_API_NIM_DATA_SYNC_H_
#define NIM_SDK_DLL_API_NIM_DATA_SYNC_H_

#include "nim_data_sync_def.h"
#include "nim_sdk_dll.h"

#ifdef __cplusplus
extern "C" {
#endif
/** @fn void nim_data_sync_reg_complete_cb(nim_data_sync_cb_func cb, const void *user_data)
 * (全局回调)注册数据同步完成的回调函数(登录时)
 * @param[in] cb 数据同步完成的回调函数， nim_data_sync_cb_func回调函数定义见nim_data_sync_def.h
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_data_sync_reg_complete_cb(nim_data_sync_cb_func cb, const void* user_data);

#ifdef __cplusplus
};
#endif  //__cplusplus

#endif  // NIM_SDK_DLL_API_NIM_DATA_SYNC_H_