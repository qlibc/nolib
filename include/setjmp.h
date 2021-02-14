/* QlibC (c) Charlie Gordon 2014-2021 */

/* 7.13 Nonlocal jumps <setjmp.h> */

#ifndef _QLIBC_SETJMP_H
#define _QLIBC_SETJMP_H

/* registers sp, fp, ip */
typedef void *jmp_buf[3];

/* 7.13.1 Save calling environment */
int setjmp(jmp_buf *env);

/* 7.13.2 Restore calling environment */
_Noreturn void longjmp(jmp_buf *env, int val);

#endif /* _QLIBC_SETJMP_H */
