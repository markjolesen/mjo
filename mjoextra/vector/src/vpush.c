/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (vpush.c). 
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
#include "_vector.h"

static int
  _mjo_vector_mem_push(mjo_vector_t *const io_var,
                       void const *i_obj,
                       size_t const i_count,
                       char const *i_fn,
                       size_t const i_ln)
{
  struct mjo_vector_arena *l_arena;
  int l_rc;
  unsigned char *l_dup;
  void *l_dst;
  void *l_src;
  size_t l_octets;
  size_t l_tally;
  size_t l_pos;
  size_t l_slot;

  do
    {
      l_arena = _mjo_vector_ptr_to_arena(*io_var);

      l_rc = mjo_add_size_t(&l_tally, l_arena->m_count, i_count);

      if (l_rc)
        {
          break;
        }

      if (l_arena->m_allocated <= l_tally)
        {
          l_rc = _mjo_vector_mem_grow(io_var, i_count, i_fn, i_ln);

          if (l_rc)
            {
              break;
            }

          l_arena = _mjo_vector_ptr_to_arena(*io_var);
        }

      l_rc = mjo_mul_size_t(&l_octets, l_arena->m_size, i_count);

      if (l_rc)
        {
          break;
        }

      l_rc = mjo_mul_size_t(&l_pos, l_arena->m_count, l_arena->m_size);

      if (l_rc)
        {
          break;
        }

      l_dst = (void *)&((unsigned char *)(*io_var))[l_pos];

      memcpy(l_dst, i_obj, l_octets);

      l_arena->m_count += i_count;
      l_rc = MJO_OK;
    }
  while (0);

  return l_rc;
}

extern int
  mjo_vector_mem_push(mjo_vector_t *const io_var,
                      void const *i_obj,
                      size_t const i_count,
                      char const *i_fn,
                      size_t const i_ln)
{
  int l_rc;
  struct mjo_vector_arena *l_arena;

  l_rc = MJO_FAIL;

  do
    {
      if ((0 == io_var) || (0 == *io_var))
        {
          errno = EINVAL;
          break;
        }

      if (0 == i_obj)
        {
          errno = EINVAL;
          break;
        }

      if (0 == i_count)
        {
          errno = E2BIG;
          break;
        }

      if (0 == (1 + i_count))
        {
          errno = E2BIG;
          break;
        }

      l_arena = _mjo_vector_ptr_to_arena(*io_var);

      if (0 == l_arena->m_size)
        {
          errno = E2BIG;
          break;
        }

      switch (l_arena->m_variant)
        {
        case mjo_vector_variant_struct:
        case mjo_vector_variant_ptrstr:
        case mjo_vector_variant_char:
        case mjo_vector_variant_short:
        case mjo_vector_variant_ushort:
        case mjo_vector_variant_bool:
        case mjo_vector_variant_int:
        case mjo_vector_variant_uint:
        case mjo_vector_variant_long:
        case mjo_vector_variant_ulong:
        case mjo_vector_variant_size_t:
        case mjo_vector_variant_ptrdiff_t:
        case mjo_vector_variant_double:
          l_rc = _mjo_vector_mem_push(io_var, i_obj, i_count, i_fn, i_ln);
          break;
        default:
          errno = ENOENT;
          break;
        }
    }
  while (0);

  return l_rc;
}
