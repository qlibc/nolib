/* QlibC (c) Charlie Gordon 2014-2021 */

#ifndef _QLIBC_STRINGS_H
#define _QLIBC_STRINGS_H

#include <_types/_size_t.h>

int strcasecmp(const char *s1, const char *s2);
int strncasecmp(const char *s1, const char *s2, size_t n);
int ffs(int value);
int ffsl(long value);
int ffsll(long long value);
int fls(int value);
int flsl(long value);
int flsll(long long value);

#endif /* _QLIBC_STRINGS_H */
