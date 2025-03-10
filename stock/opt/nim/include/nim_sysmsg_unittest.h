#ifndef _NIM_SYSMSG_UNITTEST_H
#define _NIM_SYSMSG_UNITTEST_H

#include "nim_sysmsg_def.h"

#ifdef FTEST_TESTING_DLL_IMPORT
typedef void (
    *nim_sysmsg_reg_sysmsg_cb)(const char* json_extension, nim_sysmsg_receive_cb_func cb, const void* user_data);
typedef void (*nim_sysmsg_query_msg_async)(int limit_count,
    int64_t last_time,
    const char* json_extension,
    nim_sysmsg_query_cb_func cb,
    const void* user_data);
typedef void (
    *nim_sysmsg_query_unread_count)(const char* json_extension, nim_sysmsg_res_cb_func cb, const void* user_data);
typedef void (*nim_sysmsg_set_status_async)(int64_t msg_id,
    NIMSysMsgStatus status,
    const char* json_extension,
    nim_sysmsg_res_ex_cb_func cb,
    const void* user_data);
typedef void (*nim_sysmsg_read_all_async)(const char* json_extension, nim_sysmsg_res_cb_func cb, const void* user_data);
typedef void (*nim_sysmsg_delete_async)(int64_t msg_id,
    const char* json_extension,
    nim_sysmsg_res_ex_cb_func cb,
    const void* user_data);
typedef void (
    *nim_sysmsg_delete_all_async)(const char* json_extension, nim_sysmsg_res_cb_func cb, const void* user_data);
typedef void (*nim_sysmsg_reg_custom_notification_ack_cb)(const char* json_extension,
    nim_custom_sysmsg_ack_cb_func cb,
    const void* user_data);
typedef void (*nim_sysmsg_send_custom_notification)(const char* json_msg, const char* json_extension);
typedef void (*nim_sysmsg_set_logs_status_by_type_async)(NIMSysMsgType type,
    NIMSysMsgStatus status,
    const char* json_extension,
    nim_sysmsg_res_cb_func cb,
    const void* user_data);
typedef void (*nim_sysmsg_delete_logs_by_type_async)(NIMSysMsgType type,
    const char* json_extension,
    nim_sysmsg_res_cb_func cb,
    const void* user_data);
#else
#include "nim_sysmsg.h"
#endif

#endif  //_NIM_SYSMSG_UNITTEST_H
