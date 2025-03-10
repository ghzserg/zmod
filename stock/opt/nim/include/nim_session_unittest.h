#ifndef _NIM_SESSION_UNITTEST_H
#define _NIM_SESSION_UNITTEST_H

#include "nim_session_def.h"

#ifdef FTEST_TESTING_DLL_IMPORT
typedef void (
    *nim_session_reg_change_cb)(const char* json_extension, nim_session_change_cb_func cb, const void* user_data);
typedef void (*nim_session_query_all_recent_session_async)(const char* json_extension,
    nim_session_query_recent_session_cb_func cb,
    const void* user_data);
typedef void (*nim_session_delete_recent_session_async)(NIMSessionType to_type,
    const char* id,
    const char* json_extension,
    nim_session_change_cb_func cb,
    const void* user_data);
typedef void (*nim_session_delete_all_recent_session_async)(const char* json_extension,
    nim_session_change_cb_func cb,
    const void* user_data);
typedef void (*nim_session_set_unread_count_zero_async)(NIMSessionType to_type,
    const char* id,
    const char* json_extension,
    nim_session_change_cb_func cb,
    const void* user_data);
typedef void (*nim_session_set_top)(enum NIMSessionType to_type,
    const char* id,
    bool top,
    const char* json_extension,
    nim_session_change_cb_func cb,
    const void* user_data);
typedef void (*nim_session_set_extend_data)(enum NIMSessionType to_type,
    const char* id,
    const char* data,
    const char* json_extension,
    nim_session_change_cb_func cb,
    const void* user_data);
typedef void (*nim_session_reset_all_unread_count_async)(const char* json_extension,
    nim_session_change_cb_func cb,
    const void* user_data);
#else
#include "nim_session.h"
#endif

#endif  //_NIM_SESSION_UNITTEST_H
