/* QlibC (c) Charlie Gordon 2014-2021 */

/* 7.2 Diagnostics <assert.h> */

#define static_assert  _Static_assert

/* 7.2.1 Program diagnostics */
#undef assert
#ifdef NDEBUG
#define assert(ignore)  ((void)0)
#else
_Noreturn
void _Assert(const char *filename, int line, const char *func, const char *e);
#define assert(e)  (void)(!!(e) || (_Assert(__FILE__, __LINE__, __func__, #e), 0))
#endif

//#define static_assert _Static_assert
