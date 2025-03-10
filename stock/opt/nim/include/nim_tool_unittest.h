#ifndef _NIM_TOOL_UNITTEST_H
#define _NIM_TOOL_UNITTEST_H

#include "nim_tools_def.h"

#ifdef FTEST_TESTING_DLL_IMPORT
typedef const char* (*nim_tool_get_user_appdata_dir)(const char* app_account);
typedef const char* (
    *nim_tool_get_user_specific_appdata_dir)(const char* app_account, enum NIMAppDataType appdata_type);
typedef const char* (*nim_tool_get_local_appdata_dir)();
typedef const char* (*nim_tool_get_cur_module_dir)();
typedef const char* (*nim_tool_get_md5)(const char* input);
typedef const char* (*nim_tool_get_file_md5)(const char* file_path);
typedef const char* (*nim_tool_get_uuid)();
typedef void (*nim_tool_get_audio_text_async)(const char* json_audio_info,
    const char* json_extension,
    nim_tool_get_audio_text_cb_func cb,
    const void* user_data);
typedef int (*nim_tool_is_text_matched_keywords)(char* text, char* lib_name);
typedef char* (*nim_tool_replace_text_matched_keywords)(char* text, char* replace_str, char* lib_name);
#else
#include "nim_tools.h"
#endif

#endif  //_NIM_TOOL_UNITTEST_H
