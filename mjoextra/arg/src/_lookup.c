/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (_lookup.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <mr7.h>
#include <mstring.h>
/**/
#include "_arg.h"

extern struct mjo_arg_option *const
  _mjo_arg_lookup(const mjo_arg_t i_arg, unsigned char const *i_attribute)
{
  struct mjo_arg_option *l_option;
  size_t l_hash;
  int l_rc;
  size_t l_slot;

  l_option = 0;

  do
    {
      if (0 == i_attribute || 0 == i_attribute[0])
        {
          break;
        }

      mjo_r7_hash(&l_hash, i_attribute, strlen((char const *)i_attribute));
      l_slot = (l_hash % mjo_arg_buckets_max);
      l_option = i_arg->m_bucket[l_slot];

      do
        {
          if (0 == l_option)
            {
              break;
            }

          l_rc = strcmp((char const *)l_option->m_attribute,
                        (char const *)i_attribute);

          if (0 == l_rc)
            {
              break;
            }

          l_option = l_option->m_next;
        }
      while (1);
    }
  while (0);

  return l_option;
}
