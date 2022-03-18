/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (closedir.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include "mdirect.h"
#include "mstdlib.h"

#if defined(_MSC_VER) || defined(__MSVCRT__)

extern int
  closedir(struct dirent *const io_dir)
{
  int l_rc;

  l_rc = MJO_FAIL;

  do
    {
      if (0 == io_dir)
        {
          errno = EBADF;
          break;
        }

      l_rc = _findclose((*io_dir).m_handle);
      mjo_free((void **const) & io_dir);
    }
  while (0);

  return l_rc;
}

#endif
