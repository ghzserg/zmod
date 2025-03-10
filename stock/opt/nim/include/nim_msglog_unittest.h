#ifndef _NIM_MSGLOG_UNITTEST_H
#define _NIM_MSGLOG_UNITTEST_H

#include "nim_msglog_def.h"

#ifdef FTEST_TESTING_DLL_IMPORT

typedef void (*nim_msglog_query_msg_async)(const char* account_id,
    NIMSessionType to_type,
    int limit_count,
    int64_t last_time,
    const char* json_extension,
    nim_msglog_query_cb_func cb,
    const void* user_data);
typedef void (*nim_msglog_batch_status_read_async)(const char* account_id,
    NIMSessionType to_type,
    const char* json_extension,
    nim_msglog_res_ex_cb_func cb,
    const void* user_data);
typedef void (*nim_msglog_set_status_async)(const char* msg_id,
    NIMMsgLogStatus msglog_status,
    const char* json_extension,
    nim_msglog_res_cb_func cb,
    const void* user_data);
typedef void (*nim_msglog_set_sub_status_async)(const char* msg_id,
    NIMMsgLogSubStatus msglog_sub_status,
    const char* json_extension,
    nim_msglog_res_cb_func cb,
    const void* user_data);
typedef void (*nim_msglog_batch_status_delete_async)(const char* account_id,
    NIMSessionType to_type,
    const char* json_extension,
    nim_msglog_res_ex_cb_func cb,
    const void* user_data);
typedef void (*nim_msglog_insert_msglog_async)(const char* talk_id,
    const char* json_msg,
    bool need_update_session,
    const char* json_extension,
    nim_msglog_res_cb_func cb,
    const void* user_data);
typedef void (*nim_msglog_delete_by_session_type_async)(bool delete_sessions,
    NIMSessionType to_type,
    const char* json_extension,
    nim_msglog_res_ex_cb_func cb,
    const void* user_data);
typedef void (*nim_msglog_delete_async)(const char* account_id,
    NIMSessionType to_type,
    const char* msg_id,
    const char* json_extension,
    nim_msglog_res_cb_func cb,
    const void* user_data);
typedef void (*nim_msglog_delete_all_async)(bool delete_sessions,
    const char* json_extension,
    nim_msglog_modify_res_cb_func cb,
    const void* user_data);
typedef void (*nim_msglog_query_msg_online_async)(const char* id,
    NIMSessionType to_type,
    int limit_count,
    int64_t from_time,
    int64_t end_time,
    int64_t end_msg_id,
    bool reverse,
    bool need_save_to_local,
    const char* json_extension,
    nim_msglog_query_cb_func cb,
    const void* user_data);
typedef void (*nim_msglog_query_msg_by_id_async)(const char* client_msg_id,
    const char* json_extension,
    nim_msglog_query_single_cb_func cb,
    const void* user_data);
typedef void (*nim_msglog_query_msg_by_options_async)(NIMMsgLogQueryRange query_range,
    const char* ids,
    int limit_count,
    int64_t from_time,
    int64_t end_time,
    const char* end_client_msg_id,
    bool reverse,
    NIMMessageType msg_type,
    const char* search_content,
    const char* json_extension,
    nim_msglog_query_cb_func cb,
    const void* user_data);
typedef void (*nim_msglog_update_localext_async)(const char* msg_id,
    const char* local_ext,
    const char* json_extension,
    nim_msglog_res_cb_func cb,
    const void* user_data);

typedef void (*nim_msglog_export_db_async)(const char* dst_path,
    const char* json_extension,
    nim_msglog_modify_res_cb_func cb,
    const void* user_data);
typedef void (*nim_msglog_import_db_async)(const char* src_path,
    const char* json_extension,
    nim_msglog_modify_res_cb_func res_cb,
    const void* res_user_data,
    nim_msglog_import_prg_cb_func prg_cb,
    const void* prg_user_data);

typedef void (*nim_msglog_send_receipt_async)(const char* json_msg,
    const char* json_extension,
    nim_msglog_status_changed_cb_func cb,
    const void* user_data);
typedef bool (*nim_msglog_query_be_readed)(const char* json_msg, const char* json_extension);
typedef bool (*nim_msglog_query_receipt_sent)(const char* json_msg, const char* json_extension);
typedef void (*nim_msglog_reg_status_changed_cb)(const char* json_extension,
    nim_msglog_status_changed_cb_func cb,
    const void* user_data);
typedef void (
    *nim_msglog_read_all_async)(const char* json_extension, nim_msglog_modify_res_cb_func cb, const void* user_data);

typedef void (*nim_msglog_query_the_message_of_the_specified_type_async)(enum NIMSessionType to_type,
    const char* id,
    int limit_count,
    int64_t from_time,
    int64_t end_time,
    const char* end_client_msg_id,
    bool reverse,
    const char* msg_types,
    const char* json_extension,
    nim_msglog_query_cb_func cb,
    const void* user_data);
#else
#include "nim_msglog.h"
#endif

#endif  //_NIM_MSGLOG_UNITTEST_H
