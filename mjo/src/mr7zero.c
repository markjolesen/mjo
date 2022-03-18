/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mr7zero.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include "mstring.h"

extern void
  mjo_r7_zero(void *const io_block, size_t const i_size)
{
  unsigned char *l_end;

  do
    {
      if (0 == io_block)
        {
          break;
        }

      if (0 == i_size)
        {
          break;
        }

      l_end = &((unsigned char *)io_block)[i_size - 1];

      do
        {
          *l_end = 0;

          if ((ptrdiff_t)io_block == (ptrdiff_t)l_end)
            {
              break;
            }

          l_end--;
        }
      while (1);
    }
  while (0);

  return;
}
