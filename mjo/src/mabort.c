/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mabort.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
#include <stdio.h>
#include <string.h>
/**/
#include "mstdlib.h"

extern void
  mjo_mem_abort(int const i_errno, char const *i_fn, size_t const i_ln)
{
  unsigned char const *l_ptr;

  fprintf(stderr, "ABORT:");

  if (i_fn && *i_fn)
    {
      fprintf(stderr, "\t\tFunction: %s (%u)\n", i_fn, (unsigned)i_ln);
    }

  if (i_errno)
    {
      l_ptr = (unsigned char const *)strerror(i_errno);

      if (l_ptr && *l_ptr)
        {
          fprintf(stderr, "\t\terrno: %s (%d)\n", l_ptr, i_errno);
        }
      else
        {
          fprintf(stderr, "\t\tCode: (%d)\n", i_errno);
        }
    }

  abort();

  return;
}
