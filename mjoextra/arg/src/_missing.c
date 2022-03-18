/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (_missing.c)
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <mstdio.h>
/**/
#include "_arg.h"

static void
  _option_missing(int *const o_valid,
                  mjo_arg_t const io_arg,
                  struct mjo_arg_option const *const i_option)
{
  size_t l_count;
  struct mjo_arg_option const *l_node;

  l_node = i_option;

  do
    {
      if (0 == l_node)
        {
          break;
        }

      l_count = mjo_vector_count(l_node->m_arg);

      if ((0 == l_count)
          && (mjo_arg_option_mask_required & l_node->m_option_mask))
        {
          fprintf(io_arg->m_diag.m_elog, "Error: Option is required\n");
          fprintf(io_arg->m_diag.m_elog, "\t('%s')\n", l_node->m_attribute);
          *o_valid = 0;
        }

      l_node = l_node->m_next;
    }
  while (1);

  return;
}

extern void
  _mjo_arg_argument_missing(int *const o_valid, mjo_arg_t const io_arg)
{
  size_t l_slot;

  *o_valid = 1;

  for (l_slot = 0; mjo_arg_buckets_max > l_slot; l_slot++)
    {
      if (io_arg->m_bucket[l_slot])
        {
          _option_missing(o_valid, io_arg, io_arg->m_bucket[l_slot]);
        }
    }

  return;
}
