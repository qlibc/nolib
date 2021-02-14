/* QlibC (c) Charlie Gordon 2014-2021 */

/* fcntl.h (system dependent) */

#ifndef _QLIBC_FCNTL_H
#define _QLIBC_FCNTL_H

#include <_types/_mode_t.h>
#include <_types/_off_t.h>
#include <_types/_pid_t.h>

#define O_RDONLY    0x0000
#define O_WRONLY    0x0001
#define O_RDWR      0x0002
#define O_ACCMODE   0x0003

#ifdef __MACH__
#define	O_NONBLOCK	0x0004  /* Darwin */
#define O_APPEND    0x0008
#define O_CREAT     0x0200
#define O_TRUNC     0x0400
#define O_EXCL      0x0800
#endif

#ifdef __linux__
#define O_CREAT         00000100        /* not fcntl */
#define O_EXCL          00000200        /* not fcntl */
#define O_NOCTTY        00000400        /* not fcntl */
#define O_TRUNC         00001000        /* not fcntl */
#define O_APPEND        00002000
#define O_NONBLOCK      00004000
#define O_DSYNC         00010000        /* used to be O_SYNC, see below */
#define O_DIRECT        00040000        /* direct disk access hint */
#define O_LARGEFILE     00100000
#define O_DIRECTORY     00200000        /* must be a directory */
#define O_NOFOLLOW      00400000        /* don't follow links */
#define O_NOATIME       01000000
#define O_CLOEXEC       02000000        /* set close_on_exec */
#endif

/* XXX: need other definitions for bsd, windows, etc. */

int creat(const char *path, mode_t mode);
int fcntl(int, int, ...);
int open(const char *path, int flags, ...);
int openat(int fd, const char *path, int flags, ...);

#endif /* _QLIBC_FCNTL_H */
