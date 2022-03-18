/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (vperpush.c). 
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include <mstdlib.h>
#include <mstr.h>
#include <mstring.h>
/**/
#include "_vector.h"

extern int
  mjo_vector_mem_permute_push(mjo_vector_t *const io_var,
                              unsigned char const *i_str,
                              char const *i_fn,
                              size_t const i_ln)
{
  struct mjo_vector_arena *l_arena;
  int l_rc;
  size_t l_count;
  union
  {
    short m_short;
    unsigned short m_ushort;
    int m_int;
    unsigned int m_uint;
    long m_long;
    unsigned long m_ulong;
    size_t m_size_t;
    ptrdiff_t m_ptrdiff_t;
    double m_double;
    void const *m_ptr;
  } l_value;

  l_rc = MJO_FAIL;

  do
    {
      if ((0 == io_var) || (0 == *io_var))
        {
          errno = EINVAL;
          break;
        }

      if (0 == i_str)
        {
          errno = EINVAL;
          break;
        }

      l_arena = _mjo_vector_ptr_to_arena(*io_var);

      if (0 == l_arena->m_size)
        {
          errno = E2BIG;
          break;
        }

      l_count = 1;
      memset(&l_value, 0, sizeof(l_value));

      switch (l_arena->m_variant)
        {
        case mjo_vector_variant_struct:
          l_value.m_ptr = i_str;
          l_rc = 0;
          break;
        case mjo_vector_variant_ptrstr:
          mjo_strdup((unsigned char **)&l_value.m_ptr, i_str);
          l_rc = 0;
          break;
        case mjo_vector_variant_char:
          l_count = strlen((char const *)i_str);
          l_value.m_ptr = i_str;
          l_rc = 0;
          break;
        case mjo_vector_variant_short:
          l_rc = mjo_str_to_short(&l_value.m_short, i_str);
          break;
        case mjo_vector_variant_ushort:
          l_rc = mjo_str_to_ushort(&l_value.m_ushort, i_str);
          break;
        case mjo_vector_variant_bool:
          l_rc = mjo_str_to_bool(&l_value.m_int, i_str);
          break;
        case mjo_vector_variant_int:
          l_rc = mjo_str_to_int(&l_value.m_int, i_str);
          break;
        case mjo_vector_variant_uint:
          l_rc = mjo_str_to_uint(&l_value.m_uint, i_str);
          break;
        case mjo_vector_variant_long:
          l_rc = mjo_str_to_long(&l_value.m_long, i_str);
          break;
        case mjo_vector_variant_ulong:
          l_rc = mjo_str_to_ulong(&l_value.m_ulong, i_str);
          break;
        case mjo_vector_variant_size_t:
          l_rc = mjo_str_to_size_t(&l_value.m_size_t, i_str);
          break;
        case mjo_vector_variant_ptrdiff_t:
          l_rc = mjo_str_to_ptrdiff_t(&l_value.m_ptrdiff_t, i_str);
          break;
        case mjo_vector_variant_double:
          l_rc = mjo_str_to_double(&l_value.m_double, i_str);
          break;
        }

      if (l_rc)
        {
          break;
        }

      if (l_count)
        {
          l_rc = mjo_vector_mem_push(
            io_var, (void *const) & l_value, l_count, i_fn, i_ln);
        }
    }
  while (0);

  return l_rc;
}
