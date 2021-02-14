/* QlibC (c) Charlie Gordon 2014-2021 */
#ifndef _QLIBC_SIZE_T
#define _QLIBC_SIZE_T
#if defined(__LP64__)
typedef unsigned long size_t;
#else
typedef unsigned int size_t;
#endif
#endif /* _QLIBC_SIZE_T */
