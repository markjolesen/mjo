/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (path_join.c). 
 This work is published from: United States.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <mstdio.h>
#include <mstdlib.h>
#include <munistd.h>

int
  main()
{
  unsigned char *path;
  unsigned char *cwd;

  cwd = (unsigned char *)getcwd(0, (size_t)-1);

  mjo_path_join(&path, cwd, (unsigned char *)"foo", (unsigned char *)"txt");

  printf("path=%s\n", (char *)path);

  mjo_free((void **)&path);

  return 0;
}
