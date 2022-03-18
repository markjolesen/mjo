/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (vshiftl.c).
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include <mr7.h>
#include <mstdlib.h>
/**/
#include "_vector.h"

extern int
  mjo_vector_shift_left(mjo_vector_t io_var,
                        size_t const i_slot,
                        size_t const i_count)
{
  int l_rc;
  struct mjo_vector_arena *l_arena;

  l_rc = MJO_FAIL;

  do
    {
      if (0 == io_var)
        {
          errno = EINVAL;
          break;
        }

      l_arena = _mjo_vector_ptr_to_arena(io_var);

      l_rc = mjo_r7_shift_left(io_var,
                               i_slot,
                               i_count,
                               (*l_arena).m_size,
                               (*l_arena).m_count,
                               (*l_arena).m_discharge);
    }
  while (0);

  return l_rc;
}
