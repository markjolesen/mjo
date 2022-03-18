/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (vgrow.c). 
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
  __mjo_vector_mem_grow(mjo_vector_t *const io_var,
                        size_t const i_count,
                        char const *i_fn,
                        size_t const i_ln)
{
  struct mjo_vector_arena *l_arena;
  int l_rc;
  size_t l_octets;
  size_t l_pos;
  unsigned char *l_ptr;
  size_t l_tally;

  errno = E2BIG;

  l_arena = _mjo_vector_ptr_to_arena(*io_var);

  l_rc = MJO_FAIL;

  do
    {
      l_rc = mjo_add_size_t(&l_octets, i_count, 1);

      if (l_rc)
        {
          break;
        }

      l_rc = mjo_mul_size_t(&l_octets, l_octets, l_arena->m_size);

      if (l_rc)
        {
          break;
        }

      l_rc = mjo_add_size_t(&l_octets, l_octets, sizeof(*l_arena));

      if (l_rc)
        {
          break;
        }

      mjo_mem_realloc((void **const) & l_arena, 1, l_octets, i_fn, i_ln);

      (*io_var) = _mjo_vector_arena_to_ptr(l_arena);

      l_arena->m_allocated += (i_count + 1);

      l_pos = (l_arena->m_count * l_arena->m_size);
      l_ptr = &((unsigned char *)(*io_var))[l_pos];

      l_octets = ((l_arena->m_allocated - l_arena->m_count) * l_arena->m_size);

      explicit_bzero(l_ptr, l_octets);

      l_rc = MJO_OK;
    }
  while (0);

  return l_rc;
}

extern int
  _mjo_vector_mem_grow(mjo_vector_t *const io_var,
                       size_t i_count,
                       char const *i_fn,
                       size_t const i_ln)
{
  struct mjo_vector_arena *l_arena;
  int l_rc;
  size_t l_factored;
  size_t l_tally;

  do
    {
      if (0 == i_count)
        {
          l_rc = MJO_OK;
          break;
        }

      errno = E2BIG;
      l_rc = MJO_FAIL;

      l_arena = _mjo_vector_ptr_to_arena(*io_var);

      if (0 == l_arena->m_size)
        {
          break;
        }

      l_rc = mjo_add_size_t(&l_tally, l_arena->m_count, i_count);

      if (l_rc)
        {
          break;
        }

      if (l_arena->m_allocated > l_tally)
        {
          l_rc = MJO_OK;
          break;
        }

      l_rc = mjo_mul_size_t(
        &l_factored, l_tally, (size_t)(((float)l_tally) * 0.10f));

      if (0 == l_rc)
        {
          l_tally = l_factored;
        }

      l_rc = __mjo_vector_mem_grow(io_var, l_tally, i_fn, i_ln);
    }
  while (0);

  return l_rc;
}
