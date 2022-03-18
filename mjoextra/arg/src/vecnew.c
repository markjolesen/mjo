/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (vecnew.c). 
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

#define RESULT_LESS_THAN -1
#define RESULT_EQUAL_TO 0
#define RESULT_GREATER_THAN 1

static int
  mjo_arg_option_compare(void const *const i_option1,
                         void const *const i_option2)
{
  int l_rc;
  struct mjo_arg_option *const *l_option1;
  struct mjo_arg_option *const *l_option2;

  l_option1 = (struct mjo_arg_option *const *const)i_option1;
  l_option2 = (struct mjo_arg_option *const *const)i_option2;

  l_rc = strcmp((char const *)(*l_option1)->m_attribute,
                (char const *)(*l_option2)->m_attribute);

  if (0 == l_rc)
    {
      if (mjo_arg_option_mask_long & (*l_option1)->m_option_mask)
        {
          if (0 == (mjo_arg_option_mask_long & (*l_option2)->m_option_mask))
            {
              l_rc = RESULT_GREATER_THAN;
            }
        }
      else if (mjo_arg_option_mask_long & (*l_option2)->m_option_mask)
        {
          l_rc = RESULT_LESS_THAN;
        }
    }

  return l_rc;
}

static void
  mjo_arg_vector_populate_reference(struct mjo_arg_option **o_option,
                                    const mjo_arg_t i_arg)
{
  struct mjo_arg_option *l_option;
  size_t l_count;
  size_t l_slot;

  l_count = 0;

  for (l_slot = 0; mjo_arg_buckets_max > l_slot; l_slot++)
    {
      for (l_option = i_arg->m_bucket[l_slot]; l_option;
           l_option = l_option->m_next)
        {
          o_option[l_count++] = l_option;
        }
    }

  return;
}

static size_t
  mjo_arg_bucket_count(const mjo_arg_t i_arg)
{
  struct mjo_arg_option const *l_option;
  size_t l_rc;
  size_t l_slot;

  l_rc = 0;

  for (l_slot = 0; mjo_arg_buckets_max > l_slot; l_slot++)
    {
      for (l_option = i_arg->m_bucket[l_slot]; l_option;
           l_option = l_option->m_next)
        {
          l_rc++;
        }
    }

  return l_rc;
}

extern struct mjo_arg_option *const *const
  mjo_arg_vector_mem_malloc(size_t *const o_count,
                            const mjo_arg_t i_arg,
                            char const *i_fn,
                            size_t const i_ln)
{
  size_t l_count;
  struct mjo_arg_option **l_option;

  l_count = 0;
  l_option = 0;

  do
    {
      if (0 == i_arg)
        {
          break;
        }

      l_count = mjo_arg_bucket_count(i_arg);

      if (0 == l_count)
        {
          break;
        }

      if (0 == (1 + l_count))
        {
          break;
        }

      mjo_mem_malloc((void **const) & l_option,
                     (1 + l_count),
                     sizeof(struct mjo_arg_option *),
                     i_fn,
                     i_ln);

      mjo_arg_vector_populate_reference(l_option, i_arg);

      l_option[l_count] = 0;

      qsort((void *)l_option,
            l_count,
            sizeof(struct mjo_arg_option *),
            mjo_arg_option_compare);
    }
  while (0);

  if (o_count)
    {
      *o_count = l_count;
    }

  return l_option;
}
