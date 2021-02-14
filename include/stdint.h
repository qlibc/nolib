/* QlibC (c) Charlie Gordon 2014-2021 */

/* 7.20 Integer types <stdint.h> */

#ifndef _QLIBC_STDINT_H
#define _QLIBC_STDINT_H

#include <limits.h>
#include <_types/_wchar_t.h>

/* 7.20.1.1 Exact-width integer types */
#if SCHAR_MAX == 127
typedef signed char int8_t;
#define INT8_MIN    (-128)
#define INT8_MAX    127
#define INT8_WIDTH  8
#endif

#if UCHAR_MAX == 255
typedef unsigned char uint8_t;
#define UINT8_MAX    255
#define UINT8_WIDTH  8
#endif

#if USHRT_MAX == 0xffff
typedef short int int16_t;
typedef unsigned short int uint16_t;
#define INT16_MIN     (-32767-1)
#define INT16_MAX     32767
#define INT16_WIDTH   16
#define UINT16_MAX    0xffff
#define UINT16_WIDTH  16
#endif

#if UINT_MAX == 0xffffffff
typedef int int32_t;
typedef unsigned int uint32_t;
#define INT32_MIN     (-2147483647-1)
#define INT32_MAX     2147483647
#define INT32_WIDTH   32
#define UINT32_MAX    UINT_MAX
#define UINT32_WIDTH  32
#elif ULONG_MAX == 0xffffffff
typedef long int int32_t;
typedef unsigned long int uint32_t;
#define INT32_MIN     (-2147483647-1)
#define INT32_MAX     2147483647
#define INT32_WIDTH   32
#define UINT32_MAX    ULONG_MAX
#define UINT32_WIDTH  32
#endif

#if LLONG_MAX == 0x7fffffffffffffff
/* prefer long long over other types */
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#define INT64_MIN     LLONG_MIN
#define INT64_MAX     LLONG_MAX
#define INT64_WIDTH   64
#define UINT64_MAX    ULLONG_MAX
#define UINT64_WIDTH  64
#elif LONG_MAX == 0x7fffffffffffffff
typedef long int int64_t;
typedef unsigned long int uint64_t;
#define INT64_MIN     LONG_MIN
#define INT64_MAX     LONG_MAX
#define INT64_WIDTH   64
#define UINT64_MAX    ULONG_MAX
#define UINT64_WIDTH  64
#elif INT_MAX == 0x7fffffffffffffff
typedef int int64_t;
typedef unsigned int uint64_t;
#define INT64_MIN     INT_MIN
#define INT64_MAX     INT_MAX
#define INT64_WIDTH   64
#define UINT64_MAX    UINT_MAX
#define UINT64_WIDTH  64
#endif

/* 7.20.1.2 Minimum-width integer types */
typedef signed char int_least8_t;
typedef unsigned char uint_least8_t;
#define INT_LEAST8_MIN     SCHAR_MIN
#define INT_LEAST8_MAX     SCHAR_MAX
#define INT_LEAST8_WIDTH   SCHAR_WIDTH
#define UINT_LEAST8_MAX    UCHAR_MAX
#define UINT_LEAST8_WIDTH  UCHAR_WIDTH
#define INT8_C(value)      value
#define UINT8_C(value)     value

typedef short int int_least16_t;
typedef unsigned short int uint_least16_t;
#define INT_LEAST16_MIN     SHRT_MIN
#define INT_LEAST16_MAX     SHRT_MAX
#define INT_LEAST16_WIDTH   SHRT_WIDTH
#define UINT_LEAST16_MAX    USHRT_MAX
#define UINT_LEAST16_WIDTH  USHRT_WIDTH
#define INT16_C(value)      value
#define UINT16_C(value)     value

#if INT_MAX >= 0x7fffffff
typedef int int_least32_t;
typedef unsigned int uint_least32_t;
#define INT_LEAST32_MIN     INT_MIN
#define INT_LEAST32_MAX     INT_MAX
#define INT_LEAST32_WIDTH   INT_WIDTH
#define UINT_LEAST32_MAX    UINT_MAX
#define UINT_LEAST32_WIDTH  UINT_WIDTH
#define INT32_C(value)      value
#define UINT32_C(value)     value
#else
typedef long int int_least32_t;
typedef unsigned long int uint_least32_t;
#define INT_LEAST32_MIN     LONG_MIN
#define INT_LEAST32_MAX     LONG_MAX
#define INT_LEAST32_WIDTH   LONG_WIDTH
#define UINT_LEAST32_MAX    ULONG_MAX
#define UINT_LEAST32_WIDTH  ULONG_WIDTH
#define INT32_C(value)      value ## L
#define UINT32_C(value)     value ## UL
#endif

#if INT_MAX >= 0x7fffffffffffffff
typedef int int_least64_t;
typedef unsigned int uint_least64_t;
#define INT_LEAST64_MIN     INT_MIN
#define INT_LEAST64_MAX     INT_MAX
#define INT_LEAST64_WIDTH   INT_WIDTH
#define UINT_LEAST64_MAX    UINT_MAX
#define UINT_LEAST64_WIDTH  UINT_WIDTH
#define INT64_C(value)      value
#define UINT64_C(value)     value
#elif LONG_MAX >= 0x7fffffffffffffff
typedef long int int_least64_t;
typedef unsigned long int uint_least64_t;
#define INT_LEAST64_MIN     LONG_MIN
#define INT_LEAST64_MAX     LONG_MAX
#define INT_LEAST64_WIDTH   LONG_WIDTH
#define UINT_LEAST64_MAX    ULONG_MAX
#define UINT_LEAST64_WIDTH  ULONG_WIDTH
#define INT64_C(value)      value ## L
#define UINT64_C(value)     value ## UL
#else
typedef long long int int_least64_t;
typedef unsigned long long int uint_least64_t;
#define INT_LEAST64_MIN     LLONG_MIN
#define INT_LEAST64_MAX     LLONG_MAX
#define INT_LEAST64_WIDTH   LLONG_WIDTH
#define UINT_LEAST64_MAX    ULLONG_MAX
#define UINT_LEAST64_WIDTH  ULLONG_WIDTH
#define INT64_C(value)      value ## LL
#define UINT64_C(value)     value ## ULL
#endif

/* 7.20.1.3 Fastest minimum-width integer types */
typedef int int_fast8_t;
typedef int int_fast16_t;
typedef int_least32_t int_fast32_t;
typedef int_least64_t int_fast64_t;
typedef unsigned int uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef uint_least32_t uint_fast32_t;
typedef uint_least64_t uint_fast64_t;

#define INT_FAST8_MIN      INT_MIN
#define INT_FAST8_MAX      INT_MAX
#define INT_FAST8_WIDTH    INT_WIDTH
#define INT_FAST16_MIN     INT_MIN
#define INT_FAST16_MAX     INT_MAX
#define INT_FAST16_WIDTH   INT_WIDTH
#define INT_FAST32_MIN     INT_LEAST32_MIN
#define INT_FAST32_MAX     INT_LEAST32_MAX
#define INT_FAST32_WIDTH   INT_LEAST32_WIDTH
#define INT_FAST64_MIN     INT_LEAST64_MIN
#define INT_FAST64_MAX     INT_LEAST64_MAX
#define INT_FAST64_WIDTH   INT_LEAST64_WIDTH
#define UINT_FAST8_MAX     UINT_MAX
#define UINT_FAST8_WIDTH   UINT_WIDTH
#define UINT_FAST16_MAX    UINT_MAX
#define UINT_FAST16_WIDTH  UINT_WIDTH
#define UINT_FAST32_MAX    UINT_LEAST32_MAX
#define UINT_FAST32_WIDTH  UINT_LEAST32_WIDTH
#define UINT_FAST64_MAX    UINT_LEAST64_MAX
#define UINT_FAST64_WIDTH  UINT_LEAST64_WIDTH

/* 7.20.1.4 Integer types capable of holding object pointers */
#if defined(__SUBC__)
typedef int intptr_t;
typedef unsigned int uintptr_t;
#define INTPTR_MIN     INT_MIN
#define INTPTR_MAX     INT_MAX
#define INTPTR_WIDTH   INT_WIDTH
#define UINTPTR_MAX    UINT_MAX
#define UINTPTR_WIDTH  UINT_WIDTH
#elif defined(__LP64__)
typedef long intptr_t;
typedef unsigned long uintptr_t;
#define INTPTR_MIN     LONG_MIN
#define INTPTR_MAX     LONG_MAX
#define INTPTR_WIDTH   LONG_WIDTH
#define UINTPTR_MAX    ULONG_MAX
#define UINTPTR_WIDTH  ULONG_WIDTH
#else
typedef int intptr_t;
typedef unsigned int uintptr_t;
#define INTPTR_MIN     INT_MIN
#define INTPTR_MAX     INT_MAX
#define INTPTR_WIDTH   INT_WIDTH
#define UINTPTR_MAX    UINT_MAX
#define UINTPTR_WIDTH  UINT_WIDTH
#endif

/* 7.20.1.5 Greatest-width integer types */
typedef long long int intmax_t;
typedef unsigned long long int uintmax_t;

#define INTMAX_MIN        LLONG_MIN
#define INTMAX_MAX        LLONG_MAX
#define INTMAX_WIDTH      LLONG_WIDTH
#define UINTMAX_MAX       ULLONG_MAX
#define UINTMAX_WIDTH     ULLONG_WIDTH
#define INTMAX_C(value)   value ## LL
#define UINTMAX_C(value)  value ## ULL

/* 7.20.3 Limits of other integer types */
#define PRTDIFF_MIN    INTPTR_MIN
#define PTRDIFF_MAX    INTPTR_MAX
#define PTRDIFF_WIDTH  INTPTR_WIDTH
#define SIZE_MAX       UINTPTR_MAX
#define SIZE_WIDTH     UINTPTR_WIDTH
#define WCHAR_MIN      INT_MIN  /* XXX: incorrect for Windows */
#define WCHAR_MAX      INT_MAX
#define WCHAR_WIDTH    INT_WIDTH
#define WINT_MIN       INT_MIN
#define WINT_MAX       INT_MAX
#define WINT_WIDTH     INT_WIDTH

/* K.3.4 Integer types */
#ifdef __STDC_WANT_LIB_EXT1__
#if __STDC_WANT_LIB_EXT1__
#define RSIZE_MAX    INTPTR_MAX
#define RSIZE_WIDTH  INTPTR_WIDTH
#endif
#endif

#endif /* _QLIBC_STDINT_H */
