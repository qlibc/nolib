/* QlibC (c) Charlie Gordon 2014-2021 */

/* 7.24 String handling <string.h> */

#ifndef _QLIBC_STRING_H
#define _QLIBC_STRING_H

/* 7.24.1 String function conventions */
#include <_types/_size_t.h>
#define NULL    ((void*)0)

/* 7.24.2 Copying functions */
void *memcpy(void *s1, const void *s2, size_t n);
void *memmove(void *s1, const void *s2, size_t n);
char *strcpy(char *s1, const char *s2);
char *strncpy(char *s1, const char *s2, size_t n);

/* 7.24.3 Concatenation functions */
char *strcat(char *s1, const char *s2);
char *strncat(char *s1, const char *s2, size_t n);

/* 7.24.4 Comparison functions */
int memcmp(const void *s1, const void *s2, size_t n);
int strcmp(const char *s1, const char *s2);
int strcoll(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
size_t strxfrm(char *s1, const char *s2, size_t n);

/* 7.24.5 Search functions */
void *memchr(const void *s, int c, size_t n);
char *strchr(const char *s, int c);
size_t strcspn(const char *s1, const char *s2);
char *strpbrk(const char *s1, const char *s2);
char *strrchr(const char *s, int c);
size_t strspn(const char *s1, const char *s2);
char *strstr(const char *s1, const char *s2);
char *strtok(char *s1, const char *s2);

/* 7.24.6 Miscellaneous functions */
void *memset(void *s, int c, size_t n);
char *strerror(int errnum);
size_t strlen(const char *s);

/* Non Standard functions */
size_t strnlen(const char *s, size_t n);
/* WDTR 24731-2 compatibility */
/* should be controlled by #ifdef __STDC_WANT_LIB_EXT2__ */
char *strdup(const char *s);
char *strndup(const char *s, size_t n);

extern char *sys_errlist[];
extern int sys_nerr;

/* K.3.7 String handling */
#ifdef __STDC_WANT_LIB_EXT1__
#if __STDC_WANT_LIB_EXT1__
#include <_types/_errno_t.h>
#include <_types/_rsize_t.h>

/* K.3.7.1 Copying functions */
errno_t memcpy_s(void *s1, rsize_t s1max, const void *s2, rsize_t n);
errno_t memmove_s(void *s1, rsize_t s1max, const void *s2, rsize_t n);
errno_t strcpy_s(char *s1, rsize_t s1max, const char *s2);
errno_t strncpy_s(char *s1, rsize_t s1max, const char *s2, rsize_t n);

/* K.3.7.2 Concatenation functions */
errno_t strcat_s(char *s1, rsize_t s1max, const char *s2);
errno_t strncat_s(char *s1, rsize_t s1max, const char *s2, rsize_t n);

/* K.3.7.3 Search functions */
char *strtok_s(char *s1, rsize_t *s1max, const char *s2, char **ptr);

/* K.3.7.4 Miscellaneous functions */
errno_t memset_s(void *s, rsize_t smax, int c, rsize_t n);
errno_t strerror_s(char *s, rsize_t maxsize, errno_t errnum);
size_t strerrorlen_s(errno_t errnum);
size_t strnlen_s(const char *s, size_t maxsize);
#endif
#endif

char *strcasestr(const char *s1, const char *s2);

#ifdef _GNU_SOURCE
void *memccpy(void *dest, const void *src, int c, size_t n);
void *mempcpy(void *dest, const void *src, size_t n);
void *memrchr(const void *ptr, int c, size_t n);
char *stpcpy(char *dest, const char *src);
char *stpncpy(char *s1, const char *s2, size_t n);
int strverscmp(const char *s1, const char *s2);
#endif

#ifdef _BSD_SOURCE
#define bcmp(p1,p2,n)  memcmp(p1,p2,n)
#define bcpy(p1,p2,n)  memcpy(p1,p2,n)
#define bzero(p1,n)    memset(p1,0,n)
#endif

void explicit_bzero(void *dst, size_t size);
int timingsafe_bcmp(const void *s1, const void *s2, size_t n);
int timingsafe_memcmp(const void *s1, const void *s2, size_t n);
void *memmem(const void *s1, size_t size1, const void *s2, size_t size2);
size_t strlcpy(char *dst, const char *src, size_t n);
size_t strlcat(char *dst, const char *src, size_t n);
char *strnstr(const char *s1, const char *s2, size_t n);
char *strsep(char **stringp, const char *delim);
char *strsignal(int sig);
char *strtok_r(char *s, const char *delim, char **context);

#endif /* _QLIBC_STRING_H */
