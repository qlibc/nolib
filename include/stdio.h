/* QlibC (c) Charlie Gordon 2014-2021 */

/* 7.21 Input/output <stdio.h> */

#ifndef _QLIBC_STDIO_H
#define _QLIBC_STDIO_H

#include <stdarg.h>

/* 7.21.1 Introduction */

#include <_types/_size_t.h>
#ifndef NO_WCHAR
#define MB_CUR_MAX  6  /* enough for utf-8 */
#include <_types/_mbstate_t.h>
#include <_types/_wint_t.h>
#endif

typedef struct FILE FILE;

typedef long int fpos_t;

#define NULL    ((void*)0)
#define _IOFBF  0
#define _IOLBF  1
#define _IONBF  2
#define BUFSIZ  1024
#define EOF     (-1)
#define FOPEN_MAX       20
#define FILENAME_MAX    1024
#define L_tmpnam    20
#define TMP_MAX     65535

#define SEEK_SET    0
#define SEEK_CUR    1
#define SEEK_END    2

extern FILE *stdin, *stdout, *stderr;

/* 7.21.4 Operations on files */
int remove(const char *filename);
int rename(const char *oldname, const char *newname);
FILE *tmpfile(void);
char *tmpnam(char *s);

/* 7.21.5 File access functions */
int fclose(FILE *stream);
int fflush(FILE *stream);
FILE *fopen(const char *filename, const char *mode);
FILE *freopen(const char *filename, const char *mode, FILE *stream);
void setbuf(FILE *stream, char *buf);
int setvbuf(FILE *stream, char *buf, int mode, size_t size);

/* 7.21.6 Formatted input/output functions */
int fprintf(FILE *stream, const char *format, ...);
int fscanf(FILE *stream, const char *format, ...);
int printf(const char *format, ...);
int scanf(const char *format, ...);
int snprintf(char *s, size_t n, const char *format, ...);
int sprintf(char *s, const char *format, ...);
int sscanf(const char *s, const char *format, ...);
int vfprintf(FILE *stream, const char *format, va_list arg);
int vfscanf(FILE *stream, const char *format, va_list arg);
int vprintf(const char *format, va_list arg);
int vscanf(const char *format, va_list arg);
int vsnprintf(char *s, size_t n, const char *format, va_list arg);
int vsprintf(char *s, const char *format, va_list arg);
int vsscanf(const char *s, const char *format, va_list arg);

/* 7.21.7 Character input/output functions */
int fgetc(FILE *stream);
char *fgets(char *s, int n, FILE *stream);
int fputc(int c, FILE *stream);
int fputs(const char *s, FILE *stream);
int getc(FILE *stream);
int getchar(void);
int putc(int c, FILE *stream);
int putchar(int c);
int puts(const char *s);
int ungetc(int c, FILE *stream);

#define getc(f)     getc(f)
#define getchar()   getc(stdin)
#define putc(c,f)   putc(c, f)
#define putchar(c)  putc(c, stdout)

/* 7.21.8 Direct input/output functions */
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

/* 7.21.9 File positioning functions */
int fgetpos(FILE *stream, fpos_t *pos);
int fseek(FILE *stream, long int offset, int whence);
int fsetpos(FILE *stream, const fpos_t *pos);
long int ftell(FILE *stream);
void rewind(FILE *stream);

/* 7.21.10 Error-handling functions */
void clearerr(FILE *stream);
int feof(FILE *stream);
int ferror(FILE *stream);
void perror(const char *s);

#ifndef _ANSI_SOURCE
/* Non Standard functions and definitions */
#define P_tmpdir    "/tmp/"

FILE *fdopen(int fd, const char *mode);
int fileno(FILE *stream);
char *gets(char *buf);

int dprintf(int fd, const char *format, ...);
int vdprintf(int fd, const char *format, va_list arg);
#define kprintf  dprintf

/* WDTR 24731-2 compatibility */
/* should be controlled by #ifdef __STDC_WANT_LIB_EXT2__ */
#define __STDC_ALLOC_LIB__  200708L
FILE *fmemopen(void *buf, size_t size, const char *mode);
FILE *open_memstream(char **bufp, size_t *sizep);
int asprintf(char **strp, const char *format, ...);
int vasprintf(char **strp, const char *format, va_list arg);
#endif

/* K.3.5 Input/output */
#ifdef __STDC_WANT_LIB_EXT1__
#if __STDC_WANT_LIB_EXT1__
#include <_types/_errno_t.h>
#include <_types/_rsize_t.h>

#define TMP_MAX_S   1   /* XXX: should be >= 25 */
#define L_tmpnam_s  8

/* K.3.5.1 Operations on files */
errno_t tmpfile_s(FILE **streamptr);
errno_t tmpnam_s(char *s, rsize_t maxsize);

/* K.3.5.2 File access functions */
errno_t fopen_s(FILE **streamptr, const char *filename, const char *mode);
errno_t freopen_s(FILE **newstreamptr, const char *filename, const char *mode,
                  FILE *stream);

/* K.3.5.3 Formatted input/output functions */
int fprintf_s(FILE *stream, const char *format, ...);
int fscanf_s(FILE *stream, const char *format, ...);
int printf_s(const char *format, ...);
int scanf_s(const char *format, ...);
int snprintf_s(char *s, rsize_t n, const char *format, ...);
int sprintf_s(char *s, rsize_t n, const char *format, ...);
int sscanf_s(const char *s, const char *format, ...);
int vfprintf_s(FILE *stream, const char *format, va_list arg);
int vprintf_s(const char *format, va_list arg);
int vscanf_s(const char *format, va_list arg);
int vsnprintf_s(char *s, rsize_t n, const char *format, va_list arg);
int vsprintf_s(char *s, rsize_t n, const char *format, va_list arg);
int vsscanf_s(const char *s, const char *format, va_list arg);

/* K.3.5.4 Character input/output functions */
char *gets_s(char *s, rsize_t n);
#endif
#endif

/* POSIX functions */
#if defined __USE_POSIX || defined __USE_MISC || defined __STDC_WANT_LIB_EXT2__
#include <_types/_ssize_t.h>
FILE *popen(const char *cmd, const char *mode);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
ssize_t getdelim(char **lineptr, size_t *n, int delim, FILE *stream);
#ifndef NO_WCHAR
#include <_types/_wchar_t.h>
ssize_t getwdelim(wchar_t **lineptr, size_t *n, wint_t delimiter, FILE *stream);
ssize_t getwline(wchar_t **lineptr, size_t *n, FILE *stream);
#endif

int getc_unlocked(FILE *stream);
int getchar_unlocked(void);
int putc_unlocked(int c, FILE *stream);
int putchar_unlocked(int c);
#define getc_unlocked(stream)     getc(stream)
#define getchar_unlocked()        getchar()
#define putc_unlocked(c, stream)  putc(c, stream)
#define putchar_unlocked(c)       putchar(c)
#endif
#if defined __USE_MISC
int fgetc_unlocked(FILE *stream);
int fputc_unlocked(int c, FILE *stream);
#define fgetc_unlocked(stream)     fgetc(stream)
#define fputc_unlocked(c, stream)  fputc(c, stream)
#endif
#if defined __USE_GNU
int fgets_unlocked(char *s, int n, FILE *stream);
int fputs_unlocked(const char *s, FILE *stream);
#define fgets_unlocked(s, n, stream)  fgets(s, n, stream)
#define fputs_unlocked(s, stream)     fputs(s, stream)
#endif
#ifdef __USE_MISC
size_t fread_unlocked(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t fwrite_unlocked(const void *ptr, size_t size, size_t nmemb, FILE *stream);
#define fread_unlocked(ptr, size, nmemb, stream)   fread(ptr, size, nmemb, stream)
#define fwrite_unlocked(ptr, size, nmemb, stream)  fwrite(ptr, size, nmemb, stream)
void clearerr_unlocked(FILE *stream);
int feof_unlocked(FILE *stream);
int ferror_unlocked(FILE *stream);
int fileno_unlocked(FILE *stream);
#define clearerr_unlocked(stream)  clearerr(stream)
#define feof_unlocked(stream)      feof(stream)
#define ferror_unlocked(stream)    ferror(stream)
#define fileno_unlocked(stream)    fileno(stream)
#endif
#if defined __USE_POSIX || defined __USE_MISC
void flockfile(FILE *stream);
int ftrylockfile(FILE *stream);
void funlockfile(FILE *stream);
#define flockfile(stream)
#define ftrylockfile(stream)  0
#define funlockfile(stream)
#endif

/* GNU extensions */
int fcloseall(void);

/* other extensions */
void malloc_info(int options, FILE *fp);

#endif /* _QLIBC_STDIO_H */
