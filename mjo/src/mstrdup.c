/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mjo_mem_strdup.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
#include <string.h>
/**/
#include "mstddef.h"
#include "mstdlib.h"

extern void
  mjo_mem_strdup(unsigned char **const o_dup,
                 unsigned char const *i_src,
                 char const *i_fn,
                 size_t const i_ln)
{
  size_t l_octets;

  if (o_dup)
    {
      if (i_src && i_src[0])
        {
          l_octets = strlen((char const *)i_src);

          if (0 == (1 + l_octets))
            {
              mjo_mem_abort(E2BIG, i_fn, i_ln);
            }

          l_octets++;
          mjo_mem_malloc((void **const)o_dup, 1, l_octets, i_fn, i_ln);
          strcpy((char *)(*o_dup), (char const *)i_src);
        }
      else
        {
          mjo_mem_malloc((void **const)o_dup, 1, 1, i_fn, i_ln);
          (*o_dup)[0] = 0;
        }
    }
  else
    {
      mjo_mem_abort(EINVAL, i_fn, i_ln);
    }

  return;
}
