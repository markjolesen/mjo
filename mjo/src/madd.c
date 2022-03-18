/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (madd.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
#include <stdint.h>
/**/
#include "mstddef.h"
#include "mstdlib.h"

extern int
  mjo_add_size_t(size_t *const o_sum, size_t const i_a, size_t const i_b)
{
  int l_rc;
  size_t l_fence;
  size_t l_sum;

  l_rc = MJO_OK;

  do
    {
      if (i_a && i_b)
        {
          l_fence = (SIZE_MAX - i_b);

          if (i_a > l_fence)
            {
              l_sum = SIZE_MAX;
              l_rc = MJO_FAIL;
              errno = ERANGE;
              break;
            }
        }

      l_sum = (i_a + i_b);
    }
  while (0);

  if (o_sum)
    {
      (*o_sum) = l_sum;
    }

  return l_rc;
}
