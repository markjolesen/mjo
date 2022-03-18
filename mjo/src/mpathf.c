/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mpathf.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
/**/
#include "mdirect.h"
#include "mstdio.h"
#include "mstdlib.h"
#include "munistd.h"

extern int
  mjo_path_full(unsigned char **const o_path, unsigned char const *i_path)
{
  unsigned char *l_path;

  do
    {
      if (0 == o_path)
        {
          errno = EINVAL;
          break;
        }

      errno = 0;

      if ((0 == i_path) || (0 == *i_path))
        {
          *o_path = (unsigned char *)getcwd(0, 0);
          break;
        }

#if defined(_MSC_VER) || defined(__MSVCRT__) || defined(__WATCOMC__)
      *o_path = (unsigned char *)_fullpath(0, (char const *)i_path, PATH_MAX);
#else
      *o_path = (unsigned char *)realpath((char const *)i_path, 0);
#endif
    }
  while (0);

  return ((*o_path) ? MJO_OK : MJO_FAIL);
}
