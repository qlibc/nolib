/* QlibC (c) Charlie Gordon 2014-2021 */

/* 7.19 Common definitions <stddef.h> */

#ifndef _QLIBC_STDDEF_H
#define _QLIBC_STDDEF_H

#if defined(__SUBC__)
typedef int ptrdiff_t;
#elif defined(__LP64__)
typedef long ptrdiff_t;
#else
typedef int ptrdiff_t;
#endif

#include <_types/_size_t.h>
typedef long long int max_align_t;
#include <_types/_wchar_t.h>

#define NULL  ((void*)0)
#define offsetof(type, member)  ((size_t)(&((type*)0)->member))

/* K.3.3 Common definitions */
#ifdef __STDC_WANT_LIB_EXT1__
#if __STDC_WANT_LIB_EXT1__
#include <_types/_rsize_t.h>
#endif
#endif

#endif /* _QLIBC_STDDEF_H */
