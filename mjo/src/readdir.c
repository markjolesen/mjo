/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (readdir.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <errno.h>
#include <string.h>
/**/
#include "mdirect.h"
#include "mstdlib.h"

#if defined(_MSC_VER) || defined(__MSVCRT__)

extern struct dirent *
  readdir(struct dirent *const io_dir)
{
  struct dirent *l_dir;
  int l_rc;

  l_dir = (struct dirent *)0;

  do
    {
      if ((0 == io_dir) || (-1 == io_dir->m_handle))
        {
          l_rc = -1;
          errno = EBADF;
          break;
        }

      if ((*io_dir).d_name)
        {
          l_rc = _findnext((*io_dir).m_handle, &(*io_dir).m_data);
        }
      else
        {
          l_rc = 0;
        }

      (*io_dir).d_name = &(*io_dir).m_data.name[0];

      if (0 == l_rc)
        {
          l_dir = io_dir;
        }
    }
  while (0);

  return l_dir;
}

#endif
