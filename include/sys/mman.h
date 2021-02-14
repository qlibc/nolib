/* QlibC (c) Charlie Gordon 2014-2021 */

#ifndef	_QLIBC_SYS_MMAN_H
#define _QLIBC_SYS_MMAN_H

#include <_types/_mode_t.h>
#include <_types/_off_t.h>
#include <_types/_size_t.h>

#ifdef __MACH__
/*
 * Protections are chosen from these bits, or-ed together
 */
#define	PROT_NONE	0x00	/* [MC2] no permissions */
#define	PROT_READ	0x01	/* [MC2] pages can be read */
#define	PROT_WRITE	0x02	/* [MC2] pages can be written */
#define	PROT_EXEC	0x04	/* [MC2] pages can be executed */

/*
 * Flags contain sharing type and options.
 * Sharing types; choose one.
 */
#define	MAP_SHARED	0x0001		/* [MF|SHM] share changes */
#define	MAP_PRIVATE	0x0002		/* [MF|SHM] changes are private */

/*
 * Other flags
 */
#define	MAP_FIXED	 0x0010	/* [MF|SHM] interpret addr exactly */

/*
 * Mapping type
 */
#define	MAP_FILE	0x0000	/* map from file (default) */
#define	MAP_ANON	0x1000	/* allocated from memory, swap space */
#define	MAP_ANONYMOUS	MAP_ANON
#endif  /* __MACH__ */

#ifdef __linux__

#define PROT_READ   0x1     /* page can be read */
#define PROT_WRITE  0x2     /* page can be written */
#define PROT_EXEC   0x4     /* page can be executed */
#define PROT_SEM    0x8     /* page may be used for atomic ops */
#define PROT_NONE   0x0     /* page can not be accessed */
#define PROT_GROWSDOWN  0x01000000  /* mprotect flag: extend change to start of growsdown vma */
#define PROT_GROWSUP    0x02000000  /* mprotect flag: extend change to end of growsup vma */

#define MAP_SHARED  0x01        /* Share changes */
#define MAP_PRIVATE 0x02        /* Changes are private */
#define MAP_TYPE    0x0f        /* Mask for type of mapping */
#define MAP_FIXED   0x10        /* Interpret addr exactly */
#define MAP_ANONYMOUS   0x20        /* don't use a file */

/* compatibility flags */
#define MAP_FILE    0
#define MAP_ANON    MAP_ANONYMOUS

#define MAP_GROWSDOWN   0x0100      /* stack-like segment */
#define MAP_DENYWRITE   0x0800      /* ETXTBSY */
#define MAP_EXECUTABLE  0x1000      /* mark it as an executable */
#define MAP_LOCKED  0x2000      /* pages are locked */
#define MAP_NORESERVE   0x4000      /* don't check for reservations */
#define MAP_POPULATE    0x8000      /* populate (prefault) pagetables */
#define MAP_NONBLOCK    0x10000     /* do not block on IO */
#define MAP_STACK   0x20000     /* give out an address that is best suited for process/thread stacks */
#define MAP_HUGETLB 0x40000     /* create a huge page mapping */

#endif /* __linux__ */

/*
 * Error return from mmap()
 */
#define MAP_FAILED	((void *)-1)	/* [MF|SHM] mmap failed */

void *mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
int	munmap(void *addr, size_t len);

#endif /* _QLIBC_SYS_MMAN_H */
