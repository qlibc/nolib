/* QlibC (c) Charlie Gordon 2014-2021 */

#ifndef _QLIBC_SYS_WAIT_H
#define _QLIBC_SYS_WAIT_H

#include <_types/_pid_t.h>

pid_t wait(int *rc);
/* status extraction macros */
#define WIFEXITED(x)    (((x) & 0x7f) == 0)
#define WEXITSTATUS(x)  ((x) >> 8)
#define WTERMSIG(x)     ((x) & 0x7f)
#define WSTOPSIG(x)     ((x) >> 8)
#define WIFCONTINUED(x) (((x) & 0x7f) == 0x7f && WSTOPSIG(x) == 0x13)
#define WIFSTOPPED(x)   (((x) & 0x7f) == 0x7f && WSTOPSIG(x) != 0x13)
#define WIFSIGNALED(x)  (((x) & 0x7f) != 0x7f && ((x) & 0x7f) != 0)

pid_t waitpid(pid_t pid, int *rc, int options);
/* waitpid option bits */
#define WNOHANG     0x00000001  /* [XSI] no hang in wait/no child to reap */
#define WUNTRACED   0x00000002  /* [XSI] notify on stop, untraced child */

#endif /* _QLIBC_SYS_WAIT_H */
