/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (new.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include <mstdlib.h>
#include <mstring.h>
/**/
#include "_arg.h"

extern void
  mjo_arg_mem_malloc(mjo_arg_t *const o_arg,
                     enum mjo_arg_rule_mask const i_rule_mask,
                     char const *i_fn,
                     size_t const i_ln)
{
  if (o_arg)
    {
      mjo_mem_calloc((void **const)o_arg, 1, sizeof((**o_arg)), i_fn, i_ln);

      (*o_arg)->m_rule_mask = i_rule_mask;
      (*o_arg)->m_diag.m_elog = stderr;

      mjo_vector_mem_malloc(&(*o_arg)->m_include,
                            0,
                            mjo_vector_variant_ptrdiff_t,
                            mjo_vector_size_auto,
                            mjo_vector_variant_discharge_free,
                            i_fn,
                            i_ln);

      mjo_vector_mem_malloc(&(*o_arg)->m_scratch,
                            0,
                            mjo_vector_variant_char,
                            mjo_vector_size_auto,
                            0,
                            i_fn,
                            i_ln);
    }
  else
    {
      errno = EINVAL;
    }

  return;
}
