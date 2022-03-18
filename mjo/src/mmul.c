/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mmul.c). 
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

extern int
  mjo_mul_size_t(size_t *const o_product, size_t const i_a, size_t const i_b)
{
  int l_rc;
  size_t l_fence;
  size_t l_product;

  l_rc = MJO_OK;

  do
    {
      if (i_a && i_b)
        {
          l_fence = (SIZE_MAX / i_a);

          if (i_b >= l_fence)
            {
              l_product = SIZE_MAX;
              l_rc = MJO_FAIL;
              errno = ERANGE;
              break;
            }
        }

      l_product = (i_a * i_b);
    }
  while (0);

  if (o_product)
    {
      (*o_product) = l_product;
    }

  return l_rc;
}
