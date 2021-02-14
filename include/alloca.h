/* QlibC (c) Charlie Gordon 2014-2021 */

#ifndef _QLIBC_ALLOCA_H
#define _QLIBC_ALLOCA_H

#include <_types/_size_t.h>

/* should define as #define	alloca(size)  __builtin_alloca(size) */
void *alloca(size_t);

#endif /* _QLIBC_ALLOCA_H */
