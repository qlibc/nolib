/* QlibC (c) Charlie Gordon 2014-2021 */

/* 7.27 Date and time <time.h> */

#ifndef _QLIBC_TIME_H
#define _QLIBC_TIME_H

/* 7.27.1 Components of time */
#define NULL    ((void*)0)
#define CLOCKS_PER_SEC  1000000  /* XXX: system dependent */
#define TIME_UTC  0

#include <_types/_size_t.h>
typedef int clock_t;
typedef int time_t;

struct timespec {
    time_t tv_sec;  /* whole seconds - >= 0 */
    long tv_nsec;   /* nanoseconds - [ 0, 999999999 ] */
};

struct tm {
    int tm_sec;     /* seconds after the minute [0, 60] */
    int tm_min;     /* minutes after the hour [0, 59] */
    int tm_hour;    /* hours since midnight [0, 23] */
    int tm_mday;    /* day of the month [1-31] */
    int tm_mon;     /* months since January [0, 11] */
    int tm_year;    /* years since 1900 */
    int tm_wday;    /* days since Sunday [0, 6] */
    int tm_yday;    /* days since January 1st [0, 365] */
    int tm_isdst;   /* Daylight Savings Time flag */
    int tm_gmtoff;  /* offset from UTC in seconds */
    char *tm_zone;  /* timezone abbreviation */
};

/* 7.27.2 Time manipulation functions */
clock_t clock(void);
int difftime(time_t time1, time_t time0);
time_t mktime(struct tm *timeptr);
time_t time(time_t *timer);
int timespec_get(struct timespec *ts, int base);

/* 7.27.3 Time conversion functions */
char *asctime(const struct tm *timeptr);
char *ctime(const time_t *timer);
struct tm *gmtime(const time_t *timer);
struct tm *localtime(const time_t *timer);
size_t strftime(char *s, size_t maxsize, const char *format,
                const struct tm *timeptr);

/* K.3.8 Date and time */
#ifdef __STDC_WANT_LIB_EXT1__
#if __STDC_WANT_LIB_EXT1__
#include <_types/_errno_t.h>
#include <_types/_rsize_t.h>

/* K.3.8.2 Time conversion functions */
errno_t asctime_s(char *s, rsize_t maxsize, const struct tm *timeptr);
errno_t ctime_s(char *s, rsize_t maxsize, const time_t *timer);
struct tm *gmtime_s(const time_t *timer, struct tm *result);
struct tm *localtime_s(const time_t *timer, struct tm *result);
#endif
#endif

/* Non Standard time functions */
#define timegm(t)  mktime(t)
char *asctime_r(const struct tm *tm, char *buf);
char *ctime_r(const time_t *tp, char *buf);
struct tm *gmtime_r(const time_t *tp, struct tm *tm);
struct tm *localtime_r(const time_t *tp, struct tm *tm);
extern char *tzname[2]; /* obsolete */
extern int daylight;    /* obsolete */
void tzset(void);
void tzsetwall(void);
int nanosleep(const struct timespec *rqtp, struct timespec *rmtp);

typedef enum {
    CLOCK_REALTIME = 0,
    CLOCK_MONOTONIC,
} clockid_t;
int clock_gettime(clockid_t clock_id, struct timespec *tp);

#endif /* _QLIBC_TIME_H */
