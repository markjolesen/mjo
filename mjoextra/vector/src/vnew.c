/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (vnew.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include <mstddef.h>
#include <mstdlib.h>
#include <mstring.h>
/**/
#include "_vector.h"

extern void
  mjo_vector_mem_malloc(mjo_vector_t *const o_var,
                        size_t const i_count,
                        enum mjo_vector_variant const i_variant,
                        size_t const i_size_struct,
                        void (*i_discharge)(void **const),
                        char const *i_fn,
                        size_t const i_ln)
{
  struct mjo_vector_arena *l_arena;
  int l_rc;
  size_t l_octets;
  size_t l_size;

  l_rc = MJO_OK;
  do
    {
      switch (i_variant)
        {
        case mjo_vector_variant_struct:
          l_size = i_size_struct;
          break;
        case mjo_vector_variant_char:
          l_size = sizeof(char);
          break;
        case mjo_vector_variant_short:
        case mjo_vector_variant_ushort:
          l_size = sizeof(short);
          break;
        case mjo_vector_variant_bool:
        case mjo_vector_variant_int:
        case mjo_vector_variant_uint:
          l_size = sizeof(int);
          break;
        case mjo_vector_variant_long:
        case mjo_vector_variant_ulong:
          l_size = sizeof(long);
          break;
        case mjo_vector_variant_size_t:
          l_size = sizeof(size_t);
          break;
        case mjo_vector_variant_ptrstr:
        case mjo_vector_variant_ptrdiff_t:
          l_size = sizeof(ptrdiff_t);
          break;
        case mjo_vector_variant_double:
          l_size = sizeof(double);
          break;
        default:
          l_size = 0;
          l_octets = ((sizeof(double) > sizeof(ptrdiff_t))
                        ? sizeof(double)
                        : sizeof(ptrdiff_t));
          break;
        }

      if (l_size)
        {
          l_rc = mjo_mul_size_t(&l_octets, l_size, i_count);

          if (l_rc)
            {
              mjo_abort(E2BIG);
            }

          l_rc = mjo_mul_size_t(&l_octets, l_octets, l_size);

          if (l_rc)
            {
              mjo_abort(E2BIG);
            }
        }

      l_rc = mjo_add_size_t(&l_octets, l_octets, sizeof(*l_arena));

      if (l_rc)
        {
          mjo_abort(E2BIG);
        }

      mjo_mem_calloc((void **const) & l_arena, l_octets, 1, i_fn, i_ln);

      l_arena->m_variant = i_variant;

      if (l_size)
        {
          l_arena->m_allocated = i_count;
          l_arena->m_size = l_size;
        }

      if (i_discharge)
        {
          l_arena->m_discharge = i_discharge;
        }
      else if (mjo_vector_variant_ptrstr == i_variant)
        {
          l_arena->m_discharge = mjo_vector_variant_discharge_free;
        }

      (*o_var) = _mjo_vector_arena_to_ptr(l_arena);
    }
  while (0);

  return;
}
