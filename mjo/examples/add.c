/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (add.c). 
 This work is published from: United States.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
#include <stdint.h>
/**/
#include <mstdio.h>
#include <mstdlib.h>

int
  main()
{
  int rc;
  size_t sum;

  errno = 0;
  rc = mjo_add_size_t(&sum, SIZE_MAX, 1);

  printf("%zu + 1 = %zu\n", SIZE_MAX, sum);

  if (SIZE_MAX == sum)
    {
      printf("success (SIZE_MAX = sum)\n");
    }
  else
    {
      printf("fail (SIZE_MAX != sum)\n");
    }

  if (MJO_OK == rc)
    {
      printf("failed (no overflow)\n");
      rc = -1;
    }
  else
    {
      printf("success (overflow)\n");
      rc = 0;
    }

  if (ERANGE == errno)
    {
      printf("success (errno = ERANGE)\n");
    }
  else
    {
      printf("fail (errno != ERANGE)\n");
      rc = -1;
    }

  return rc;
}
