/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (vclear.c). 
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
  mjo_vector_clear(mjo_vector_t io_var)
{
  struct mjo_vector_arena *l_arena;
  unsigned char *l_obj;
  size_t l_slot;

  if (io_var)
    {
      l_arena = _mjo_vector_ptr_to_arena(io_var);

      if (l_arena->m_discharge)
        {
          l_obj = (unsigned char *)io_var;

          for (l_slot = 0; l_arena->m_count > l_slot; l_slot++)
            {
              (*l_arena->m_discharge)((void **const) & l_obj);
              l_obj += l_arena->m_size;
            }
        }

      explicit_bzero((void *)io_var, (l_arena->m_allocated * l_arena->m_size));

      l_arena->m_count = 0;
    }

  return;
}
