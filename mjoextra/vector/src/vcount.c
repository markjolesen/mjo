/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (vcount.c).
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include "_vector.h"

extern size_t
  mjo_vector_count(const mjo_vector_t i_var)
{
  struct mjo_vector_arena const *l_arena;
  size_t l_count;

  l_count = 0;

  if (i_var)
    {
      l_arena = _mjo_vector_ptr_to_arena(i_var);
      l_count = l_arena->m_count;
    }

  return l_count;
}
