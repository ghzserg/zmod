/** @file stdbool.h
 * @brief
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Harrison
 * @date 2015/7/23
 */

/* stdbool.h header */
/* Copyright 2003-2010 IAR Systems AB.  */

/* NOTE: IAR Extensions must be enabled in order to use the bool type! */

#ifndef _STDBOOL
#define _STDBOOL

#ifndef _SYSTEM_BUILD
#pragma warning(disable : 4068)
#pragma system_include
#endif

#ifndef __cplusplus

/* Even in pure C, we still need a standard boolean typedef */
#ifndef bool
typedef unsigned char bool;
#endif
// #define true    1
// #define false   0
#ifndef true
#define true (1)
#endif
#ifndef false
#define false (0)
#endif

// typedef int _Bool;
// #define bool _Bool
//
// #define true 1
// #define false 0

#endif /* !__cplusplus */

#define __bool_true_false_are_defined 1

#endif /* !_STDBOOL */

/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
