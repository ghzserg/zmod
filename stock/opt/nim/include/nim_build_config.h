/** @file nim_build_config.h
 * @brief 编译和平台设置定义
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Harrison
 * @date 2015/2/1
 */

#ifndef NIM_SDK_UTIL_NIM_BUILD_CONFIG_H_
#define NIM_SDK_UTIL_NIM_BUILD_CONFIG_H_

// Windows or Unix-like(POSIX) macro definition.
#if defined(WIN32) || defined(_WIN32) || defined(_WIN32_WCE)
#define NIMAPI_UNDER_WINDOWS 1
#if defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP || WINAPI_FAMILY == WINAPI_FAMILY_APP)
#define NIMAPI_UNDER_WINDOWS_RT 1
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
#define NIMAPI_UNDER_WINDOWS_PHONE 1
#endif
#endif
#else
#define NIMAPI_UNDER_POSIX 1
#endif

// OS X or iOS macro definition.
#if defined(__APPLE__)
#define NIMAPI_UNDER_APPLE 1
#endif
#if defined(TARGET_OS_MAC) && TARGET_OS_MAC
#define NIMAPI_UNDER_MAC 1
#endif
#if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE
#define NIMAPI_UNDER_IPHONE 1
#endif
#if defined(TARGET_IPHONE_SIMULATOR) && TARGET_IPHONE_SIMULATOR
#define NIMAPI_UNDER_IPHONE_SIMULATOR 1
#endif

// NIM SDK (Universal SDK or Windows desktop-only SDK) API target platform macro definition.
#if defined(NIM_WIN_DESKTOP_ONLY_SDK) && (defined(NIMAPI_UNDER_WINDOWS))
#define NIMAPI_UNDER_WIN_DESKTOP_ONLY 1
#else
#define NIMAPI_UNDER_UNIVERSAL 1  // Also support Windows desktop
#endif

#endif /* NIM_SDK_UTIL_NIM_BUILD_CONFIG_H_ */
