/*
 CC0 1.0 Universal --- Public Domain

 To the extent possible under law, Mark J. Olesen has waived all copyright
 and related or neighboring rights to this file (mjo_u8_validate.c). 
 This work is published from: United States.

 This file is part of the mjo library.

 Full text of this license can be found in '${MJO_HOME}/licenses/CC-CC0'
 or visit 'https://creativecommons.org/publicdomain/zero/1.0/legalcode.txt' or
 send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*/
#include "mu8.h"
#include "mutf8.h"

static void
  _mjo_u8_validate(int *const o_valid,
                   unsigned char **const o_last,
                   unsigned char const *i_str)
{
  unsigned char const *l_head;
  struct mjo_utf8 l_peek;
  enum mjo_status l_status;

  *o_valid = 1;

  l_head = i_str;

  do
    {
      if (0 == *l_head)
        {
          break;
        }

      mjo_utf8_compose(
        &l_status, (unsigned char const **)o_last, &l_peek, l_head);

      if (l_status)
        {
          if (mjo_status_eof != l_status)
            {
              *o_valid = 0;
            }
          break;
        }

      l_head = (*o_last);
    }
  while (1);

  return;
}

extern void
  mjo_u8_validate(int *const o_valid,
                  unsigned char **const o_last,
                  unsigned char const *i_str)
{
  unsigned char *l_last;
  int l_valid;

  l_last = (unsigned char *)i_str;
  l_valid = 0;

  if (i_str && (o_valid || o_last))
    {
      _mjo_u8_validate(&l_valid, &l_last, i_str);
    }

  if (o_last)
    {
      (*o_last) = l_last;
    }

  if (o_valid)
    {
      *o_valid = l_valid;
    }

  return;
}
