/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (path_full.c). 
 This work is published from: United States.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
#include <string.h>
/**/
#include <mstdio.h>
#include <mstdlib.h>

int
  main(int argc, char **argv)
{
  unsigned char *path;
  char *path_prog;

  printf("before=%s\n", argv[0]);

  mjo_path_full(&path, (unsigned char const *)argv[0]);

  if (path)
    {
      printf("after=%s\n", (char *)path);
      mjo_free((void **)&path);
    }
  else
    {
      printf("failed: errrno(%d)=%s\n", errno, strerror(errno));
    }

  return 0;
}
