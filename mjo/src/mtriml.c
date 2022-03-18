/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mjo_u8_trim_left.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include <string.h>
/**/
#include "mr7.h"
#include "mu8.h"
#include "mutf8.h"

extern void
  _mjo_u8_trim_left(unsigned char *const io_str)
{
  int l_bool;
  int l_len;
  unsigned char const *l_head;
  unsigned char *l_last;
  struct mjo_utf8 l_peek;
  enum mjo_status l_status;

  l_head = io_str;

  do
    {
      mjo_utf8_compose(
        &l_status, (unsigned char const **)&l_last, &l_peek, l_head);

      if (l_status)
        {
          break;
        }

      mjo_utf8_is_whitespace(&l_bool, &l_peek);

      if (0 == l_bool)
        {
          break;
        }

      l_head = l_last;
    }
  while (1);

  if ((ptrdiff_t)l_last != (ptrdiff_t)l_head)
    {
      l_last = io_str;
      while (*l_head)
        {
          *l_last++ = *l_head++;
        }
      *l_last = 0;
    }

  return;
}

extern void
  mjo_u8_trim_left(unsigned char *const io_str)
{
  do
    {
      if (0 == io_str)
        {
          break;
        }

      if (0 == *io_str)
        {
          break;
        }

      _mjo_u8_trim_left(io_str);
    }
  while (0);

  return;
}
