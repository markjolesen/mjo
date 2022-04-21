/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mrealloc.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include "mstddef.h"
#include "mstdlib.h"

extern void
  mjo_mem_realloc(void **const io_obj,
                  size_t const i_obj_count,
                  size_t const i_obj_size,
                  char const *i_fn,
                  size_t const i_ln)
{
  int l_rc;
  void *l_obj;
  size_t l_product;

  do
    {
      if (0 == io_obj)
        {
          mjo_mem_abort(EINVAL, i_fn, i_ln);
        }

      if (0 == *io_obj)
        {
          mjo_mem_malloc(io_obj, i_obj_count, i_obj_size, i_fn, i_ln);
          break;
        }

      l_rc = mjo_mul_size_t(&l_product, i_obj_count, i_obj_size);

      if (l_rc)
        {
          mjo_mem_abort(E2BIG, i_fn, i_ln);
        }

      if (0 == l_product)
        {
          mjo_mem_free(io_obj, i_fn, i_ln);
          break;
        }

      l_obj = realloc((*io_obj), l_product);

      if (0 == l_obj)
        {
          mjo_mem_abort(errno, i_fn, i_ln);
        }

      (*io_obj) = l_obj;
    }
  while (0);

  return;
}
