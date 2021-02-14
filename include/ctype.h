/* QlibC (c) Charlie Gordon 2014-2021 */

/* 7.4 Character handling <ctype.h> */

#ifndef _QLIBC_CTYPE_H
#define _QLIBC_CTYPE_H

/* 7.4.1 Character classification functions */
int isalnum(int c);
int isalpha(int c);
int isblank(int c);
int iscntrl(int c);
int isdigit(int c);
int isgraph(int c);
int islower(int c);
int isprint(int c);
int ispunct(int c);
int isspace(int c);
int isupper(int c);
int isxdigit(int c);

/* 7.4.2 Character case mapping functions */
int tolower(int c);
int toupper(int c);

#endif /* _QLIBC_CTYPE_H */
