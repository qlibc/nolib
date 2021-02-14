/* QlibC (c) Charlie Gordon 2014-2021 */

/* 7.29 Extended multibyte and wide character utilities <wchar.h> */

#ifndef _QLIBC_WCHAR_H
#define _QLIBC_WCHAR_H

#include <stdarg.h>     /* va_arg */
#include <stdio.h>      /* FILE */
#include <time.h>       /* struct tm */

/* 7.29.1 Introduction: macros and types */
#include <_types/_wchar_t.h>
#include <_types/_size_t.h>
#include <_types/_mbstate_t.h>
#include <_types/_wint_t.h>

#define NULL  ((void*)0)
#define WCHAR_MIN  INT_MIN
#define WCHAR_MAX  INT_MAX
#define WEOF  ((wint_t)-1)

/* 7.29.2 Formatted wide character input/output functions */
int fwprintf(FILE *stream, const wchar_t *format, ...);
int fwscanf(FILE *stream, const wchar_t *format, ...);
int swprintf(wchar_t *s, size_t n, const wchar_t *format, ...);
int swscanf(const wchar_t *s, const wchar_t *format, ...);
int vfwprintf(FILE *stream, const wchar_t *format, va_list arg);
int vfwscanf(FILE *stream, const wchar_t *format, va_list arg);
int vswprintf(wchar_t *s, size_t n, const wchar_t *format, va_list arg);
int vswscanf(const wchar_t *s, const wchar_t *format, va_list arg);
int vwprintf(const wchar_t *format, va_list arg);
int vwscanf(const wchar_t *format, va_list arg);
int wprintf(const wchar_t *format, ...);
int wscanf(const wchar_t *format, ...);

/* 7.29.3 Wide character input/output functions */
wint_t fgetwc(FILE *stream);
wchar_t *fgetws(wchar_t *s, int n, FILE *stream);
wint_t fputwc(wchar_t c, FILE *stream);
int fputws(const wchar_t *s, FILE *stream);
int fwide(FILE *stream, int mode);
wint_t getwc(FILE *stream);
wint_t getwchar(void);
wint_t putwc(wchar_t c, FILE *stream);
wint_t putwchar(wchar_t c);
wint_t ungetwc(wint_t c, FILE *stream);

/* 7.29.4 General wide string utilities */
/* 7.29.4.1 Wide string numeric conversion functions */
double wcstod(const wchar_t *nptr, wchar_t **endptr);
float wcstof(const wchar_t *nptr, wchar_t **endptr);
long double wcstold(const wchar_t *nptr, wchar_t **endptr);
long int wcstol(const wchar_t *nptr, wchar_t **endptr, int base);
long long int wcstoll(const wchar_t *nptr, wchar_t **endptr, int base);
unsigned long int wcstoul(const wchar_t *nptr, wchar_t **endptr, int base);
unsigned long long int wcstoull(const wchar_t *nptr, wchar_t **endptr, int base);

/* 7.29.4.2 Wide string copying functions */
wchar_t *wcscpy(wchar_t *s1, const wchar_t *s2);
wchar_t *wcsncpy(wchar_t *s1, const wchar_t *s2, size_t n);
wchar_t *wmemcpy(wchar_t *s1, const wchar_t *s2, size_t n);
wchar_t *wmemmove(wchar_t *s1, const wchar_t *s2, size_t n);

/* 7.29.4.3 Wide string concatenation functions */
wchar_t *wcscat(wchar_t *s1, const wchar_t *s2);
wchar_t *wcsncat(wchar_t *s1, const wchar_t *s2, size_t n);

/* 7.29.4.4 Wide string comparison functions */
int wcscmp(const wchar_t *s1, const wchar_t *s2);
int wcscoll(const wchar_t *s1, const wchar_t *s2);
int wcsncmp(const wchar_t *s1, const wchar_t *s2, size_t n);
size_t wcsxfrm(wchar_t *s1, const wchar_t *s2, size_t n);
int wmemcmp(const wchar_t *s1, const wchar_t *s2, size_t n);

/* 7.29.4.5 Wide string search functions */
wchar_t *wcschr(const wchar_t *s, wchar_t c);
size_t wcscspn(const wchar_t *s1, const wchar_t *s2);
wchar_t *wcspbrk(const wchar_t *s1, const wchar_t *s2);
wchar_t *wcsrchr(const wchar_t *s, wchar_t c);
size_t wcsspn(const wchar_t *s1, const wchar_t *s2);
wchar_t *wcsstr(const wchar_t *s1, const wchar_t *s2);
wchar_t *wcstok(wchar_t *s1, const wchar_t *s2, wchar_t **ptr);
wchar_t *wmemchr(const wchar_t *s, wchar_t c, size_t n);

/* 7.29.4.6 Miscellaneous functions */
size_t wcslen(const wchar_t *s);
wchar_t *wmemset(wchar_t *s, wchar_t c, size_t n);

/* 7.29.5 Wide character time conversion functions */
size_t wcsftime(wchar_t *s, size_t maxsize, const wchar_t *format,
                const struct tm *timeptr);

/* 7.29.6 Extended multibyte/wide character conversion utilities */
/* 7.29.6.1 Single-byte/wide character conversion functions */
wint_t btowc(int c);
int wctob(wint_t c);

/* 7.29.6.2 Conversion state functions */
int mbsinit(const mbstate_t *ps);

/* 7.29.6.3 Restartable multibyte/wide character conversion functions */
size_t mbrlen(const char *s, size_t n, mbstate_t *ps);
size_t mbrtowc(wchar_t *pwc, const char *s, size_t n, mbstate_t *ps);
size_t wcrtomb(char *s, wchar_t wc, mbstate_t *ps);

/* 7.29.6.4 Restartable multibyte/wide string conversion functions */
size_t mbsrtowcs(wchar_t *dst, const char **src, size_t len,
                 mbstate_t *ps);
size_t wcsrtombs(char *dst, const wchar_t **src, size_t len,
                 mbstate_t *ps);

/* K.3.9 Extended multibyte and wide character utilities */
#ifdef __STDC_WANT_LIB_EXT1__
#if __STDC_WANT_LIB_EXT1__
#include <_types/_errno_t.h>
#include <_types/_rsize_t.h>

/* K.3.9.1 Formatted wide character input/output functions */
int fwprintf_s(FILE *stream, const wchar_t *format, ...);
int fwscanf_s(FILE *stream, const wchar_t *format, ...);
int snwprintf_s(wchar_t *s, rsize_t n, const wchar_t *format, ...);
int swprintf_s(wchar_t *s, rsize_t n, const wchar_t *format, ...);
int swscanf_s(const wchar_t *s, const wchar_t *format, ...);
int vfwprintf_s(FILE *stream, const wchar_t *format, va_list arg);
int vfwscanf_s(FILE *stream, const wchar_t *format, va_list arg);
int vsnwprintf_s(wchar_t *s, rsize_t n, const wchar_t *format, va_list arg);
int vswprintf_s(wchar_t *s, rsize_t n, const wchar_t *format, va_list arg);
int vswscanf_s(const wchar_t *s, const wchar_t *format, va_list arg);
int vwprintf_s(const wchar_t *format, va_list arg);
int vwscanf_s(const wchar_t *format, va_list arg);
int wprintf_s(const wchar_t *format, ...);
int wscanf_s(const wchar_t *format, ...);

/* K.3.9.2 General wide string utilities */
errno_t wcscpy_s(wchar_t *s1, rsize_t s1max, const wchar_t *s2);
errno_t wcsncpy_s(wchar_t *s1, rsize_t s1max, const wchar_t *s2, rsize_t n);
errno_t wmemcpy_s(wchar_t *s1, rsize_t s1max, const wchar_t *s2, rsize_t n);
errno_t wmemmove_s(wchar_t *s1, rsize_t s1max, const wchar_t *s2, rsize_t n);
errno_t wcscat_s(wchar_t *s1, rsize_t s1max, const wchar_t *s2);
errno_t wcsncat_s(wchar_t *s1, rsize_t s1max, const wchar_t *s2, rsize_t n);
wchar_t *wcstok_s(wchar_t *s1, rsize_t *s1max, const wchar_t *s2, wchar_t **ptr);
size_t wcsnlen_s(const wchar_t *s, size_t maxsize);

/* K.3.9.3 Extended multibyte/wide character conversion utilities */
errno_t wcrtomb_s(size_t *retval, char *s, rsize_t smax, wchar_t wc, mbstate_t *ps);
errno_t mbsrtowcs_s(size_t *retval, wchar_t *dst, rsize_t dstmax,
                    const char **src, rsize_t len, mbstate_t *ps);
errno_t wcsrtombs_s(size_t *retval, char *dst, rsize_t dstmax,
                    const wchar_t **src, rsize_t len, mbstate_t *ps);
#endif
#endif

#ifdef __STDC_WANT_LIB_EXT2__
FILE *open_wmemstream(wchar_t **bufp, size_t *sizep);
int aswprintf(wchar_t **ptr, const wchar_t *format, ...);
int vaswprintf(wchar_t **ptr, const wchar_t *format, va_list arg);
#endif

#endif /* _QLIBC_WCHAR_H */
