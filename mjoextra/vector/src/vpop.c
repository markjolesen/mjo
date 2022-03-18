/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (vpop.c).
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <mstring.h>
/**/
#include "_vector.h"

extern void
  mjo_vector_pop(mjo_vector_t io_var)
{
  struct mjo_vector_arena *l_arena;
  unsigned char *l_obj;

  do
    {
      if (0 == io_var)
        {
          break;
        }

      l_arena = _mjo_vector_ptr_to_arena(io_var);

      if (0 == l_arena->m_size)
        {
          break;
        }

      if (0 == l_arena->m_count)
        {
          break;
        }

      l_arena->m_count--;

      l_obj = ((unsigned char **)io_var)[(l_arena->m_size * l_arena->m_count)];

      if (l_arena->m_discharge)
        {
          (*l_arena->m_discharge)((void **const) & l_obj);
        }

      explicit_bzero(l_obj, l_arena->m_size);
    }
  while (0);

  return;
}
