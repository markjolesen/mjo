/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (opendir.c). 
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
#include "mdirect.h"
#include "mstdlib.h"

#if defined(_MSC_VER) || defined(__MSVCRT__)

extern struct dirent *
  opendir(char const *i_path)
{
  struct dirent *l_ent;
  ptrdiff_t l_handle;
  struct _finddata_t l_data;
  unsigned char *l_path;

  l_ent = 0;
  l_path = 0;

  do
    {
      if ((0 == i_path) || (0 == *i_path))
        {
          errno = ENOTDIR;
          break;
        }

      mjo_path_join(&l_path, i_path, "*.*", 0);

      l_handle = _findfirst((char const *)l_path, &l_data);

      if (-1 == l_handle)
        {
          break;
        }

      mjo_calloc((void **const) & l_ent, 1, sizeof(*l_ent));
      (*l_ent).d_name = 0;
      (*l_ent).m_handle = l_handle;
      memcpy(&(*l_ent).m_data, &l_data, sizeof(l_data));
    }
  while (0);

  mjo_free((void **const) & l_path);

  return l_ent;
}

#endif
