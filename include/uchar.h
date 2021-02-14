/* QlibC (c) Charlie Gordon 2014-2021 */

/* 7.28 Unicode utilities <uchar.h> */

#ifndef _QLIBC_UCHAR_H
#define _QLIBC_UCHAR_H

#include <_types/_mbstate_t.h>
#include <_types/_size_t.h>

typedef unsigned short char16_t; /* same as uint_least16_t */
typedef unsigned int char32_t;   /* same as uint_least32_t */

/* 7.28.1 Restartable multibyte/wide character conversion functions */
size_t mbrtoc16(char16_t *pc16, const char *s, size_t n, mbstate_t *ps);
size_t c16rtomb(char *s, char16_t c16, mbstate_t *ps);
size_t mbrtoc32(char32_t *pc32, const char *s, size_t n, mbstate_t *ps);
size_t c32rtomb(char *s, char32_t c32, mbstate_t *ps);

#endif /* _QLIBC_UCHAR_H */
