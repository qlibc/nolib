/* QlibC (c) Charlie Gordon 2014-2021 */
#ifndef _QLIBC_SSIZE_T
#define _QLIBC_SSIZE_T
#if defined(__LP64__)
typedef long ssize_t;
#else
typedef int ssize_t;
#endif
#endif /* _QLIBC_SSIZE_T */
