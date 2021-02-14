/* QlibC (c) Charlie Gordon 2014-2021 */

/* 7.22 General utilities <stdlib.h> */

#ifndef _QLIBC_STDLIB_H
#define _QLIBC_STDLIB_H

#include <_types/_size_t.h>
#include <_types/_wchar_t.h>

typedef struct { int quot, rem; } div_t;
typedef struct { long int quot, rem; } ldiv_t;
typedef struct { long long int quot, rem; } lldiv_t;

#define NULL     ((void*)0)

#define EXIT_FAILURE    1
#define EXIT_SUCCESS    0

#define RAND_MAX    65535
#define MB_CUR_MAX  6 /* enough for utf-8 */

/* 7.22.1 Numeric conversion functions */
double atof(const char *nptr);
int atoi(const char *nptr);
long int atol(const char *nptr);
long long int atoll(const char *nptr);
double strtod(const char *nptr, char **endptr);
float strtof(const char *nptr, char **endptr);
long double strtold(const char *nptr, char **endptr);
long int strtol(const char *s, char **endp, int base);
long long int strtoll(const char *s, char **endp, int base);
unsigned long int strtoul(const char *s, char **endp, int base);
unsigned long long int strtoull(const char *s, char **endp, int base);

/* 7.22.2 Pseudo-random sequence generation functions */
int rand(void);
void srand(unsigned int seed);

/* 7.22.3 Memory management functions */
void *aligned_alloc(size_t alignment, size_t size);
void *calloc(size_t nmemb, size_t size);
void free(void *p);
void *malloc(size_t size);
void *realloc(void *p, size_t size);

/* 7.22.4 Communication with the environment */
_Noreturn void abort(void);
int atexit(void (*func)(void));
int at_quick_exit(void (*func)(void));
_Noreturn void exit(int status);
_Noreturn void _Exit(int status);
char *getenv(const char *name);
_Noreturn void quick_exit(int status);
int system(const char *s);

/* 7.22.5 Searching and sorting utilities */
void *bsearch(const void *key, const void *base,
              size_t nmemb, size_t size,
              int (*compar)(const void *, const void *));
void qsort(void *base, size_t nmemb, size_t size,
           int (*compar)(const void *, const void *));

/* 7.22.6 Integer arithmetic functions */
int abs(int n);
long int labs(long int n);
long long int llabs(long long int n);
div_t div(int numer, int denom);
ldiv_t ldiv(long int numer, long int denom);
lldiv_t lldiv(long long int numer, long long int denom);

/* 7.22.7 Multibyte/wide character conversion functions */
int mblen(const char *s, size_t n);
int mbtowc(wchar_t *pwc, const char *s, size_t n);
int wctomb(char *s, wchar_t wc);

/* 7.22.8 Multibyte/wide string conversion functions */
size_t mbstowcs(wchar_t *pwcs, const char *s, size_t n);
size_t wcstombs(char *s, const wchar_t *pwcs, size_t n);

#define random()  rand()    /* XXX: long random(void); */
#define srandom(seed)  srand(seed)  /* XXX: void srandom(int seed); */

extern char **environ;

/* K.3.6 General utilities */
#ifdef __STDC_WANT_LIB_EXT1__
#if __STDC_WANT_LIB_EXT1__
#include <_types/_errno_t.h>
#include <_types/_rsize_t.h>

typedef void (*constraint_handler_t)(const char *msg, void *ptr, errno_t error);

/* K.3.6.1 Runtime-constraint handling */
constraint_handler_t set_constraint_handler_s(constraint_handler_t handler);
void abort_handler_s(const char *msg, void *ptr, errno_t error);
void ignore_handler_s(const char *msg, void *ptr, errno_t error);

/* K.3.6.2 Communication with the environment */
errno_t getenv_s(size_t *len, char *value, rsize_t maxsize, const char *name);

/* K.3.6.3 Searching and sorting utilities */
void *bsearch_s(const void *key, const void *base, rsize_t nmemb, rsize_t size,
                int (*compar)(const void *k, const void *y, void *context),
                void *context);
errno_t qsort_s(void *base, rsize_t nmemb, rsize_t size,
                int (*compar)(const void *x, const void *y, void *context),
                void *context);

/* K.3.6.4 Multibyte/wide character conversion functions */
errno_t wctomb_s(int *status, char *s, rsize_t smax, wchar_t wc);

/* K.3.6.5 Multibyte/wide string conversion functions */
errno_t mbstowcs_s(size_t *retval, wchar_t *dst, rsize_t dstmax,
                   const char *src, rsize_t len);
errno_t wcstombs_s(size_t *retval, char *dst, rsize_t dstmax,
                   const wchar_t *src, rsize_t len);
#endif
#endif

#if 1  /* Posix extensions */
// _POSIX_C_SOURCE >= 200112L
// || /* Glibc versions <= 2.19: */ _BSD_SOURCE
int setenv(const char *name, const char *value, int overwrite);
int unsetenv(const char *name);
// _XOPEN_SOURCE
// || /* Glibc since 2.19: */ _DEFAULT_SOURCE
// || /* Glibc versions <= 2.19: */ _SVID_SOURCE
int putenv(char *str);
int clearenv(void);
// /* Glibc since 2.19: */ _DEFAULT_SOURCE
// || /* Glibc versions <= 2.19: */ _SVID_SOURCE || _BSD_SOURCE

int shellsort(void *base, size_t nmemb, size_t size,
              int (*compar)(const void *, const void *));
int heapsort(void *base, size_t nmemb, size_t size,
             int (*compar)(const void *, const void *));
int mergesort(void *base, size_t nmemb, size_t size,
              int (*compar)(const void *, const void *));

/* char __resolved_name[PATH_MAX] */
char *realpath(const char *__path_name, char *__resolved_name);

double drand48(void);
double erand48(unsigned short xsubi[3]);
long jrand48(unsigned short xsubi[3]);
void lcong48(unsigned short param[7]);
long lrand48(void);
long mrand48(void);
long nrand48(unsigned short xsubi[3]);
unsigned short *seed48(unsigned short seed16v[3]);
void srand48(long seedval);

int posix_memalign(void **pp, size_t alignment, size_t size);
void *memalign(size_t alignment, size_t size);
void *reallocf(void *ptr, size_t size);
void *valloc(size_t size);
size_t malloc_good_size(size_t size);
size_t malloc_size(const void *ptr);
#define malloc_usable_size(ptr)  malloc_size(ptr)

char *ecvt(double value, int ndigit, int *decpt, int *sign);
char *fcvt(double value, int ndigit, int *decpt, int *sign);
char *gcvt(double value, int ndigit, char *buf);

#include <alloca.h>
#endif

#endif /* _QLIBC_STDLIB_H */
