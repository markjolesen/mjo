/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (value.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include "_arg.h"

extern mjo_vector_t
  mjo_arg_value(size_t *const o_slots,
                const mjo_arg_t i_arg,
                unsigned char const *i_attribute)
{
  struct mjo_arg_option *l_option;
  mjo_vector_t l_rc;
  size_t l_slots;

  l_rc = 0;
  l_slots = 0;

  do
    {
      if (0 == i_arg)
        {
          break;
        }

      if (0 == i_attribute || 0 == i_attribute[0])
        {
          break;
        }

      l_option = _mjo_arg_lookup(i_arg, i_attribute);

      if (0 == l_option)
        {
          break;
        }

      l_slots = mjo_vector_count(l_option->m_arg);
      l_rc = l_option->m_arg;
    }
  while (0);

  if (o_slots)
    {
      *o_slots = l_slots;
    }

  return l_rc;
}
