/* QlibC (c) Charlie Gordon 2014-2021 */

/* 7.16 Variable arguments <stdarg.h> */

#ifndef _QLIBC_STDARG_H
#define _QLIBC_STDARG_H

typedef char *va_list;

/* 7.16.1 Variable argument list access macros */
//#define va_arg(ap,type)     (ap += (sizeof(type)+sizeof(int)-1)&~(sizeof(int)-1),*(type *)(ap - ((sizeof(type)+sizeof(int)-1)&~(sizeof(int)-1))))
#define va_arg(ap,type)     (*(type *)((ap += (sizeof(type)+sizeof(int)-1)&~(sizeof(int)-1)) - ((sizeof(type)+sizeof(int)-1)&~(sizeof(int)-1))))
#define va_copy(dest, src)  ((dest) = (src))
#define va_end(ap)
#define va_start(ap,last)   (ap = ((char *)&(last)) + ((sizeof(last)+sizeof(int)-1)&~(sizeof(int)-1)))

#endif /* _QLIBC_STDARG_H */
