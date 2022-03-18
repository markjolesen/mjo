/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (vdequeue.c).
 This work is published from: United States.

 This file is part of the mjo_extra library.

 Full text of this license can be found in '${MJO_EXTRA_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <mstdlib.h>
#include <mstring.h>
/**/
#include "_vector.h"

extern void
  mjo_vector_dequeue(mjo_vector_t io_var)
{
  struct mjo_vector_arena *l_arena;

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

      if (l_arena->m_discharge)
        {
          (*l_arena->m_discharge)((void **const)io_var);
          explicit_bzero((void *)io_var, l_arena->m_size);
        }

      l_arena->m_count--;

      memcpy((void *)io_var,
             ((unsigned char **)io_var)[l_arena->m_size],
             (l_arena->m_size * l_arena->m_count));

      explicit_bzero(
        ((unsigned char **)io_var)[l_arena->m_size * l_arena->m_count],
        l_arena->m_size);
    }
  while (0);

  return;
}
