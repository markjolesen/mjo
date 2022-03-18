/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (free.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <mstdlib.h>
#include <mstring.h>
/**/
#include "_arg.h"

static void
  _mjo_arg_option_free(struct mjo_arg_option **const io_option)
{
  struct mjo_arg_option *l_head;
  struct mjo_arg_option *l_next;

  l_head = (*io_option);

  do
    {
      if (0 == l_head)
        {
          break;
        }

      l_next = l_head->m_next;

      mjo_free((void **const) & l_head->m_attribute);
      mjo_free((void **const) & l_head->m_description);
      mjo_vector_free(&l_head->m_arg);

      explicit_bzero((void *const)l_head, sizeof(*l_head));
      mjo_free((void **const) & l_head);

      l_head = l_next;
    }
  while (1);

  (*io_option) = 0;

  return;
}

static void
  _mjo_hash_discharge(struct mjo_arg_option **const io_bucket,
                      size_t const i_count)
{
  size_t l_slot;

  for (l_slot = 0; i_count > l_slot; l_slot++)
    {
      if (io_bucket[l_slot])
        {
          _mjo_arg_option_free(&io_bucket[l_slot]);
        }
    }

  return;
}

extern void
  mjo_arg_mem_free(mjo_arg_t *const io_arg,
                   char const *i_fn,
                   size_t const i_ln)
{
  if (io_arg && *io_arg)
    {
      mjo_vector_free(&(*io_arg)->m_scratch);
      mjo_vector_free(&(*io_arg)->m_include);
      _mjo_hash_discharge((*io_arg)->m_bucket, mjo_arg_buckets_max);
      explicit_bzero((void *const)(*io_arg), sizeof(**io_arg));
      mjo_mem_free((void **const)io_arg, i_fn, i_ln);
    }

  return;
}
