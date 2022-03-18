/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (vfree.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <mstdlib.h>
#include <mstring.h>
/**/
#include "_vector.h"

extern void
  mjo_vector_mem_free(mjo_vector_t *const io_var,
                      char const *i_fn,
                      size_t const i_ln)
{
  struct mjo_vector_arena *l_arena;

  if (io_var && *io_var)
    {
      mjo_vector_clear(*io_var);
      l_arena = _mjo_vector_ptr_to_arena(*io_var);
      explicit_bzero(l_arena, sizeof(*l_arena));
      mjo_mem_free((void **const) & l_arena, i_fn, i_ln);
      *io_var = 0;
    }

  return;
}
