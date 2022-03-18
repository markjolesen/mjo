/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (vtype.c).
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include "_vector.h"

extern enum mjo_vector_variant
  mjo_vector_type(const mjo_vector_t i_var)
{
  struct mjo_vector_arena const *l_arena;
  enum mjo_vector_variant l_variant;

  if (i_var)
    {
      l_arena = _mjo_vector_ptr_to_arena(i_var);
      l_variant = l_arena->m_variant;
    }
  else
    {
      l_variant = (enum mjo_vector_variant) - 1;
    }

  return l_variant;
}
