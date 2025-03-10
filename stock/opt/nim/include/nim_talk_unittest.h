#ifndef __NIM_TALK_UNITTEST_H__
#define __NIM_TALK_UNITTEST_H__

#include "nim_global_def.h"
#include "nim_nos_def.h"
#include "nim_session_def.h"
#include "nim_talk_def.h"

#ifdef FTEST_TESTING_DLL_IMPORT
typedef void (*nim_talk_reg_ack_cb)(const char* json_extension, nim_talk_ack_cb_func cb, const void* user_data);
typedef void (*nim_talk_send_msg)(const char* json_msg,
    const char* json_extension,
    nim_nos_upload_prg_cb_func prg_cb,
    const void* prg_user_data);
typedef void (*nim_talk_stop_send_msg)(const char* json_msg, const char* json_extension);
typedef void (*nim_talk_reg_receive_cb)(const char* json_extension, nim_talk_receive_cb_func cb, const void* user_data);
typedef void (
    *nim_talk_reg_receive_msgs_cb)(const char* json_extension, nim_talk_receive_cb_func cb, const void* user_data);
typedef void (*nim_talk_reg_notification_filter_cb)(const char* json_extension,
    nim_talk_team_notification_filter_func cb,
    const void* user_data);
typedef char* (*nim_talk_create_retweet_msg)(const char* src_msg_json,
    const char* client_msg_id,
    const NIMSessionType retweet_to_session_type,
    const char* retweet_to_session_id,
    const char* msg_setting,
    int64_t timetag);
typedef void (*nim_talk_recall_msg)(const char* json_msg,
    const char* notify,
    const char* json_extension,
    nim_talk_recall_msg_func cb,
    const void* user_data);
typedef void (
    *nim_talk_reg_recall_msg_cb)(const char* json_extension, nim_talk_recall_msg_func cb, const void* user_data);
typedef char* (*nim_talk_get_attachment_path_from_msg)(const char* json_msg);
typedef void (*nim_talk_reg_receive_broadcast_cb)(const char* json_extension,
    nim_talk_receive_broadcast_cb_func cb,
    const void* user_data);
typedef void (*nim_talk_reg_receive_broadcast_msgs_cb)(const char* json_extension,
    nim_talk_receive_broadcast_cb_func cb,
    const void* user_data);

#else
#include "nim_talk.h"
#endif

#endif  //__NIM_TALK_UNITTEST_H__
