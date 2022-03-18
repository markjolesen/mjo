/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mread.h). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#if !defined(__mread_h__)

#  include <stddef.h>
/**/
#  include "mstdio.h"
/**/
#  include "mvector.h"

#  define mjo_suffix_csv "csv"

#  if defined(__cplusplus)
extern "C"
{
#  endif

  extern int
    mjo_read_line(enum mjo_status *const,
                  mjo_vector_t *const,
                  size_t const,
                  mjo_read_t const,
                  mjo_handle_t);

  extern int
    mjo_read_csv(int *const,
                 enum mjo_status *const,
                 mjo_vector_t *const,
                 size_t const,
                 mjo_read_t const,
                 mjo_handle_t);

#  if defined(__cplusplus)
}
#  endif

#  define __mread_h__
#endif
