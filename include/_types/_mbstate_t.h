/* QlibC (c) Charlie Gordon 2014-2021 */
#ifndef _QLIBC_MBSTATE_T
#define _QLIBC_MBSTATE_T
typedef struct mbstate_t mbstate_t;
struct mbstate_t {
    int _limit; /* 256 for iso8859-x and 128 for utf-8 */
    int _state;
    int _save;
};
#endif /* _QLIBC_MBSTATE_T */
