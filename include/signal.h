/* QlibC (c) Charlie Gordon 2014-2021 */

/* 7.14 Signal handling <signal.h> */

#ifndef _QLIBC_SIGNAL_H
#define _QLIBC_SIGNAL_H

typedef int sig_atomic_t;

#define SIG_DFL  (void(*)(int))0
#define SIG_IGN  (void(*)(int))1
#define SIG_ERR  (void(*)(int))2

/* XXX: missing definitions for system dependent signals:
 * SIGHUP, SIGQUIT, SIGTRAP, SIGKILL, SIGBUS, SIGSYS, SIGPIPE,
 * SIGALRM, SIGSTOP, SIGCONT, SIGCHLD, SIGWINCH, SIGUSR1, SIGUSR2...
 * XXX: values for these and the following should come from a system
 * specific header.
 */
#define SIGINT   2
#define SIGILL   4
#define SIGABRT  6
#define SIGFPE   8
#define SIGSEGV  11
#define SIGTERM  15

/* 7.14.1 Specify signal handling */
/* XXX: should be void (*signal(int sig, void (*func)(int)))(int); */
int signal(int sig, void (*func)(int));

/* 7.14.2 Send signal */
int raise(int sig);

#endif /* _QLIBC_SIGNAL_H */
