/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mfree.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include "mstdlib.h"

extern void
  mjo_mem_free(void **const io_obj, char const *i_fn, size_t const i_ln)
{
  if (io_obj)
    {
      if (*io_obj)
        {
          free(*io_obj);
        }
      *io_obj = 0;
    }

  return;
}
