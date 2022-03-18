/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mtrim.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include "mu8.h"

extern void
  mjo_u8_trim(unsigned char *const io_str)
{
  do
    {
      if (0 == io_str)
        {
          break;
        }

      if (0 == *io_str)
        {
          break;
        }

      mjo_u8_trim_left(io_str);
      mjo_u8_trim_right(io_str);
    }
  while (0);

  return;
}
