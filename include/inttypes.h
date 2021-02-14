/* QlibC (c) Charlie Gordon 2014-2021 */

/* 7.8 Format conversion of integer types <inttypes.h> */

#ifndef _QLIBC_INTTYPES_H
#define _QLIBC_INTTYPES_H

#include <stdint.h>
#include <_types/_wchar_t.h>

typedef struct imaxdiv_t imaxdiv_t;
struct imaxdiv_t { intmax_t quot, rem; };

/* 7.8.1 Macros for format specifiers */

#define _PRI8        ""
#define _PRILEAST8   ""
#define _PRIFAST8    ""
#define _PRI16       ""
#define _PRILEAST16  ""
#define _PRIFAST16   ""
#define _PRI32       ""
#define _PRILEAST32  ""
#define _PRIFAST32   ""
#define _PRI64       "ll"
#define _PRILEAST64  "ll"
#define _PRIFAST64   "ll"
#define _PRIMAX      "ll"
#define _PRIPTR      ""

#define PRId8        _PRI8 "d"
#define PRIi8        _PRI8 "i"
#define PRIo8        _PRI8 "o"
#define PRIu8        _PRI8 "u"
#define PRIx8        _PRI8 "x"
#define PRIX8        _PRI8 "X"

#define PRIdLEAST8   _PRILEAST8 "d"
#define PRIiLEAST8   _PRILEAST8 "i"
#define PRIoLEAST8   _PRILEAST8 "o"
#define PRIuLEAST8   _PRILEAST8 "u"
#define PRIxLEAST8   _PRILEAST8 "x"
#define PRIXLEAST8   _PRILEAST8 "X"

#define PRIdFAST8    _PRIFAST8 "d"
#define PRIiFAST8    _PRIFAST8 "i"
#define PRIoFAST8    _PRIFAST8 "o"
#define PRIuFAST8    _PRIFAST8 "u"
#define PRIxFAST8    _PRIFAST8 "x"
#define PRIXFAST8    _PRIFAST8 "X"

#define PRId16       _PRI16 "d"
#define PRIi16       _PRI16 "i"
#define PRIo16       _PRI16 "o"
#define PRIu16       _PRI16 "u"
#define PRIx16       _PRI16 "x"
#define PRIX16       _PRI16 "X"

#define PRIdLEAST16  _PRILEAST16 "d"
#define PRIiLEAST16  _PRILEAST16 "i"
#define PRIoLEAST16  _PRILEAST16 "o"
#define PRIuLEAST16  _PRILEAST16 "u"
#define PRIxLEAST16  _PRILEAST16 "x"
#define PRIXLEAST16  _PRILEAST16 "X"

#define PRIdFAST16   _PRIFAST16 "d"
#define PRIiFAST16   _PRIFAST16 "i"
#define PRIoFAST16   _PRIFAST16 "o"
#define PRIuFAST16   _PRIFAST16 "u"
#define PRIxFAST16   _PRIFAST16 "x"
#define PRIXFAST16   _PRIFAST16 "X"

#define PRId32       _PRI32 "d"
#define PRIi32       _PRI32 "i"
#define PRIo32       _PRI32 "o"
#define PRIu32       _PRI32 "u"
#define PRIx32       _PRI32 "x"
#define PRIX32       _PRI32 "X"

#define PRIdLEAST32  _PRILEAST32 "d"
#define PRIiLEAST32  _PRILEAST32 "i"
#define PRIoLEAST32  _PRILEAST32 "o"
#define PRIuLEAST32  _PRILEAST32 "u"
#define PRIxLEAST32  _PRILEAST32 "x"
#define PRIXLEAST32  _PRILEAST32 "X"

#define PRIdFAST32   _PRIFAST32 "d"
#define PRIiFAST32   _PRIFAST32 "i"
#define PRIoFAST32   _PRIFAST32 "o"
#define PRIuFAST32   _PRIFAST32 "u"
#define PRIxFAST32   _PRIFAST32 "x"
#define PRIXFAST32   _PRIFAST32 "X"

#define PRId64       _PRI64 "d"
#define PRIi64       _PRI64 "i"
#define PRIo64       _PRI64 "o"
#define PRIu64       _PRI64 "u"
#define PRIx64       _PRI64 "x"
#define PRIX64       _PRI64 "X"

#define PRIdLEAST64  _PRILEAST64 "d"
#define PRIiLEAST64  _PRILEAST64 "i"
#define PRIoLEAST64  _PRILEAST64 "o"
#define PRIuLEAST64  _PRILEAST64 "u"
#define PRIxLEAST64  _PRILEAST64 "x"
#define PRIXLEAST64  _PRILEAST64 "X"

#define PRIdFAST64   _PRIFAST64 "d"
#define PRIiFAST64   _PRIFAST64 "i"
#define PRIoFAST64   _PRIFAST64 "o"
#define PRIuFAST64   _PRIFAST64 "u"
#define PRIxFAST64   _PRIFAST64 "x"
#define PRIXFAST64   _PRIFAST64 "X"

#define PRIdMAX      _PRIMAX "d"
#define PRIiMAX      _PRIMAX "i"
#define PRIoMAX      _PRIMAX "o"
#define PRIuMAX      _PRIMAX "u"
#define PRIxMAX      _PRIMAX "x"
#define PRIXMAX      _PRIMAX "X"

#define PRIdPTR      _PRIPTR "d"
#define PRIiPTR      _PRIPTR "i"
#define PRIoPTR      _PRIPTR "o"
#define PRIuPTR      _PRIPTR "u"
#define PRIxPTR      _PRIPTR "x"
#define PRIXPTR      _PRIPTR "X"

#define _SCN8        "hh"
#define _SCNLEAST8   "hh"
#define _SCNFAST8    "hh"
#define _SCN16       "h"
#define _SCNLEAST16  "h"
#define _SCNFAST16   "h"
#define _SCN32       ""
#define _SCNLEAST32  ""
#define _SCNFAST32   ""
#define _SCN64       "ll"
#define _SCNLEAST64  "ll"
#define _SCNFAST64   "ll"
#define _SCNMAX      "ll"
#define _SCNPTR      ""

#define SCNd8        _SCN8 "d"
#define SCNi8        _SCN8 "i"
#define SCNo8        _SCN8 "o"
#define SCNu8        _SCN8 "u"
#define SCNx8        _SCN8 "x"

#define SCNdLEAST8   _SCNLEAST8 "d"
#define SCNiLEAST8   _SCNLEAST8 "i"
#define SCNoLEAST8   _SCNLEAST8 "o"
#define SCNuLEAST8   _SCNLEAST8 "u"
#define SCNxLEAST8   _SCNLEAST8 "x"

#define SCNdFAST8    _SCNFAST8 "d"
#define SCNiFAST8    _SCNFAST8 "i"
#define SCNoFAST8    _SCNFAST8 "o"
#define SCNuFAST8    _SCNFAST8 "u"
#define SCNxFAST8    _SCNFAST8 "x"

#define SCNd16       _SCN16 "d"
#define SCNi16       _SCN16 "i"
#define SCNo16       _SCN16 "o"
#define SCNu16       _SCN16 "u"
#define SCNx16       _SCN16 "x"

#define SCNdLEAST16  _SCNLEAST16 "d"
#define SCNiLEAST16  _SCNLEAST16 "i"
#define SCNoLEAST16  _SCNLEAST16 "o"
#define SCNuLEAST16  _SCNLEAST16 "u"
#define SCNxLEAST16  _SCNLEAST16 "x"

#define SCNdFAST16   _SCNFAST16 "d"
#define SCNiFAST16   _SCNFAST16 "i"
#define SCNoFAST16   _SCNFAST16 "o"
#define SCNuFAST16   _SCNFAST16 "u"
#define SCNxFAST16   _SCNFAST16 "x"

#define SCNd32       _SCN32 "d"
#define SCNi32       _SCN32 "i"
#define SCNo32       _SCN32 "o"
#define SCNu32       _SCN32 "u"
#define SCNx32       _SCN32 "x"

#define SCNdLEAST32  _SCNLEAST32 "d"
#define SCNiLEAST32  _SCNLEAST32 "i"
#define SCNoLEAST32  _SCNLEAST32 "o"
#define SCNuLEAST32  _SCNLEAST32 "u"
#define SCNxLEAST32  _SCNLEAST32 "x"

#define SCNdFAST32   _SCNFAST32 "d"
#define SCNiFAST32   _SCNFAST32 "i"
#define SCNoFAST32   _SCNFAST32 "o"
#define SCNuFAST32   _SCNFAST32 "u"
#define SCNxFAST32   _SCNFAST32 "x"

#define SCNd64       _SCN64 "d"
#define SCNi64       _SCN64 "i"
#define SCNo64       _SCN64 "o"
#define SCNu64       _SCN64 "u"
#define SCNx64       _SCN64 "x"

#define SCNdLEAST64  _SCNLEAST64 "d"
#define SCNiLEAST64  _SCNLEAST64 "i"
#define SCNoLEAST64  _SCNLEAST64 "o"
#define SCNuLEAST64  _SCNLEAST64 "u"
#define SCNxLEAST64  _SCNLEAST64 "x"

#define SCNdFAST64   _SCNFAST64 "d"
#define SCNiFAST64   _SCNFAST64 "i"
#define SCNoFAST64   _SCNFAST64 "o"
#define SCNuFAST64   _SCNFAST64 "u"
#define SCNxFAST64   _SCNFAST64 "x"

#define SCNdMAX      _SCNMAX "d"
#define SCNiMAX      _SCNMAX "i"
#define SCNoMAX      _SCNMAX "o"
#define SCNuMAX      _SCNMAX "u"
#define SCNxMAX      _SCNMAX "x"

#define SCNdPTR      _SCNPTR "d"
#define SCNiPTR      _SCNPTR "i"
#define SCNoPTR      _SCNPTR "o"
#define SCNuPTR      _SCNPTR "u"
#define SCNxPTR      _SCNPTR "x"

/* 7.8.2 Functions for greatest-width integer types */
intmax_t imaxabs(intmax_t j);
imaxdiv_t imaxdiv(intmax_t numer, intmax_t denom);
intmax_t strtoimax(const char *nptr, char **endptr, int base);
uintmax_t strtoumax(const char *nptr, char **endptr, int base);
intmax_t wcstoimax(const wchar_t *nptr, wchar_t **endptr, int base);
uintmax_t wcstoumax(const wchar_t *nptr, wchar_t **endptr, int base);

#endif /* _QLIBC_INTTYPES_H */
