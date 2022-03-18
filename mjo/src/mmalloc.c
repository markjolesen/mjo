/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mmalloc.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include "mstdlib.h"

extern void
  mjo_mem_malloc(void **const o_obj,
                 size_t const i_obj_count,
                 size_t const i_obj_size,
                 char const *i_fn,
                 size_t const i_ln)
{
  int l_rc;
  size_t l_sum;

  l_sum = 1;

  do
    {
      if (0 == o_obj)
        {
          mjo_mem_abort(EINVAL, i_fn, i_ln);
        }

      (*o_obj) = 0;

      l_rc = mjo_mul_size_t(&l_sum, i_obj_count, i_obj_size);

      if (l_rc)
        {
          mjo_mem_abort(E2BIG, i_fn, i_ln);
        }

      if (0 == l_sum)
        {
          l_sum = 1;
        }

      (*o_obj) = malloc(l_sum);

      if (0 == (*o_obj))
        {
          mjo_mem_abort(errno, i_fn, i_ln);
        }
    }
  while (0);

  return;
}
