#pragma once

#include <inttypes.h>
#include <stdbool.h>

/// Line number type
typedef int32_t linenr_T;
/// Format used to print values which have linenr_T type
#define PRIdLINENR PRId32

/// Column number type
typedef int colnr_T;
/// Format used to print values which have colnr_T type
#define PRIdCOLNR "d"

enum { MAXLNUM = 0x7fffffff, };  ///< Maximal (invalid) line number

// MAXCOL used to be INT_MAX, but with 64 bit ints that results in running
// out of memory when trying to allocate a very long line.
enum { MAXCOL = 0x7fffffff, };   ///< Maximal column number

enum { MINLNUM = 1, };           ///< Minimum line number

enum { MINCOL = 1, };            ///< Minimum column number

/// position in file or buffer
typedef struct {
  linenr_T lnum;        ///< line number
  colnr_T col;          ///< column number
  colnr_T coladd;
} pos_T;

/// position in file or buffer, but without coladd
typedef struct {
  linenr_T lnum;        ///< line number
  colnr_T col;          ///< column number
} lpos_T;

/// for range position in file or buffer
typedef struct {
  linenr_T lnum;        ///< line number
  colnr_T col;          ///< column number
  bool blockwise;        ///< 'false' if charwise range
} rpos_T;
