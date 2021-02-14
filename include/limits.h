/* QlibC (c) Charlie Gordon 2014-2021 */

/* 7.10 Sizes of integer types <limits.h> */

#define CHAR_BIT    8
#define SCHAR_MAX   127
#define SCHAR_MIN   (-128)
#define UCHAR_MAX   255
#define CHAR_MAX    SCHAR_MAX
#define CHAR_MIN    SCHAR_MIN
#define CHAR_WIDTH  8
#define SCHAR_WIDTH 8
#define UCHAR_WIDTH 8

#define MB_LEN_MAX  6

#define USHRT_MAX   0xffff
#define SHRT_MAX    32767
#define SHRT_MIN    (-SHRT_MAX-1)
#define SHRT_WIDTH  16
#define USHRT_WIDTH 16

/* 16-bit mode not supported for generic mode */
#define UINT_MAX    0xffffffffU
#define INT_MAX     2147483647
#define INT_MIN     (-INT_MAX-1)
#define INT_WIDTH   32
#define UINT_WIDTH  32

#ifdef __LP64__
#define ULONG_MAX   0xffffffffffffffffUL
#define LONG_MAX    0x7fffffffffffffffL
#define LONG_MIN    (-LONG_MAX-1)
#define LONG_WIDTH  64
#define ULONG_WIDTH 64
#else
#define ULONG_MAX    0xffffffffUL
#define LONG_MAX     2147483647L
#define LONG_MIN     (-LONG_MAX-1)
#define LONG_WIDTH  32
#define ULONG_WIDTH 32
#endif

#define ULLONG_MAX  0xffffffffffffffffULL
#define LLONG_MAX   0x7fffffffffffffffLL
#define LLONG_MIN   (-LLONG_MAX-1)
#define LLONG_WIDTH 64
#define ULLONG_WIDTH 64

#define ATEXIT_MAX  32
#define NAME_MAX    255
#define PATH_MAX    4096    /* linux definition */
