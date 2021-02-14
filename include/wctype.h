/* QlibC (c) Charlie Gordon 2014-2021 */

/* 7.30 Wide character classification and mapping utilities <wctype.h> */

#ifndef _QLIBC_WCTYPE_H
#define _QLIBC_WCTYPE_H

/* 7.30.1 Introduction: macros and types */
#include <_types/_wint_t.h>
typedef int wctrans_t;
typedef int wctype_t;
#define WEOF  ((wint_t)-1)

/* 7.30.2 Wide character classification utilities */
/* 7.30.2.1 Wide character classification functions */
int iswalnum(wint_t wc);
int iswalpha(wint_t wc);
int iswblank(wint_t wc);
int iswcntrl(wint_t wc);
int iswdigit(wint_t wc);
int iswgraph(wint_t wc);
int iswlower(wint_t wc);
int iswprint(wint_t wc);
int iswpunct(wint_t wc);
int iswspace(wint_t wc);
int iswupper(wint_t wc);
int iswxdigit(wint_t wc);

/* 7.30.2.2 Extensible wide character classification functions */
int iswctype(wint_t wc, wctype_t desc);
wctype_t wctype(const char *property);

/* 7.30.3 Wide character case mapping utilities */
/* 7.30.3.1 Wide character case mapping functions */
wint_t towlower(wint_t wc);
wint_t towupper(wint_t wc);

/* 7.30.3.2 Extensible wide character case mapping functions */
wint_t towctrans(wint_t wc, wctrans_t desc);
wctrans_t wctrans(const char *property);

#endif /* _QLIBC_WCTYPE_H */
