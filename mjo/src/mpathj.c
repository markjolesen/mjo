/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mpathj.c). 
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
/**/
#include "mr7.h"

extern void
  mjo_mem_path_join(unsigned char **const o_path,
                    unsigned char const *i_prefix,
                    unsigned char const *i_name,
                    unsigned char const *i_suffix,
                    char const *i_fn,
                    size_t const i_ln)
{
  int l_rc;
  size_t l_name_octets;
  size_t l_prefix_octets;
  size_t l_suffix_octets;
  size_t l_sum;
  unsigned char *l_path;
  unsigned char *l_tail;

  do
    {
      if (0 == o_path)
        {
          mjo_mem_abort(EINVAL, i_fn, i_ln);
        }

      l_prefix_octets = ((i_prefix) ? strlen((char const *)i_prefix) : 0);
      l_name_octets = ((i_name) ? strlen((char const *)i_name) : 0);
      l_suffix_octets = ((i_suffix) ? strlen((char const *)i_suffix) : 0);

      if (l_name_octets || l_prefix_octets || l_suffix_octets)
        {
          l_rc = mjo_add_size_t(&l_sum, l_prefix_octets, l_name_octets);

          if (l_rc)
            {
              mjo_mem_abort(E2BIG, i_fn, i_ln);
            }

          l_rc = mjo_add_size_t(&l_sum, l_sum, l_suffix_octets);

          if (l_rc)
            {
              mjo_mem_abort(E2BIG, i_fn, i_ln);
            }

          l_rc = mjo_add_size_t(&l_sum, l_sum, 4);

          if (l_rc)
            {
              mjo_mem_abort(E2BIG, i_fn, i_ln);
            }
        }
      else
        {
          mjo_mem_calloc((void **const)o_path, 2, 1, i_fn, i_ln);
          (*o_path)[0] = mjo_r7_period;
          (*o_path)[1] = 0;
          break;
        }

      mjo_mem_calloc((void **const) & l_path, l_sum, 1, i_fn, i_ln);

      if (l_prefix_octets)
        {
          strcpy((char *)l_path, (char const *)i_prefix);
          l_tail = (l_path + l_prefix_octets);
          *l_tail++ = mjo_r7_dirsep;
        }
      else
        {
          l_tail = l_path;
        }

      if (l_name_octets)
        {
          strcat((char *)l_tail, (char const *)i_name);
          l_tail += l_name_octets;
        }

      if (l_suffix_octets)
        {
          *l_tail++ = mjo_r7_period;
          strcat((char *)l_tail, (char const *)i_suffix);
        }

      (*o_path) = l_path;
    }
  while (0);

  return;
}
