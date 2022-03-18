/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mstdio.h). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__mstdio_h__)

#  include <stdio.h>

#  if defined(_MSC_VER) || defined(__MSVCRT__) || defined(__WATCOMC__)
#    include <io.h>
#  endif

#  include <mstddef.h>

typedef ptrdiff_t mjo_handle_t;

typedef ssize_t (*mjo_read_t)(mjo_handle_t, void *, size_t);

enum mjo_status
{
  mjo_status_ok = 0,
  mjo_status_invalid,
  mjo_status_eof,
  mjo_status_truncated
};

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern int
    mjo_read(enum mjo_status *const,
             size_t *const,
             void *,
             size_t const,
             mjo_read_t const,
             mjo_handle_t);

#  if defined(__cplusplus)
}
#  endif

#  define __mstdio_h__
#endif
