#ifndef __NIM_NOS_UNITTEST_H__
#define __NIM_NOS_UNITTEST_H__

#include "nim_nos_def.h"

#ifdef FTEST_TESTING_DLL_IMPORT
typedef void (*nim_nos_reg_download_cb)(nim_nos_download_cb_func cb, const void* user_data);
typedef void (*nim_nos_reg_upload_cb)(nim_nos_upload_cb_func cb, const void* user_data);
typedef void (*nim_nos_download_media)(const char* json_msg,
    nim_nos_download_cb_func callback_result,
    const void* download_user_data,
    nim_nos_download_prg_cb_func prg_cb,
    const void* prg_user_data);
typedef void (*nim_nos_download_media_ex)(const char* json_msg,
    const char* json_extension,
    nim_nos_download_cb_func callback_result,
    const void* download_user_data,
    nim_nos_download_prg_cb_func prg_cb,
    const void* prg_user_data,
    nim_nos_download_speed_cb_func speed_cb,
    const void* speed_user_data,
    nim_nos_download_info_cb_func info_cb,
    const void* info_user_data);
typedef void (*nim_nos_stop_download_media)(const char* json_msg);
typedef void (*nim_nos_upload)(const char* local_file,
    nim_nos_upload_cb_func callback_result,
    const void* res_user_data,
    nim_nos_upload_prg_cb_func prg_cb,
    const void* prg_user_data);
typedef void (*nim_nos_upload_ex)(const char* local_file,
    const char* json_extension,
    nim_nos_upload_cb_func callback_result,
    const void* res_user_data,
    nim_nos_upload_prg_cb_func prg_cb,
    const void* prg_user_data,
    nim_nos_upload_speed_cb_func speed_cb,
    const void* speed_user_data,
    nim_nos_upload_info_cb_func info_cb,
    const void* info_user_data);
typedef void (*nim_nos_stop_upload_ex)(const char* task_id, const char* json_extension);
typedef void (*nim_nos_download)(const char* nos_url,
    nim_nos_download_cb_func callback_result,
    const void* res_user_data,
    nim_nos_download_prg_cb_func prg_cb,
    const void* prg_user_data);
typedef void (*nim_nos_download_ex)(const char* nos_url,
    const char* json_extension,
    nim_nos_download_cb_func callback_result,
    const void* res_user_data,
    nim_nos_download_prg_cb_func prg_cb,
    const void* prg_user_data,
    nim_nos_download_speed_cb_func speed_cb,
    const void* speed_user_data,
    nim_nos_download_info_cb_func info_cb,
    const void* info_user_data);
typedef void (*nim_nos_stop_download_ex)(const char* task_id, const char* json_extension);
#else
#include "nim_nos.h"
#endif

#endif  //__NIM_NOS_UNITTEST_H__
