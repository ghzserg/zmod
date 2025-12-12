/** @file nim_base_types.h
 * @brief SDK基本类型定义
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Harrison
 * @date 2015/2/1
 */

#ifndef NIM_SDK_UTIL_NIM_BASE_TYPES_H_
#define NIM_SDK_UTIL_NIM_BASE_TYPES_H_

#include <sys/types.h>

#ifndef _MSC_VER
// stdint.h is part of C99 but MSVC doesn't have it.
#include <stdint.h>  // For intptr_t.
#endif

/* define int types*/
#if defined(__GNUC__)

#ifndef _STDINT_H

/* FreeBSD has these C99 int types defined in /sys/inttypes.h already */
#ifndef _SYS_TYPES_H
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long long int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
#else
typedef u_int8_t uint8_t;
typedef u_int16_t uint16_t;
typedef u_int32_t uint32_t;
typedef u_int64_t uint64_t;
#endif  // _SYS_TYPES_H

#endif  // _STDINT_H

#elif defined(_MSC_VER)
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed __int64 int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned __int64 uint64_t;

/* the following definitions are from VS2010's stdint.h */
#ifndef _INTPTR_T_DEFINED
#define _INTPTR_T_DEFINED
#ifdef _WIN64
typedef __int64 intptr_t;
#else  /* _WIN64 */
typedef int intptr_t;
#endif /* _WIN64 */
#endif /* _INTPTR_T_DEFINED */

#ifndef _UINTPTR_T_DEFINED
#define _UINTPTR_T_DEFINED
#ifdef _WIN64
typedef unsigned __int64 uintptr_t;
#else  /* _WIN64 */
typedef unsigned int uintptr_t;
#endif /* _WIN64 */
#endif /* _UINTPTR_T_DEFINED */

#endif  // COMPILER_GCC/COMPILER_MSVC

// const uint8_t  kUint8Max  = (( uint8_t) 0xFF);
// const uint16_t kUint16Max = ((uint16_t) 0xFFFF);
// const uint32_t kUint32Max = ((uint32_t) 0xFFFFFFFF);
// const uint64_t kUint64Max = ((uint64_t) GG_LONGLONG(0xFFFFFFFFFFFFFFFF));
// const int8_t   kInt8Min   = ((  int8_t) 0x80);
// const int8_t   kInt8Max   = ((  int8_t) 0x7F);
// const int16_t  kInt16Min  = (( int16_t) 0x8000);
// const int16_t  kInt16Max  = (( int16_t) 0x7FFF);
// const int32_t  kInt32Min  = (( int32_t) 0x80000000);
// const int32_t  kInt32Max  = (( int32_t) 0x7FFFFFFF);
// const int64_t  kInt64Min  = (( int64_t) GG_LONGLONG(0x8000000000000000));
// const int64_t  kInt64Max  = (( int64_t) GG_LONGLONG(0x7FFFFFFFFFFFFFFF));

#endif  // NIM_SDK_UTIL_NIM_BASE_TYPES_H_
