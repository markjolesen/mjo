/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (abort.c). 
 This work is published from: United States.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
#include <stdint.h>
/**/
#include <mstdlib.h>

int
  main()
{
  int rc;
  size_t result;

  rc = mjo_add_size_t(&result, SIZE_MAX, 1);

  if (rc)
    {
      mjo_abort(errno);
    }

  return rc;
}
