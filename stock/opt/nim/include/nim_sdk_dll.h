/** @file nim_sdk_dll.h
 * @brief 定义导出宏
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Harrison
 * @date 2015/7/23
 */

// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 NIM_SDK_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// NIM_SDK_DLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。

// 该文件只定义导出宏，不定义其他任何东西！modified by HarrisonFeng, 2015.7.23

#if !defined(__GNUC__) && defined(NIM_SDK_EXPORTS)
#define NIM_SDK_DLL_API __declspec(dllexport)
#elif !defined(__GNUC__) && !defined(NIM_SDK_EXPORTS)
#define NIM_SDK_DLL_API __declspec(dllimport)
#elif defined(__GNUC__) && defined(NIM_SDK_EXPORTS)
#define NIM_SDK_DLL_API __attribute__((visibility("default")))
#else
#define NIM_SDK_DLL_API
#endif
