/* QlibC (c) Charlie Gordon 2014-2021 */

#ifndef _QLIBC_UNISTD_H
#define _QLIBC_UNISTD_H

#include <stdint.h>
#include <time.h>
#include <_types/_gid_t.h>
#include <_types/_off_t.h>
#include <_types/_pid_t.h>
#include <_types/_size_t.h>
#include <_types/_ssize_t.h>
#include <_types/_uid_t.h>

#define SEEK_SET    0
#define SEEK_CUR    1
#define SEEK_END    2

#define STDIN_FILENO   0
#define STDOUT_FILENO  1
#define STDERR_FILENO  2

typedef int suseconds_t;
typedef unsigned int useconds_t;
struct timeval {
    time_t      tv_sec;     /* seconds */
    suseconds_t tv_usec;    /* microseconds */
};
struct timezone {
    int tz_minuteswest;     /* minutes west of Greenwich */
    int tz_dsttime;         /* type of DST correction */
};

/* POSIX.1-1990 */

_Noreturn void _exit(int);
int access(const char *, int);
unsigned int alarm(unsigned int);
int chdir(const char *);
int chown(const char *, uid_t, gid_t);
int close(int);
int dup(int);
int dup2(int, int);
int execl(const char * __path, const char * __arg0, ...);
int execle(const char * __path, const char * __arg0, ...);
int execlp(const char * __file, const char * __arg0, ...);
int execv(const char * __path, char * const * __argv);
int execve(const char *path, const char *argv[], char *envp[]);
int execvp(const char * __file, char * const * __argv);
pid_t fork(void);
long fpathconf(int, int);
char *getcwd(char *, size_t);
gid_t getegid(void);
uid_t geteuid(void);
gid_t getgid(void);
int getgroups(int, gid_t []);
char *getlogin(void);
pid_t getpgrp(void);
pid_t getpid(void);
pid_t getppid(void);
uid_t getuid(void);
int isatty(int);
int link(const char *, const char *);
off_t lseek(int, off_t, int);
long pathconf(const char *, int);
int pause(void);
int pipe(int [2]);
ssize_t read(int, void *, size_t);
int rmdir(const char *);
void *sbrk(intptr_t size);  /* obsolete */
int setgid(gid_t);
int setpgid(pid_t, pid_t);
pid_t setsid(void);
int setuid(uid_t);
unsigned int sleep(unsigned int);
int syscall(int, ...);
long sysconf(int);
pid_t tcgetpgrp(int);
int tcsetpgrp(int, pid_t);
char *ttyname(int);
char *ttyname_r(int, char *, size_t);
int unlink(const char *);
ssize_t write(int, const void *, size_t);

/* POSIX.2-1992 */
size_t confstr(int, char *, size_t);
int getopt(int, char * const [], const char *);
extern char *optarg; /* getopt(3) external variables */
extern int optind, opterr, optopt;

void *brk(const void *);
int chroot(const char *);
char *crypt(const char *, const char *);
int fchdir(int);
long gethostid(void);
pid_t getpgid(pid_t);
pid_t getsid(pid_t);
int getdtablesize(void);
int getpagesize(void);
char *getpass(const char *);
int lchown(const char *, uid_t, gid_t);
int lockf(int, int, off_t);
int nice(int);
ssize_t pread(int __fd, void * __buf, size_t __nbyte, off_t __offset);
ssize_t pwrite(int __fd, const void * __buf, size_t __nbyte, off_t __offset);
int setregid(gid_t, gid_t);
int setreuid(uid_t, uid_t);
void swab(const void *, void *, ssize_t);
void sync(void);
int truncate(const char *, off_t);
useconds_t ualarm(useconds_t, useconds_t);
int usleep(useconds_t);
pid_t vfork(void);
int fsync(int);
int ftruncate(int, off_t);
int getlogin_r(char *, size_t);
int fchown(int, uid_t, gid_t);
int gethostname(char *, size_t);
ssize_t readlink(const char *, char *, size_t);
int setegid(gid_t);
int seteuid(uid_t);
int symlink(const char *, const char *);

/* linux */
int gettimeofday(struct timeval *, struct timezone *);
unsigned long long int __rdtsc(void);
ssize_t _write_retry(int, const void *, size_t);
ssize_t _write_string(int, const char *);

#if defined _GNU_SOURCE
extern char **environ;
#endif

#endif /* _QLIBC_UNISTD_H */
